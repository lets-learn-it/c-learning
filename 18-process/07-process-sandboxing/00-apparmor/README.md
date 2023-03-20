# AppArmor

## using cmdline utility

```sh
# install utilites
sudo apt install apparmor apparmor-profiles apparmor-profiles-extra apparmor-utils apparmor-notify apparmor-easyprof -y

# install development files
sudo apt install libapparmor-dev

## stop logs or something ##
# check log ratelimit
sudo systemctl -n kernel.printk_ratelimit

# make it 0 (one profile created, set it back to original value)
sudo systemctl -w kernel.printk_ratelimit=0

## AppArmor ##
# check if enabled
aa-enabled

# unprotected apps which are listening for network connections
aa-unconfied
aa-unconfied --paranoid # all processes & profile

# check status
sudo aa-status

# put profile in enforce/complain mode
sudo aa-enforce /etc/apparmor.d/my_profile
sudo aa-complain /etc/apparmor.d/my_profile

# disable profile temporarily
sudo aa-disable /etc/apparmor.d/my_profile

# clean profile
sudo aa-cleanprof /etc/apparmor.d/my_profile

# remove all profiles
sudo aa-teardown

### apparmor_parser ###
# after editing profile manually validate it
sudo apparmor_parser -Q /etc/apparmor.d/home.parikshit.github.c-learning.18-process.07-process-sandboxing.00-apparmor.00-cli.main.sh

# replace old with new
sudo apparmor_parser -r /etc/apparmor.d/home.parikshit.github.c-learning.18-process.07-process-sandboxing.00-apparmor.00-cli.main.sh
```

## Rules

- profile contains three main types of rules: **path entries**, **capability entries**, and **network entries**. E.g.
```
#include <tunables/global>

# This is comment
/usr/bin/foo {
  #include <abstractions/base>

  capability setgid,
  network inet tcp,

  /bin/mount ux,
  /dev/{,u}random r,
  /usr/lib/** mr,
  /tmp/ r,
  /@{HOME}/.profile rw,
}
```

### Network Access Control

- syntax : `network [[<domain>] [<type] [<protocol]]`
- supported domains: `inet`, `ax25`, `appletalk`, `netrom`, `bridge`, `x25`, `inet6`, `rose`, `netbeui`, `security`, `key`, `packet`, `ash`, `econet`, `atmsvc`, `sna`, `irda`, `pppox`, `wanpipe`, `bluetooth`.
- Supported types: `stream`, `dgram`, `seqpacket`, `rdm`, `raw`, `packet`
- supported protocols: `tcp`, `udp`, `icmp`

**Example Rules**

```
# allow all networking
network,

# Only IPv4
network inet,

# only IPv6
network inet6,

# Only IPv4 TCP (1)
network inet stream,
network inet tcp,
```

### Filesystem Access Control

#### Paths & Globbing

Globbing (regular expression matching) is when modify directory path using wild cards. File resources can be specified with globbing syntax similar to shells (bash, csh, zsh).

| Wild Card | Meaning                                                      |
|-----------|--------------------------------------------------------------|
| `*`       | Substitutes for any number of characters except `/`          |
| `**`      | Substitutes for any number of characters including `/`       |
| `?`       | Substitutes for any single character except `/`              |
| `[abc]`   | Substitutes for single character `a`, `b`, or `c`            |
| `[a-c]`   | Same as above                                                |
| `{ab,cd}` | Expands to one rule to match `ab` and one rule to match `cd` |
| `[^a]`    | Substitutes for any character except a                       |

**Examples**

- `/xyz/abc/*`: all files inside abc directory
- `/xyz/abc/`: only abc directory
- `/xyz/abc/**/`: any directory below abc
- `/xyx/abc/**`: all files & directories under abc
- `/xyz/abc/**[^/]`: only files not directories

#### File Permission Access Modes

| Mode | Meaning                                                                                                                                                                        |
|------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `r`  | Read Only                                                                                                                                                                      |
| `w`  | Write Only (cant be used with `a`). For removing file.                                                                                                                         |
| `a`  | Append Only (cant be used with `w`). Cant overwrite, rename, remove file                                                                                                       |
| `k`  | File Locking Mode                                                                                                                                                              |
| `px` | Discrete Profile Execute Mode                                                                                                                                                  |
| `Px` | Discrete Profile Execute Mode -- Clean Exec                                                                                                                                    |
| `ux` | Unconstrained Execute Mode.                                                                                                                                                    |
| `Ux` | Unconstrained Execute Mode -- Clean Exec                                                                                                                                       |
| `ix` | Inherit Execute Mode. It prevents AppArmor domain transition on `execve(2)` when profiled program executes named program. Instead, executed resource inherits current profile. |
| `m`  | Allow Executable Mapping. Allows a file to be mapped into memory using `mmap(2)`'s `PROT_EXEC` flag.                                                                           |
| `l`  | Link Mode. It mediates access to hard links.                                                                                                                                   |
### Capability Entries

Capabilties statements are simply word `capability` followed by name of the POSIX capability.

## Building Profiles

- All files in `/etc/apparmor.d/` directory are interpreted as profiles and are loaded as such. To stop profiles from being read & evaluated, remove them from directory.
- There are 2 methods for creating profiles:
  - **Standalone profiling**: Method suitable for profiling small applications that have a finite run time.
  - **Systemic Profiling**: suitable for profiling large numbers of programs all at once or applications that may run for days, weeks, or continuously across reboots.

### Standalone Profiling

- use `aa-genprof` command
```
aa-genprof [ -d /path/to/profiles ] program
```
- Start application in another terminal & test it.
- Once done, go ahead with `aa-genprof` command.

### Systemic Profiling

- Make AppArmor monitor your program. To do that, create approximate profile using `aa-autodep`.
```
aa-autodep [ -d /path/to/profiles ] [ program1 program2 ... ]
```
- Put that profile in **complain** mode.
- Exercise application. Run it & test all functionality.
- Analyze logs using `aa-logprof`.
```
aa-logprof [-d /path/to/profiles ] [ -f /path/to/logfile ]
```

## ChangeHat

WIP

## References

[[00] https://gitlab.com/apparmor/apparmor/-/wikis/Documentation](https://gitlab.com/apparmor/apparmor/-/wikis/Documentation)

[[01] https://help.ubuntu.com/community/AppArmor](https://help.ubuntu.com/community/AppArmor)

[[02] https://manpages.ubuntu.com/manpages/jammy/en/man5/apparmor.d.5.html](https://manpages.ubuntu.com/manpages/jammy/en/man5/apparmor.d.5.html)

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

## References

[[00] https://gitlab.com/apparmor/apparmor/-/wikis/Documentation](https://gitlab.com/apparmor/apparmor/-/wikis/Documentation)

[[01] https://help.ubuntu.com/community/AppArmor](https://help.ubuntu.com/community/AppArmor)

[[02] https://manpages.ubuntu.com/manpages/jammy/en/man5/apparmor.d.5.html](https://manpages.ubuntu.com/manpages/jammy/en/man5/apparmor.d.5.html)

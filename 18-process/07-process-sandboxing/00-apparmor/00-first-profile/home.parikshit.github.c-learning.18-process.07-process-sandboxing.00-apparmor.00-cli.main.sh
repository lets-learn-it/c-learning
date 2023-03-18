# Last Modified: Sat Mar 18 10:15:53 2023
abi <abi/3.0>,

include <tunables/global>

/home/parikshit/github/c-learning/18-process/07-process-sandboxing/00-apparmor/00-cli/main.sh {
  include <abstractions/base>
  include <abstractions/bash>

  /home/parikshit/github/c-learning/18-process/07-process-sandboxing/00-apparmor/00-cli/main.sh r,
  /usr/bin/bash ix,
  /home/parikshit/github/c-learning/18-process/07-process-sandboxing/00-apparmor/00-cli/hello.txt w,
  owner /home/parikshit/github/c-learning/18-process/07-process-sandboxing/00-apparmor/00-cli/bye.txt w,
}

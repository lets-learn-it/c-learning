# Signals

- Signals are **software interrupts.** They provide way of handling **asynchronous events.**
- `kill()` function allows process to send any signal to another process/process group. (need to be owner of the process that we are sending signal to, or superuser).
- process can define what to do when XYZ signal occurs using `signal(int sigcode, Sigfunc *)`

  **We can tell kernel to do one of below action**
  1. **Ignore the signal**: This works with all signals except *SIGKILL* and *SIGSTOP*. These two signals provide kernel & superuser a way to kill or stop process.
  2. **Catch the signal**: We can register function with kernel. We can write function which perform clean up when *SIGTERM* signal occurs. Note: *SIGKILL* & *SIGSTOP* can't be caught.
  3. **Let default action apply**: Every signal has their own default action. Note: most signals has **terminate process** as default action.
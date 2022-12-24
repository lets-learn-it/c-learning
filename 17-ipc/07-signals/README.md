# Signals

- Signals are **software interrupts.** They provide way of handling **asynchronous events.**
- `kill()` function allows process to send any signal to another process/process group. (need to be owner of the process that we are sending signal to, or superuser).
- process can define what to do when XYZ signal occurs using `signal(int sigcode, void (*func) (int))`. func can be 1. constant *SIG_IGN* (ignore signal) 2. constant *SIG_DFL* (default action) or 3. address of function.

  **We can tell kernel to do one of below action**
  1. **Ignore the signal**: This works with all signals except *SIGKILL* and *SIGSTOP*. These two signals provide kernel & superuser a way to kill or stop process.
  2. **Catch the signal**: We can register function with kernel. We can write function which perform clean up when *SIGTERM* signal occurs. Note: *SIGKILL* & *SIGSTOP* can't be caught.
  3. **Let default action apply**: Every signal has their own default action. Note: most signals has **terminate process** as default action.
- When new process created, it inherits parent's signal disposition (action for signal). This is because child starts off with copy of parent's memory image, address of signal catching function.
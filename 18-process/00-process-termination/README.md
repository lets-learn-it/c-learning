# Process Termination

### Normal Termination

- return from `main`
- calling `exit`
- calling `_exit` or `_Exit`
- return of last thread from its start routine
- Calling `pthread_exit` from last thread

### Abnormal Termination

- Calling `abort`
- receipt of signal (`kill -L`)
- response of last thread to cancellation request

## References

[sigaction(2) — Linux manual page](https://man7.org/linux/man-pages/man2/sigaction.2.html)

[signal(2) — Linux manual page](https://man7.org/linux/man-pages/man2/signal.2.html)

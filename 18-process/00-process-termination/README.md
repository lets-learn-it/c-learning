# Process Termination

### Normal Termination

- return from `main`
- calling `exit`
- calling `_exit` or `_Exit`
- return of last thread from its start routine
- Calling `pthread_exit` from last thread

### Abnormal Termination

- Calling `abort`
- receipt of signal
- response of last thread to cancellation request

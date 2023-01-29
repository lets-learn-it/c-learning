# Coroutines

- It is similar to thread but not exactly.
- **Similar because**: a line of execution, with its own stack, its own local variables, and its own instruction pointer, sharing global variables etc.
- **Not threads because**: On multiprocessor machine, more threads can run parallely but at a time only one coroutine will be running.
- **Coroutine States**: suspended, running, dead.
- When coroutine is created, it is in suspended state & can be put in running state using `resume` function. Once coroutine completed, it goes into dead state.
- coroutine can `yield` itself. It goes into suspended state & can be resumed later. `coroutine.yield()`

## Simple Example

```lua
co = coroutine.create(function (arg1)
      print(arg1)
     end)

print(coroutine.status(co))          -- suspended

coroutine.resume(co, "This is arg")  -- prints This is arg

coroutine.status(co)                 -- dead
```

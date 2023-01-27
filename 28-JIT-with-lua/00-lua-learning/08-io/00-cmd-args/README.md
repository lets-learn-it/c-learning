# Command Args

- lua collects all args in table with name `arg` before running script. script name goes into index 0.

If you are running program like below,

```sh
lua myscript.lua arg1 arg2
```

Then lua will collect arguments

```lua
arg[-1] = "lua"
arg[0] = "myscript.lua"
arg[1] = "arg1"
arg[2] = "arg2"
```
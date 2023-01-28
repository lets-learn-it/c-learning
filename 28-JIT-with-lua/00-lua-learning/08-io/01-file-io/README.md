# File IO

```lua
-- open file
file = io.open("filename", "mode")

-- write to file
file:write("This is random data")

-- seek
file:seek("set", 0)   -- go to start of file

-- read from file
-- file*:read(...string|integer|"L"|"a"|"l"|number)
file:read(*a)         -- read all data

-- close file
file:close()
```

## Modes

- `r`: read only (default)
- `w`: write (create if not exists)
- `a`: append (create if not exists)
- `r+`: read & write to existing file
- `w+`: read & write (create if not exists)
- `a+`: append & read (create if not exists)

There are additional binary modes too. Like `rb`, `wb`, `w+b` etc

# Error Handling

- As Lua is mostly embeded in an application, it cannot simply crash or exist when error happens. Instead, whenever an error occurs, Lua ends the current chunk and returns to applications.

## Basic Error Handling

```lua
n = io.read("*number")

-- check if n is nil or not
if not n then error("Invalid Input") end
```

- Above code raises an error calling `error` function. It is like `throw` in java equivalent.
- Easier alternative to abov code

```lua
-- if first arg of assert is false, error happened
-- second arg is optional. if not present, error msg will be printed
n = assert(io.read("*number"), "someerror")
```

## `pcall`  (protected call)

- better controll over what to do when error occures than `assert`
- `pcall` returns `true` if encapsulated function is successful.
- `pcall (f [, arg1, ···])` Calls the function `f` with the given arguments in **protected mode**. This means that any error inside `f` is not propagated; instead, `pcall` catches the error and returns a status code.
- Its first result is the status code (a boolean), which is `true` if the call succeeds without errors. In such case, `pcall` also returns all results from the call, after this first result. 
- In case of any error, `pcall` returns `false` plus the error object. Note that errors caught by pcall do not call a message handler.

```lua
function somefunction(arg)
  -- generating error
end

status, errorOrResult = pcall(somefunction, arg)

if status then
  print("Success")
else
  print(errorOrResult)
end
```

- `pcall` is like `catch` in java equivalent.

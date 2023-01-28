# Functions

- Functions are first class values in lua. That means functions can be stored in variables, passed as arguments to other functions, and returned as results.
- Lua can call functions written in Lua and in C.

## Syntax

```lua
-- simple function
local function functionName(args)
  return value
end

-- return multiple values
local function functionName(args)
  return value1, value2
end

-- variadic functions
local function functionName(...)
  for key, value in pairs{...} do
    -- do something
  end
end
```

## Functional Programming

```lua
-- functions
local myFunc = function () {
  -- do something
}

-- calling function
myFunc()

-- closures
local outerFunction =function () {
  local someVariable = 0

  return function (){
    -- using someVariable
  } 
}

innerFunc = outerFunction()
```

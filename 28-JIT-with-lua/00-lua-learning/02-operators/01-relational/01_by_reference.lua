--[[
  Lua compares tables, usedata and functions by reference.
]]

local a = {}; a.x = 1; a.y = 0
local b = {}; b.x = 1; b.y = 0
local c = a

print(a == b)  -- false
print(a == c)  -- true

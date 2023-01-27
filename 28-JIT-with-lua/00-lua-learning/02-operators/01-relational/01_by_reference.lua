--[[
  Lua compares tables, usedata and functions by reference.
]]

a = {}; a.x = 1; a.y = 0
b = {}; b.x = 1; b.y = 0
c = a

print(a == b)  -- false
print(a == c)  -- true

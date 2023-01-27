--[[
  and or not

  all logical operators consider false and nil as false
  ]]

print(4 and 5)      -- 5
print(nil and 13)   -- nil
print(false and 13) -- false
print(4 or 5)       -- 4
print(false or 5)   -- 5
print(not 5)        -- false
print(not nil)      -- true

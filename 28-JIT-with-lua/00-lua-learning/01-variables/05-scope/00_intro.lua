
for i = 1, 10, 1 do
  current = i        -- global variable
end

for i = 1, 20, 1 do
  local current = i   -- local variable (scope inside for loop)
end

print(current)        -- 10

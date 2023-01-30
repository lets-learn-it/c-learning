local a = 10

for i = 1, 1, 1 do

  local b = i
  print("[1] a: ", a, ", b: ", b, ", c: ", c)  -- c out of scope

  if b % 2 ~= 0 then
    local c = 1
    print("[2] a: ", a, ", b: ", b, ", c: ", c) -- all in scope
  end

end

print("[3] a: ", a, ", b: ", b, ", c: ", c)     -- b & c out of scope
 
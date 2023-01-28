local function getSum(a, b)
  return a + b
end

print("5 + 2 = ", getSum(5, 2))

-- multiple returns
local function getSumAndMinus(a, b)
  return a + b, a - b
end

local sum, minus = getSumAndMinus(56, 45)

print("Sum: ", sum, " Minus: ", minus)

-- lua dont have named arg support
local function someFunction(arg)
  for key, value in pairs(arg) do
    print(key, " ", value)
  end
end

someFunction{name="Parikshit", age=25}

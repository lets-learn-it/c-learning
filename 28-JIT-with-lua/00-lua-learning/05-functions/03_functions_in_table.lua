local mathlib1 = {}

mathlib1.sum = function (a, b)
  return a + b
end

mathlib1.minus = function (a, b)
  return a - b
end

-- another syntax
local mathlib2 = {
  sum = function (a, b) return a + b end,
  minus = function (a, b) return a - b end
}

-- yet another syntax
local mathlib3 = {}

function mathlib3.sum(a, b)
  return a + b
end

function mathlib3.minus(a, b)
  return a - b
end

-- calling
print(mathlib1.sum(5, 6))
print(mathlib2.sum(5, 6))
print(mathlib3.sum(5, 6))

local doubleIt = function (x)
  return 2 * x
end

print(doubleIt(5))

-- closures

local function outerFunc()
  local i = 0

  return function ()
    i = i + 1
    return i
  end
end

local getNext = outerFunc()

print(getNext())
print(getNext())

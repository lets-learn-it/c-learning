local function getSumMore(...)
  local sum = 0
  
  for key, value in pairs{...} do
    sum = sum + value
  end

  return sum
end


print(getSumMore(1,2,3,4,5,6,7,8,9,10))

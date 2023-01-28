-- array iterator

local function array_iterator(arr)
  local i = 0
  local n = #arr
  return function ()
    i = i + 1
    if i <= n then return arr[i] end
  end
end

local myArray = {12,34,13,75,87,45}

local iter = array_iterator(myArray)

while true do
  local ele = iter()

  if ele == nil then break end

  print(ele)
end


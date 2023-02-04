-- 1 based index

local arr = {1, 56, 84, 77, 51, 213, 845}

print(arr[3])

--insert at end
table.insert(arr, 100)

for key, value in pairs(arr) do
  io.write(value, " ")
end

-- length of array or list
print("\nLenght of arr: ", #arr)

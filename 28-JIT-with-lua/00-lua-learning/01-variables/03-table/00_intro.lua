local myTable = {}
local myIntegerTable = {}

-- add key value in table
myTable["name"] = "Parikshit"
myTable["age"] = 25
myTable[1998] = "My Birth Year"

table.insert(myTable, 1, "lalalala")

-- add values to myIntegerTable
for i = 1, 10, 1 do
  myIntegerTable[i] = i
end

-- number of elements in table
print("Number of elements in myIntegerTable: ", #myIntegerTable)
print("Number of elements in myTable: ", #myTable)  -- getting 0, strange

for key, value in pairs(myTable) do
  print(key .. " " .. value)
end

print("=========================")

-- remove key value from table
myTable["age"] = nil

for key, value in pairs(myTable) do
  print(key .. " " .. value)
end

myTable = {}

-- add key value in table
myTable["name"] = "Parikshit"
myTable["age"] = 25
myTable[1998] = "My Birth Year"

for key, value in pairs(myTable) do
  print(key .. " " .. value)
end

print("=========================")

-- remove key value from table
myTable["age"] = nil

for key, value in pairs(myTable) do
  print(key .. " " .. value)
end
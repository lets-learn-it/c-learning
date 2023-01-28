local file = io.open("demo.txt", "r+")

if file == nil then
  io.stderr:write("Error")
  return
end

print(file:read("*a"))
file:close()

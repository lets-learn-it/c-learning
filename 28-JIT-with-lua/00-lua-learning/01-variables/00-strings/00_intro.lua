-- string variable
local name = "parikshit"
local surname = 'patil'

-- print name & surname
io.write(name, " ", surname, "\n")

-- concatenate strings using .. operator (double dot)
local fullname = name .. " " .. surname
io.write("Fullname: ", fullname, "\n")

-- get length of string
local len = #fullname
io.write("Length of fullname: ", len, "\n")

-- multiline string
local multilinestring = [[This is 
multiline string. 
  This is]]
io.write(multilinestring, "\n")

-- local variables
local localvariable = "name"
io.write(localvariable, "\n")

io.write(string.format("Full Name: %s %s", name, surname))

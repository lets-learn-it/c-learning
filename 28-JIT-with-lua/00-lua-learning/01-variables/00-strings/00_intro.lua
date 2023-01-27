-- string variable
name = "parikshit"
surname = 'patil'

-- print name & surname
io.write(name, " ", surname, "\n")

-- concatenate strings using .. operator (double dot)
fullname = name .. " " .. surname
io.write("Fullname: ", fullname, "\n")

-- get length of string
len = #fullname
io.write("Length of fullname: ", len, "\n")

-- multiline string
multilinestring = [[This is 
multiline string. 
  This is]]
io.write(multilinestring, "\n")

-- local variables
local localvariable = "name"
io.write(localvariable, "\n")

io.write(string.format("Full Name: %s %s", name, surname))

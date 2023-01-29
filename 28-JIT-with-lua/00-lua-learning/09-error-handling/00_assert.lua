-- if first arg of assert is false then error
local file1 = assert(io.open("notexists.txt", "r"))

-- Overiding error msg
local file2 = assert(io.open("notexists.txt", "r"), "Overiding error message")

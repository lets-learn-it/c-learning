local function openFile(filename)
  local file, err = io.open(filename, "r")

  if file then
    return file, "dummyString"
  else
    error(err, 1)     -- error at line 7
    -- error(err, 2)  -- error at line 12
  end
end


local status, errorOfResult = pcall(openFile, "filenotexists.txt")
-- local status, errorOfResult = pcall(openFile, "fileexists.txt")

if status then
  print("Success")
  errorOfResult:close()
else
  print("Failure")
  print(errorOfResult)
end


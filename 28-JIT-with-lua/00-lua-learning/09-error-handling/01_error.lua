local function openFile()
  local file, err = io.open("notexists.txt", "r")

  if file then
    return file
  else
    error(err, 1)     -- error at line 7
    -- error(err, 2)  -- error at line 12
  end
end


local file = openFile()

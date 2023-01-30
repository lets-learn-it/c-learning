-- for i = start, end, step do .... end

for i = 1, 10, 1 do
  print(i)
end

print("==========================")

-- looping in table
local months ={"चैत्र", "वैशाख", "ज्येष्ठ", "आषाढ", "श्रावण","भाद्रपद", "आश्विन", "कार्तिक","मार्गशीर्ष", "पौष", "माघ", "फाल्गुन"}
for key, value in pairs(months) do
  print(string.format("%2d", key), " : ", value)
end

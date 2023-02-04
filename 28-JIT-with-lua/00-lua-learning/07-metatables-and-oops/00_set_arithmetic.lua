local Set = {}

-- nil metatables
print("metatable of Set: ", getmetatable(Set))

-- create metatable
Set.mt = {}

-- methods for Set
function Set.new(t)
  local set = {}
  setmetatable(set, Set.mt)
  for _, l in ipairs(t) do
    set[l] = true
  end
  return set
end

function Set.union (a,b)
  local res = Set.new{}
  for k in pairs(a) do res[k] = true end
  for k in pairs(b) do res[k] = true end
  return res
end

function Set.intersection (a,b)
  local res = Set.new{}
  for k in pairs(a) do
    res[k] = b[k]
  end
  return res
end

function Set.tostring (set)
  local s = "{"
  local sep = ""
  for e in pairs(set) do
    s = s .. sep .. e
    sep = ", "
  end
  return s .. "}"
end

-- register methods in metatable
Set.mt.__add = Set.union
Set.mt.__mul = Set.intersection
Set.mt.__tostring = Set.tostring


-- create sets
local set1 = Set.new{1,2,3,4,5,6}
local set2 = Set.new{4,5,6,7,8,9}

print(set1 + set2)
print(set1 * set2)

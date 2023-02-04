# Metatables and OOPS

- Whenever Lua tries to add two tables, it checks whether either of them has a metatable and whether that metatable has an `__add` field. If Lua finds this field, it calls the corresponding value (the so-called *metamethod*, which should be a function) to compute the sum.
- Each table in Lua may have its own metatable.
- `userdata` also can have metatables.
- Lua always create new tables without metatables
- metatable can be set to table `t1` using `setmetatable(t, t1)` function.

## Common Metamethods

[http://lua-users.org/wiki/MetatableEvents](http://lua-users.org/wiki/MetatableEvents)

- `__tostring`:
- `__len`: When table length is requested using length operator `#`
- `__unm`: unary minus
- `__add`: + operator
- `__sub`: - operator
- `__mul`: * operator
- `__div`: / operator
- `__idiv`: floor operator //
- `__mod`: % operator
- `__pow`: ^ operator
- `__concat`: .. operator
- `__eq`: == operator
- `__lt`: < operator
- `__le`: <= operator


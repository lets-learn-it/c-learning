# Variables

- By default, all variables are global unless specified explicitely.
- if variable is not defined, then it is considered as `nil`
- There are eight basic types in Lua: `nil`, `boolean`, `number`, `string`, `function`, `userdata`, `thread`, & `table`.
- Lua can call functions in Lua & C. Both are represented by type `function`
- Type `userdata` is provided to allow arbitraty C data to be stored in Lua variables. It represent block of raw memory. `userdata` can't be created or modified in Lua, only through C API.
- Type `thread` represent independent threads of execution & it is used to implement coroutines. (Not OS threads).
- Type `table` implements associative arrays (dictionaries in python). These tables can be *heterogeneous*.


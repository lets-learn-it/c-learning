# restrict

- When we use `restrict` with a pointer ptr, it tells the compiler that ptr is the only way to access the object pointed by it, in other words, there’s no other pointer pointing to the same object.
- If a programmer uses restrict keyword and violate the above condition, the result is undefined behavior.
- restrict is not supported by C++. It is a C only keyword.
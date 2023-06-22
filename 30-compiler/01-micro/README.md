# micro

- `integer` is only datatype
- All identifiers are no longer than 32 characters
- Literals are strings of digits
- comments begin with `--` and end at the end of current line.
- Statement types are `ID := Expression;`. Expression is infix expression constructed from identifiers, literals and operators. Parenthesis are allowed.
- IO: `read(List of IDs)` and `write(List of Expressions)`
- `begin`, `end`, `read` and `write` are reserved words.
- Each statement is terminated by `;`. The body of program is delimited by `begin` and `end`

## References

[00] Crafting a Compiler with C - By Charles N. Fischer & Richard J. LeBlanc, Jr.

# Read shared mapping

we will map file in shared mode. reader process will read continously until end of file. you can add or remove data from file.

- If new data appended then that will be read
- if data removed which is not read yet then that data wont be printed.
- if data removed which is read already, it will mess offset.
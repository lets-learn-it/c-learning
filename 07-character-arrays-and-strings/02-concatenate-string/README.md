# Concatenate String

## strcat

```c
char * strcat ( char * destination, const char * source );
```

- Appends a copy of the `source` string to the `destination` string & returns `destination`.
- terminating null `\0` character will be overwritten by first character from `source`
- `destination` and `source` shall not overlap.
- `destination` should be sufficiently long.

## strncat

```c
char * strncat ( char * destination, const char * source, size_t num );
```

- Appends the first `num` characters of `source` to `destination`, plus a terminating null-character `\0` & returns `destination`
- If the length of the C string in `source` is less than `num`, **only the content up to the terminating null-character is copied**.


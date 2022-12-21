# Copying string

## memcpy

```c
void * memcpy ( void * destination, const void * source, size_t num );
```

- `num` bytes will be copied from `source` to `destination` & returns `destination`
- `source` and `destination` buffers should not overlap. for overlapping memory block, use `memmove()`

## memmove

```c
void * memmove ( void * destination, const void * source, size_t num );
```

- `num` bytes will be copied from `source` to `destination` & returns `destination`
- Copying takes place as if an **intermediate buffer** were used, allowing the `destination` and `source` to overlap.

## strcpy

```c
char * strcpy ( char * destination, const char * source );
```

- copies c string pointed by `source` to `destination` including terminating null `\0` character and returns `destination`
- This function can create issues when source is longer than destination.

## strncpy

```c
char * strncpy ( char * destination, const char * source, size_t num );
```

- copies c string pointed by `source` to `destination` including terminating null `\0` character and returns `destination`
- copies maximum of `num` characters. and if `num` is larger than string lenth then `destination` will be padded with zeros until total `num` chars are written.
- safer version of `strcpy()`.
- no null `\0` character will be appended if `source` is longer than `num`.
- `destination` and `source` shall not overlap.

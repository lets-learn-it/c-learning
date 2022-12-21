# Compare Strings

## memcmp

```c
int memcmp ( const void * ptr1, const void * ptr2, size_t num );
```

- Compares the first `num` bytes of the block of memory pointed by `ptr1` to the first num bytes pointed by `ptr2`
- returns `0` if they all match
- return `<0` if first byte that does not match has lower value (unsigned char) in `ptr1` than `ptr2`
- return `>0` if first byte that does not match has greater value (unsigned char) in `ptr1` than `ptr2`
- unlike `strcmp`, the function does **not stop comparing** after finding a null character `\0`.

## strcmp

```c
int strcmp ( const char * str1, const char * str2 );
```

- compares 2 strings until null character `\0` reached.
- returns `0` if they all match
- return `<0` if first byte that does not match has lower value (unsigned char) in `ptr1` than `ptr2`
- return `>0` if first byte that does not match has greater value (unsigned char) in `ptr1` than `ptr2`

## strcoll


## strncmp

```c
int strncmp ( const char * str1, const char * str2, size_t num );
```

- same as `strcmp` except it compares until terminating null character or `num` characters are matched whichever happens first.

## strxfrm


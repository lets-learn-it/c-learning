# Search in strings

## memchr

```c
void * memchr ( const void * ptr, int value, size_t num );
```

- Searches within the first `num` bytes of the block of memory pointed by `ptr` for the first occurrence of `value` (interpreted as an `unsigned char`), and returns a pointer to it.
- if not found, returns `NULL`

## strchr

```c
char * strchr ( const char * str, int character );
```

- Returns a pointer to the first occurrence of `character` in the C string `str`.
- The terminating null-character is considered part of the C string. Therefore, it can also be located in order to retrieve a pointer to the end of a string.

## strcspn

```c
size_t strcspn ( const char * str1, const char * str2 );
```

- Scans `str1` for the first occurrence of any of the characters that are part of `str2`, returning the number of characters of `str1` read before this first occurrence.
- The search includes the terminating null-characters. Therefore, the function will return the length of `str1` if none of the characters of `str2` are found in `str1`.

## strpbrk

```c
char * strpbrk ( const char * str1, const char * str2 );
```

- Returns a pointer to the first occurrence in `str1` of any of the characters that are part of `str2`, or a null pointer if there are no matches
- The search does not include the terminating null-characters of either strings, but ends there.

## strrchr

```c
char * strrchr ( const char * str, int character );
```

- Returns a pointer to the last occurrence of character in the C string `str`.
- The terminating null-character is considered part of the C string. Therefore, it can also be located to retrieve a pointer to the end of a string.

## strspn

```c
size_t strspn ( const char * str1, const char * str2 );
```

- Returns the length of the initial portion of `str1` which consists only of characters that are part of `str2`.
- The search does not include the terminating null-characters of either strings, but ends there.

## strstr (IMP)

```c
char * strstr ( const char * str1, const char * str2 );
```

- Returns a pointer to the first occurrence of `str2` in `str1`, or a `null` pointer if `str2` is not part of `str1`.
- The matching process does not include the terminating null-characters, but it stops there.

## strtok (IMP)

```c
char * strtok ( char * str, const char * delimiters );
```

- split string into multiple token using specified `delimiters`. those tokens can be get using sequence of calls to this same function. only change is pass `NULL` inplace of `str`.
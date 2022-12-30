# Http 1.1

This project will be better copy of [07-character-arrays-and-strings/04-search-in-string/08_http_PROJECT.c](../../07-character-arrays-and-strings/04-search-in-string/08_http_PROJECT.c)

## Vectored IO / Scatter-Gather IO

Method of input and output by which a **single procedure call sequentially reads data from multiple buffers and writes it to a single data stream**, or **reads data from a data stream and writes it to multiple buffers**, as defined in a vector of buffers.

### Uses

- Atomicity
- Concatenating Output
- Efficiency
- Splitting Input

**Sys Calls Support Vectored IO**

- `readv`
- `writev`
- `sendfile`

## References

[[01] https://en.wikipedia.org/wiki/Vectored_I/O](https://en.wikipedia.org/wiki/Vectored_I/O)

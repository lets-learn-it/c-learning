# C Files

## Functions

- **`fopen`**: Opens a file and returns a pointer to a `FILE` stream.
- **`fclose`**: Closes a `FILE` stream.
- **`fread`**: Reads data from a `FILE` stream.
- **`fwrite`**: Writes data to a `FILE` stream.
- **`fprintf`**: Formats and writes data to a `FILE` stream.
- **`fscanf`**: Reads formatted data from a `FILE` stream.
- **`fgetc`**: Reads a single character from a `FILE` stream.
- **`fputc`**: Writes a single character to a `FILE` stream.
- **`fgets`**: Reads a line of text from a `FILE` stream.
- **`fputs`**: Writes a line of text to a `FILE` stream.
- **`feof`**: Tests for the end-of-file condition on a `FILE` stream.
- **`rewind`**: Sets the position indicator for a `FILE` stream to the beginning of the file.
- **`fseek`**: Sets the position indicator for a `FILE` stream to a specific location in the file.
- **`ftell`**: Tell position of position indicator.
- **`freopen`**: Redirecting standard input and output to & from
- **`tmpfile`**: Creates a temporary `FILE` stream that is automatically deleted when the stream is closed.
  ```c
  FILE *fp = tmpfile();
  // do read write etc
  fclose(fp);  // file deleted
  ```



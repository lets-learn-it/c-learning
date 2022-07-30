# Constants, Variables and data types

## Constants

**Fixed values that do not change during the execution of program**

#### Integer constant

- sequence of digits
- decimal integer (123), octal integer (0123), hexadecimal integer (0X123, 0x123)
- 

#### Real Constant

- expressed in exponential notation ( 215.65 == 2.1565e2)
- aeb or aEb where a is mantissa and b is exponent
- 

#### Single character constant

- enclosed in signel quote ('a', 'P', '6')
- '5' is not equal to 5

```c
printf("%d", 'a');  // 97 
printf("%c", 97);   // 'a'
```

#### String constant

- sequence of characters enclosed in double quote ("lets-learn-it")
- "X" not equivalent to 'X'
- Single character string dont have integer value.

#### Backslash Character constant

| Constant |     Meaning     |
|:--------:|:---------------:|
|    \a    |  audible alert  |
|    \b    |    backspace    |
|    \f    |    form feed    |
|    \n    |     new line    |
|    \r    | carriage return |
|    \t    |  horizontal tab |
|    \v    |   vertical tab  |
|    \'    |   single quote  |
|    \"    |   double quote  |
|    \?    |  question mark  |
|    \\    |    backslash    |
|    \0    |       null      |
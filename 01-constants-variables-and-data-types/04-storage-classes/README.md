# Storage Classes

| **Storage Class**   | **Declaration Location** | **Scope (Visibility)**                                         | **Lifetime (Alive)**           | **Notes**                                                  |
|---------------------|--------------------------|----------------------------------------------------------------|--------------------------------|------------------------------------------------------------|
| **auto**            | Inside function/block    | Within function/block                                          | Until function/block completes | by default, inside function/block                          |
| **register**        | Inside function/block    | Within function/block                                          | Until function/block completes | compiler will decide to put it in register or not.         |
| **extern**          | Outside all functions    | Entire file + other files where variable is declared as extern | Until program terminates       | compiler has to ignore its existence, linker will find it. |
| **static (local)**  | Inside function/block    | Within the function/block                                      | Until program terminates       |                                                            |
| **static (global)** | Outside all functions    | Entire file in which it is declared                            | Until program terminates       |                                                            |
# Tom Asserts

This is simply some macro asserts which are compatible with C++.

## How to use tom's asserts
Put the `tomsasserts.hpp` header file in the directory of your src code. Include in your C++ code with `#include "tomsasserts.hpp"`

Then within main you can use.

```
ASSERT(True,"This won't fail");
ASSERT(False,"This will always fail.")
```

## What do the asserts do.
They test the truth of an expression `ASSSERT`, or the equality of an array `ASSERT_ARRAYS_EQUAL`. If this fails then the fail reason will be printed to the command line along side some useful information like the line of the assert and the file the assert is in. Then the assert return -1. 

This could be used with in functions or the main of a program for different results.
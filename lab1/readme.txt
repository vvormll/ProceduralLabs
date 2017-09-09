Compile using:
gcc --std=c89 -Wall -Werror file.c

Tested with clang:
Apple LLVM version 8.1.0 (clang-802.0.42)
Target: x86_64-apple-darwin16.7.0
Thread model: posix

and with gcc:
gcc version 7.2.0 (Homebrew GCC 7.2.0)
Target: x86_64-apple-darwin16.7.0
Thread model: posix

To see usage message run compiled binary with no arguments.

Usage examples:

$ ./tempconv 0
0.00 C:
32.00 F
273.15 K

0.00 F:
-17.78 C
255.37 K

0.00 K:
-273.15 C
-459.67 F

$ ./tempconv -300 C
Error: specified temperature is lower than absolute zero in C

$ ./tempconv 36 C
96.80 F
309.15 K
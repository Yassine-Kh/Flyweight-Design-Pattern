# Requirements

* g++ v5.4 or newer
* Make


# Compilation

The code can be compiled with the provided makefile using the standard `make`
command.

If compiling the code manually, or integrating into a larger program, include
the following flags:

```
FLAGS=-std=c++14 -Wall 
```

# Context
This project's objective is to point out the advantages of the flyweight design pattern. 
In the main.cpp you can see a clear comparison between an implementation using the flyweight 
design pattern and one without this design pattern. In terms of physical memory, the implementation
with flyweight is clearly better. 


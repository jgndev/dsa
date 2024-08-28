# DSA C++ Template

This repo is for quickly setting up a C++ project that uses [CMake](https://cmake.org) and [GoogleTest](https://google.github.io/googletest/).  

It is intended for practice with the C++ language while doing Data Structures and  
Algorithms problems like those found on [leetcode.com](https://leetcode.com)

## Instructions

1 - Clone the repo to a directory name of your choice.

```bash
git clone https://github.com/jgndev/dsa_cpp_templ example_problem
```

2 - Run the project init script `project-init.sh`

```bash
./project-init.sh
```

This creates a `build` directory and links `compile-commands.json` to the top level which
helps LSPs work in editors like [neovim](https://neovim.io).

## Building

1 - Change directory into `build`

2 - Run `make`


## Running tests

1 - Add your tests to `tests/test_solution.cpp`

2 - Change directory to `build`

3 - Run `make` to compile `test_solution`

4 - Run `./test_solution` to run the tests.

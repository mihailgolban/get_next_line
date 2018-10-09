# get_next_line

My implementation of [get_next_line](get_next_line.en.pdf).

### Goals
Write a function that returns a line ending with a newline, read from a file descriptor.

## Installation

### Requirements
* GNU make
* GNU C Compiler (GCC)

## Usage
```
git clone https://github.com/mihailgolban/get_next_line.git
clang -I libft/includes -o get_next_line.o -c get_next_line.c
clang -I libft/includes -o main.o -c main.c
clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
```
## License
[MIT](https://choosealicense.com/licenses/mit/)

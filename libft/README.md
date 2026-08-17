*This project has been created as part of the 42 curriculum by llinda.*

# Libft

## Description

Libft is my own implementation of a C standard library, built from scratch as the
first project of the 42 core curriculum. Its goal is to make me understand how the
classic `libc` functions actually work under the hood — memory handling, string
manipulation, character classification — by rewriting them myself instead of just
using them.

Beyond the `libc` clones, the library also adds a set of extra helper functions
(string joining/splitting/trimming, number conversion, iteration helpers) and a
small singly linked list toolkit built around a generic `t_list` node. Together
they form a personal toolbox that gets reused in every later 42 project.

The library is compiled as a static archive, `libft.a`, using the `ar` command.

## Instructions

### Compilation

```sh
make        # builds libft.a
make clean  # removes the .o files
make fclean # removes .o files and libft.a
make re     # fclean + all
```

The `Makefile` compiles every `ft_*.c` source file with `cc` and the flags
`-Wall -Wextra -Werror`, then archives the resulting object files into
`libft.a` with `ar rcs`.

### Usage in another project

1. Copy this repository (or add it as a subfolder, e.g. `libft/`) into your project.
2. Build the archive: `make -C libft`.
3. Include the header and link the archive when compiling your project:

```sh
cc -Wall -Wextra -Werror your_program.c -I libft -L libft -lft -o your_program
```

```c
#include "libft.h"
```

### Testing against the system libc

Some reimplemented functions (`strlcpy`, `strlcat`, `bzero`) are not part of
glibc by default. To compare behavior against the real BSD implementations on
a glibc system, include `<bsd/string.h>` and compile with `-lbsd`:

```c
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
```

## Detailed description of the library

All prototypes are declared in [libft.h](libft.h). The `t_list` structure used by
the linked-list part is also defined there:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

### Part 1 — Libc functions

Reimplementations of standard `libc` functions, prefixed with `ft_`, matching the
original prototypes and behavior:

| Function | Description |
|---|---|
| `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` | Character classification |
| `ft_strlen` | String length |
| `ft_memset`, `ft_bzero` | Memory initialization |
| `ft_memcpy`, `ft_memmove` | Memory copying |
| `ft_strlcpy`, `ft_strlcat` | Safe string copy/concatenation |
| `ft_toupper`, `ft_tolower` | Case conversion |
| `ft_strchr`, `ft_strrchr` | Character search in a string |
| `ft_strncmp`, `ft_memcmp` | Bounded comparison |
| `ft_memchr` | Byte search in a memory area |
| `ft_strnstr` | Bounded substring search |
| `ft_atoi` | String to integer conversion |
| `ft_calloc`, `ft_strdup` | Allocation-based functions (use `malloc`) |

### Part 2 — Additional functions

Extra functions, not part of `libc`, useful for string manipulation and I/O:

| Function | Description |
|---|---|
| `ft_substr` | Extracts a substring from a string |
| `ft_strjoin` | Concatenates two strings into a newly allocated one |
| `ft_strtrim` | Trims a set of characters from both ends of a string |
| `ft_split` | Splits a string into an array of strings on a delimiter |
| `ft_itoa` | Converts an integer to a newly allocated string |
| `ft_strmapi` | Applies a function to each character of a string, building a new string |
| `ft_striteri` | Applies a function to each character of a string in place |
| `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | Output helpers writing to a given file descriptor |

### Part 3 — Linked list

A minimal singly linked list toolkit built around the generic `t_list` node:

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node |
| `ft_lstadd_front` | Adds a node at the beginning of the list |
| `ft_lstadd_back` | Adds a node at the end of the list |
| `ft_lstsize` | Counts the nodes of a list |
| `ft_lstlast` | Returns the last node of a list |
| `ft_lstdelone` | Frees a single node and its content |
| `ft_lstclear` | Frees a node and all its successors |
| `ft_lstiter` | Applies a function to each node's content |
| `ft_lstmap` | Builds a new list by applying a function to each node's content |

## Resources

- [man7.org Linux man-pages](https://man7.org/linux/man-pages/) — reference for the exact behavior of the original `libc` functions (`strlen`, `memcpy`, `strlcpy`, `atoi`, etc.)
- [FreeBSD man pages](https://man.freebsd.org/) — reference for BSD-only functions such as `strlcpy`/`strlcat`, absent from glibc
- [42 Norm](https://github.com/42School/norminette) — coding style used to check this project
- [GeeksforGeeks](https://www.geeksforgeeks.org/) — explanations and examples for C concepts and algorithms
- [W3Schools](https://www.w3schools.com/) — quick syntax reference for C
- [Wikipedia — Make (software)](https://en.wikipedia.org/wiki/Make_(software)) — background on the `make` build tool used by the Makefile

### AI usage disclosure

An AI assistant was used only for supporting tasks:

- Drafting and formatting this `README.md` file (Description, Instructions,
  Resources sections and the function tables) once the library implementation
  was already finished.
- Reviewing the project's Makefile (rule names, compilation flags) against the subject requirements.
- Explaining complicated C concepts (pointers, memory allocation, etc.) using
  Gemini's "Learn" mode, in a Q&A capacity rather than for code generation.

The C source files (`ft_*.c`) implementing the library functions were written by
myself without AI-generated code, in line with the project's learning goals.

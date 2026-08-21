*This project has been created as part of the 42 curriculum by llinda.*

---

## Description

`ft_printf` is a custom implementation of the C standard library function `printf()`.  
The goal of this project is to learn about variadic functions in C (`stdarg.h`) by
recreating one of the most widely used output functions.

The function writes formatted output to the standard output (file descriptor 1) and
returns the total number of characters printed.

### Supported Conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer in hexadecimal format (e.g. `0x7fff`) |
| `%d` | Prints a signed decimal number |
| `%i` | Prints a signed integer (base 10) |
| `%u` | Prints an unsigned decimal number |
| `%x` | Prints an unsigned hexadecimal number (lowercase) |
| `%X` | Prints an unsigned hexadecimal number (uppercase) |
| `%%` | Prints a literal percent sign |

---

## Instructions

### Compilation

```sh
make
```

This builds the static library `libftprintf.a` at the root of the repository.
The Makefile also compiles the `libft` dependency located in the `libft/` subdirectory.

### Makefile Rules

| Rule | Action |
|------|--------|
| `make` / `make all` | Builds `libftprintf.a` |
| `make clean` | Removes object files (`.o`) and precompiled headers (`.gch`) |
| `make fclean` | Runs `clean` and removes `libftprintf.a` |
| `make re` | Runs `fclean` followed by `all` |

### Usage

Include `ft_printf.h` and link with the library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! The answer is %d.\n", "world", 42);
    return (0);
}
```

```sh
cc main.c -L. -lftprintf
./a.out
```

### Testing

A test program (`main.c`) is provided for development purposes. It compares the output
and return value of `ft_printf` against the system's `printf()` for each supported
conversion. To compile and run the tests:

```sh
cc -g main.c -L. -lftprintf -o test_printf
./test_printf
```

---

## Resources

- `man 3 printf` — official documentation of the `printf()` function family
- `man 3 stdarg` — documentation of the `stdarg.h` variadic argument macros
- [Variadic functions in C](https://en.cppreference.com/w/c/variadic) — cppreference article on variadic functions
- [42 Norm](https://github.com/42School/norminette) — the coding standard enforced on this project

### AI Usage

AI tools were used during the development of this project in the following ways:
- As a teaching assistant to explain concepts such as include discipline (IWYU),
  Makefile dependency management, and the purpose of the `va_end` macro.
- To review the codebase for correctness, identify bugs, and verify compliance with
  the project subject.
- No AI-generated code was directly copied into the project; all code was written
  and understood by the author.

---

## Algorithm & Data Structure

### Architecture

The project follows a layered design with a clear separation of concerns:

```
ft_printf(const char *str, ...)
  └── ft_vprintf(str, args)
       └── while (*str)
            ├── regular char → write & count
            └── '%' → handle_conversion(specifier, args)
                 ├── %c → ft_putchar_fd
                 ├── %s → ft_print_str
                 ├── %p → ft_print_ptr
                 ├── %d/%i → ft_print_nbr
                 ├── %u → ft_print_unsigned
                 ├── %x → ft_print_hexlower
                 ├── %X → ft_print_hexupper
                 └── %% → ft_putchar_fd('%')
```

### Parsing Strategy

The format string is parsed linearly in a single pass using a `while` loop inside
`ft_vprintf`. Each character is examined: plain characters are written directly,
and the `%` character triggers a lookup in `handle_conversion` which dispatches to
the appropriate printer function via a chain of `if/else if` conditions.

This approach was chosen for its simplicity and clarity — each conversion specifier
maps to exactly one handler function, making the code easy to extend and debug.

No buffer management is implemented, as the original `printf()` buffering is not
required by the subject. Each character or digit is written immediately via the
`write()` system call.

### Number Printing

All numeric conversions use **recursive division**:

- The number is successively divided by the base (10 for decimal, 16 for hex).
- Each recursive call handles the higher-order digits, then the current digit is
  printed via `write()`.
- This guarantees that digits are printed from most significant to least significant
  without needing to store them in a temporary buffer or reverse a string.

#### Handling `INT_MIN`

For signed conversions (`%d`, `%i`), the integer is cast to `long` before negating,
preventing undefined behavior when the input is `INT_MIN` (`-2147483648`). The sign is
written separately before the recursive digit printing begins.

### Pointer Printing

The `%p` conversion casts the `void *` argument to `unsigned long long` to safely
accommodate 64-bit pointer values. The `0x` prefix is printed at the deepest level
of the recursion (the most significant digit), followed by the hexadecimal digits
in descending order as the stack unwinds. A null pointer is handled as a special
case and prints `(nil)`.

### Return Value

Every printer function returns the number of characters written. These values are
accumulated in a counter in `ft_vprintf` and returned as the final result of
`ft_printf`, matching the behavior of the original `printf()`.

### Data Structures

This project uses **no heap allocations** and **no custom data structures**. All
data is passed by value or through the variadic argument list. The only external
dependency is the `libft` library, which provides helper functions like `ft_strlen`
and `ft_putchar_fd`.

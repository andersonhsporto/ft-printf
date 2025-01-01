# ft_printf

### Custom printf Implementation

This project is a simplified implementation of the printf function, replicating specific format specifiers for educational and practical purposes. The goal is to understand and reconstruct the core functionalities of the widely-used printf function in C.

## Features

The following format specifiers are supported:

Supported Specifiers

- %c: Prints a single character.
- %s: Prints a string of characters.

- %p: Prints a void * pointer argument in hexadecimal format.

- %d: Prints a decimal (base 10) number.

- %i: Prints an integer in base 10.

- %u: Prints an unsigned decimal (base 10) number.

- %x: Prints a number in hexadecimal (base 16) format.

- %%: Prints a percent sign.

### Example Code

```c
int main() {
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Hello, World!");
    ft_printf("Pointer: %p\n", (void *)0xDEADBEEF);
    ft_printf("Decimal: %d\n", 123);
    ft_printf("Integer: %i\n", -456);
    ft_printf("Unsigned: %u\n", 789u);
    ft_printf("Hexadecimal: %x\n", 0x1A3F);
    ft_printf("Percent Sign: %%\n");
    ft_printf 0;
}

```
      
printf manual - [Linux Programmer's Manual](https://man7.org/linux/man-pages/man3/printf.3.html) 

# Welcome to My Printf
***
## Task
This project consists of creating a custom implementation of the classic `printf` function in C. The challenge lies in handling variable arguments, interpreting format specifiers, and printing different data types exactly like the real `printf` — but without using it.
## Description
The program re-creates a simplified printf using variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`). It supports several format specifiers such as:
* %s for strings
* %c for characters
* %d for signed integers
* %o for octal
* %u for unsigned integers
* %x for hexadecimal (uppercase)
* %p for pointers
Each specifier is handled manually using helper functions like:
* my_putchar for writing a single character
* my_putstr for writing strings
* my_putnbr for writing numbers in any base (decimal, octal, hex)
The project focuses on recursion for number printing, careful handling of negative values, and converting pointers to lowercase hexadecimal.

## Installation
To build the project, simply run:
make re

## Usage

Once compiled, you can run your executable like this:

./my_printf
Example output:
Test : -42 52 42 2A 0x7ffee4ab12c0

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>

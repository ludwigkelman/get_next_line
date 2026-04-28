*This project was created as part of the 42 curriculum by fliraud-.*

# Get Next Line

## 📝 Description
The **Get Next Line** project is a fundamental task in the 42 curriculum that challenges students to create a function capable of reading a line from a file descriptor. While it may sound simple, the implementation requires a deep understanding of memory management, the use of static variables, and efficient buffer handling.

The goal is to provide a reliable tool that can be integrated into future projects (like `fdf` or `minishell`) to parse files or read user input line by line, regardless of the `BUFFER_SIZE` defined at compilation.

## 🛠️ Instructions

### Compilation
The project is designed to be compiled with the `-D BUFFER_SIZE=n` flag. This flag defines the size of the buffer used in each `read()` call.

To compile the mandatory part:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c -o gnl
```

To compile the bonus part (multiple file descriptors):
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

### Execution
To test the function, you can include the header and call it in a loop until it returns `NULL`. 
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 🧠 Algorithm Justification
The selected algorithm focuses on a **Buffer-and-Remainder** strategy. 

1. **Read Loop**: The function enters a loop where it reads `BUFFER_SIZE` bytes from the file descriptor and joins them with any leftover text from the previous call (`static variable`). This loop continues until a newline character (`\n`) is found or the end of the file is reached.
2. **Dynamic Concatenation**: By using `ft_strjoin` and a static variable, we ensure that no data is lost between consecutive calls to `get_next_line`.
3. **Extraction**: Once a newline or EOF is detected, the algorithm splits the accumulated string. One part becomes the line to be returned (including the newline), and the other part (the remainder) is stored back in the static variable for the next call.
4. **Memory Safety**: The algorithm is designed to handle memory allocation failures at any stage. If a `malloc` fails, all currently allocated buffers are freed, the static variable is set to `NULL`, and the function returns `NULL` to prevent leaks or undefined behavior.

## 🌟 Bonus Features
The bonus implementation supports **multiple file descriptors simultaneously**. By replacing the single static pointer with an array of pointers (`static char *remaining[FD_MAX]`), the function can track the reading state of various files independently. This allows a user to read one line from `fd 3`, then one from `fd 4`, and return to `fd 3` without losing the current position or data.

## 📚 Resources
- **Documentation**: [The C `read` function (man 2)](https://man7.org/linux/man-pages/man2/read.2.html).
- **Articles**: Understanding Static Variables in C.
- **Tutorials**: 42 Project-specific guides on memory management and pointers.

### AI Usage Disclosure
Artificial Intelligence (AI) was utilized in the development of this project for the following specific tasks:
- **Logic Refinement**: Assistance in defining edge cases (e.g., simulated malloc failures).
- **Documentation**: Assistance in explaining the subject and core elements of C programming and memory handling.
- **Project Documentation**: Generating and formatting this `README.md` to ensure clarity and adherence to the 42 Norm.
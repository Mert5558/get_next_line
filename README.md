# 📄 get_next_line

get_next_line is a function that reads a file line by line.  
This project is part of the 42 curriculum and focuses on file descriptors, memory management, and static variables in C.

---

## 📖 About the Project

The goal of this project is to implement a function that returns a line read from a file descriptor each time it is called.

This project helps develop a deeper understanding of:

- File descriptors
- Static variables
- Memory allocation and management
- Buffer handling

The function reads from a file descriptor until it encounters a newline or reaches the end of the file.

---

## ⚙️ Function Prototype

```c
char *get_next_line(int fd);
```

The function returns:

- The next line from the file descriptor
- `NULL` if there is nothing left to read or an error occurs

---

## ✨ Bonus

The bonus implementation adds support for:

- Handling **multiple file descriptors at the same time**
- Independent buffers for each file descriptor

---

## 📦 Installation

Clone the repository:

```bash
git clone https://github.com/Mert5558/get_next_line.git
cd get_next_line
```

Compile with your program:

```bash
cc main.c get_next_line.c get_next_line_utils.c
```

For the bonus version:

```bash
cc main.c get_next_line_bonus.c get_next_line_utils_bonus.c
```

---

## 📁 Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int fd = open("file.txt", O_RDONLY);
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

---

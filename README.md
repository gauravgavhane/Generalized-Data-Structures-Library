
# Generalized Data Structures Library (GDSL)

This project provides a comprehensive library for various generalized data structures implemented in C++.
The library is designed to offer flexibility by utilizing templates, allowing you to work with different data types.

## Features

- **Singly Linear Linked List**
  - Insert elements at the beginning, end, or specific positions.
  - Delete elements from the beginning, end, or specific positions.
  - Display all elements and count nodes.

- **Doubly Linear Linked List**
  - Bi-directional linked list with insert, delete, display, and count operations.

- **Singly Circular Linked List**
  - Circular linked list implementation with support for insert, delete, display, and count operations.

- **Doubly Circular Linked List**
  - Bi-directional circular linked list with robust manipulation methods.

- **Stack**
  - Last In First Out (LIFO) implementation with push, pop, display, and count functionalities.

- **Queue**
  - First In First Out (FIFO) implementation with enqueue, dequeue, display, and count functionalities.

## Installation

Clone the repository and include the `GDSL.cpp` file in your C++ project.

```bash
git clone https://github.com/your-username/GDSL.git
```

## Usage

Include the `GDSL.cpp` file and create objects of the required data structure in your main function. Here's an example of using a Singly Linear Linked List:

```cpp
#include "GDSL.cpp"

int main() {
    SinglyLL<int> list;
    list.InsertFirst(10);
    list.InsertLast(20);
    list.Display();
    return 0;
}
```

## License

This project is licensed under the MIT License. See the LICENSE file for details.

---

Contributions and suggestions are welcome. Feel free to fork and submit pull requests!

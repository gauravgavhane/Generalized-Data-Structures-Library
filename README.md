# Generalized Data Structures Library (GDSL)

The Generalized Data Structures Library (GDSL) is a comprehensive C++ library designed to provide flexible and efficient implementations of various data structures, search algorithms, and sorting algorithms. The library is written using templates, enabling it to work seamlessly with different data types.

---

## Features

### 1. Data Structures
- **Singly Linear Linked List**
  - Basic operations: Insert, Delete, Display, and Count.
  - **Aggregate Functions**:
    - Sum of elements, count of even/odd elements.
    - Frequency and search of specific elements.
    - Sum of digits, sum of factors, perfect number check.
    - Find first/last occurrence and middle element.
- **Doubly Linear Linked List**
  - Basic operations: Insert, Delete, Display, and Count.
- **Singly Circular Linked List**
  - Basic operations: Insert, Delete, Display, and Count.
  - **Aggregate Functions**:
    - Sum of elements, count of even/odd elements.
    - Frequency and search of specific elements.
    - Sum of digits, sum of factors, perfect number check.
    - Find first/last occurrence and middle element.
- **Doubly Circular Linked List**
  - Basic operations: Insert, Delete, Display, and Count.
- **Stack**
  - Basic operations: Push, Pop, Display, and Count.
    - **Aggregate Functions**:
    - Sum of elements, count of even/odd elements.
    - Frequency and search of specific elements.
    - Sum of digits, sum of factors, perfect number check.
    - Find first/last occurrence and middle element.
- **Queue**
  - Basic operations: Enqueue, Dequeue, Display, and Count.
  - **Aggregate Functions**:
    - Sum of elements, count of even/odd elements.
    - Frequency and search of specific elements.
    - Sum of digits, sum of factors, perfect number check.
    - Find first/last occurrence and middle element.

### 2. Search Algorithms
- **Linear Search**
- **Bi-Directional Search**
- **Binary Search**

### 3. Sort Algorithms
- **Bubble Sort**
- **Selection Sort**
- **Insertion Sort**

### 4. Binary Search Tree
- **Basic Operations**: Insert, Search, Count Nodes.
- **Traversals**: Inorder, Preorder, Postorder.
- **Node Types**: Leaf nodes, Parent nodes, Total nodes.

---

## Installation

Follow these steps to set up the GDSL library in your project:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/your-username/GDSL.git
   ```

2. **Include the GDSL source file**:
   Add the `GDSL.cpp` file to your project directory.

3. **Include GDSL in your code**:
   Add the following line to your C++ source file:
   ```cpp
   #include "GDSL.cpp"
   ```

---

## Usage Guide

### Step 1: Creating Objects
To use the data structures, create objects of the respective classes:

```cpp
#include "GDSL.cpp"

int main() {
    SinglyLL<int> list;
    Stack<float> stack;
    Queue<double> queue;
    BinarySearchTree<int> bst;

    return 0;
}
```

### Step 2: Using Basic Operations
Each data structure comes with basic operations. Here's an example:

#### Singly Linear Linked List:
```cpp
SinglyLL<int> list;
list.InsertFirst(10);
list.InsertLast(20);
list.Display();
cout << "Count: " << list.Count() << endl;
```

#### Queue:
```cpp
Queue<int> queue;
queue.Enqueue(10);
queue.Enqueue(20);
queue.Display();
cout << "Sum: " << queue.Addition() << endl;
```

#### Binary Search Tree:
```cpp
BinarySearchTree<int> bst;
bst.Insert(50);
bst.Insert(30);
bst.Insert(70);
bst.Inorder();
bst.Preorder();
bst.Postorder();
cout << "Leaf Nodes: " << bst.CountLeafNodes() << endl;
```

### Step 3: Using Searching Algorithms
The `SearchAlgorithms` class provides Linear, Bi-Directional, and Binary Search functionalities:

```cpp
SearchAlgorithms<int> search(5);
search.Accept();
search.Display();
if (search.LinearSearch(10)) {
    cout << "Element found!" << endl;
}
```

### Step 4: Using Sorting Algorithms
The `SortAlgorithms` class provides Bubble, Selection, and Insertion Sort:

```cpp
SortAlgorithms<int> sort(5);
sort.Accept();
sort.BubbleSort();
sort.Display();
```

---

## License

This project is licensed under the MIT License. See the LICENSE file for details.

---

## Contributions

Contributions are welcome! Feel free to fork the repository and submit pull requests with your changes.

---

For more information, contact **Gaurav Suresh Gavhane** at [gauravgavhane1702@gmail.com](mailto:gauravgavhane1702@gmail.com).


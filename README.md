# Sorting Algorithms and Time Complexity - Readme

This project aims to implement various sorting algorithms and understand their time complexity and usage. It covers the following learning objectives:

- Implement at least four different sorting algorithms.
- Understand the concept of Big O notation and evaluate the time complexity of an algorithm.
- Select the most suitable sorting algorithm for a given input.
- Recognize and comprehend stable sorting algorithms.

## Requirements

- Allowed editors: vi, vim, emacs.
- All files will be compiled on Ubuntu 20.04 LTS using gcc, with the options -Wall -Werror -Wextra -pedantic -std=gnu89.
- All files should end with a new line.
- A README.md file at the root of the project folder is mandatory.
- Code should follow the Betty style, which will be checked using betty-style.pl and betty-doc.pl.
- Usage of global variables is not allowed.
- Each file should have no more than 5 functions.
- The standard library should not be used unless explicitly permitted.
- The provided main.c files are examples and can be used for testing but do not need to be pushed to the repository.
- Function prototypes should be included in a header file called sort.h.
- All header files should have include guards.
- A list/array does not need to be sorted if its size is less than 2.

## Data Structure and Functions

The project provides the following functions for printing arrays and linked lists:

```c
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
```

The print_array function prints an array of integers, while the print_list function prints a list of integers. Both functions are already implemented in the files print_array.c and print_list.c.

The doubly linked list data structure is defined as follows:

```c
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```

## Time Complexity Notation

The time complexity notation used in this project follows the standard Big O notation. Some examples of time complexities are:

- O(1): Constant time.
- O(n): Linear time.
- O(n!): Factorial time.
- O(n^2): Quadratic time.
- O(log n): Logarithmic time.
- O(n log n): Linearithmic time.
- O(n + k): Linear time with additional variables.
- ...

## Copyright and Plagiarism

This project emphasizes originality and prohibits any form of plagiarism. It is crucial to come up with your own solutions and refrain from copying someone else's work. Publishing any content from this project is strictly forbidden. Violating these rules may result in removal from the program.

## Tests

To test your sorting algorithms with large sets of random integers, you can use Random.org, which provides random number generation services.

Please make sure to include a newline at the end of each answer file if required.

---
Remember, this is a basic template for the README file. Feel free to enhance it based on your project's specific requirements and structure.

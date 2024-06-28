
# Iterators in C++ (std98)

## Introduction

Iterators are a generalization of pointers that allow a programmer to traverse through elements in a container (such as an array or a list). They are a critical component of the C++ Standard Library, providing a consistent way to access elements within containers.

## Types of Iterators

1. **Input Iterators**: These are used to read values from a container.
2. **Output Iterators**: These are used to write values to a container.
3. **Forward Iterators**: These can read and write values and move forward through a container.
4. **Bidirectional Iterators**: These can move both forward and backward through a container.
5. **Random Access Iterators**: These provide access to any element in constant time.

## Basic Usage

Here is an example of how to use iterators with a vector:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Using an iterator to traverse the vector
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Explanation:

- `vec.begin()` returns an iterator to the first element of the vector.
- `vec.end()` returns an iterator to the element following the last element of the vector.
- `*it` dereferences the iterator to access the value of the element it points to.
- `++it` increments the iterator to point to the next element.

## Common Operations

- **Dereferencing**: `*it` gives access to the element pointed to by the iterator.
- **Incrementing**: `++it` moves the iterator to the next element.
- **Decrementing**: `--it` moves the iterator to the previous element (for bidirectional iterators).
- **Addition/Subtraction**: `it + n` or `it - n` moves the iterator forward or backward by `n` elements (for random access iterators).

## Example with Different Containers

### List Example:

```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> myList = {1, 2, 3, 4, 5};

    for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Map Example:

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "one";
    myMap[2] = "two";
    myMap[3] = "three";

    for (std::map<int, std::string>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }

    return 0;
}
```

### Explanation:

- In a `std::list`, the iterators are bidirectional.
- In a `std::map`, the iterators point to `std::pair<const Key, T>` objects, so you use `it->first` to access the key and `it->second` to access the value.

## Conclusion

Iterators provide a powerful and flexible way to traverse and manipulate the elements in C++ containers. Understanding how to use them effectively is essential for writing efficient and readable C++ code.


# Using the `<algorithm>` Library with STL Containers in C++98

The `<algorithm>` library in C++ provides a range of functions that perform various operations on sequences of elements, such as searching, sorting, counting, and modifying elements. These algorithms work seamlessly with STL containers through iterators.

## Common Algorithms and Their Usage

### 1. `std::sort`
- **Description:** Sorts the elements in a range.
- **Example Usage:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {4, 2, 3, 1, 5};

    std::sort(vec.begin(), vec.end());

    for (int val : vec) {
        std::cout << val << " ";
    }

    return 0;
}
```

### 2. `std::find`
- **Description:** Finds the first occurrence of a value in a range.
- **Example Usage:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {4, 2, 3, 1, 5};

    std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), 3);

    if (it != vec.end()) {
        std::cout << "Element found: " << *it << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}
```

### 3. `std::for_each`
- **Description:** Applies a function to each element in a range.
- **Example Usage:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void print(int value) {
    std::cout << value << " ";
}

int main() {
    std::vector<int> vec = {4, 2, 3, 1, 5};

    std::for_each(vec.begin(), vec.end(), print);

    return 0;
}
```

### 4. `std::count`
- **Description:** Counts the occurrences of a value in a range.
- **Example Usage:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {4, 2, 3, 1, 5, 3, 3};

    int count = std::count(vec.begin(), vec.end(), 3);

    std::cout << "Number of 3s: " << count << std::endl;

    return 0;
}
```

### 5. `std::remove`
- **Description:** Removes elements equal to a value by moving the elements to the end of the range.
- **Example Usage:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {4, 2, 3, 1, 5, 3, 3};

    std::vector<int>::iterator new_end = std::remove(vec.begin(), vec.end(), 3);

    vec.erase(new_end, vec.end());

    for (int val : vec) {
        std::cout << val << " ";
    }

    return 0;
}
```

### 6. `std::transform`
- **Description:** Applies a function to each element in a range and stores the result in a new range.
- **Example Usage:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int increment(int value) {
    return value + 1;
}

int main() {
    std::vector<int> vec = {4, 2, 3, 1, 5};
    std::vector<int> result(vec.size());

    std::transform(vec.begin(), vec.end(), result.begin(), increment);

    for (int val : result) {
        std::cout << val << " ";
    }

    return 0;
}
```

### Explanation

1. **Iterators:**
   - Algorithms in `<algorithm>` operate on ranges defined by iterators.
   - Examples: `vec.begin()`, `vec.end()`

2. **Lambda Functions (C++11 and Later):**
   - If you are using a C++11 or later compiler, you can use lambda functions to simplify code.
   - Example with `std::for_each`:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {4, 2, 3, 1, 5};

    std::for_each(vec.begin(), vec.end(), [](int value) {
        std::cout << value << " ";
    });

    return 0;
}
```

### Summary

- **`std::sort`**: Sorts elements.
- **`std::find`**: Finds an element.
- **`std::for_each`**: Applies a function to each element.
- **`std::count`**: Counts occurrences of a value.
- **`std::remove`**: Removes elements.
- **`std::transform`**: Transforms elements using a function.

The `<algorithm>` library provides powerful tools to manipulate and process elements in STL containers efficiently. By combining these algorithms with the versatility of STL containers, you can write clean, efficient, and expressive C++ code.

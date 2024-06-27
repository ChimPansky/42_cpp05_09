
# Using the `<algorithm>` Library with STL Containers in C++98

## `sort`
The `sort` algorithm sorts the elements in a range.

### Example
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9};
    
    std::sort(v.begin(), v.end());
    
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## `find`
The `find` algorithm searches for a value in a range.

### Example
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9};
    
    std::vector<int>::iterator it = std::find(v.begin(), v.end(), 4);
    
    if (it != v.end()) {
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}
```

## `count`
The `count` algorithm counts the occurrences of a value in a range.

### Example
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9};
    
    int count = std::count(v.begin(), v.end(), 1);
    
    std::cout << "Count of 1: " << count << std::endl;

    return 0;
}
```

## `for_each`
The `for_each` algorithm applies a function to each element in a range.

### Example
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void print(int x) {
    std::cout << x << " ";
}

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9};
    
    std::for_each(v.begin(), v.end(), print);
    std::cout << std::endl;

    return 0;
}
```

## `remove_if`
The `remove_if` algorithm removes elements from a range based on a condition.

### Example
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

bool is_odd(int x) {
    return x % 2 != 0;
}

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9};
    
    v.erase(std::remove_if(v.begin(), v.end(), is_odd), v.end());
    
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## `copy`
The `copy` algorithm copies elements from one range to another.

### Example
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v1 = {3, 1, 4, 1, 5, 9};
    std::vector<int> v2(v1.size());
    
    std::copy(v1.begin(), v1.end(), v2.begin());
    
    for (size_t i = 0; i < v2.size(); ++i) {
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

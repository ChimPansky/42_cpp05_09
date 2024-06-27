
# STL Containers in C++98

## `vector`
The `vector` container is a dynamic array that can grow and shrink in size. It provides random access to elements.

### Example
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## `list`
The `list` container is a doubly linked list. It allows efficient insertion and deletion of elements.

### Example
```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> lst;
    
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## `deque`
The `deque` (double-ended queue) container allows fast insertion and deletion at both ends.

### Example
```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq;
    
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(0);
    
    for (size_t i = 0; dq.size(); ++i) {
        std::cout << dq[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## `map`
The `map` container is an associative array. It stores key-value pairs with unique keys.

### Example
```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> mp;
    
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";
    
    for (std::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
```

## `set`
The `set` container stores unique elements in a sorted order.

### Example
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> st;
    
    st.insert(3);
    st.insert(1);
    st.insert(2);
    
    for (std::set<int>::iterator it = st.begin(); it != st.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

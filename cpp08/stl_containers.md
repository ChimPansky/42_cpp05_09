
# Overview of STL Containers in C++98

## Sequence Containers
### 1. `std::vector`
- **Description:** Dynamic array, provides random access to elements, and allows efficient insertion and deletion at the end.
- **Example Usage:**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }

    return 0;
}
```

### 2. `std::deque`
- **Description:** Double-ended queue, allows fast insertion and deletion at both the beginning and the end.
- **Example Usage:**

```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_front(0);

    for (size_t i = 0; i < deq.size(); ++i) {
        std::cout << deq[i] << " ";
    }

    return 0;
}
```

### 3. `std::list`
- **Description:** Doubly-linked list, allows fast insertion and deletion from anywhere in the sequence.
- **Example Usage:**

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

    return 0;
}
```

## Associative Containers
### 1. `std::set`
- **Description:** Stores unique elements in a specific order.
- **Example Usage:**

```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> myset;
    myset.insert(3);
    myset.insert(1);
    myset.insert(2);

    for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
```

### 2. `std::multiset`
- **Description:** Stores elements in a specific order, allows duplicate elements.
- **Example Usage:**

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> mymultiset;
    mymultiset.insert(3);
    mymultiset.insert(1);
    mymultiset.insert(2);
    mymultiset.insert(2);

    for (std::multiset<int>::iterator it = mymultiset.begin(); it != mymultiset.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
```

### 3. `std::map`
- **Description:** Stores key-value pairs with unique keys in a specific order.
- **Example Usage:**

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> mymap;
    mymap[1] = "one";
    mymap[2] = "two";
    mymap[3] = "three";

    for (std::map<int, std::string>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
        std::cout << "Key: " << it->first << " Value: " << it->second << std::endl;
    }

    return 0;
}
```

### 4. `std::multimap`
- **Description:** Stores key-value pairs, allows duplicate keys.
- **Example Usage:**

```cpp
#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> mymultimap;
    mymultimap.insert(std::make_pair(1, "one"));
    mymultimap.insert(std::make_pair(2, "two"));
    mymultimap.insert(std::make_pair(2, "deux"));

    for (std::multimap<int, std::string>::iterator it = mymultimap.begin(); it != mymultimap.end(); ++it) {
        std::cout << "Key: " << it->first << " Value: " << it->second << std::endl;
    }

    return 0;
}
```

## Container Adaptors
### 1. `std::stack`
- **Description:** Adaptor for `std::deque` (default), provides LIFO (last-in, first-out) data structure.
- **Example Usage:**

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);

    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }

    return 0;
}
```

### 2. `std::queue`
- **Description:** Adaptor for `std::deque` (default), provides FIFO (first-in, first-out) data structure.
- **Example Usage:**

```cpp
#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
```

### 3. `std::priority_queue`
- **Description:** Adaptor for `std::vector` (default), provides priority queue (elements are ordered by priority).
- **Example Usage:**

```cpp
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(2);

    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
```

This document provides an overview of the primary containers available in the C++98 STL, along with example usages demonstrating basic operations.

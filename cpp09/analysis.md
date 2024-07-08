
# CPP Module 09

## Ex00 Bitcoin Exchange
### optimal container:  `std::map`
- **Why?** We are dealing with key-value pairs. Dates are keys (unique aka no duplicates) and each date has a value (Bitcoin exchange rate on that day)

## Ex01 Reverse Polish Notation (RPN)
### optimal container:  `std::stack` (stacks use deque as underlying container by default)
- **Why?** Usually we write mathematical expressions like this : ```a + b``` (infix notation). Polish notation is just a different way to write the expression. So instead of ```a + b``` we write ```+ a b``` (prefix notation). Thus, in Reverse Polish Notation we write ```a b +```. This way of writing mathematical operations works perfectly together with stacks:
We work through the input string from left to right. When we find a value, we put it on the stack (push). When we find an operator, we take the top 2 elements from the stack (2 pops) and apply the operator on them and put the result back on the stack (push). We process the input string until the end and should end up with exactly 1 value on the stack which is the endresult of the mathematical expression. If during our calculations we find an operator, but do not have at least 2 values on the stack, then the syntax of the input string was wrong.

Example:
```
Stack: {empty}
Input: "8 9 * 9 - 9 - 9 - 4 - 1 +"

Stack: 9 8
Input: "* 9 - 9 - 9 - 4 - 1 +"
--> 8 * 9
Stack: 72
Input: "9 - 9 - 9 - 4 - 1 +"

Stack: 9 72
Input: "- 9 - 9 - 4 - 1 +"
--> 72 - 9
Stack: 63
Input: "9 - 9 - 4 - 1 +"

Stack: 9 63
Input: "- 9 - 4 - 1 +"
--> 63 - 9
Stack: 54
Input: "9 - 4 - 1 +"

Stack: 9 54
Input: "- 4 - 1 +"
--> 54 - 9
Stack: 45
Input: "4 - 1 +"

Stack: 4 45
Input: "- 1 +"
--> 45 - 4
Stack: 41
Input: "1 +"

Stack: 1 41
Input: "+"
--> 41 + 1
Stack: 42
Input: "" --> END condition reached
```

## Ex02 PmergeMe (aka Merge-Insert sort algorithm aka Ford-Johnson algorithm)
### containers (2 different ones):  `std::vector`, `std::list`
- **Vector Description:** Dynamic array, provides random access to elements, and allows efficient insertion and deletion at the end.
- **List Description:** Doubly-linked list, allows fast insertion and deletion from anywhere in the sequence.

## Ford Johnson Algorithm aka merge-insertion-algorithm to sort n elements:
```
example: (4, 3, 7, 43, 0, 20, 77, 50, 1)
1) make pairs from left to right (if uneven n then, just leave last element out):
  [(4,3) (7,43) (0,20) (77,50)]  | 1
  
2) order the pairs internally: 
  [(3,4) (7,43) (0,20) (50,77)] 
  
4) order pairs by their larger element using mergesort:
   [(3,4) (0,20) (7,43) (50,77)]

5) take the larger elements of each pair and put them into a sorted list (this will already be sorted):
  (4, 20, 43, 77)

6) the lower (unsorted) elements are:
  (3, 0, 7, 50)

7) insert the first of the lower elements at the beginning of the sorted list:
  (3, 4, 20, 43, 77)

8) insert the rest of the lower elements using binary insert:
      insert them in a specific order       (first the third element, then the 2nd element, then the 5th element, then the 4th, then the 11th, then the 10th,...) 
      this is called the Jacobsthal-Sequence: J(0) = 0; J(1) = 1; J(n) = J(n-2)*2 + J(n-1) | 0, 1 , 1, 3, 5, 11, 21, 43, 85,...
        
      when using binary insert look up what position in the sorted list the upper element of the to be inserted lower element currently occupies and take this   position as a right bound for the binary insert:
      that means: binary insert value 7 (it's upper value is 43) into the sorted list using left position 0 and right position 3 (index of 43); so binaryInsert(leftInd: 0, rightInd: 3, val:7);
      we get:
      -> (3, 4, 7, 20, 43, 77) (Jacobsthal says: lower element at pos 3: 7)
      -> (0, 3, 4, 7, 20, 43, 77) (Jacobsthal says: lower element at pos 2: 0)
      -> (0, 3, 4, 7, 20, 43, 50, 77) (Jacobsthal says: lower element at pos 5, but we only have 4 lower elements, so take pos 4: 50)
  
9) lastly: if n was uneven, binary insert the last element (here: binaryInsert(leftInd: 0, rightInd:7, val:1);

  -> (0, 1, 3, 4, 7, 20, 43, 50, 77)
```

unused containers in this module:
### `std::set`
### `std::multiset`
### `std::multimap`
### `std::queue`
### `std::priority_queue`

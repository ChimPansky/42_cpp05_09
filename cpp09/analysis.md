
# CPP Module 09

## Ex00 Bitcoin Exchange
### optimal container:  `std::map`
- **Why?** We are dealing with key-value pairs. Dates are keys (unique aka no duplicates) and each date has a value (Bitcoin exchange rate on that day)

## Ex01 Reverse Polish Notation (RPN)
### optimal container:  `std::stack`
- **Why?** Usually we write mathematical expressions like this : ```a + b``` (infix notation). Polish notation is just a different way to write the expression. So instead of ```a + b``` we write ```+ a b``` (prefix notation). Thus, in Reverse Polish Notation we write ```a b +```. This way of writing mathematical operations works perfectly together with stacks:
We work through the input string from left to right. When we find a value, we put it on the stack (push). When we find an operator, we take the top 2 elements from the stack (2 pops) and apply the operator on them and put the result back on the stack (push). We process the input string until the end and should end up with exactly 1 value on the stack which is the endresult of the mathematical expression. If during our calculations we find an operator, but do not have at least 2 values on the stack, then the syntax of the input string was wrong.

Example:
Stack: {empty}
Input: "8 9 * 9 - 9 - 9 - 4 - 1 +"
--> 8 * 9
Stack: 72
Input: "9 - 9 - 9 - 4 - 1 +"
-->
Stack: 9 72
Input: "- 9 - 9 - 4 - 1 +"
--> 72 - 9
Stack: 63
Input: "9 - 9 - 4 - 1 +"
-->
Stack: 9 63
Input: "- 9 - 4 - 1 +"
--> 63 - 9
Stack: 54
Input: "9 - 4 - 1 +"
-->
Stack: 9 54
Input: "- 4 - 1 +"
--> 54 - 9
Stack: 45
Input: "4 - 1 +"
-->
Stack: 4 45
Input: "- 1 +"
--> 45 - 4
Stack: 41
Input: "1 +"
-->
Stack: 1 41
Input: "+"
--> 41 + 1
Stack: 42 --> END condition reached

## Ex02 PmergeMe (aka Merge-Insert sort algorithm aka Ford-Johnson algorithm)
### optimal container:  `???`
- **Why?**

    std::deque<int> deq;
### `std::deque`
### `std::list`
### `std::set`
### `std::multiset`
### `std::multimap`
### `std::queue`
### `std::priority_queue`

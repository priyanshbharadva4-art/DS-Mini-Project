# DS-Mini-Project
# Stock Exchange System

## 1. Introduction

The Stock Exchange System is a C programming project that simulates the basic process of buying and selling shares. It compares buy and sell orders and performs a simulated trade when the buying price is greater than or equal to the selling price.

## 2. Features

* Stores buy and sell orders separately.
* Displays order prices and quantities.
* Matches buy and sell orders based on price.
* Updates the remaining quantity after each trade.
* Stores cancelled orders using a stack.
* Displays prices in ascending order using a binary search tree.
* Shows trading results in the console.

## 3. Technologies Used

* **Programming Language:** C
* **Data Structures:** Queue, Stack, and Binary Search Tree (BST)
* **Memory Management:** Dynamic memory allocation for tree nodes
* **Compiler:** GCC or another compatible C compiler
* **Output:** Console-based interface

## 4. How It Works

1. The program loads predefined buy and sell orders.
2. Buy and sell orders are stored separately.
3. The program compares the prices of buy and sell orders.
4. If the buying price is greater than or equal to the selling price, a trade can occur.
5. The program calculates the tradable quantity using the smaller remaining quantity of the two orders.
6. The remaining quantities are updated after the trade.
7. A cancelled order is stored in a stack.
8. A binary search tree displays the stored prices in ascending order.
9. Finally, the program displays the trading results.

## 5. Limitations

* It uses predefined sample orders instead of accepting orders interactively.
* Order matching follows array order rather than a complete stock exchange priority system.
* Order cancellation is demonstrated in a basic way.
* Orders and trading results are not saved permanently.
* It does not connect to a real stock exchange or perform actual financial transactions.

## 6. Future Improvements

* Add an interactive menu to place buy and sell orders.
* Allow users to enter prices and quantities.
* Implement more realistic order-matching rules.
* Increase order capacity using dynamic data structures.
* Add a complete order cancellation system.
* Store trade history using file handling or a database.
* Improve input validation and error handling.

## 8. Applications

* Demonstrates the basic concept of stock order matching.
* Helps students understand the practical use of data structures.
* Shows how queues, stacks, and trees can work together in one program.
* Provides a foundation for developing more advanced trading simulations.

## 9. Learning Outcomes

This project provides practical experience with C programming, structures, arrays, dynamic memory allocation, and fundamental data structures. It also helps develop an understanding of order matching, quantity updates, and the organization of trading records.

## 10. Conclusion

The Stock Exchange System is an educational project that demonstrates how queues, stacks, and binary search trees can be used to simulate basic stock trading operations. It provides a practical way to understand data structures and their applications in real-world scenarios.

The project can be improved further by adding interactive order entry, better matching rules, and permanent record storage.

**Disclaimer:** This project is developed for educational purposes only. It does not perform real stock market trading or financial transactions.

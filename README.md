# 🔢 Arbitrary Precision Calculator (APC)

> A C-based application that performs arithmetic operations on integers of **virtually unlimited size** — far beyond the limits of standard C data types.

---

## 📌 Overview

Standard C data types like `int`, `long`, and `long long` cap out at fixed sizes. **APC** breaks that barrier by representing numbers as **doubly linked lists**, where each node stores a single digit — enabling calculations on numbers with thousands of digits.

---

## ✨ Features

- ➕ Addition of arbitrarily large integers
- ➖ Subtraction of arbitrarily large integers
- ✖️ Multiplication of arbitrarily large integers
- ➗ Division of arbitrarily large integers
- 🔣 Modulus operation
- 🔗 Digit-by-digit storage using **Doubly Linked Lists**
- 🧠 Dynamic memory allocation
- 📋 Menu-driven interface

---

## 🛠️ Technologies Used

| Category | Details |
|---|---|
| Language | C |
| Data Structure | Doubly Linked List |
| Memory | Dynamic Allocation (`malloc` / `free`) |
| Compiler | GCC |
| Platform | Linux / Ubuntu |

---

## 📁 Project Structure

```text
.
├── main.c            # Entry point & menu logic
├── addition.c        # Addition operation
├── subtraction.c     # Subtraction operation
├── multiplication.c  # Multiplication operation
├── division.c        # Division operation
├── modulus.c         # Modulus operation
├── insert.c          # Node insertion utilities
├── delete.c          # Node deletion & memory cleanup
├── header.h          # Shared declarations & structs
└── README.md
```

---

## ⚙️ Working Principle

Large numbers are stored digit-by-digit in a **doubly linked list**:

```
12345678901234567890

Head
 ↓
[1] ↔ [2] ↔ [3] ↔ [4] ↔ ... ↔ [0]
                                 ↑
                                Tail
```

Arithmetic is performed **digit-by-digit**, similar to manual pen-and-paper calculations, with proper carry and borrow handling at each step.

---

## 🚀 Getting Started

### Prerequisites

- GCC compiler
- Linux / Ubuntu environment

### 🔧 Compilation

```bash
gcc *.c -o apc
```

### ▶️ Execution

```bash
./apc
```

---

## 🧪 Sample Operations

### ➕ Addition

```
Enter Number 1 : 99999999999999999999
Enter Number 2 : 1
Result         : 100000000000000000000
```

### ✖️ Multiplication

```
Enter Number 1 : 123456789
Enter Number 2 : 987654321
Result         : 121932631112635269
```

---

## 📚 Learning Outcomes

Building this project provided hands-on experience in:

- 🔗 Doubly Linked Lists and pointer manipulation
- 🧠 Dynamic memory allocation and deallocation
- 🧩 Modular programming in C
- 🔢 Large numerical computation algorithms
- 🐛 Debugging and problem solving

---

## 🔮 Future Enhancements

- [ ] **Floating-point** arithmetic
- [ ] **Expression evaluation** (e.g., `(a + b) * c`)
- [ ] Scientific calculator functionality
- [ ] Performance optimization for very large inputs

---

## 👨‍💻 Author

**Avinash Patil**

[![GitHub](https://img.shields.io/badge/GitHub-patilavinash0208-181717?style=flat&logo=github)](https://github.com/patilavinash0208)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Avinash%20Patil-0A66C2?style=flat&logo=linkedin)](https://www.linkedin.com/in/avinash-patil-873b9b227)

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

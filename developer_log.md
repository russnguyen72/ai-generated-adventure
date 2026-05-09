# AI-Generated Adventure
## CS 210 (Spring 26)

---

### Entry 1
#### Date: 5/8/2026

I completed the implementation of the Tree class located in `tree.h` by fleshing out the methods used in the class and created this developer log to track my progress within this project. I have not yet deleted the TODO comments so I can later compare the actual functionality of the class to its intended functionality once I have developed the main.cpp file and begin testing the code.

---

### Entry 2
#### Date: 5/9/2026

I implemented the rest of the logic located in `main.cpp` and `tree.h`. I added some recursive helper functions in `tree.h` as there were linter errors present during the implementation of some `tree.h` methods in `main.cpp`. Therefore, I made some helper functions in the Node class, which the similarly named Tree class methods call to start the initial recursion. The only problems that could now occur are most likely within the node connecting part of the main function. I would love to test the entire program, but I suffer from not having money for OpenAI API credits, so hopefully everything works without bugs.
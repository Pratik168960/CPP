# The Function Call Stack

Think of the call stack exactly like a **stack of plates**. 

* **Starting a function:** You put a new plate on top of the stack.
* **A function calls another function:** You put another plate on top.
* **Finishing a function:** You take the top plate off.

The golden rule: You can only ever add or remove plates from the **very top**. 

### What is a Stack Overflow?
If a function calls itself infinitely, the computer keeps stacking plates until it runs out of room. The stack falls over, and your program crashes!
# The Kafe programming language

*excuse me if it's a bit messy but it's only the beginning an I am writing things here whenever something new or important come to my mind*

## Variables

### Const qualifier

Variables can be either const or dynamic, const ones can only be read (they must have a value when creating them) and not modified.

### Visibility

It's possible to read upper scope variables, but not to modify them. By upper scope, I mean the global scope **only**. A function B called by a function A can not access the variables inside A, but can read the variables declared at the global scope.
# The Kafe programming language

*excuse me if it's a bit messy but it's only the beginning an I am writing things here whenever something new or important come to my mind*

## Variables

### Const qualifier

Variables can be either const or dynamic, const ones can only be read (they must have a value when creating them) and not modified.

### Visibility

It's possible to read upper scope variables, but not to modify them. By upper scope, I mean the global scope **only**. A function B called by a function A can not access the variables inside A, but can read the variables declared at the global scope.

To be able to modify an upper scope variable in a function, it must be declared as following :

```
dyn a : str = "hello"

fun yourfunction : int  # remember we can't return nil/None/null, because it do not exists in Kafe
    # we must return a status code if the same function in C for example would have been of return type `void`
    print(a)  # we can only read it
    a = 10  # would raise an exception and terminate the program
    nonlocal a  # we'll now be able to write in it
    a ..= " world"  # concatenation, a is now equal to "hello world"
    ret 0

yourfunction()
```
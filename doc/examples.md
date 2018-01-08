# Examples

Here are some examples of Kafe code before turning it into bytecode (if you want to learn how the bytecode works, check [this](vm.md) out) :

```
fun myfunction : int
    dyn value : int = 15
    ret value  // push value on the stack
end

fun other : int -- arg:int truc:string
    ret arg * (len truc) + arg
end

dyn var : int
dyn var2 : int = 10
const var3 : int = 12
dyn truc : int = myfunction
dyn machin : int = other 1 "hello"

struct car_without_arg
    dyn size : int = 5
    dyn weight : int = 10
end

struct car -- _size:int _weight:int
    dyn size : int = _size
    dyn weight : int = _weight
end

dyn car1 : car_without_arg
dyn car2 : car = 22 37

struct car
    dyn size : int = 10
    dyn weight : double = 1250.25

    fun doStuff : int -- me:car
        print "hello world" me.size " " me.weight
        ret 0
    end
end

fun createCar : car -- s:int w:double
    dyn mycar : car
    mycar.size = s
    mycar.weight = w
    ret mycar
end

dyn renaud20 : car = createCar 1000 765.12

while renaud20.size <= 20
    renaud20.size ++
end

for i in range 0 10
    print i
end

renaud20.doStuff # calling the function doStuff on renaud20
```

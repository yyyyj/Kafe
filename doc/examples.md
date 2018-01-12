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

dyn var : int  # will be declared using a default value
dyn var2 : int = 10
dyn truc : int = myfunction
dyn machin : int = other 1 "hello"

struct car_without_arg
    dyn size : int = 5
    dyn weight : int = 10

    fun doStuff : void -- me:car
        print "hello world" me.size " " me.weight
        ret
    end
end

struct car -- _size:int _weight:int
    dyn size : int = _size
    dyn weight : int = _weight
end

dyn car1 : car_without_arg
dyn car2 : car = 22 37  # implicit constructor call

fun createCar : car -- s:int w:double
    dyn mycar : car
    mycar.size = s
    mycar.weight = w
    ret mycar
end

dyn renaud20 : car = createCar 1000 765.12  # implicit function call

while renaud20.size <= 20
    renaud20.size ++
end

for i in (range 0 10)
    print i
end

renaud20.doStuff  # calling the function doStuff on renaud20
```

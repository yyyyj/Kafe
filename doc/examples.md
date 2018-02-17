# Examples

Here are some examples of Kafe code before turning it into bytecode (if you want to learn how the bytecode works, check [this](vm.md) out) :

```
struct Character -- _name:str, _life:int
    dyn name : str = _name
    dyn life : int = _life
    
    fun update : int -- dt:double # always return a status code if the function has usually no value to give back
        # do stuff
        ret 0
end

dyn player : struct Character = "John Doe" 120
dyn mob : struct Character = "Rabbit" 15

# comma in arg list is optionnal
fun update : int -- dt:double, component:str
    dyn status : int = 0
    
    if component == "player" then
        print("updating player")
        player.update(dt)
    elif component == "mob" then
        print("updating mob")
        mod.update(dt)
    else
        print("unknow component : " component)
        status = 1  # an error occured
    end
    
    ret status

update(0.005 "player")

struct car
    dyn size : int = 10

    fun main : bool -- me : struct car
        print("hello  world" me.size)
        ret true
end

# this is a comment which should be skipped
dyn i : int = 10 #same here
dyn v : list = [0 2 4 6 8]

if 1 + 1 == 2 then
    while i != 0 do
        i -= 1
    end

    for j in (range 5 20) do
        print(j * 10 + 5)
    end
else
    print("hello world   bis")
end
```

# Kafe

Java was named Java because of the coffee of the same name. Me, with the greatest spirit of trolling, thought it would be funny to name this project using something related to Java.
Why ? Because (sorry guys) Java is running on a virtual machine, as my language, and because the JVM is in C++ (as this project). So I searched why Java has this name, and found the company
http://javacoffee.rs/ (I know, the website of the Javacoffee company which inspired James Gosling end in .com), which also sells something called "Kafe".

Now you know everything.

# Pre-requisites

* C++14 compiler

* Python (>= 3.4)

* CMake (>= 3.5)

# Goal

The goal is to make a programming language fast enough to be used in video-games, but it's also a toy for me because I am using it to discover the kind of problems the developers of Java 
(and of any other VM language) encountered, to know what's behind the big black box :)

# Free samples everyone ?

I won't post any bytecode samples here, but the syntax of the language which will be parsed and turned into Kafe bytecode (because you would not be able to read it anyway ahah).

```
struct Character -- _name:str _life:int
    dyn name : str = _name
    dyn life : int = _life
    
    fun update : void -- dt:double
        # do stuff
        ret
    end
end

dyn player : Character = "John Doe" 120
dyn mob : Character = "Rabbit" 15

fun update : int -- dt:double component:str
    dyn status : int = 0
    
    if component == "player"
        print "updating player"
        player.update dt
    elif component == "mob"
        print "updating mob"
        mod.update dt
    else
        print "unknow component : " component
        status = 1  # an error occured
    end
    
    ret status
end

update 0.005 "player"
```

# [Documentation](doc/main.md)

# [Tests](tests/README.md)
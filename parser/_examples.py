# coding : utf-8

EVERY_KW_EX = """
struct car
    dyn size : int = 10

    fun main : bool -- me : car
        print "hello  world" me.size
        ret true
    end
end

# this is a comment which should be skipped
dyn i : int = 10#same here
dyn v : list = [0 2 4 6 8]

if 1 + 1 == 2
    while i != 0
        i --
    end

    for j in (range 5 20)
        print j * 10 + 5
    end
else
    print "hello world   bis"
end
""".split("\n")

if __name__ == '__main__':
    raise NotImplementedError("This script isn't meant to be run directly")

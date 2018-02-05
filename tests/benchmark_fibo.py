import time

class Benchmark():
    def __init__(self, test_name):
        self.start = time.time()
        self.name = test_name
        self.end = None
        
    def __enter__(self):
        return self
        
    def __exit__(self, exc_type, exc_val, exc_tb):
        self.end = time.time()
    
    def to_ticks(self, unit="us"):
        if unit not in ("ms", "us", "ns"):
            raise NotImplementedError
        elapsed = self.end - self.start
        if unit == "ms":
            return elasped * 1000 ** 1
        elif unit == "us":
            return elapsed * 1000 ** 2
        elif unit == "ns":
            return elapsed * 1000 ** 3
    
    def repr(self, runs):
        return "Benchmark of {} on {} run(s) = {:.2f}us\nAverage = {:.2f}us".format(self.name, runs, self.to_ticks("us"), self.to_ticks("us") / runs)

def f(n):
    if not hasattr(f, "c"): f.c = 0
    f.c += 1
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return f(n - 1) + f(n - 2)

def fib(n):
    i, a, b = 0, 0, 1
    while i < n:
        a, b = b, a + b
        i += 1
    return a

with Benchmark("Fibonacci (recursive)") as bench:
    for i in range(100):
        f(23)
print(bench.repr(100))

with Benchmark("Fibonacci (loop)") as bench:
    for i in range(100):
        fib(23)
print(bench.repr(100))
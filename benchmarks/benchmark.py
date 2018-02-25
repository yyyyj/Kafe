import time

class Benchmark():
    def __init__(self, test_name, runs):
        self.start = time.time()
        self.name = test_name
        self.runs = runs
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
    
    def repr(self):
        return "Benchmark of {} on {} run(s) = {:.2f}us\nAverage = {:.2f}us".format(self.name, self.runs, self.to_ticks("us"), self.to_ticks("us") / self.runs)

def f(n):
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
"""
with Benchmark("Fibonacci (recursive)", 500) as bench:
    for i in range(bench.runs):
        f(40)
print(bench.repr())
"""
with Benchmark("Fibonacci (loop)", 1000) as bench:
    for i in range(bench.runs):
        fib(40)
print(bench.repr())
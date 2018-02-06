# Benchmarks

I tried to do some benchmarks (which are ran alongside the tests), and the results are quiet good !

## Benchmarks of Kafe

```
[ int:18768, str:hello, bool:true ]

Benchmark of loading on 1 run(s) = 0ns
Benchmark on 100 run(s) = 1000us
Average = 10us
Benchmark of saving on 1 run(s) = 10ms

Stack (3)
-------------
[2] BOOL 1
[1] STRING hello
[0] INT 18768

=================================

[ var = 1; push(var); push(9); add ]

Benchmark of loading on 1 run(s) = 0ns
Benchmark on 100 run(s) = 1000us
Average = 10us
Benchmark of saving on 1 run(s) = 11ms

Stack (1)
-------------
[0] INT 10


Variables (1)
-------------
var = 1 (INT)

=================================

[ push true, jump if => 15, push false, jump => 7, jump if not, halt ]

Benchmark of loading on 1 run(s) = 0ns
Benchmark on 100 run(s) = 2001us
Average = 20.01us
Benchmark of saving on 1 run(s) = 12ms

=================================

[ testing segments, jump and ret ]

Benchmark of loading on 1 run(s) = 0ns
Benchmark on 100 run(s) = 2001us
Average = 20.01us
Benchmark of saving on 1 run(s) = 12ms

Stack (1)
-------------
[0] BOOL 1


Variables (1)
-------------
a = 0 (BOOL)

=================================

[ testing variable duplication and negatives numbers (-32767, 32767) ]

Benchmark of loading on 1 run(s) = 0ns
Benchmark on 100 run(s) = 2002us
Average = 20.02us
Benchmark of saving on 1 run(s) = 18ms

Stack (3)
-------------
[2] INT 32767
[1] INT -32768
[0] INT -32768


Variables (1)
-------------
h = -32768 (INT)

=================================

[ Fibonacci ]

Benchmark of loading on 1 run(s) = 0ns
Benchmark on 100 run(s) = 208138us
Average = 2081.38us
Benchmark of saving on 1 run(s) = 802ms

Stack (1)
-------------
[0] INT 102334155
```

Kafe was compiled using `-O3 -s -std=c++14`, the VM was ran with `tests` (no `-i` or `-v`) (on the date of the 71st commit)

## Benchmarks in other languages

Just to be able to compare (because I love numbers and stats ahah), I created the same tests (the most elaborated, like the Fibonacci one) in other languages.

### C++

[benchmark.cpp](benchmarks/benchmark.cpp)

```
Benchmark of Fibonacci (recursive) on 100 run(s) = 25016us
Average = 250.16us
Benchmark of Fibonacci (loop) on 100 run(s) = 0us
Average = 0us
```

Compiled with `-O3 -s -std=c++14`

### Python (3.4)

[benchmark.py](benchmarks/benchmark.py)

```
Benchmark of Fibonacci (recursive) on 100 run(s) = 10201771.97us
Average = 102017.72us
Benchmark of Fibonacci (loop) on 100 run(s) = 0.00us
Average = 0.00us
```
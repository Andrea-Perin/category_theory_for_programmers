1.

```python3
from typing import Callable
from functools import wraps
from itertools import chain


def f(x):
    return x**2


def memoize_fun(f: Callable):
    @wraps(f)
    def inner(*args, **kwargs):
        key = (tuple(args), tuple(kwargs.items()))
        if key not in inner.cache:
            inner.cache[key] = f(*args, **kwargs)
        return inner.cache[key]
    inner.cache = dict()
    return inner
    

class memoize_obj():
    def __init__(self, f):
        self.f = f
        self.cache = dict()

    def __call__(x):
        if x not in self.cache:
            self.cache[x] = self.f(x)
        return self.cache
```

2. Try to memoize a function from your standard library that you normally use
   to produce random numbers. Does it work?

```python3
import random

myrand = memoize_fun(random.random)

print(myrand())
print(myrand())
print(myrand())

# however...

print(random.random())
print(random.random())
print(random.random())
```

The two differ: the inner cache in myrand "occupies" all the space of possible
calls to it! Since random.random is called with no arguments, it can only be
memoized in a single way. So the first possible result is saved forever.

This is due to the fact that `random.random()` is not a pure function: calling
it multiple times with the same parameters *does not* result in the same result
every time, quite the contrary.

3. Most random number generators can be initialized with a seed. Implement a
   function that takes a seed, calls the random number generator with that
   seed, and returns the result. Memoize that function. Does that work?

```python3
def seeded_random(seed: int):
    random.seed(seed)
    return random.random

myrand_seeded = memoize_fun(seeded_random(1))

print(myrand_seeded())
print(myrand_seeded())
print(myrand_seeded())
```

This still does not work, as the problem described above persists. There is
only one way to call `random.random`, and that gets cached regardless of the
seed.

4. Which of these C++ functions are pure? Try to memoize them and observe what
   happens when you call them multiple times: memoized and not.
   (a) the factorial function from the example in the text.
   (b) `std::getchar()`
   (c) 
    ```cpp
    bool f() {
        std::cout << "Hello!" << std::endl;
        return true;
    }
```
   (d)
    ```cpp
    int f(int x) {
        static int y = 0;
        y += x;
        return y;
    }
```

See `code_challenge_2.cpp`.


5. How many different functions are there from `Bool` to `Bool`? Can you
   implement them all?

There are 4 possible such functions:

bool true_(bool x) { return true; }
bool false_(bool x) { return false; }
bool id_(bool x) { return x; }
bool neg_(bool x) { return !x; }

6. Draw a picture of a category whose only objects are the types `Void`, `()`
   (unit), and `Bool`; with arrows corresponding to all possible functions
   between these types. Label the arrows with the names of the functions.

```
() -> Bool: True, False
Void -> _: absurd
Bool -> (): unit
_ -> Void: absorb
```

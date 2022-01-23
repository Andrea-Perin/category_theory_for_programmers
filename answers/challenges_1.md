1. Implement, as best as you can, the identity function in your favorite language.

```python3
def id(x):
    return x
```

2. Implement, the composition function in your favorite language. It takes two
   functions as arguments and returns a function that is their composition.

```python3
from typing import Callable
def compose(f: Callable, g: Callable):
    def f_g(x):
        return f(g(x))
    return f_g
```

3. Write a program that tries to test that your composition function respects
   identity.

```python3
def f(x):
    return x**2

def g(x):
    return 2*x

# must be: 
# f . id == f
# id . f == f

vals = range(10)
res_fid = map(compose(f, id), vals)
res_idf = map(compose(id, f), vals)
res_f = map(f, vals)
for v_, fid_, idf_, f_ in zip(vals, res_fid, res_idf, res_f):
    print(f"f . id ({v}) == {fid_};")
    print(f"id . f ({v}) == {idf_};")
    print(f"f ({v}) == {f_};")
```

4. Is the world wide web a category in any sense? Are links morphisms?

For something to be a category, it must:
* contain objects;
* contain morphisms between said objects, with the composition property; also,
  an identity morphism must exist.

For the "world wide web category":
* webpages are objects;
* links are morphisms.
Ideally, the identity morphisms are self-links, and composition is respected.
However, self-links are not guaranteed to exist. Also, given the existence of a
link between pages a and b, and of a link between pages b and c, there is no
guarantee that a link between a and c exists.

5. Is Facebook a category, with people as objects and friendships as morphisms?

For similar reasons as those outlined above, Facebook (in the interpretation
given above) is not a valid category. Indeed, a user can not be a friend of
himself, and a 3-chain of friendships does not necessarily imply that the
initial and final users are also linked by a friendship relation.

6. When is a directed graph a category?

In a directed graph, let the nodes be objects and the edges be morphisms.
The graph, with the loops, induces a category. Self-links are obvious, and
composition is simply the joining of two consecutive edges.

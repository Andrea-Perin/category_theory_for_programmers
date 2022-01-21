1. Show that the terminal object is unique up to unique isomorphism.

The terminal object is the object that has one and only one morphism coming to
it from any object in the category. This object, while not unique, is unique up
to unique isomorphism.
Let us assume that there are 2 terminal objects, not linked by a unique
isomorphism. Then, both objects will have one and only one morphism coming to
them from any object in the category. In particular, they have a morphism coming
from each other. Named t1 and t2 the two terminal objects, name the morphisms
connecting them f and g. Both t1 and t2 have the identity morphisms; since they
are terminal, f and g are unique. The compositions of f and g are morphisms from
t1 to itself and from t2 to itself. They too are unique, due to them being
terminal. So the compositions are actually the identities, and so t1 and t2 are
isomorphic. Since, by definition, f and g are the unique morphisms connecting
t1 and t2, they are unique up to unique isomorphism.

2. What is a product of two objects in a poset? Hint: Use the universal
   construction.

A poset is a partially ordered set.
The definition of a product is as follows:

> A **product** of two objects _a_ and _b_ is the object _c_ equipped with two
> projections such that for any other object _c'_ equipped with two projections
> there is a unique morphism _m_ from _c'_ to _c_ that factorizes those
> projections.

A candidate object _c_ must have two morphisms, p and q, which connect it to the
objects _a_ and _b_. These morphisms, in a poset, are the "less than or equal".
So, for _c_ to be a candidate, it must be that

```
c ≤ a AND c ≤ b
```

If the poset had an initial object, then that would be a trivial candidate, as
it is the element which is smaller than or equal to all the others. However,
there is no guarantee that a poset has a terminal object. Instead, we can take
any of the "common ancestors" of **both** _a_ and _b_ in the "less than or equal
to" graph which "encodes" the poset.
These candidates can be ranked on the basis of the "size" of the projections
from them to _a_ and _b_. More precisely, take this graph as an example:

```
      b  e  
    ↗  ⤨  ↘  
a  →  c →  f → h   
    ↘  ⤨  ↗  
      d  g  
```

For objects _e_ and _g_, two possible candidates for the product are _a_ and
_c_. Indeed, for _a_, the projections are:

```
p_a :: a → e  is  p_a = (c→ e) · (a→ c)
q_a :: a → g  is  q_a = (c→ g) · (a→ c)
```

while for _c_ they are

```
p_c :: c → e  is  p_c = (c→ e)
q_c :: c → g  is  q_c = (c→ g)
```

From this, it can be seen that the morphism `(a → c)` is an "extra factor" in
the morphism connecting _a_ with _e_ and _g_ if compared to the morphism
connecting _c_ with _e_ and _g_.

It then follows that the product between two objects in a poset is the largest
object that is less than or equal to both of them.

In the case of a "fully connected" network (i.e., total ordering), this is the
min between the two objects.


3. What is a coproduct of two objects in a poset?

The definition of a coproduct is as follows:

> A **coproduct** of two objects _a_ and _b_ is the object _c_ equipped with two
> injections such that for any other object _c'_ equipped with two injections
> there is a unique morphism _m_ from _c'_ to _c_ that factorizes those
> projections.

For a candidate _c_, the constituents _a_ and _b_ must have two morphisms, p and
q, which connect them to it. As before, these morphisms are the "less than or
equal to" relations. As such, for a candidate _c_, its constituents must be less
than or equal to it.

As before, a trivial candidate would be the terminal object, the existence of
which however is not guaranteed for a general poset (see the integers).

Taking the graph above, once again, as an example/aid:

```
      b  e  
    ↗  ⤨  ↘  
a  →  c →  f → h   
    ↘  ⤨  ↗  
      d  g  
```

for the objects _b_ and _d_, possible candidates include _f_ and _h_.
Let us start with _h_. It is indeed a candidate, as the injections are

```
p_h :: e → h  is  p_h = (f→ h) · (b→ f)
q_h :: g → h  is  q_h = (f→ h) · (d→ f)
```

The same is true for _f_, for which the injections are

```
p_f :: e → f  is  p_f = (b→ f)
q_f :: g → f  is  q_f = (d→ f)
```

As it can be seen, _f_ is "more minimal" than _h_ as a candidate, as the
latter's injections can be factorized by a common "pre-factor" `(f→ h)`.

It can be seen that the coproduct between two objects in a poset is the smallest
object that is larger than both of its constituents.

In the case of a "fully connected" network (i.e., total ordering), this is the
max between the two objects.

4. Implement the equivalent of Haskell `Either`  as a generic type in your
   favorite language (other than Haskell).

See the file `code_challenge_5.cpp`.

5. Show that `Either` is a "better" coproduct than `int` equipped with two
   injections:

   ```cpp
   int i(int n) { return n; }
   int j(bool b) { return b ? 0: 1; }
   ```
   
   Hint: Define a function
   ```cpp
   int m(Either const & e);
   ```
   that factorizes `i` and `j`.
   
`Either` is a coproduct: the injections, in Haskell parlance, are the
constructors `Left` and `Right`. Its factorizer is

```haskell
factorizer :: (a -> c) -> (b -> c) -> (Either a b -> c)
factorizer i j (Left a) = i a
factorizer i j (Right b) = j b
```

Such function may be:

```cpp
int m(Either const & e)
{
    if (e.tag == Either.isLeft)
        return int(e.l);
    else
        return int(e.r);
}
```
which, united with some constructors/injectors for `Either`, recreates `i` and
`j`.

6. Continuing the previous problem: How would you argue that `int` with the two
   injections `i` and `j` cannot be "better" than `Either`?

If `int` with `i` and `j` was better than `Either`, then it would mean that
there was a morphism `m` which factorized the injections/constructors of
`Either`. This means that there should be
```
m : int -> Either
```
but this fails when it is fed 0 or 1, since for these values both `int` and
`bool` overlap. Which injection/constructor should be used inside `m` to create
an `Either`?

7. Still continuing: What about these injections?
```cpp
int i(int n) {
    if (n<0) return n;
    return n+2;
    }
int j(bool b) {return b?0:1;}
```

These injections remove the aforementioned overlap which was a problem.
In practice, an Either (at least, in C++) is obtained by using a tagged union.
By using tags, the potentially overlapped values are effectively "doubled" and
thus the overlap is removed.
These injections may look good, but they also introduce another, hidden overlap:
since `int` is not infinitely big, only a finite set of numbers can be
represented. Thus, shifting the positives by 2 only means that 2 pairs of
integers will be overlapped.

8. Come up with an inferior candidate for a coproduct of `int` and `bool` that
   cannot be better than `Either` because it allows multiple acceptable
   morphisms from it to `Either`.

Maybe just a pair of `int`s. This object is "bigger" than `Either`, so there are
many ways to go from it to `Either`.
To start, the candidate injections may be
```
i : int -> (int, int)
i x = (x, x)

j : bool -> (int, int)
j True = (5, 5 + 2)
j False = (5, 6)
```
and there are however many of these.
However, one can also create however many morphisms from `(int, int)` to
`Either`. For instance, something that constructs `Either` via an `int` if the
two values of `(int, int)` are equal and via `bool` otherwise; or alternatively,
by `bool` using the remainder by 2 of the first value if the second is even, and
by `int` using the second value in the pair if the second is odd.

The point is that this pair is "too big" to be a valid coproduct.

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

It then follows that, for a poset, the product between two objects in a poset is
the largest object that is less than or equal to both of them.

3. What is a coproduct of two objects in a poset?

The definition of a coproduct is as follows:

> A **coproduct** of two objects _a_ and _b_ is the object _c_ equipped with two
> injections such that for any other object _c'_ equipped with two injections
> there is a unique morphism _m_ from _c'_ to _c_ that factorizes those
> projections.

For a candidate _c_, the constituents _a_ and _b_ must have two morphisms, p and
q, which connect them to it. As before, these morphisms are the "less than or
equal to" relations. 

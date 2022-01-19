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
Let c be an object, and p and q be two morphisms (projections) connecting it to
a and b:
```haskell
p :: c -> a
q :: c -> b
```

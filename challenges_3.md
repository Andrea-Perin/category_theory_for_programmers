1. Generate a free category from:
    (a) A graph with one node and no edges
    (b) A graph with one node and one (directed) edge (hint: this edge can be
        composed with itself)
    (c) A graph with two nodes and a single arrow between them
    (d) A graph with a single node and 26 arrows marked with the letters of the
        alphabet: a, b, c, ..., z

(a) The free category that is induced by this graph is obtained by adding the
loop on the single object.
(b) The category is the same as the one in (a).
(c) The free category is obtained by adding the loops on the two objects.
(d) If no objects/nodes are to be added, then all the 26 arrows must be the
same, that is, the identity/loop.

2. What kind of order is this?
    (a) A set of sets with the inclusion relation: A is included in B if every
    element of A is also an element of B.
    (b) C++ types with the following subtyping relation: `T1` is a subtype of
    `T2` if a pointer to `T1` can be passed to a function that expects a
    pointer to `T2` without triggering a compilation error.

(a) Let us check the properties of the inclusion relation. It is true that A is
included in A, as each of its elements is an element of A. As for composition:
if A is included in B, and B is included in C, is A included in C? Every
element of A is in B, but every element of B is in C, so the inclusion relation
is indeed composable. This means that a set of sets equipped with the inclusion
is a preorder.
However, it is also a partial order: if A is included in B, and B is included
in A, then A is the same as B. Thus, this is also a partial order.
It is not however a total order, as for two sets A and B, it can be that
neither is included in the other (it is enough that the two sets are disjoint).

(b) Let us check the properties of the `is_subtype` property. Is it true that a
type `T` is a subtype of itself? According to the definition: `T` is a subtype
of `T` if a pointer to `T` can be passed to a function that expects a pointer
to `T` without compilation errors. Indeed, this is quite obvious. Is the
subtyping relation composable? It indeed is. As a consequence, `is_subtype` is
a valid morphism between type ojects. `is_subtype` is a preorder.
However, it is also a partial order: if A is a subtype of B, and B is a subtype
of C, then A is a subtype of C. This can be thought of as follows: A "enriches"
B, by adding some fields to it, but it still contains all the fields in B. The
same holds for B and C, and thus A contains all the fields in C, possibly
adding some others. Indeed, this can be thought of as an inclusion relation:
every type/struct/class contains a set of fields, and between these fields one
can define an inclusion relation.
This category is indeed not a total order: there are types that are mutually
not subtypes of each other.

3. Considering that `Bool` is a set of two values `True` and `False`, show that
   it forms two (set-theoretical) monoids with respect to, respectively,
   operator && (AND) and || (OR).

A monoid is traditionally defined as a set equipped with a binary operation
that is associative, and in the set there is an element which behaves like
unity with respect to the binary operation.
* With respect to AND:
For any set of three boolean values a, b, and c: (a && b) && c =?= a && (b && c).

| A | B | C | A && B | B && C | (A && B) && C | A && (B && C) |
|:-:|:-:|:-:|:------:|:------:|:-------------:|:-------------:|
| 0 | 0 | 0 |    0   |    0   |       0       |       0       |
| 0 | 0 | 1 |    0   |    0   |       0       |       0       |
| 0 | 1 | 0 |    0   |    0   |       0       |       0       |
| 0 | 1 | 1 |    0   |    1   |       0       |       0       |
| 1 | 0 | 0 |    0   |    0   |       0       |       0       |
| 1 | 0 | 1 |    0   |    0   |       0       |       0       |
| 1 | 1 | 0 |    1   |    0   |       0       |       0       |
| 1 | 1 | 1 |    1   |    1   |       1       |       1       |

The neutral element is 1: (1 && 1) = 1, and (1 && 0) = 0.

* With respect to OR:
For any set of three boolean values a, b, and c: (a || b) || c =?= a || (b || c).

| A | B | C | A || B | B || C | (A || B) || C | A || (B || C) |
|:-:|:-:|:-:|:------:|:------:|:-------------:|:-------------:|
| 0 | 0 | 0 |    0   |    0   |       0       |       0       |
| 0 | 0 | 1 |    0   |    1   |       1       |       1       |
| 0 | 1 | 0 |    1   |    1   |       1       |       1       |
| 0 | 1 | 1 |    1   |    1   |       1       |       1       |
| 1 | 0 | 0 |    1   |    0   |       1       |       1       |
| 1 | 0 | 1 |    1   |    1   |       1       |       1       |
| 1 | 1 | 0 |    1   |    1   |       1       |       1       |
| 1 | 1 | 1 |    1   |    1   |       1       |       1       |

The neutral element is 0: (0 || 0) = 0, and (1 || 0) = 1.

In all of the cases above, commutativity is silently assumed.

4. Represent the `Bool` monoid with the AND operator as a category. List the
   morphisms and their rules of composition.

Let us imagine the `Bool` values (True and False) as a single object category.
This category will have a set of morphisms, following the rules of composition.
The following are the morphisms:
* AND 1
* AND 0
They compose as follows:
* (AND 1) . (AND 0) = (AND 0) . (AND 1) = (AND 0)
The identity is the morphism (AND 1), while the morphism (AND 0) is the
"absorbing" morphism that turns any `Bool` value into 0.

5. Represent addition modulo 3 as a monoid category.

The definition of "addition modulo m" is the following:
a +\_m b = r, for 0 <= r < m

Some examples: 12 +\_3 4 = (12 + 4) mod 3 = 16 mod 3 = 1

Let us think of all integers as a single object. We basically want to
substitute integers with the respective modulo3 n-adders. However, one can
notice that mod3 0 adder is equal to mod3 3 adder, and to mod3 6 adder, and so
on. The adders "repeat", modulo 3. As such, there are only really 3 modulo 3
adders in this monoid. How do these transformations compose?

mod3-0 adder . mod3-1 adder -> mod3-1 adder
mod3-0 adder . mod3-2 adder -> mod3-2 adder
mod3-1 adder . mod3-1 adder -> mod3-2 adder
mod3-1 adder . mod3-2 adder -> mod3-0 adder
mod3-2 adder . mod3-2 adder -> mod3-1 adder

Since addition is commutative, inverting the composition leads to the same
results. By these composition rules, it is also clear that mod3-0 adder is the
identity morphisms in this monoid category.

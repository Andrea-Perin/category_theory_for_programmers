1. Can we turn the `Maybe` type constructor into a functor by defining:

   ```haskell
   fmap _ _ = Nothing
   ```
   
   which ignores both of its arguments? (Hint: Check the functor laws.)

A functor is a mapping between categories which preserves their structures.
Given a functor `F : C -> D`, for objects `a, b, c ∈ C`, connected by morphisms
`f :: a -> b` and `g :: b -> c`, the functor `F` maps them respectively to `Fa,
Fb, Fc ∈ D`, connected by morphisms `Ff :: Fa -> Fb` and `Fg :: Fb -> Fc`. Since
morphisms preserve structure, and `h = g . f`, then it must be true that `Fh =
Fg . Ff`.

Functor laws refer to the function `fmap` preserving composition and identity.
To check this, we will use equational reasoning.

Let us start with the `id` function:

```haskell
fmap id = id

fmap id _ = Nothing
```

Identity is not preserved; as such, this definition of `fmap` does not create a
functor when coupled with the `Maybe` type constructor.

2. Prove functor laws for the reader functor. Hint: it's really simple.

The reader functor is the `(->) a` type constructor. It needs one more type `b`
in order to create a complete type `a -> b`. Its `fmap` has the following
signature and definition:

```haskell
fmap :: (a -> b) -> (r -> a) -> (r -> b)
fmap f g = f . g
```

which means that it takes a function from `a` to `b`, and returns a function
from a function `r->a` to a function `r->b`.

It must preserve identity and composition.
For identity, given any function `g :: r -> a`:
```
fmap id = id

    fmap id g   
 = {definition of fmap}   
    id . g   
 = {definition of identity}   
    g   
```
which holds for any such function `g`.

For composition, given any function `h :: r -> a`:
```
fmap (g . f) = fmap g . fmap f

    fmap (g . f) h   
 = {definition of fmap}   
    (g . f) . h   
 = {composition is associative}   
    g . f . h   
 = {definition of fmap}   
    g . fmap f h   
 = {definition of fmap}   
    fmap g fmap f h   
 = {composability of fmap g and fmap f}   
    fmap g . fmap f h   
```

since `fmap g :: (r->c) -> (r->b)`, and `fmap f :: (r->a) -> (r->c)`, with the
convention that `f :: a->c` and `g :: c->b`.

3. Implement the reader functor in your second favorite language.

See `code_challenge_7.cpp`.

4. Prove the functor laws for the list functor. Assume that the laws are true
   for the tail part of the list you're applying it to (int other words, use
   induction).

For a list, `fmap` is the usual `map`. Let us check identity:
```
fmap id = id?

    fmap id [x : xs]   
    = {definition of fmap}
    [id x : fmap id xs]
    = {definition of id}
    [x : fmap id xs]
    = {inductive assumption}
    [x : xs]
    = {definition of id}
    id [x : xs]
```

Let us check composition:
```
fmap (f . g) = fmap f . fmap g?

    fmap (f . g) [x : xs]
    = {definition of fmap}
    [(f . g)(x) : fmap (f . g) xs]
    = {definition of composition and inductive assumption}
    [f(g(x)) : fmap f . fmap g xs]
    = {definition of fmap}
    [fmap f (g x) : fmap f . fmap g xs]
    = {definition of fmap and composition}
    [fmap f . fmap g x : fmap f . fmap g xs]
    = {definition of fmap}
    fmap f . fmap g [x : xs]
```

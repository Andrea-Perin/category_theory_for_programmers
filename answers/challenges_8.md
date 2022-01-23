1. Show that the data type:
   ```haskell
   data Pair a b = Pair a b
   ```
   is a bifunctor. For additional credit implement all three methods of
   `Bifunctor` and use equational reasoning to show that these definitions are
   compatible with the default implementations whenever they can be applied.

For `Pair` to be a bifunctor, it needs to map the morphisms of the objects in
the pair, as well as the objects themselves to `(a, b)`.
In Haskell, a bifunctor is defined as follows:

```haskell
class Bifunctor f where
    bimap :: (a -> c) -> (b -> d) -> f a b -> f c d
    bimap g h = first g . second h
    first :: (a -> c) -> f a b -> f c b
    first g = bimap g id
    second :: (b -> d) -> f a b -> f a d
    second :: bimap id
```

A `Pair` satisfies these three requirements, with
```haskell
first f (Pair a b) = Pair (f a, b)
second g (Pair a b) = Pair (a, g b)
```
and `bimap` defined accordingly, or, equivalently,
```haskell
bimap g h (Pair a b) = (g a, h b)
```
and `first` and `second` defined accordingly.
To be precise, here are the functions (see also `code_challenge_8.hs`)

```haskell
data Pair a b = Pair a b

first :: (a -> c) -> Pair a b -> Pair c b
first f (Pair x y) = Pair (f x) y

second :: (b -> d) -> Pair a b -> Pair a d
second g (Pair x y) = Pair x (g y)

bimap :: (a -> c) -> (b -> d) -> Pair a b -> Pair c d
bimap f g (Pair x y) = Pair (f x) (g y)
```

2. Show the isomorphisms between the standard definition  of `Maybe` and this
   desugaring:
   ```haskell
   type Maybe' a = Either (Const ()a) (Identity a)
   ```
   Hint: Define two mappings between the two implementations. For additional
   credit, show that they are the inverse of each other using equational
   reasoning.

See `code_challenge_8.hs`.

3. Let's try another data structure. I call it a `PreList` because it's a
   precursor to a `List`. It replaces recursion with a type parameter `b`.
   ```haskell
   data PreList a b = Nil | Cons a b
   ```
   You could recover our earlier definition of a `List` by recursively applying
   `PreList` to itself (we'll see how it's done when we talk about fixed
   points).
   Show that `PreList` is an instance of `Bifunctor`.

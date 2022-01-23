1. Show the isomorphism between `Maybe a` and `Either () a`.

Example of types that are "the same" up to isomorphism. `(a, b) = (b, a)`
through the `swap` isomorphism. The idea is that these two composite data types
actually contain the same information, and the isomorphism serves as a
conversion mechanism: same data, different format.

Is there a translation between `Maybe a` and `Either () a`? We must find a pair
of morphisms that go from one to the other.

```haskell
maybeToEitherUnit :: Maybe a -> Either () a
maybeToEitherUnit (Nothing) = Left ()
maybeToEitherUnit (Just x) = Right x


eitherUnitToMaybe :: Either () a -> Maybe a
eitherUnitToMaybe (Left ()) = Nothing
eitherUnitToMaybe (Right x) = Just x

-- some tests
let ms_j = Just "Hello world!" :: Maybe String
let ms_n = Nothing :: Maybe String

ms_j == eitherUnitToMaybe (maybeToEitherUnit ms_j)
ms_n == eitherUnitToMaybe (maybeToEitherUnit ms_n)


let es_r = Right "Hello world!" :: Either () String
let es_l = Left () :: Either () String

es_r == maybeToEitherUnit (eitherUnitToMaybe es_r)
es_l == maybeToEitherUnit (eitherUnitToMaybe es_l)
```

These two functions are the inverse of each other; thus, `Maybe a` and `Either
() a` are isomorphic. See `code_challenge_6.hs`.

2. Here's a sum type defined in Haskell:
   
   ```haskell
   data Shape = Circle Float
              | Rect Float Float
   ```
   
   When we want to define a function like `area` that acts on a `Shape`, we do
   it by pattern matching on the two constructors:
   
   ```haskell
   area :: Shape -> Float
   area (Circle r) = pi * r * r
   area (Rect d h) = d * h
   ```
   
   Implement `Shape` in C++ or Java as an interface and create two classes:
   `Circle` and `Rect`. Implement `area` as a virtual function.

See `code_challenge_6.cpp`.


3. Continuing with the previous example: We can easily add a new function `circ`
   that calculates the circumference of a `Shape`. We can do it without touching
   the definition of `Shape`:

   ``` haskell
   circ :: Shape -> Float
   circ (Circle r) = 2.0 * pi * r
   circ (Rect d h) = 2.0 * (d + h)
   ```

   Add `circ` to your C++ or Java implementation. What parts of the original
   code did you have to touch?

In order to add `circ`, the definition needs to be added to the abstract class
`Shape` with an "empty" implementation, and to both the concrete classes that
inherit from `Shape`. Thus, some lines need to be added to each derived concrete
class.

4. Continuing further: Add a new shape, `Square`, to `Shape` and make all the
   necessary updates. What code did you have to touch in Haskell vs. C++ or
   Java? (Even if you're not a Haskell programmer, the modifications should be
   pretty obvious.)

In Haskell, we may simply do the following:

```haskell
data Shape = Circle Float
           | Rect Float Float
           | Square Float

circ :: Shape -> Float
circ (Circle r) = 2.0 * pi * r
circ (Rect d h) = 2.0 * (d + h)
circ (Square b) = 4.0 * b

area :: Shape -> Float
area (Circle r) = pi * r * r
area (Rect d h) = d * h
area (Square b) = b * b
```

while in C++ we need an additional derived class altogether, with a much more
verbose syntax.


5. Show that _a + a = 2 x a_ holds for types (up to isomorphism). Remember that
   _2_ corresponds to `Bool`, according to our translation table.

The coproduct of two types _a_ is the disjoint union of the two types. As an
example, the coproduct of two `Int` is simply an instance of `Either Int Int`.
Thinking about its C++ implementation, such a type is a tagged union, where the
tag is used to distinguish between the types of the actual contents of the
`Either` functor (or, in case of identical types, to "label" the "copy" of the
type from which the value comes). Indeed, the tagged union is an example of a
product type, that is, a `struct` with two fields, one of type `Int` and another
of type `Bool`. This shows that the type equation holds.

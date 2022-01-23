1. Construct the Kleisli category for partial functions (define composition and
   the identity).

In order to define a Kleisli category, we need to define composition and
identity.
For an embellished function like the following:
```cpp

template<class A> class optional {
    bool _isValid;
    A _value;
public:
    optional() : _isValid(false) {}
    optional(A v) : _isValid(true), _value(v) {}
    bool isValid() const { return _isValid; }
    A value() const { return _value; }
};

optional<double> safe_root(double x)
{
    if (x>=0) return optional<double>{sqrt(x)};
    else return optional<double>{};
}
```

a possible composition rule is the following:

```cpp
// using templates
template<class A, class B, class C>
std::function<optional<C>(A)> compose(std::function<optional<B>(A)> f,
                                      std::function<optional<C>(B)> g)
{
    return [f, g](A x) {
        auto p1 = f(x);
        if p1.isValid() return g(p1.value());
        else return optional<C>{};
    };
}

// using auto stuff
auto const compose = [](auto m1, auto m2){
    return [m1, m2](auto x) {
        auto p1 = m1(x);
        if p1.isValid() return m2(p1.value());
        else return p1;
    };
};
```

The identity is instead:

```cpp
template<class T> 
optional<T> id(T x) {
    return optional<T>{x};
}
```

2. See `code_challenge_4.cpp`
3. See `code_challenge_4.cpp`

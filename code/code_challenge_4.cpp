#include <cmath>
#include <functional>
#include <iostream>

// optional, hand made
template <class A> class optional {
  bool _isValid;
  A _value;

public:
  optional() : _isValid(false) {}
  optional(A v) : _isValid(true), _value(v) {}
  bool isValid() const { return _isValid; }
  A value() const { return _value; }
};

// composition, using templates; does not work, apparently
template <class A, class B, class C>
std::function<optional<C>(A)> compose(std::function<optional<B>(A)> f,
                                      std::function<optional<C>(B)> g) {
  return [f, g](A x) {
    auto p1 = f(x);
    return (p1.isValid()) ? g(p1.value()) : optional<C>();
  };
}

// composition, using auto stuff
auto const compose_lambda = [](auto f, auto g) {
  return [f, g](auto x) {
    auto y = f(x);
    return (y.isValid()) ? g(y.value()) : y;
  };
};

// identity
template <class T> optional<T> id(T x) { return optional<T>{x}; }

// safe functions
optional<double> safe_root(double x) {
  return (x >= 0) ? optional<double>(sqrt(x)) : optional<double>();
}

optional<double> safe_reciprocal(double x) {
  return (x != 0) ? optional<double>(1. / x) : optional<double>();
}

int main() {
  // composition of safe_root and safe_reciprocal
  auto safe_root_reciprocal_lambda = compose_lambda(safe_reciprocal, safe_root);

  std::cout << safe_root_reciprocal_lambda(1.).value() << "\n";
  std::cout << safe_root_reciprocal_lambda(2.).value() << "\n";
  std::cout << safe_root_reciprocal_lambda(4.).value() << "\n";
  std::cout << safe_root_reciprocal_lambda(0.).value() << "\n";
}

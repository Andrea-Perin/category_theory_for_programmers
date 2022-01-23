#include <functional>
#include <iostream>

auto const compose = [](auto f, auto g) {
  return [f, g](auto x) { return f(g(x)); };
};

// (->) r
// This is a reader functor. We need a template on r and a
template <typename R> struct reader {
  template <typename A, typename B>
  std::function<B(R)> fmap(std::function<B(A)> a_to_b,
                           std::function<A(R)> r_to_a) {
    return compose(a_to_b, r_to_a);
  }

  // template <typename A, typename B>
  // std::function<std::function<B(R)>(std::function<B(R)>)> fmap_curry(std::function<B(A)> a_to_b) {
  //   return [=](std::function<A(R)> r_to_a) {
  //     return [=](auto x) -> std::function<B(R)> { return a_to_b(r_to_a(x)); };
  //   };
  // }
};

int main() {
  reader<int> myreader;
  std::function<double(int)> int_to_double = [](int x) { return double(x); }; // a_to_b
  std::function<int(int)> int_square = [](int x) { return x*x; }; // r_to_a
  auto fmapped = myreader.fmap(int_to_double, int_square);
  std::cout << fmapped(12) << "\n";
  std::cout << fmapped(1) << "\n";
  std::cout << fmapped(-12) << "\n";
  std::cout << fmapped(-1) << "\n";
  std::cout << fmapped(0) << "\n";
}

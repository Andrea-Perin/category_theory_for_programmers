#include <cstdio>
#include <functional>
#include <iostream>
#include <unordered_map>

template <class OUT, class IN> struct memoize {
  std::unordered_map<IN, OUT> cache;
  OUT (*fun)(IN);

  memoize(OUT (*fun)(IN)) : fun(fun) {}
  OUT operator()(IN x) {
    if (cache.find(x) == cache.end())
      cache[x] = fun(x);
    return cache[x];
  }
};

int fact(int n) {
  int i;
  int result = 1;
  for (i = 2; i <= n; ++i)
    result *= i;
  return result;
}

bool f_1() {
  std::cout << "Hello!" << std::endl;
  return true;
}

int f_2(int x) {
  static int y = 0;
  y += x;
  return y;
}

int main() {

  memoize<int, int> memo_fact = memoize<int, int>(fact);
  // getchar cannot be memoized using the syntax above
  // neither can f_1
  // However, they are both functions from unit. This is not a problem for f_1
  // (however it has side effects), but it is a problem for getchar.
  memoize<int, int> memo_f_2 = memoize<int, int>(f_2);

  std::cout << memo_f_2(2) << "\n";
  std::cout << memo_f_2(2) << "\n";

  for (int i = 0; i < 10; ++i) {
    std::cout << memo_fact(i) << ", " << memo_f_2(i) << '\n';
  }

  std::cout << memo_f_2(2) << "\n";
  std::cout << memo_f_2(2) << "\n";

  return 0;
}

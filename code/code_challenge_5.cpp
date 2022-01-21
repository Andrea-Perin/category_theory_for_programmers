#include <iostream>
#include <variant>

template <class L, class R> struct Either {
    // Either as a tagged union
    enum tag_t {isLeft, isRight} tag;
    union { L l; R r; };
    // Constructors as injections
    Either() {}
    Either(L l) : l(l), tag(isLeft) {}
    Either(R r) : r(r), tag(isRight) {}
    L get_left() { return l; }
    R get_right() { return r; }
};

template <class L, class R>
std::ostream& operator<<(std::ostream& os, Either<L, R>& eith)
{
    os << "(tag: " << eith.tag << ", val: ";
    if (eith.tag == eith.isLeft)
        os << eith.get_left() << ")";
    else
        os << eith.get_right() << ")";
    return os;
}

int main()
{
    Either<int, double> some_number_1, some_number_2;
    some_number_1 = 2;
    some_number_2 = 2.1;
    
    std::cout << some_number_1 << "\n";
    std::cout << some_number_2 << "\n";
}

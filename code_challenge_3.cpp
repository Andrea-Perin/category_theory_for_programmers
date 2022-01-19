#include <iostream>

struct T1 {
    int elem_1;
    T1(int elem_1) : elem_1(elem_1) {}
};

struct T2 : public T1 {
    int elem_2;
    T2(int elem_1, int elem_2) : T1(elem_1), elem_2(elem_2) {}
};

struct T3 : public T2 {
    int elem_3;
    T3(int elem_1, int elem_2, int elem_3) : T2(elem_1, elem_2), elem_3(elem_3) {}
};


int double_elem_from_T1(T1* pointer_to_T1)
{
    return pointer_to_T1->elem_1*2;
}

int double_elem_from_T2(T2* pointer_to_T2)
{
    return pointer_to_T2->elem_2*2;
}

int double_elem_from_T3(T3* pointer_to_T3)
{
    return pointer_to_T3->elem_3*2;
}


int main() {
    T1 t_1 = T1(4);
    T2 t_2 = T2(5, 7);
    T3 t_3 = T3(5, 7, 88);

    // auto out = double_elem_from_T2(&t_1);
    auto out_1_from_2 = double_elem_from_T1(&t_2);
    // In this case, T2 is a subtype of T1:
    // a function that expects a pointer to T1 is given a pointer to T2.
    // No errors are detected.
    auto out_1_from_3 = double_elem_from_T1(&t_3);
    // In this case, T3 is a subtype of T1:
    // a function that expects a pointer to T1 is given a pointer to T3.
    // No errors are detected.
}

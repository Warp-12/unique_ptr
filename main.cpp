#include <iostream>

#include "uniquePtr.hpp"

struct X {};
struct Y : public X {};

int main() {
    unique_ptr<X> x(new X);
    unique_ptr<Y> y(new Y);

    return 0;
}
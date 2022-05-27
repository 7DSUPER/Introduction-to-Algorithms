#include "vector.h"
#include <iostream>

int main() {
    
    Vector<int> a;
    std::cout << a.size() << std::endl;
    std::cout << a.capcity() << std::endl;
    return 0;
}
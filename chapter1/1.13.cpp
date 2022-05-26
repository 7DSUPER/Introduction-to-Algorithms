#include <iostream>
#include "1.13.h"

using std::vector;
using std::cout;
using std::endl;

int main() {

    Collection<int> col;

    cout << col.isEmpty() << endl;
    int i = 1, j = 2;
    col.insert(i);
    col.insert(j);
    cout << col.isEmpty() << endl;
    col.remove();
    cout << col.contains(1) << endl;
    col.makeEmpty();
    cout << col.isEmpty() << endl;

    return 0;
}
#ifndef ORDEREDCOMPARABLE_H
#define ORDEREDCOMPARABLE_H

#include <iostream>
#include <vector>

using std::vector;

template <class Comparable>
class orderedComparable {
private:
    vector<Comparable> obj;
public:
    orderedComparable();
    ~orderedComparable();
    bool isEmpty();
    void makeEmpty();
    void insert(Comparable &x);
    void remove();
    Comparable findMin();
    Comparable findMax();
};

template <class Comparable>
orderedComparable<Comparable>::orderedComparable() : obj(0) {}

template <class Comparable>
orderedComparable<Comparable>::~orderedComparable() {}

template <class Comparable>
bool orderedComparable<Comparable>::isEmpty() {
    return obj.size() == 0;
}

template <class Comparable>
void orderedComparable<Comparable>::makeEmpty() {
    while (!this->isEmpty()) {
        this->remove();
    }
}

template <class Comparable>
void orderedComparable<Comparable>::insert(Comparable &x) {
    obj.push_back(x);
}

template <class Comparable>
void orderedComparable<Comparable>::remove() {
    if (!this->isEmpty()) {
        this->obj.pop_back();
    }
}

template <class Comparable>
Comparable orderedComparable<Comparable>::findMin() {
    if (this->isEmpty()) {
        cout << "Empty Object!!!" << endl;
        exit(1);
    }
    Comparable min = obj[0];
    for (int i = 0; i < this->obj.size(); i++) {
        if (obj[i] < min)
            min = obj[i];
    }
    return min;
}

template <class Comparable>
Comparable orderedComparable<Comparable>::findMax() {
    if (this->isEmpty()) {
        cout << "Empty Object!!!" << endl;
        exit(1);
    }
    Comparable max = obj[0];
    for (int i = 0; i < this->obj.size(); i++) {
        if (obj[i] > max)
            max = obj[i];
    }
    return max;
}

#endif
#include <iostream>
#include <vector>

using std::vector;

template <class Object>
class Collection {
private:
    vector<Object> obj;
public:
    Collection();
    ~Collection();
    bool isEmpty();
    void makeEmpty();
    void insert(Object &x);
    void remove();
    bool contains(Object x);
};

template <class Object>
Collection<Object>::Collection() : obj(0) {}

template <class Object>
Collection<Object>::~Collection() {}

template <class Object>
bool Collection<Object>::isEmpty() {
    return obj.size() == 0;
}

template <class Object>
void Collection<Object>::makeEmpty() {
    while (!this->isEmpty()) {
        this->remove();
    }
}

template <class Object>
void Collection<Object>::insert(Object &x) {
    obj.push_back(x);
}

template <class Object>
void Collection<Object>::remove() {
    if (!this->isEmpty()) {
        this->obj.pop_back();
    }
}

template <class Object>
bool Collection<Object>::contains(Object x) {
    for (int i = 0; i < this->obj.size(); i++) {
        if (x == this->obj[i])
            return true;
    }
    return false;
}
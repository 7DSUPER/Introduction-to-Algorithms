#ifndef __VECTOR__H__
#define __VECTOR__H__

#include <cstddef>

template <class Object>
class Vector
{
private:
    int TheSize;
    int TheCapcity;
    Object *objects;
public:
    enum { INITSIZE = 16 };
    Vector(int initSize = 0) : TheSize(initSize), TheCapcity(initSize + INITSIZE) {
        objects = new Object[TheCapcity];
    }
    Vector(const Vector &rhs) : objects(NULL) {
        operator=(rhs);
    }
    ~Vector() {
        delete [] objects;
    }
    Vector operator = (const Vector &rhs) {
        delete [] objects;
        TheSize = rhs.size();
        TheCapcity = rhs.TheCapcity;
        objects = new Object[TheCapcity];
        for (int i = 0; i < TheSize; i++) {
            objects[i] = rhs.objects[i];
        }
    }
    void reserve(int NewCapcity) {
        if (NewCapcity < TheSize) {
            return ;
        }
        Object *oldObject = objects;
        objects = new Object[NewCapcity];
        for (int i = 0; i < oldObject.size(); i++) {
            objects[i] = oldObject[i];
        }
        TheCapcity = NewCapcity;
        delete [] oldObject;
    }
    void resize(int NewSize) {
        if (NewSize > TheCapcity) {
            reserve(NewSize * 2 + 1);
        }
        TheSize = NewSize;
    }
    Object & operator [] (int index) {
        return objects[index];
    }
    const Object & operator [] (int index) const {
        return objects[index];
    }
    bool Empty() const {
        return objects.size() == 0;
    }
    int size() const {
        return TheSize;
    }
    int capcity() const {
        return TheCapcity;
    }
    void push_back(const Object & val) {
        if (TheSize == TheCapcity) {
            reserve(TheCapcity * 2 + 1);
        }
        objects[TheSize++] = val;
    }
    void pop_back() {
        TheSize--;
    }
    const Object & back() {
        return objects[TheSize - 1];
    }

    typedef Object * iterator;
    typedef const Object * const_iterator;

    iterator begin() {
        return objects;
    }
    iterator end() {
        return objects + TheSize;
    }
    const_iterator Cbegin() const {
        return objects;
    }
    const_iterator Cend() const {
        return objects + TheSize;
    }
};


#endif


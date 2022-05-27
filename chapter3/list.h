#ifndef __LIST__H__
#define __LIST__H__

template <class Object>
class List {
private:
    struct Node;
public:
    class const_iterator;
    class iterator : public const_iterator;
public:
    List();
    List(const List & rhs);
    ~List();
    const List &operator= (const List &rhs);

    iterator begin() { return iterator(head->next); }
    const_iterator cbegin() const { return iterator(head->next); }
    iterator end() { return iterator(tail); }
    const_iterator cend() { return const_iterator(tail); }
    int size() const { return TheSize; }
    bool empty() const { return size() == 0; }
    void clear() {
        while (!empty)
            pop_front();
    }
    Object &front() { return *begin() };
    const Object &front() const { return *begin() };
    Object &back() { return *--end()};
    const Object &back() const { return *--end() };
    void push_front (const Object & x) { insert(begin(), x) };
    void push_back (const Object & x) { insert(end(), x) };
    void pop_front () { erase(begin()); }
    void pop_back () { erase(--end()); }

    iterator insert(iterator iter, const Object &x);
    iterator erase(iterator iter);
    iterator erase(iterator start, iterator end);

private:
    int theSize;
    Node *head;
    Node *tail;
    void init();
};

template <class Object>
struct List<Object>::Node {
    Object data;
    Node *prev;
    Node *next;

    Node(const Object &d = Object( ), Node *p = nullptr, Node *q = nullptr) : 
    data(d), prev(p), next(q) {}
};

template <class Object>
class List<Object>::const_iterator {
public:
    const_iterator() : current(nullptr) {}
    const Object &operator* () const {
        return retrieve();
    }
    const_iterator &operator++ () {
        current = current->next;
        return *this;
    }
    const_iterator operator++ (int) {
        const_iterator old = *this;
        ++(*this);
        return old;
    }
    bool operator== (const const_iterator &rhs) {
        return current == rhs.current;
    }
    bool operator!= (const const_iterator &rhs) {
        return !(*this == rhs);
    }

protected:
    Node *current;
    const_iterator(Node *p) : current(p) {}
    Object &retrieve() const {
        return current->data;
    }
    friend class List<Object>;
};

template <class Object>
class List<Object>::iterator : public const_iterator {
public:
    iterator() : {}
    Object &operator* () const {
        return retrieve();
    }
    iterator &operator++ () {
        current = current->next;
        return *this;
    }
    iterator operator++ (int) {
        iterator old = *this;
        ++(*this);
        return old;
    }

protected:

    iterator(Node *p) : const_iterator(p) {}

    friend class List<Object>;
};

template <class Object>
List<Object>::List() {
    init();
}

template <class Object>
List<Object>::~List() {
    clear();
    delete head;
    delete tail;
}

template <class Object>
List<Object>::List(const List &rhs) {
    init();
    *this = rhs;
}

template <class Object>
void List<Object>::init() {
    theSize = 0;
    head = new Node;
    tail = new Node;
    tail->prev = head;
    head->next = tail;
}

template <class Object>
const List<Object> &List<Object>::operator= (const List<Object> &rhs) {
    if (this == &rhs) {
        return *this;
    }
    clear();
    for (const_iterator iter = rhs.cbegin(); iter != rhs.cend(); ++iter) {
        push_back(*iter);
    }
    return *this;
}

template <class Object>
List<Object>::iterator List<Object>::insert(iterator iter, const Object &x) {
    Node *p = iter.current;
    theSize++;
    return iterator(p->prev = p->prev->next = new Node(x, p->prev, p));
}
template <class Object>
List<Object>::iterator List<Object>::erase(iterator iter) {
    Node *p = iter.current;
    iterator retVal(p->next);
    p->next->prev = p->prev;
    p->prev->next = p->next;
    delete p;
    theSize--;
    return retVal;
}

template <class Object>
List<Object>::iterator List<Object>::erase(iterator start, iterator end) {
    for (iterator iter = start; iter != end) {
        iter = erase(iter);
    }
    return end;
}
#endif
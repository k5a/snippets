#ifndef __SNIPPETS_LIST_HPP__
#define __SNIPPETS_LIST_HPP__

namespace snippets {
template <typename T>
struct Node {
    Node *next;
    T value;
};

template <typename T>
class List {
public:
    typedef T ValueType;
    List(): head_(nullptr), tail_(nullptr), size_(0) {}
    const T& PopFront();
    const T& PopBack();
    void PushFront(const T& item);
    void PushBack(const T& item);
private:
    Node<T> *head_;
    Node<T> *tail_;
    std::size_t size_;
}
}

#endif  // __SNIPPETS_LIST_HPP__

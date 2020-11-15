#include <memory>
#include <algorithm>
#include <iostream>

template <class T>
class TVector{
private:
    unsigned long long TVectorSize;
    unsigned long long TVectorCapacity;
    std::shared_ptr<T> Data;

public:
    TVector();
    unsigned long long Size();
    void PushBack(const T elem);
    void PopBack();
    void Insert(const unsigned long long &pos,const T &elem);
    void OrdinaryInsert (const T &elem);
    void Erase(const unsigned long long &pos);
    T& operator[] (long long iterator);

    class ForwardIterator{
    private:
        std::shared_ptr<T> Iterator;
        unsigned long long Index;
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T ;
        using pointer = T*;
        using reference = T&;
        ForwardIterator();
        ForwardIterator(const std::shared_ptr<T> &shPtr, unsigned long long ind);
        ForwardIterator& operator++();
        friend bool operator!= (const ForwardIterator &lhs, const ForwardIterator &rhs);
        T& operator* ();
    };


    ForwardIterator begin(){
        return ForwardIterator(Data, 0);
    }
    TVector<T>::ForwardIterator end(){
        return ForwardIterator(Data, TVectorSize);
    }
};

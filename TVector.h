//группа М8О-107Б-19 Федоров Антон Сергеевич
//вариант 30 5-угольник динамический массив

#include <memory>
#include <algorithm>
#include <iostream>

template <class T>
class TVector{
private:
    unsigned long long TVectorSize;
    unsigned long long TVectorCapacity;
    std::shared_ptr<T[]> Data;

public:
    TVector();
    unsigned long long Size();
    void PushBack(const T elem);
    void PopBack();
    T& operator[] (long long iterator);

    class ForwardIterator{
    private:
        std::shared_ptr<T[]> Iterator;
        unsigned long long index;
        unsigned long long Size;
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T ;
        using pointer = T*;
        using reference = T&;
        ForwardIterator(): Iterator(nullptr) {
            index = 0;
        };
        ForwardIterator(const std::shared_ptr<T[]> &shPtr, unsigned long long ind, unsigned long long Size): Iterator(shPtr), Size(Size){
            index = ind;
        };
        T& operator* (){
            return Iterator[index];
        }
        ForwardIterator& operator++(){
            if (index + 1 > Size)
                throw std::out_of_range("Iterator cannot be incremented past the end of range.");
            ++index;
            return *this;
        }
        bool operator != (const ForwardIterator & rhs) {
            return this->index != rhs.index;
        }
        friend class TVector<T>;
    };
    ForwardIterator begin(){
        return ForwardIterator(Data,0,TVectorSize);
    }
    ForwardIterator end(){
        return ForwardIterator(Data,TVectorSize,TVectorSize);
    }
    void Insert(ForwardIterator Iterator, T elem);
    void Erase(ForwardIterator Iterator);
};



template <class T>
TVector<T>::TVector(){
    TVectorSize = 0;
    TVectorCapacity = 0;
    Data = nullptr;
}
template <class T>
unsigned long long TVector<T>::Size(){
    return TVectorSize;
}
template <class T>
void TVector<T>::PushBack(const T elem){
    if (TVectorCapacity == 0){
        TVectorCapacity = 1;
        TVectorSize = 0;
        Data = std::move(std::unique_ptr<T[]>{new T[TVectorCapacity]});
    }
    else if (TVectorCapacity == TVectorSize){
        TVectorCapacity *= 2;
        std::shared_ptr<T[]> newData{new T[TVectorCapacity]};
        for (unsigned long long i = 0; i < TVectorSize; ++i){
            newData[i] = Data[i];
        }
        Data = newData;
    }
    TVectorSize += 1;
    Data[TVectorSize - 1] = elem;
}
template<class T>
void TVector<T>::PopBack() {
    if (TVectorSize > 0){
        --TVectorSize;
        if (TVectorSize < TVectorCapacity / 2){
            TVectorCapacity /= 2;
            std::shared_ptr<T[]> newData(new T[TVectorCapacity]);
            for (unsigned long long i = 0; i < TVectorSize; ++i){
                newData[i] = Data[i];
            }
            Data = newData;
        }
    }
}
template<class T>
void TVector<T>::Insert(ForwardIterator Iterator, T elem){
    unsigned long long pos = Iterator.index;
    if (pos > TVectorSize){
        std::cout << "incorrect position to insrt\n";
        return;
    }
    PushBack(T());
    for (unsigned long long i = TVectorSize - 1; i > pos; --i){
        Data[i] = Data.get()[i-1];
    }
    Data[pos] = elem;
}
template<class T>
void TVector<T>::Erase(ForwardIterator Iterator){
    unsigned long long pos = Iterator.index;
    if (pos >= TVectorSize){
        throw std::out_of_range("Erase position out of range.");
    }
    for (unsigned long long i = pos; i < TVectorSize - 1; ++i){
        Data[i] = Data[i+1];
    }
    PopBack();
}
template <class T>
T& TVector<T>::operator[] (const long long iterator){
    return Data[iterator];
}



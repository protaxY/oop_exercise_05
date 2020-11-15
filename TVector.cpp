#include "TVector.h"


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
        Data = new T[TVectorCapacity];
    }
    else if (TVectorCapacity == TVectorSize){
        TVectorCapacity *= 2;
        T* newData = new T[TVectorCapacity];
        for (unsigned long long i = 0; i < TVectorSize; ++i){
            newData[i] = Data[i];
        }
        delete [] Data;
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
            T* newData = new T[TVectorCapacity];
            for (unsigned long long i = 0; i < TVectorSize; ++i){
                newData[i] = Data[i];
            }
            delete [] Data;
            Data = newData;
        }
    }
}
template<class T>
void TVector<T>::Insert(const unsigned long long &pos, const T &elem) {
    if (pos > TVectorSize){
        std::cout << "incorrect position to insrt\n";
        return;
    }
    PushBack(T());
    for (unsigned long long i = TVectorSize - 1; i > pos; --i){
        Data[i] = Data[i-1];
    }
    Data[pos] = elem;
}
template<class T>
void TVector<T>::OrdinaryInsert(const T &elem) {
    unsigned long long l = 0;
    unsigned long long r = TVectorSize;
    unsigned long long m;
    while (l < r){
        m = (l + r) / 2;
        if (Data[m] < elem){
            l = m + 1;
        } else {
            r = m;
        }
    }
    Insert(l, elem);
}
template<class T>
void TVector<T>::Erase(const unsigned long long int &pos) {
    if (pos >= TVectorSize){
        std::cout << "incorrect position to insrt\n";
        return;
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
template<class T>
TVector<T>::ForwardIterator::ForwardIterator(): Iterator(nullptr){
    Index = 0;
}
template<class T>
TVector<T>::ForwardIterator::ForwardIterator(const std::shared_ptr<T> &shPtr, unsigned long long int ind): Iterator(shPtr){
    Index = ind;
}
template<class T>
typename TVector<T>::ForwardIterator &TVector<T>::ForwardIterator::operator++() {
    if ((Iterator + 1) * sizeof(T) >= sizeof(*Iterator)){
        throw std::out_of_range("Iterator cannot be incremented past the end of range.");
    }
    ++Index;
    return *this;
}
template<class T>
bool operator!= (const typename TVector<T>::ForwardIterator &lhs, const typename TVector<T>::ForwardIterator &rhs){
    return lhs.Iterator != rhs.Iterator;
}
template<class T>
T &TVector<T>::ForwardIterator::operator*(){
    return Iterator.get()[Index];
}

//template<class T>
//typename TVector<T>::ForwardIterator begin(){
//    return ForwardIterator(TVector<T>::Data, 0);
//}
//template<class T>
//typename TVector<T>::ForwardIterator end() {
//    return ForwardIterator(TVector<T>::Data, TVector<T>::TVectorSize);
//}


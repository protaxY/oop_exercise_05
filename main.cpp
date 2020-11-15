//вариант 30 5-угольник динамический массив

#include <algorithm>
#include "Pentagon.h"
#include "TVector.h"

int main() {
    TVector<int> arr;
    for (int i=0; i<10; ++i){
        arr.PushBack(i);
    }

    auto print = [](const int& obj){
        std::cout << obj << " ";
    };

    std::for_each(arr.begin(),arr.end(), print);

    return 0;
}

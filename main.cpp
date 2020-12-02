//вариант 30 5-угольник динамический массив
//Федоров Антон Сергеевич М8О-107Б-19

#include <algorithm>
#include "Pentagon.h"
#include "Cord.h"
#include "TVector.h"

int main() {
    TVector<Pentagon> arr;
    char function;
    while (std::cin >> function){
        try{
            if (function == '+'){
                std::cout << "enter position for insert:";
                unsigned int pos;
                std::cin >> pos;
                std::cout << "enter pentagon center cords and radius:";
                int x,y;
                std::cin >> x >> y;
                Cord center(x,y);
                int radius;
                std::cin >> radius;
                if (radius < 0){
                    std::cout << "incorrect radius\n";
                    break;
                }
                Pentagon newElem(center, radius);
                TVector<Pentagon>::ForwardIterator iterator = arr.begin();
                for (int i=0; i<pos; ++i){
                    ++iterator;
                }
                arr.Insert(iterator, newElem);
            }
            if (function == '-'){
                std::cout << "enter position for delete:";
                unsigned int pos;
                std::cin >> pos;
                TVector<Pentagon>::ForwardIterator iterator = arr.begin();
                for (int i=0; i<pos; ++i){
                    ++iterator;
                }
                arr.Erase(iterator);
            }
            if (function == 's'){
                auto print = [](Pentagon &obj){
                    obj.print();
                };
                std::for_each(arr.begin(),arr.end(), print);
            }
            if (function == 't'){
                std::cout << "enter area value for check:";
                double area;
                std::cin >> area;
                if (area < 0){
                    std::cout << "incorrect area\n";
                }
                auto check = [area](Pentagon &obj){
                    if (obj.Area() < area){
                        obj.print();
                    }
                    return obj.Area() < area;
                };
                std::count_if(arr.begin(), arr.end(), check);
            }
        }
        catch (std::exception &e){
            std::cout << e.what();
        }
    }
    return 0;
}

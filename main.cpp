#include <iostream>
#include <vector>

std::vector<int> sort(std::vector<int> vec)
{
if (vec.size() < 2) return vec; // Условие выхода из рекурсии если в векторе 1 элемент
if (vec.size() < 3) // Условие выхода если 2 элемента которые меняются местами в зависимости от старшенства
{
    if (*vec.begin()>*(vec.end()-1))
    {
        std::swap(*vec.begin(), *(--vec.end()));
    }
    return vec;
}

/*auto begin = vec.begin(); Это пока не пригодилось, но пусть пока будет)
auto end = vec.end();*/

int pivot;
pivot= vec[(vec.size())/2-1]; // В качестве опорного элемента решил брать центральный элемент
std::vector<int> left; // Вектор для чисел меньше опорного элемента
std::vector<int> right; // И для чисел больше него

    for (int i : vec) { // Пробегаемся по вектору
        if (i < pivot) // Всё что меньше пивота - налево
            left.push_back(i);
        if (i >= pivot) // Всё что больше направо
            right.push_back(i);
    }
    left = sort(left); // Рекурсия для меньших чисел
    right = sort(right); // Рекурсия для больших
    left.insert(left.end(), right.begin(),right.end()); //Соединяем получившиеся вектора - в конец меньшего дописываем больший
    return left; // Возвращаем то что получилось


}

void Qsort(std::vector<int> & v) // Это функция - буфер, она для того чтобы при выполнении сортировки ничего не нужно было куда-то возвращать вектор
{
    v = sort(v);
}




int main()
{
    std::vector<int> first{9,19,8,31,13,11,12,15,14,31,45,677,0,0,11,11,22,33,33};
    for(int i : first)
        std::cout << i << std::endl;
    Qsort(first);
    std::cout << std::endl << "-------------------------------------------------" << std::endl;
    for(int i : first)
        std::cout << i << std::endl;


}
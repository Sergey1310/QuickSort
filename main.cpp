#include <iostream>
#include <vector>

std::vector<int> sort(std::vector<int> vec)
{
if (vec.size() < 2) return vec;
if (vec.size() < 3)
{
    if (*vec.begin()>*(vec.end()-1))
    {
        std::swap(*vec.begin(), *(--vec.end()));
    }
    return vec;
}

auto begin = vec.begin();
auto end = vec.end();

int pivot;
pivot= vec[(vec.size())/2-1];
std::vector<int> left;
std::vector<int> right;

    for (int i : vec) {
        if (i < pivot)
            left.push_back(i);
        if (i >= pivot)
            right.push_back(i);
    }
    left = sort(left);
    right = sort(right);
    left.insert(left.end(), right.begin(),right.end());
    return left;


}

void Qsort(std::vector<int> & v)
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
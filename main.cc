#include <iostream>
#include "vector.hpp"

int main()
{
    rabbit::vector<int> test_vec(10);
    for (int i = 0; i < 10; i++)
        test_vec.push_back(i);

    for (int i = 0; i < 11; i++)
        std::cout << test_vec[i] <<std::endl;
}

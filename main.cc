#include <iostream>
#include "vector.hpp"
#include "logger.hpp"
#include "stack.hpp"

void test_vector(){
    fprintf(stderr, "-------------test vector--------------");
    rabbit::vector<int> test_vec(10);
    for (int i = 0; i < 10; i++)
        test_vec.push_back(i);

    for (int i = 0; i < 11; i++)
        std::cout << test_vec[i] <<std::endl;
}

void test_stack(){
    fprintf(stderr, "------------test stack------------");
    rabbit::stack<int> my_stack;
    for (int i = 0; i < 10; i++) {
        my_stack.push(i);
    }

    for (int i = 0; i < 10; i++) {
        int top_value = my_stack.top();
        fprintf(stderr, "top value %d", top_value);
        my_stack.pop();
    }
}

int main()
{
    test_vector();
    test_stack();
    return 0;
}

#include <iostream>
#include "vector.hpp"
#include "logger.hpp"
#include "stack.hpp"

void test_vector(){
    fprintf(stderr, "-------------test vector--------------\n");
    rabbit::vector<int> test_vec(10);
    for (int i = 0; i < 10; i++)
        test_vec.push_back(i);

    for (int i = 0; i < 10; i++)
        std::cout << test_vec[i] <<std::endl;
}

void test_stack(){
    fprintf(stderr, "------------test stack------------\n");
    rabbit::stack<int> my_stack;
    for (int i = 0; i < 10; i++) {
        my_stack.push(i);
    }

    for (int i = 0; i < 10; i++) {
        int top_value = my_stack.top();
        fprintf(stderr, "top value %d\n", top_value);
        my_stack.pop();
    }
}

void test_logger(){
    rabbit::logger::init();
    rabbit::logger::set_log_level(rabbit::FATAL);
    rabbit::logger::set_file(stderr);
    rabbit::logger::info("hello, i am logger! log level: %s", "fatal");
    rabbit::logger::set_log_level(rabbit::INFO);
    rabbit::logger::info("hello, i am logger! log level: %s", "info");
}

int main()
{
    test_vector();
    test_stack();
    test_logger();
    return 0;
}

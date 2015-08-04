#include <iostream>
#include "vector.hpp"
#include "logger.hpp"
#include "stack.hpp"
#include "queue.hpp"

void test_vector(){
    rabbit::logger::info("-----------test vector--------------");
    rabbit::vector<int> test_vec(10);
    for (int i = 0; i < 10; i++)
        test_vec.push_back(i);

    for (int i = 0; i < 10; i++)
        std::cout << test_vec[i] <<std::endl;
}

void test_stack(){
    rabbit::logger::info("----------- test stack ---------------");
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

void test_queue(){
    rabbit::logger::info("------------- test queue -------------------");
    rabbit::queue<int, 10> my_queue, third_queue;

    for(int i = 0; i < 5; i++)
        my_queue.push(i);
    rabbit::queue<int, 10> ano_queue(my_queue);

    for (int j = 0; j < 5; j++)
    {
        int ele = my_queue.front();
        my_queue.pop();
        rabbit::logger::info("pop element from my_queue %d", ele);
    }

    while (!ano_queue.empty()) {

        int ele = ano_queue.front();
        ano_queue.pop();
        rabbit::logger::info("pop element from ano_queue %d", ele);
    }

    third_queue = my_queue;
    while (!third_queue.empty()) {

        int ele = third_queue.front();
        third_queue.pop();
        rabbit::logger::info("pop element from third_queue %d", ele);
    }

}


void test_logger(){
    rabbit::logger::init();
    rabbit::logger::set_log_level(rabbit::FATAL);
    rabbit::logger::set_file(stderr);
    rabbit::logger::fatal("hello, i am logger! log level: %s", "fatal");
//    rabbit::logger::set_log_level(rabbit::INFO);
//    rabbit::logger::info("hello, i am logger! log level: %s", "info");
}

int main()
{
    test_logger();
    test_vector();
    test_stack();
    test_queue();
    return 0;
}

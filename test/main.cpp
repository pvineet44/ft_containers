#include "Test.hpp"

int main()
{
    test_stack();
    test_queue();
    test_vector();
    test_list();
    test_map();
    std::cout << "\033[01;32m \nAll tests ran successfully!" << std::endl;
}
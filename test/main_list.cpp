#include "Test.hpp"

static void test_pushback()
{
    ft::List<ConstrCounter> lst;
	assert(lst.size() == 0);

	lst.push_back(ConstrCounter(0));
	assert(lst.size() == 1);
	assert(lst.back().val == 0);

	lst.push_back(ConstrCounter(1));
	assert(lst.size() == 2);
	assert(lst.back().val == 1);

	lst.push_back(ConstrCounter(8000));
	assert(lst.size() == 3);
	assert(lst.back().val == 8000);

	lst.push_back(ConstrCounter(33));
	assert(lst.size() == 4);
	assert(lst.back().val == 33);
}

void test_list()
{
    test_one("push_back", test_pushback);
}
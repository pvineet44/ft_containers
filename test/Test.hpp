#ifndef TEST_HPP
# define TEST_HPP
# include "../List.hpp"
#include <iostream>
#include <assert.h>

class ConstrCounter
{
    public:
        static int g_constr;
        static int g_destr;

        int val;

        ConstrCounter(int val);
        ConstrCounter(const ConstrCounter &o);
        ~ConstrCounter();

        static void reset_counters();
};

bool operator==(const ConstrCounter& lhs, const ConstrCounter& rhs);
bool operator!=(const ConstrCounter& lhs, const ConstrCounter& rhs);
bool operator<(const ConstrCounter& lhs, const ConstrCounter& rhs);
bool operator<=(const ConstrCounter& lhs, const ConstrCounter& rhs);
bool operator>(const ConstrCounter& lhs, const ConstrCounter& rhs);
bool operator>=(const ConstrCounter& lhs, const ConstrCounter& rhs);

void test_one(std::string name, void (&fn)());

void test_list();
#endif
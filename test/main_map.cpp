#include "Test.hpp"

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

// template <typename Map>
// void print_map(Map c)
// {
// 	for (typename Map::iterator it = c.begin(); it != c.end(); it++)
// 	{
// 		std::cout << "(" << it->first << ", " << it->second << ")"
// 				  << " ";
// 	}
// 	std::cout << std::endl;
// }

static void test_constr()
{
    ft::Map<int, char, classcomp> map;
   
    ft::Map<int, char, classcomp>::iterator it;

}
void test_map()
{
    std::cout << "\e[1m\e[33m \nTesting Map\n\n";
    test_one("constr", test_constr);
}
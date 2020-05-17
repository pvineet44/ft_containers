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
		ft::Pair<int, char> pm[] = {
		ft::make_pair(1, 'a'),//<-array
		ft::make_pair(2, 'b'),//1
		ft::make_pair(3, 'c'),//2
		ft::make_pair(4, 'd'),//3
		ft::make_pair(5, 'e')};//4
		ft::Map<int, char, classcomp> map(pm, pm + 5);

		std::cout << map.size() << std::endl; //5
		map[2] = 'x';
		std::cout << map[7];
		std::cout << map.size() << std::endl; //6
		//;
		for (ft::Map<int, char, classcomp>::iterator it = map.begin(); it != map.end(); it++)
			std::cout << it->first << " " << it->second << "\n";
}
void test_map()
{
		std::cout << "\e[1m\e[33m \nTesting Map\n\n";
		test_one("constr", test_constr);
}
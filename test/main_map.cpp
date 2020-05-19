#include "Test.hpp"

template <typename Map>
void print_map(Map c)
{
	for (typename Map::iterator it = c.begin(); it != c.end(); it++)
	{
		std::cout << "(" << it->first << ", " << it->second << ")"
				  << " ";
	}
	std::cout << std::endl;
}



static void test_constr()
{
	//default constructor
	ft::Map<int, char>  ft_empty_map;
	std::map<int, char> st_empty_map;
	assert(ft_empty_map.size() == 0);
	assert(st_empty_map.size() == 0);
	
	//range constructor
	ft::Pair<int, char> pm[] = 
    {
		ft::make_pair(1, 'a'),
		ft::make_pair(2, 'b'),
		ft::make_pair(3, 'c'),
		ft::make_pair(4, 'd'),
		ft::make_pair(5, 'e')
	};


	std::pair<int, char> po[] = 
    {
		std::make_pair(1, 'a'),
		std::make_pair(2, 'b'),
		std::make_pair(3, 'c'),
		std::make_pair(4, 'd'),
		std::make_pair(5, 'e')
	};

	ft::Map<int, char> ft_map(pm, pm + 5);
	std::map<int, char> st_map(po, po + 5);
	assert(ft_map.size() == 5);
	assert(st_map.size() == 5);
	
	assert(ft_map[1] == 'a');
	assert(ft_map[2] == 'b');
	assert(ft_map[3] == 'c');
	assert(ft_map[4] == 'd');
	assert(ft_map[5] == 'e');

	assert(st_map[1] == 'a');
	assert(st_map[2] == 'b');
	assert(st_map[3] == 'c');
	assert(st_map[4] == 'd');
	assert(st_map[5] == 'e');

	//copy constructor
	ft::Map<int, char> ft_copy_map(ft_map);
	std::map<int, char> st_copy_map(st_map);
	
	assert(ft_copy_map.size() == 5);
	assert(ft_copy_map[1] == 'a');
	assert(ft_copy_map[2] == 'b');
	assert(ft_copy_map[3] == 'c');
	assert(ft_copy_map[4] == 'd');
	assert(ft_copy_map[5] == 'e');

	assert(st_copy_map.size() == 5);
	assert(st_copy_map[1] == 'a');
	assert(st_copy_map[2] == 'b');
	assert(st_copy_map[3] == 'c');
	assert(st_copy_map[4] == 'd');
}

static void test_assign_copy()
{
	ft::Map<int, char> ft_diary;
	std::map<int, char> st_diary;
	assert(ft_diary.size() == 0);
	assert(st_diary.size() == 0);

	ft_diary[32] = ' ';
	ft_diary[65] = 'A';
	ft_diary[97] = 'a';

	st_diary[32] = ' ';
	st_diary[65] = 'A';
	st_diary[97] = 'a';

	assert(ft_diary.size() == 3);
	assert(ft_diary[32] == (char)32);
	assert(ft_diary[65] == (char)65);
	assert(ft_diary[97] == (char)97);

	assert(st_diary.size() == 3);
	assert(st_diary[32] == (char)32);
	assert(st_diary[65] == (char)65);
	assert(st_diary[97] == (char)97);


	ft::Map<int, char> ft_new_diary = ft_diary;
	std::map<int, char> st_new_diary = st_diary;
	ft_diary = ft::Map<int, char>();
	st_diary = std::map<int, char>();
	assert(ft_diary.size() == 0);
	assert(st_diary.size() == 0);

	assert(ft_new_diary.size() == 3);
	assert(ft_new_diary[32] == (char)32);
	assert(ft_new_diary[65] == (char)65);
	assert(ft_new_diary[97] == (char)97);

	assert(st_new_diary.size() == 3);
	assert(st_new_diary[32] == (char)32);
	assert(st_new_diary[65] == (char)65);
	assert(st_new_diary[97] == (char)97);
}

static void test_begin()
{

	ft::Map<char,int> ft_mymap;
	std::map<char,int> std_mymap;

  	ft_mymap['b'] = 100;
  	ft_mymap['a'] = 200;
  	ft_mymap['c'] = 300;

	std_mymap['b'] = 100;
  	std_mymap['a'] = 200;
  	std_mymap['c'] = 300;

	ft::Map<char, int>::iterator ft_it = ft_mymap.begin();
	std::map<char, int>::iterator st_it = std_mymap.begin();
	
	assert(ft_it->first == 'a');
	assert(ft_it->second == 200);
	ft_it++;
	assert(ft_it->first == 'b');
	assert(ft_it->second == 100);
	ft_it++;
	assert(ft_it->first == 'c');
	assert(ft_it->second == 300);

	assert(st_it->first == 'a');
	assert(st_it->second == 200);
	st_it++;
	assert(st_it->first == 'b');
	assert(st_it->second == 100);
	st_it++;
	assert(st_it->first == 'c');
	assert(st_it->second == 300);
}

static void test_end()
{
	ft::Map<char,int> ft_mymap;
	std::map<char,int> std_mymap;

  	ft_mymap['b'] = 100;
  	ft_mymap['a'] = 200;
  	ft_mymap['c'] = 300;

  	std_mymap['b'] = 100;
  	std_mymap['a'] = 200;
  	std_mymap['c'] = 300;

	ft::Map<char, int>::iterator ft_it = ft_mymap.end();
	std::map<char, int>::iterator st_it = std_mymap.end();

	ft_it--;
	st_it--;

	assert(ft_it->first == 'c');
	assert(ft_it->second == 300);
	ft_it--;
	assert(ft_it->first == 'b');
	assert(ft_it->second == 100);
	ft_it--;
	assert(ft_it->first == 'a');
	assert(ft_it->second == 200);

	assert(st_it->first == 'c');
	assert(st_it->second == 300);
	st_it--;
	assert(st_it->first == 'b');
	assert(st_it->second == 100);
	st_it--;
	assert(st_it->first == 'a');
	assert(st_it->second == 200);
}

static void test_rbegin()
{
	ft::Map<char,int> ft_mymap;
	std::map<char,int> st_mymap;

  	ft_mymap['b'] = 100;
  	ft_mymap['a'] = 200;
  	ft_mymap['c'] = 300;

	st_mymap['b'] = 100;
  	st_mymap['a'] = 200;
  	st_mymap['c'] = 300;

	ft::Map<char, int>::reverse_iterator ft_it = ft_mymap.rbegin();
	std::map<char, int>::reverse_iterator st_it = st_mymap.rbegin();

	assert(ft_it->first == 'c');
	assert(ft_it->second == 300);
	ft_it++;
	assert(ft_it->first == 'b');
	assert(ft_it->second == 100);
	ft_it++;
	assert(ft_it->first == 'a');
	assert(ft_it->second == 200);

	assert(st_it->first == 'c');
	assert(st_it->second == 300);
	st_it++;
	assert(st_it->first == 'b');
	assert(st_it->second == 100);
	st_it++;
	assert(st_it->first == 'a');
	assert(st_it->second == 200);
}

static void test_rend()
{
	ft::Map<char,int> ft_mymap;
	std::map<char,int> st_mymap;

  	ft_mymap['b'] = 100;
  	ft_mymap['a'] = 200;
  	ft_mymap['c'] = 300;

	st_mymap['b'] = 100;
  	st_mymap['a'] = 200;
  	st_mymap['c'] = 300;


	ft::Map<char, int>::reverse_iterator ft_it = ft_mymap.rend();
	std::map<char, int>::reverse_iterator st_it = st_mymap.rend();
	
	ft_it--;
	assert(ft_it->first == 'a');
	assert(ft_it->second == 200);
	ft_it--;
	assert(ft_it->first == 'b');
	assert(ft_it->second == 100);
	ft_it--; 
	assert(ft_it->first == 'c');
	assert(ft_it->second == 300);

	st_it--;
	assert(st_it->first == 'a');
	assert(st_it->second == 200);
	st_it--;
	assert(st_it->first == 'b');
	assert(st_it->second == 100);
	st_it--; 
	assert(st_it->first == 'c');
	assert(st_it->second == 300);
}

static void test_empty_and_maxsize()
{
	ft::Map<char,int> ft_mymap;
	std::map<char,int> st_mymap;

	assert(ft_mymap.size() == 0);
	assert(st_mymap.size() == 0);

	assert(ft_mymap.empty());
	assert(st_mymap.empty());
	assert(ft_mymap.max_size() == st_mymap.max_size());
}

static void	test_element_access()
{
	ft::Map<char,int> ft_mymap;
	std::map<char,int> st_mymap;
	
	ft_mymap['x'] = 1001;
	ft_mymap['y'] = 2001;
	ft_mymap['z'] = 3001;
 
	st_mymap['x'] = 1001;
	st_mymap['y'] = 2001;
	st_mymap['z'] = 3001;

	assert(ft_mymap['x'] == st_mymap['x']);
	assert(ft_mymap['y'] == st_mymap['y']);
	assert(ft_mymap['z'] == st_mymap['z']);
}

static void	test_insert()
{
	ft::Map<char,int> ft_mymap;
	std::map<char,int> st_mymap;
	
	//insert with single parameter
	ft_mymap.insert( ft::Pair<char,int>('x',100) );
	st_mymap.insert( std::pair<char,int>('x',100) );

	ft_mymap.insert( ft::Pair<char,int>('y',200) );
	st_mymap.insert( std::pair<char,int>('y',200) );

	assert(ft_mymap.size() == st_mymap.size());
	assert(ft_mymap['x'] == st_mymap['x']);
	assert(ft_mymap['y'] == st_mymap['y']);

	ft::Pair<ft::Map<char,int>::iterator , bool> ft_ret = ft_mymap.insert ( ft::Pair<char,int>('y',200) );
	std::pair<std::map<char,int>::iterator , bool> st_ret = st_mymap.insert ( std::pair<char,int>('y',200) );
  	assert(ft_ret.second == false);
  	assert(st_ret.second == false);

	//insert with hint position

	ft::Map<char,int>::iterator ft_it1 = ft_mymap.begin();
	std::map<char,int>::iterator st_it1 = st_mymap.begin();
  	
	ft_mymap.insert (ft_it1, ft::Pair<char,int>('b',300));  // max efficiency inserting
  	st_mymap.insert (st_it1, std::pair<char,int>('b',300));  // no max efficiency inserting

	assert(ft_mymap['b'] == st_mymap['b']);
	assert(ft_mymap['c'] == st_mymap['c']);

	//insert with range
	ft::Map<char,int> ft_anothermap;
	std::map<char,int> st_anothermap;
	ft_anothermap.insert(ft_mymap.begin(), ft_mymap.find('y'));
	st_anothermap.insert(st_mymap.begin(), st_mymap.find('y'));

	assert(ft_anothermap.size() == st_anothermap.size());
	assert(ft_anothermap.size() == st_anothermap.size());
	assert(ft_anothermap['b'] == st_anothermap['b']);
	assert(ft_anothermap['x'] == st_anothermap['x']);
	assert(ft_anothermap['y'] == st_anothermap['y']);
}

static void test_erase()
{
	ft::Map<int,int> ft_mymap;
	std::map<int,int> st_mymap;
	
	
	// insert some values:
  	ft_mymap[0] = 10;
  	ft_mymap[1] = 11;
  	ft_mymap[2] = 12;
  	ft_mymap[3] = 13;
  	ft_mymap[4] = 14;
  	ft_mymap[5] = 15;

	st_mymap[0] = 10;
	st_mymap[1] = 11;
	st_mymap[2] = 12;
	st_mymap[3] = 13;
	st_mymap[4] = 14;
	st_mymap[5] = 15;

	assert(ft_mymap.size() == 6);
	assert(st_mymap.size() == 6);

	ft::Map<int,int>::iterator ft_it = ft_mymap.find(3);
	std::map<int,int>::iterator st_it = st_mymap.find(3);
	
	//delete using one iterator
	ft_mymap.erase(ft_it);
	st_mymap.erase(st_it);

	assert(ft_mymap.size() == 5);
	assert(st_mymap.size() == 5);

	//delete using key
	ft_mymap.erase(0);
	st_mymap.erase(0);

	assert(ft_mymap.size() == 4);
	assert(st_mymap.size() == 4);

	//delete using first, last iterator
	ft::Map<int,int>::iterator ft_it1 = ft_mymap.find(2);
	std::map<int,int>::iterator st_it1 = st_mymap.find(2);
	(void)ft_it1;
	(void)st_it1;

	// ft_mymap.erase(ft_it1, ft_mymap.end());
	// st_mymap.erase(st_it1, st_mymap.end());


	// ft_mymap.erase(ft_mymap.begin(), ft_it1);
	// st_mymap.erase(st_mymap.begin(), st_it1);
}

static void test_swap()
{
	ft::Map<char,int> ft_foo, ft_bar;
	std::map<char,int> st_foo, st_bar;

	ft_foo['x']=100;
  	ft_foo['y']=200;

  	ft_bar['a']=11;
  	ft_bar['b']=22;
  	ft_bar['c']=33;

	st_foo['x']=100;
  	st_foo['y']=200;

  	st_bar['a']=11;
  	st_bar['b']=22;
  	st_bar['c']=33;
	
	ft_foo.swap(ft_bar);
	st_foo.swap(st_bar);

	assert(ft_foo.size() == 3);
	assert(st_foo.size() == 3);

	assert(ft_bar.size() == 2);
	assert(st_bar.size() == 2);

	assert(ft_bar['x'] == 100);
	assert(st_bar['x'] == 100);
	assert(st_bar['y'] == 200);
	assert(st_bar['y'] == 200);

	assert(ft_foo['a'] == 11);
	assert(st_foo['a'] == 11);
	assert(ft_foo['b'] == 22);
	assert(st_foo['b'] == 22);
	assert(ft_foo['c'] == 33);
	assert(st_foo['c'] == 33);
	
}

static void test_clear()
{
	ft::Map<int,int> ft_mymap;
	std::map<int,int> st_mymap;
	
	
	// insert some values:
  	ft_mymap[0] = 10;
  	ft_mymap[1] = 11;
  	ft_mymap[2] = 12;
  	ft_mymap[3] = 13;
  	ft_mymap[4] = 14;
  	ft_mymap[5] = 15;

	st_mymap[0] = 10;
	st_mymap[1] = 11;
	st_mymap[2] = 12;
	st_mymap[3] = 13;
	st_mymap[4] = 14;
	st_mymap[5] = 15;

	assert(ft_mymap.size() == 6);
	assert(st_mymap.size() == 6);

	ft_mymap.clear();
	st_mymap.clear();

	assert(ft_mymap.size() == 0);
	assert(st_mymap.size() == 0);
}

void test_map()
{
		std::cout << "\e[1m\e[34m \nTesting Map\n\n";
		test_one("constr", test_constr);
		test_one("assign_copy", test_assign_copy);
		test_one("begin", test_begin);
		test_one("end", test_end);
		test_one("rbegin", test_rbegin);
		test_one("rend", test_rend);
		test_one("capacity", test_empty_and_maxsize);
		test_one("element_access", test_element_access);
		test_one("insert", test_insert);
		test_one("insert", test_insert);
		test_one("erase", test_erase);
		test_one("swap", test_swap);
		test_one("clear", test_clear);
}

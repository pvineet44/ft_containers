#include "Test.hpp"
#include <queue>

static void test_push_pop()
{
	ft::Queue<ConstrCounter> queue;
	assert(queue.size() == 0);
	assert(queue.empty());
	//std
	std::queue<ConstrCounter> q;
	assert(q.size() == 0);
	assert(q.empty());

	queue.push(ConstrCounter(0));
	assert(queue.size() == 1);
	assert(!queue.empty());
	assert(queue.back() == 0);
	assert(queue.front() == 0);
	//std
	q.push(ConstrCounter(0));
	assert(q.size() == 1);
	assert(!q.empty());
	assert(q.back() == 0);
	assert(q.front() == 0);


	queue.push(ConstrCounter(1));
	assert(queue.size() == 2);
	assert(!queue.empty());
	assert(queue.back() == 1);
	assert(queue.front() == 0);
	//std
	q.push(ConstrCounter(1));
	assert(q.size() == 2);
	assert(!q.empty());
	assert(q.back() == 1);
	assert(q.front() == 0);


	queue.push(ConstrCounter(2));
	assert(queue.size() == 3);
	assert(!queue.empty());
	assert(queue.back() == 2);
	assert(queue.front() == 0);
	//std
	q.push(ConstrCounter(2));
	assert(q.size() == 3);
	assert(!q.empty());
	assert(q.back() == 2);
	assert(q.front() == 0);


	queue.push(ConstrCounter(3));
	assert(queue.size() == 4);
	assert(!queue.empty());
	assert(queue.back() == 3);
	assert(queue.front() == 0);
	//std
	q.push(ConstrCounter(3));
	assert(q.size() == 4);
	assert(!q.empty());
	assert(q.back() == 3);
	assert(q.front() == 0);


	queue.push(ConstrCounter(4));
	assert(queue.size() == 5);
	assert(!queue.empty());
	assert(queue.back() == 4);
	assert(queue.front() == 0);
	//std
	q.push(ConstrCounter(4));
	assert(q.size() == 5);
	assert(!q.empty());
	assert(q.back() == 4);
	assert(q.front() == 0);


	queue.pop();
	assert(queue.size() == 4);
	assert(!queue.empty());
	assert(queue.back() == 4);
	assert(queue.front() == 1);
	//std
	q.pop();
	assert(q.size() == 4);
	assert(!q.empty());
	assert(q.back() == 4);
	assert(q.front() == 1);


	queue.pop();
	assert(queue.size() == 3);
	assert(!queue.empty());
	assert(queue.back() == 4);
	assert(queue.front() == 2);
	//std
	q.pop();
	assert(q.size() == 3);
	assert(!q.empty());
	assert(q.back() == 4);
	assert(q.front() == 2);


	queue.pop();
	assert(queue.size() == 2);
	assert(!queue.empty());
	assert(queue.back() == 4);
	assert(queue.front() == 3);
	//std
	q.pop();
	assert(q.size() == 2);
	assert(!q.empty());
	assert(q.back() == 4);
	assert(q.front() == 3);


	queue.pop();
	assert(queue.size() == 1);
	assert(!queue.empty());
	assert(queue.back() == 4);
	assert(queue.front() == 4);
	//std
	q.pop();
	assert(q.size() == 1);
	assert(!q.empty());
	assert(q.back() == 4);
	assert(q.front() == 4);


	queue.pop();
	assert(queue.size() == 0);
	assert(queue.empty());
	//std
	q.pop();
	assert(q.size() == 0);
	assert(q.empty());
}

static void test_assign_copy()
{
	ft::Queue<ConstrCounter> queue;
	queue.push(ConstrCounter(0));
	queue.push(ConstrCounter(1));
	queue.push(ConstrCounter(2));
	//std
	std::queue<ConstrCounter> q;
	q.push(ConstrCounter(0));
	q.push(ConstrCounter(1));
	q.push(ConstrCounter(2));

	ft::Queue<ConstrCounter> queue2(queue);
	assert(queue2.size() == 3);
	assert(queue2.back() == 2);
	assert(queue2.front() == 0);
	queue2.pop();
	assert(queue2.size() == 2);
	assert(queue2.back() == 2);
	assert(queue2.front() == 1);
	queue2.pop();
	assert(queue2.size() == 1);
	assert(queue2.back() == 2);
	assert(queue2.front() == 2);
	queue2.pop();
	assert(queue2.size() == 0);
	//std
	std::queue<ConstrCounter> q2(q);
	assert(q2.size() == 3);
	assert(q2.back() == 2);
	assert(q2.front() == 0);
	q2.pop();
	assert(q2.size() == 2);
	assert(q2.back() == 2);
	assert(q2.front() == 1);
	q2.pop();
	assert(q2.size() == 1);
	assert(q2.back() == 2);
	assert(q2.front() == 2);
	q2.pop();
	assert(q2.size() == 0);


	queue2.push(ConstrCounter(0));
	assert(queue2.size() == 1);
	queue2.push(ConstrCounter(1));
	assert(queue2.size() == 2);
	queue2.push(ConstrCounter(2));
	assert(queue2.size() == 3);
	//std
	q2.push(ConstrCounter(0));
	assert(q2.size() == 1);
	q2.push(ConstrCounter(1));
	assert(q2.size() == 2);
	q2.push(ConstrCounter(2));
	assert(q2.size() == 3);


	queue2.push(ConstrCounter(3));
	assert(queue.size() == 3);
	assert(queue2.size() == 4);
	//std
	q2.push(ConstrCounter(3));
	assert(q.size() == 3);
	assert(q2.size() == 4);


	ft::Queue<ConstrCounter> queue3;
	assert(queue3.size() == 0);
	//std
	std::queue<ConstrCounter> q3;
	assert(q3.size() == 0);


	queue3 = queue2;
	assert(queue.size() == 3);
	assert(queue2.size() == 4);
	assert(queue3.size() == 4);
	//std
	q3 = q2;
	assert(q.size() == 3);
	assert(q2.size() == 4);
	assert(q3.size() == 4);


	queue = queue3;
	assert(queue.size() == 4);
	assert(queue2.size() == 4);
	assert(queue3.size() == 4);
	//std
	q = q3;
	assert(q.size() == 4);
	assert(q2.size() == 4);
	assert(q3.size() == 4);


	assert(queue.size() == 4);
	assert(queue.back() == 3);
	assert(queue.front() == 0);
	queue.pop();
	assert(queue.size() == 3);
	assert(queue.back() == 3);
	assert(queue.front() == 1);
	queue.pop();
	assert(queue.size() == 2);
	assert(queue.back() == 3);
	assert(queue.front() == 2);
	queue.pop();
	assert(queue.size() == 1);
	assert(queue.back() == 3);
	assert(queue.front() == 3);
	queue.pop();
	assert(queue.size() == 0);
	//std
	assert(q.size() == 4);
	assert(q.back() == 3);
	assert(q.front() == 0);
	q.pop();
	assert(q.size() == 3);
	assert(q.back() == 3);
	assert(q.front() == 1);
	q.pop();
	assert(q.size() == 2);
	assert(q.back() == 3);
	assert(q.front() == 2);
	q.pop();
	assert(q.size() == 1);
	assert(q.back() == 3);
	assert(q.front() == 3);
	q.pop();
	assert(q.size() == 0);


	assert(queue2.size() == 4);
	assert(queue2.back() == 3);
	assert(queue2.front() == 0);
	queue2.pop();
	assert(queue2.size() == 3);
	assert(queue2.back() == 3);
	assert(queue2.front() == 1);
	queue2.pop();
	assert(queue2.size() == 2);
	assert(queue2.back() == 3);
	assert(queue2.front() == 2);
	queue2.pop();
	assert(queue2.size() == 1);
	assert(queue2.back() == 3);
	assert(queue2.front() == 3);
	queue2.pop();
	assert(queue2.size() == 0);
	//std
	assert(q2.size() == 4);
	assert(q2.back() == 3);
	assert(q2.front() == 0);
	q2.pop();
	assert(q2.size() == 3);
	assert(q2.back() == 3);
	assert(q2.front() == 1);
	q2.pop();
	assert(q2.size() == 2);
	assert(q2.back() == 3);
	assert(q2.front() == 2);
	q2.pop();
	assert(q2.size() == 1);
	assert(q2.back() == 3);
	assert(q2.front() == 3);
	q2.pop();
	assert(q2.size() == 0);

	assert(queue3.size() == 4);
	assert(queue3.back() == 3);
	assert(queue3.front() == 0);
	queue3.pop();
	assert(queue3.size() == 3);
	assert(queue3.back() == 3);
	assert(queue3.front() == 1);
	queue3.pop();
	assert(queue3.size() == 2);
	assert(queue3.back() == 3);
	assert(queue3.front() == 2);
	queue3.pop();
	assert(queue3.size() == 1);
	assert(queue3.back() == 3);
	assert(queue3.front() == 3);
	queue3.pop();
	assert(queue3.size() == 0);
	//std
	assert(q3.size() == 4);
	assert(q3.back() == 3);
	assert(q3.front() == 0);
	q3.pop();
	assert(q3.size() == 3);
	assert(q3.back() == 3);
	assert(q3.front() == 1);
	q3.pop();
	assert(q3.size() == 2);
	assert(q3.back() == 3);
	assert(q3.front() == 2);
	q3.pop();
	assert(q3.size() == 1);
	assert(q3.back() == 3);
	assert(q3.front() == 3);
	q3.pop();
	assert(q3.size() == 0);
}

static void test_swap()
{
	ft::Queue<ConstrCounter> queue;
    queue.push(5);
    queue.push(2);
    queue.push(3);
    queue.push(1);
    queue.push(4);
	//std
	std::queue<ConstrCounter> q;
    q.push(5);
    q.push(2);
    q.push(3);
    q.push(1);
    q.push(4);

	ft::Queue<ConstrCounter> queue2;
    queue2.push(3);
    queue2.push(2);
    queue2.push(1);
	//std
	std::queue<ConstrCounter> q2;
    q2.push(3);
    q2.push(2);
    q2.push(1);


	ft::swap(queue, queue2);
	assert(queue.size() == 3);
	assert(queue2.size() == 5);
	assert(queue.back() == 1);
	assert(queue2.back() == 4);
	//std
	std::swap(q, q2);
	assert(q.size() == 3);
	assert(q2.size() == 5);
	assert(q.back() == 1);
	assert(q2.back() == 4);


	ft::swap(queue2, queue);
	assert(queue.size() == 5);
	assert(queue2.size() == 3);
	assert(queue.back() == 4);
	assert(queue2.back() == 1);
	//std
	std::swap(q2, q);
	assert(q.size() == 5);
	assert(q2.size() == 3);
	assert(q.back() == 4);
	assert(q2.back() == 1);
}

static void test_cmp_eq()
{
	ft::Queue<ConstrCounter> queue;
    queue.push(5);
    queue.push(2);
    queue.push(3);
    queue.push(1);
    queue.push(4);
	//std
	std::queue<ConstrCounter> q;
    q.push(5);
    q.push(2);
    q.push(3);
    q.push(1);
    q.push(4);


    ft::Queue<ConstrCounter> queue2(queue);
	assert(queue == queue2);
	assert(queue >= queue2);
	assert(queue <= queue2);
	//std
	std::queue<ConstrCounter> q2(q);
	assert(q == q2);
	assert(q >= q2);
	assert(q <= q2);

	queue2.push(50);
	assert(queue != queue2);
	assert(queue < queue2);
	assert(queue <= queue2);
	assert(queue2 > queue);
	assert(queue2 >= queue);
	//std
	q2.push(50);
	assert(q != q2);
	assert(q < q2);
	assert(q <= q2);
	assert(q2 > q);
	assert(q2 >= q);

	queue.push(200);
	assert(queue != queue2);
	assert(queue > queue2);
	assert(queue >= queue2);
	assert(queue2 < queue);
	assert(queue2 <= queue);
	//std
	q.push(200);
	assert(q != q2);
	assert(q > q2);
	assert(q >= q2);
	assert(q2 < q);
	assert(q2 <= q);
}

static void test_constr()
{
	//default constructor
	std::queue<ConstrCounter> st_queue;
	ft::Queue<ConstrCounter> ft_queue;

	st_queue.push(5);
    st_queue.push(2);
    st_queue.push(3);
    st_queue.push(1);
    st_queue.push(4);

	ft_queue.push(5);
	ft_queue.push(2);
	ft_queue.push(3);
	ft_queue.push(1);
	ft_queue.push(4);

	//copy constructor
	std::queue<ConstrCounter> st_copy_queue(st_queue);
	ft::Queue<ConstrCounter>  ft_copy_queue(ft_queue);

	assert(ft_copy_queue.front().val == st_copy_queue.front().val);
	ft_copy_queue.pop();st_copy_queue.pop();
	assert(ft_copy_queue.front().val == st_copy_queue.front().val);
	ft_copy_queue.pop();st_copy_queue.pop();
	assert(ft_copy_queue.front().val == st_copy_queue.front().val);
	ft_copy_queue.pop();st_copy_queue.pop();
	assert(ft_copy_queue.front().val == st_copy_queue.front().val);
	ft_copy_queue.pop();st_copy_queue.pop();
	assert(ft_copy_queue.front().val == st_copy_queue.front().val);
	ft_copy_queue.pop();st_copy_queue.pop();
	assert(ft_copy_queue.empty() == st_copy_queue.empty());
}

static void test_relational_operator()
{
	std::queue<ConstrCounter> st_myqueue1;
	ft::Queue<ConstrCounter> ft_myqueue1;

	std::queue<ConstrCounter> st_myqueue2;
	ft::Queue<ConstrCounter> ft_myqueue2;

	assert(ft_myqueue1 == ft_myqueue2);
	assert(st_myqueue1 == st_myqueue2);
	
	ft_myqueue1.push(ConstrCounter(1));
	st_myqueue1.push(ConstrCounter(1));

	assert(ft_myqueue1 >= ft_myqueue2);
	assert(st_myqueue1 >= st_myqueue2);

	assert(ft_myqueue1 > ft_myqueue2);
	assert(st_myqueue1 > st_myqueue2);

	assert(ft_myqueue2 <= ft_myqueue1);
	assert(st_myqueue2 <= st_myqueue1);

	assert(ft_myqueue2 < ft_myqueue1);
	assert(st_myqueue2 < st_myqueue1);

	assert(ft_myqueue2 != ft_myqueue1);
	assert(st_myqueue2 != st_myqueue1);
}

static void test_empty()
{
	std::queue<ConstrCounter> st_myqueue;
	ft::Queue<ConstrCounter> ft_myqueue;

	assert(st_myqueue.empty());
	assert(ft_myqueue.empty());
}

static void	test_size()
{
	std::queue<ConstrCounter> st_myqueue;
	ft::Queue<int> ft_myqueue;

	assert(st_myqueue.size() == 0);
	assert(ft_myqueue.size() == 0);

	ft_myqueue.push(ConstrCounter(1));
	ft_myqueue.push(ConstrCounter(2));
	ft_myqueue.push(ConstrCounter(3));

	st_myqueue.push(ConstrCounter(1));
	st_myqueue.push(ConstrCounter(2));
	st_myqueue.push(ConstrCounter(3));

	assert(st_myqueue.size() == 3);
	assert(ft_myqueue.size() == 3);

}

void test_queue()
{
    std::cout << "\e[1m\e[36m \n<=== Testing Queue ===>\n\n";
	test_one("constr", test_constr);
	test_one("empty", test_empty);
	test_one("size", test_size);
	test_one("push_pop", test_push_pop);
	test_one("assign_copy", test_assign_copy);
	test_one("swap", test_swap);
	test_one("cmp_eq", test_cmp_eq);
	test_one("relational_operators", test_relational_operator);
}
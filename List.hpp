#ifndef LIST_HPP
#define LIST_HPP
# include <iterator>
# include "Utility.hpp"
namespace ft
{	/*
	List:
		1.  Struct listNode --DONE
		2.  ListIterator --DONE
		3.  List class
		4.  Member functions
		5.  Operator overloads
	*/
	template<typename T>
	struct ListNode
	{
		ListNode(ListNode<T> *prev_, ListNode<T> *nxt_, const T &node_):prev(prev_),nxt(nxt_), node(node_)
		{
		}
		ListNode<T> *prev;
		ListNode<T> *nxt;
		T           node;
	};
	template<typename T>
	class ListIterator
	{
		private:
			ListNode<T>*    _prev;
			ListNode<T>*    _nxt;
		public:
			// struct iterator {
			//   typedef T         value_type;
			//   typedef Distance  difference_type;
			//   typedef Pointer   pointer;
			//   typedef Reference reference;
			//   typedef Category  iterator_category;
			// };BidirectionalIteratorTag
			typedef T								value_type;
			typedef	std::ptrdiff_t					difference_type;
			typedef	T*								pointer;
			typedef	T&								reference;
			typedef	BidirectionalIteratorTag		iterator_category;
			ListIterator(ListNode<T> *prev, ListNode<T> *nxt): _prev(prev), _nxt(nxt)
			{
			}

			ListIterator(const ListIterator<T>& other):	_prev(other._prev), _nxt(other._nxt)
			{
			}

			~ListIterator()
			{
			}

			ListIterator<T>& operator=(const ListIterator<T> &rhs)
			{
				_prev = rhs._prev;
				_nxt = rhs._nxt;
				return *this;
			}

			ListIterator<T>& operator++()
			{
				_prev = _nxt;
				_nxt = _nxt->nxt;
				return *this;
			}

			ListIterator<T> operator++(int)
			{
				ListIterator<T> cpy = *this;
				_prev = _nxt;
				_nxt = _nxt->nxt;
				return cpy;
			}

			ListIterator<T>& operator--()
			{
				_nxt = _prev;
				_prev = _prev->prev;
				return *this;
			}

			ListIterator<T> operator--(int)
			{
				ListIterator<T> cpy = *this;
				_nxt = _prev;
				_prev = _prev->prev;
				return cpy;
			}

			T&	operator*()
			{
				return _nxt->node;
			}

			T&	operator->()
			{
				return &_nxt->node;
			}

			template <typename E>
			friend class List;
			template <typename E>
			friend bool operator==(const ListIterator<E>& lhs, const ListIterator<E>& rhs);
			template <typename E>
			friend bool operator!=(const ListIterator<E>& lhs, const ListIterator<E>& rhs);
		};

		template <typename T>
		bool operator==(const ListIterator<T>& lhs, const ListIterator<T>& rhs)
		{
			return (lhs._prev == rhs._prev && lhs._nxt == rhs._nxt);
		}

		template <typename T>
		bool operator!=(const ListIterator<T>& lhs, const ListIterator<T>& rhs)
		{
			return (lhs._prev != rhs._prev || lhs._nxt != rhs._nxt);
		}

		template <typename T>
		class List
		{
			private:
				ListNode<T>* 	_head;
				ListNode<T>* 	_tail;
				size_t			_len;

			public:

			// value_type	The first template parameter (T)	
			// allocator_type	The second template parameter (Alloc)	defaults to: allocator<value_type>
			// reference	allocator_type::reference	for the default allocator: value_type&
			// const_reference	allocator_type::const_reference	for the default allocator: const value_type&
			// pointer	allocator_type::pointer	for the default allocator: value_type*
			// const_pointer	allocator_type::const_pointer	for the default allocator: const value_type*
			// iterator	a bidirectional iterator to value_type	convertible to const_iterator
			// const_iterator	a bidirectional iterator to const value_type	
			// reverse_iterator	reverse_iterator<iterator>	
			// const_reverse_iterator	reverse_iterator<const_iterator>	
			// difference_type	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
			// size_type	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

			typedef 		T									value_type;
			typedef			T&									reference;
			typedef const	T&									const_reference;
			typedef			T*									pointer;
			typedef	const	T*									const_pointer;
			typedef 		ListIterator<T>						iterator;
			typedef			ListIterator<const T>				const_iterator;
			typedef			ReverseIterator<iterator>			reverse_iterator;
			typedef			ReverseIterator<const iterator>		const_reverse_iterator;
			typedef			std::ptrdiff_t						difference_type;
			typedef			size_t								size_type;

			/*
				Define Constructors:
					(1) empty container constructor (default constructor)
					    Constructs an empty container, with no elements.
					(2) fill constructor
					    Constructs a container with n elements. Each element is a copy of val.
					(3) range constructor
					    Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
					(4) copy constructor
					    Constructs a container with a copy of each of the elements in x, in the same order. 
			*/

			explicit	List(): _head(NULL), _tail(NULL), _len(0)
			{
			}

			explicit	List(size_t n, const value_type& val = value_type()): _head(NULL), _tail(NULL), _len(0)
			{
				insert(begin(), n, val);
			}

			template <typename InputIt>
			explicit List(InputIt first, InputIt last): _head(NULL), _tail(NULL), _len(0)
			{
				insert(begin(), first, last);
			}

			explicit	List(const List& other): _head(NULL), _tail(NULL), _len(0)
			{
				insert(begin(), other.begin(), other.end());
			}

			List&	operator=(const List<T>& other)
			{
				clear();
				insert(begin(), other.begin(), other.end());
				return *this;
			}

			~List()
			{
				erase(begin(), end());
			}

			/*
				Define Iterators
			*/

			iterator	begin()
			{
				return iterator(NULL, _head);
			}

			const_iterator begin() const
			{
				return iterator(NULL, (ListNode<const T>*) _head);
			}

			iterator	end()
			{
				return iterator(NULL, _tail);
			}

			const_iterator end() const
			{
				return iterator(NULL, (ListNode<const T>*)_tail);
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(end());
			}

			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(end());
			}

			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}

			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			}

			/*
				Define capacity
			*/

			bool empty() const
			{
				return _len == 0;
			}

			size_t size() const
			{
				return _len;
			}

			size_t max_size() const;

			/*
				Define element access
			*/

			reference front()
			{
				return _head->node;
			}

			reference front() const
			{
				return _head->node;
			}

			reference back()
			{
				return _tail->node;
			}

			reference back() const
			{
				return _tail->node;
			}

			/*
				Define modifiers
			*/

			template <typename InputIt>
			void assign(InputIt first, InputIt last)
			{
				clear();
				insert(begin(), first, last);
			}

			void assign(size_t n, const value_type& val)
			{
				clear();
				insert(begin(), n, val);
			}

			void push_front(const value_type& val)
			{
				insert(begin(), val);
			}

			void pop_front()
			{
				erase(begin());
			}

			void push_back(const value_type& val)
			{
				insert(end(), val);
			}

			void pop_back()
			{
				iterator iter = end();
				iter--;
				erase(iter);
			}

			iterator insert(iterator position, const value_type& val)
			{
				insert(position, 1, val);

				ListNode<T>* nodeLeft = position._prev;
				ListNode<T>* nodeRight = nodeLeft ?  nodeLeft->nxt : _head;
				return iterator(nodeLeft, nodeRight);
			}

			void insert(iterator position, size_t n, const value_type& val)
			{
				ListNode<T>* nodeLeft = position._prev;
				ListNode<T>* nodeRight = position._nxt;

				ListNode<T>* nn = nodeLeft;
				for (size_t i = 0; i < n; i++)
				{
					ListNode<T>* tmp = new ListNode<T>(nn, NULL, val);
					if (nn)
						nn->nxt = tmp;
					else
						_head = tmp;
					_len++;
					nn = tmp;
				}

				if (nodeRight)
				{
					nodeRight->prev = nn;
					nn->nxt = nodeRight;
				}
				else
					_tail = nn;
			}

			template <typename InputIt>
			void insert(iterator position, InputIt first, InputIt last)
			{
				ListNode<T>* nodeLeft = position._prv;
				ListNode<T>* nodeRight = position._nxt;

				ListNode<T>* nn = nodeLeft;
				for (InputIt iter = first; iter != last; iter++)
				{
					ListNode<T>* tmp = new ListNode<T>(nn, NULL, *iter);
					if (nn)
						nn->next = tmp;
					else
						_head = tmp;
					_len++;
					nn = tmp;
				}

				if (nodeRight)
				{
					nodeRight->prev = nn;
					nn->nxt = nodeRight;
				}
				else
					_tail = nn;
			}

			iterator erase(iterator first, iterator last)
			{
				ListNode<T>* nodeLeft = first._prev;
				ListNode<T>* nodeRight = last._nxt;

				iterator ite = first;
				while(ite != last)
				{
					iterator tmp(ite);
					_len--;
					ite = ++ite;
					delete tmp._nxt;
				}

				if (nodeLeft)
					nodeLeft->nxt = nodeRight;
				else
					_head = nodeRight;
				if (nodeRight)
					nodeRight->prev = nodeLeft;
				else
					_tail = nodeLeft;

				last._prev = first._prev;
				return last;
			}

			iterator erase(iterator position)
			{
				iterator nxt = iterator(position);
				nxt++;
				return erase(position, nxt);
			}

			void swap(List &x)
			{
				std::swap(_head, x._head);
				std::swap(_tail, x._tail);
				std::swap(_len, x._len);
			}

			void resize(size_t n, value_type val = value_type())
			{
				if (n >= _len)
					insert(end(), n - _len, val);
				else
				{
					iterator ite = begin();
					for (size_t i = 0; i < n; i++)
						++ite;
					erase(ite, end());
				}
			}

			void clear()
			{
				erase(begin(), end());
			}

			/*
				Define operations
			*/

			void splice(iterator position, List& x)
			{
				insert(position, x.begin(), x.end());
				x.clear();
			}

			void splice(iterator position, List& x, iterator i)
			{
				insert(position, *i);
				x.erase(i);
			}

			void splice(iterator position, List& x, iterator first, iterator last)
			{
				insert(position, first, last);
				x.erase(first, last);
			}

			void remove(const value_type& val)
			{
				for(iterator it = begin(); it != end();)
				{
					if (*it == val)
						it = erase(it);
					else
						it++;
				}
			}

			template <typename Predicate>
			void remove_if(Predicate pred)
			{
				for (iterator it = begin(); it != end();)
				{
					if (pred(*it))
						it = erase(it);
					else
						it++;
				}
			}

			void unique()
			{
				iterator start = begin();
				start++;
				for (iterator it = start; it != end();)
				{
					iterator tmp = it;
					tmp--;
					if (*tmp == *it)
						it = erase(it);
					else
						it++;
				}
			}


			template <typename BinaryPredicate>
			void unique(BinaryPredicate binary_pred)
			{
				iterator start = begin();
				start++;
				for (iterator it = start; it != end();)
				{
					iterator tmp = it;
					--tmp;
					if (binary_pred(*tmp, *it))
						it = erase(it);
					else
						++it;
				}
			}
			void merge(List& x);
			template <typename Compare>
			void merge(List& x, Compare comp);
			// void merge(List& x)
			// {
			// 	ListNode<T> *a = begin(); //List a
			// 	ListNode<T> *b = x.begin(); //List x
			// 	ListNode<T> *nxt;
			// 	ListNode<T> *bef;
			// 	while(b != b._tail)
			// 	{
			// 		if (a == end() || b->node < a->node)
			// 		{
			// 			nxt = b->nxt;
			// 			bef = a->prev;
						
			// 			//Link bef and x 
			// 			bef->nxt = b;
			// 			b->prev = bef;

			// 			//Link x and a
			// 			b->nxt = a;
			// 			a->prev = b;

			// 			//Move x
			// 			b = nxt;
			// 		}
			// 		else
			// 			a = a->nxt;
			// 	}
			// 	_len += x._len;

			// 	//Reset x
			// 	x._size = 0;
			// 	ListNode<T> *tmp = x._tail;
			// 	tmp->nxt = tmp;
			// 	tmp->prv = tmp;
			// }

			// template <typename Compare>
			// void merge(List& x, Compare comp)
			// {
			// 	ListNode<T> *a = begin(); //List a
			// 	ListNode<T> *b = x.begin(); //List x
			// 	ListNode<T> *nxt;
			// 	ListNode<T> *bef;
			// 	while(b != b._tail)
			// 	{
			// 		if (a == end() || comp(b->node, a->node))
			// 		{
			// 			nxt = b->nxt;
			// 			bef = a->prev;
						
			// 			//Link bef and x 
			// 			bef->nxt = b;
			// 			b->prev = bef;

			// 			//Link x and a
			// 			b->nxt = a;
			// 			a->prev = b;

			// 			//Move x
			// 			b = nxt;
			// 		}
			// 		else
			// 			a = a->nxt;
			// 	}
			// 	_len += x._len;

			// 	//Reset x
			// 	x._size = 0;
			// 	ListNode<T> *tmp = x._tail;
			// 	tmp->nxt = tmp;
			// 	tmp->prv = tmp;				
			// }
			void sort();
			template <typename Compare>
			void sort(Compare comp);
			void reverse();
			template <typename E>
			friend class ListIterator;
	};

	template <typename T>
	bool operator!=(const List<T>& lhs, const List<T>& rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T>
	bool operator<(const List<T>& lhs, const List<T>& rhs)
	{
		ListIterator<const T> iter1 = lhs.begin();
		ListIterator<const T> iter2 = rhs.begin();
		while (iter1 != lhs.end() && iter2 != rhs.end())
		{
			if (*iter1 != *iter2)
				return *iter1 < *iter2;

			++iter1;
			++iter2;
		}

		if (lhs.size() == rhs.size())
			return false;

		return lhs.size() < rhs.size();
	}

	template <typename T>
	bool operator<=(const List<T>& lhs, const List<T>& rhs)
	{
		return !(lhs > rhs);
	}

	template <typename T>
	bool operator>(const List<T>& lhs, const List<T>& rhs)
	{
		return (lhs > rhs);
	}

	template <typename T>
	bool operator>=(const List<T>& lhs, const List<T>& rhs)
	{
		return !(lhs < rhs);
	}


	template <typename T>
	void swap(List<T>& x, List<T>& y)
	{
		x.swap(y);
	}
}
#endif
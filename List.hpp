#ifndef LIST_HPP
#define LIST_HPP

	/*
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
		ListNode(ListNode<t> *prev_, ListNode<T> *nxt, ListNode<T> node_):prev(prev_),nxt(nxt_), node(node_)
		{
		}

		ListNode<T> *prev;
		ListNode<T> *nxt;
		T           node;
	};
	template<typname T>
	class ListIterator
	{
		private:
			ListNode<t>*    _prev;
			ListNode<t>*    _nxt;

		public:
			// struct iterator {
  			//   typedef T         value_type;
  			//   typedef Distance  difference_type;
  			//   typedef Pointer   pointer;
  			//   typedef Reference reference;
  			//   typedef Category  iterator_category;
  			// };
			typedef T							value_type;
			typedef	std::ptrdiff_t				difference_type;
			typedef	T*							pointer;
			typedef	T&							reference;
			typedef	BidirectionalIteratorTag	iterator_category;

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

		template typename<InputIt>
		explicit List(InputIt first, InputIt last): _head(NULL), _tail(NULL), _len(0)
		{
			insert(begin(), first, last);
		}

		explist	List(const List& other): _head(NULL), _tail(NULL), _len(0)
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
	};
#endif
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

#endif
#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <sstream>
# include <stdexcept>
# include "Utility.hpp"

namespace	ft
{
	template <typename T>
	class VectorIterator
	{
		private:
			T* _ptr;
		public:
			typedef std::ptrdiff_t difference_type;
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;
			typedef RandomAccessIteratorTag iterator_category;

			VectorIterator(): _ptr(NULL)
			{
			}
			VectorIterator(T* elem):
				_ptr(elem)
			{
			}

			T* ptr() const
			{
				return _ptr;
			}

			VectorIterator(const VectorIterator<T>& other):
				_ptr(other._ptr)
			{
			}

			~VectorIterator()
			{
			}

			VectorIterator<T>& operator=(const VectorIterator<T>& other)
			{
				_ptr = other._ptr;
				return *this;
			}

			VectorIterator<T>& operator++() //prefix increment
			{
				++_ptr;
				return *this;
			}


			VectorIterator<T> operator++(int) //postfix increment
			{
				VectorIterator<T> ite = *this;
				++_ptr;
				return ite;
			}

			T& operator*() const
			{
				return *_ptr;
			}

			T* operator->() const
			{
				return _ptr;
			}

			// bidirectional_iterator
			VectorIterator<T>& operator--() //prefix decrement
			{
				--_ptr;
				return *this;
			}

			VectorIterator<T> operator--(int) //postfix decrement
			{
				VectorIterator<T> ite = *this;
				--_ptr;
				return ite;
			}

			//Random access iterator
			VectorIterator<T>& operator+=(size_t offset)
			{
				_ptr += offset;
				return *this;
			}

			VectorIterator<T>& operator-=(size_t offset)
			{
				_ptr -= offset;
				return *this;
			}
	};

	template <typename T>
	bool operator==(const VectorIterator<T>& lhs, const VectorIterator<T>& rhs)
	{
		return lhs.ptr() == rhs.ptr();
	}

	template <typename T>
	bool operator!=(const VectorIterator<T>& lhs, const VectorIterator<T>& rhs)
	{
		return lhs.ptr() != rhs.ptr();
	}

	// random_access_iterator

	template <typename T>
	bool operator<(const VectorIterator<T>& lhs, const VectorIterator<T>& rhs)
	{
		return lhs.ptr() < rhs.ptr();
	}

	template <typename T>
	bool operator>(const VectorIterator<T>& lhs, const VectorIterator<T>& rhs)
	{
		return lhs.ptr() > rhs.ptr();
	}

	template <typename T>
	bool operator<=(const VectorIterator<T>& lhs, const VectorIterator<T>& rhs)
	{
		return lhs.ptr() <= rhs.ptr();
	}

	template <typename T>
	bool operator>=(const VectorIterator<T>& lhs, const VectorIterator<T>& rhs)
	{
		return lhs.ptr() >= rhs.ptr();
	}

	template <typename T>
	VectorIterator<T> operator+(const VectorIterator<T>& ite, size_t offset)
	{
		return ite.ptr() + offset;
	}

	template <typename T>
	VectorIterator<T> operator+(size_t offset, const VectorIterator<T>& ite)
	{
		return offset + ite.ptr();
	}

	template <typename T>
	VectorIterator<T> operator-(const VectorIterator<T>& ite, size_t offset)
	{
		return ite.ptr() - offset;
	}

	template <typename T>
	std::ptrdiff_t operator-(const VectorIterator<T>& lhs, const VectorIterator<T>& rhs)
	{
		return lhs.ptr() - rhs.ptr();
	}

	template <typename T>
	class Vector
	{
		private:
			T* _arr;
			size_t _len;
			size_t _cap;

		public:
			typedef T value_type;
			typedef size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef T& reference;
			typedef const T& const_reference;
			typedef T* pointer;
			typedef const T * const_pointer;
			typedef VectorIterator<T> iterator;
			typedef VectorIterator<const T> const_iterator;
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;

			Vector():
				_arr(NULL), _len(0), _cap(0)
			{
			}

			explicit Vector(size_type count, const value_type& value = value_type()):
				_arr(NULL), _len(0), _cap(0)
			{
				insert(begin(), count, value);
			}

			template <typename InputIt>
			Vector(InputIt first, InputIt last):
				_arr(NULL), _len(0), _cap(0)
			{
				insert(begin(), first, last);
			}

			Vector(const Vector<T>& other):
				_arr(NULL), _len(0), _cap(0)
			{
				insert(begin(), other.begin(), other.end());
			}

			~Vector()
			{
				std::allocator<T> alloc;
				for (size_t i = 0; i < _len; i++)
					alloc.destroy(&_arr[i]);
				alloc.deallocate(_arr, _cap);
			}

			Vector<T>& operator=(const Vector<T>& other)
			{
				clear();
				insert(begin(), other.begin(), other.end());
				return *this;
			}

			iterator begin()
			{
				return _arr;
			}

			const_iterator begin() const
			{
				return _arr;
			}

			iterator end()
			{
				return _arr + _len;
			}

			const_iterator end() const
			{
				return _arr + _len;
			}

			reverse_iterator rbegin()
			{
				return ReverseIterator< VectorIterator<T> >(end());
			}

			const_reverse_iterator rbegin() const
			{
				return ReverseIterator< VectorIterator<T> >(end());
			}

			reverse_iterator rend()
			{
				return ReverseIterator< VectorIterator<T> >(begin());
			}

			const_reverse_iterator rend() const
			{
				return ReverseIterator< VectorIterator<T> >(begin());
			}

			// capacity

			size_type size() const
			{
				return _len;
			}

			size_type max_size() const
			{
				// 64 bit pointers -- 2**64 / sizeof(T)
				return 18446744073709551615uL / sizeof(T);
			}

			void resize(size_t count, T value = T())
			{
				if (count >= _len)
					insert(end(), count - _len, value);
				else
					erase(begin() + count, end());
			}

			size_type capacity() const
			{
				return _cap;
			}

			bool empty() const
			{
				return _len == 0;
			}

			void reserve(size_type new_cap)
			{
				if (new_cap <= _cap) // no reallocation when not needed
					return;

				if (!new_cap) // no empty allocation
					return;

				std::allocator<T> alloc;
				T* new_arr = alloc.allocate(new_cap);
				for (size_t i = 0; i < _len; i++)
				{
					alloc.construct(&new_arr[i], _arr[i]);
					alloc.destroy(&_arr[i]);
				}

				alloc.deallocate(_arr, _cap);
				_arr = new_arr;
				_cap = new_cap;
			}

			//Element access
			reference operator[](size_type pos)
			{
				return _arr[pos];
			}

			const_reference operator[](size_type pos) const
			{
				return _arr[pos];
			}

			reference at(size_type pos)
			{
				if (pos >= size())
				{
					std::stringstream ss;
					ss << "index " << pos
						<< " out of bound (size() is " << size()
						<< ")";
					throw std::out_of_range(ss.str());
				}

				return _arr[pos];
			}

			const_reference at(size_t pos) const
			{
				if (pos >= _len)
				{
					std::stringstream ss;
					ss << "index " << pos
						<< " out of bound (size() is " << size()
						<< ")";
					throw std::out_of_range(ss.str());
				}

				return _arr[pos];
			}

			reference front()
			{
				return _arr[0];
			}

			const_reference front() const
			{
				return _arr[0];
			}

			reference back()
			{
				return _arr[_len - 1];
			}

			const_reference back() const
			{
				return _arr[_len - 1];
			}

			//Modifiers
			void assign(size_type count, const value_type& value)
			{
				clear();
				insert(begin(), count, value);
			}

			template <typename InputIt>
			void assign(InputIt first, InputIt last)
			{
				clear();
				insert(begin(), first, last);
			}

			void push_back(const value_type& value)
			{
				insert(end(), value);
			}

			void pop_back()
			{
				erase(end() - 1);
			}
			iterator insert(iterator pos, const value_type& value)
			{
				insert(pos, 1, value);
				return pos;
			}

			void insert( iterator pos, size_type count, const value_type& value )
			{
				size_t index = pos.ptr() - _arr;
				if (!count)
					return;
				reserve(_len + count); // reserve more space for count new elements
				std::allocator<T> alloc;

				for (std::ptrdiff_t i = _len - 1; i >= (std::ptrdiff_t)index; i--)
				{
					// move elements count times to the right
					alloc.construct(&_arr[i + count], _arr[i]);
					alloc.destroy(&_arr[i]);
				}

				for (size_t i = index; i < index + count; i++)
					alloc.construct(&_arr[i], value);
				_len += count;
			}

			template <typename InputIt>
			void insert(iterator pos, InputIt first, InputIt last)
			{
				size_t index = pos.ptr() - _arr;
				size_t count = distance(first, last);
				if (!count)
					return;
				reserve(_len + count); // reserve after calculating the index!

				std::allocator<T> alloc;

				for (std::ptrdiff_t i = _len - 1; i >= (std::ptrdiff_t)index; i--)
				{
					// move elements count times to the right
					alloc.construct(&_arr[i + count], _arr[i]);
					alloc.destroy(&_arr[i]);// empty space for new elements
				}

				for (InputIt ite = first; ite != last; ++ite)
					alloc.construct(&_arr[index++], *ite);

				_len += count;
			}

			iterator erase(iterator pos)
			{
				return erase(pos, pos + 1);
			}

			iterator erase(iterator first, iterator last)
			{
				size_t count = last - first;
				if (count <= 0)
					return last;
				size_t index = first.ptr() - _arr;
			
				std::allocator<T> alloc;
				for (size_t i = index; i < index + count; i++)
					alloc.destroy(&_arr[i]); // destroy elements from position

				for (size_t i = index + count; i < _len; i++)
				{
					// move elements count to the left
					alloc.construct(&_arr[i - count], _arr[i]);
					alloc.destroy(&_arr[i]);
				}
				_len -= count;
				return first;
			}
			
			void swap(Vector<T>& other)
			{
				std::swap(_arr, other._arr);
				std::swap(_len, other._len);
				std::swap(_cap, other._cap);
			}

			void clear()
			{
				erase(begin(), end());
			}
	};

	template <typename T>
	bool operator==(const Vector<T>& lhs, const Vector<T>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return false;

		return true;
	}

	template <typename T>
	bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T>
	bool operator<(const Vector<T>& lhs, const Vector<T>& rhs)
	{
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
			if (lhs[i] != rhs[i])
				return lhs[i] < rhs[i];

		if (lhs.size() == rhs.size())
			return false; // lhs == rhs at that point

		return lhs.size() < rhs.size(); // lhs < rhs if lhs is prefix of rhs
	}

	template <typename T>
	bool operator<=(const Vector<T>& lhs, const Vector<T>& rhs)
	{
		return !(lhs > rhs);
	}

	template <typename T>
	bool operator>(const Vector<T>& lhs, const Vector<T>& rhs)
	{
		return rhs < lhs;
	}

	template <typename T>
	bool operator>=(const Vector<T>& lhs, const Vector<T>& rhs)
	{
		return !(lhs < rhs);
	}

	template <typename T>
	void swap(Vector<T>& lhs, Vector<T>& rhs)
	{
		rhs.swap(lhs);
	}
}

#endif
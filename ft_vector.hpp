#pragma once
#include <memory> // for std::allocator
#include <iterator> // for itterator traits
// #include <>

namespace ft {
template < class T, class Allocator = std::allocator<T> >
class vector {
	public:
		/*---------------------------Iterator traits--------------------------*/
		typedef	T										value_type; 
		typedef Allocator								allocator_type;
		typedef	T*										pointer;
		typedef	const T*								const_pointer;		
		typedef	T&										reference;
		typedef const T&								const_reference;
		typedef size_t		 							size_type;

		typedef	T*										iterator;
		// typedef	std::iterator_traits<iterator>::difference_type	difference_type;
		// typedef	std::__is_random_access_iterator<T, const T*, const T&>	const_iterator;
		// typedef	reverse_iterator<iterator>						reverse_iterator;
		// typedef	reverse_iterator<const_iterator>				const_reverse_iterator;
		

		typedef typename ft::iterator_traits<iterator>	trait; // formatting
		typedef random_access_iterator					rai; // formatting
		typedef rai<T, T*, T&>							iterator;
		typedef	trait::difference_type					difference_type;
		typedef rai<T, T*, T&>							iterator;
		typedef	rai<T, const T*, const T&>				const_iterator;
		typedef	reverse_iterator<iterator>				reverse_iterator;
		typedef	reverse_iterator<const_iterator>		const_reverse_iterator;

	private:
		/*--------------------------Member variables--------------------------*/
		allocator_type									_allocator;
		value_type*										_data;
		size_type										_size;
		size_type										_capacity;

	public:
		/*----------------------------Constructors----------------------------*/
		explicit vector(const allocator_type& alloc = allocator_type()) : 
			 _allocator(alloc), _data(NULL), _size(0)
			{ _capacity = _allocator.max_size(); }

		// explicit vector(size_type n, const value_type& val = value_type()

		// const allocator_type& alloc = allocator_type());

		// template <class InputIterator>
		// vector(InputIterator first, InputIterator last,
		// 	 const allocator_type& alloc = allocator_type());

		// vector(const vector& x);


		/*-----------------------------Equals opp-----------------------------*/
		// vector& operator=(const vector& x);

		/*-----------------------------Destructor-----------------------------*/
		~vector() { _allocator.deallocate(_data, _capacity); }

		/*------------------------------Capacity------------------------------*/
		size_type size() const { return _size; }

		size_type max_size() const { return _allocator.max_size(); }

		void resize (size_type n, value_type val = value_type()) {
			if (n < _size)
			{
				while (n >= _size) {
					this->pop_back();
					--n;
				}
			}
			else
			{
				while (n <= _size) {
					this->push_back(val);
					++n;
				}
			}
		}

		size_type capacity() const { return _capacity; }

		bool empty() const { return _size == 0 ? true : false; }

		void reserve(size_type n) {
			if (n > max_size())
				return ;
			if (n > _capacity)
			{
				value_type	*tmp = _allocator.allocate(n, &_data);
				for (size_type i = 0; i < _size; i++)
					tmp[i] = _data[i];
				_allocator.deallocate(_data, _size);
				_data = tmp;
				_capacity = n;
			}
		}

		/*------------------------------Modifier------------------------------*/
		void push_back(const T& value) {
			if (_size == _capacity)
			{
				if (_size == _capacity)
					reserve(1);
				else
					reserve(_capacity + 1);
			}
			_data[_size] = value;
			++_size;
		}

		void	pop_back() {
			if (_capacity > 0) {
				erase()
			}
		}

		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
};
}
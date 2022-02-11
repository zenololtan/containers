#pragma once
#include <memory> // for std::allocator
#include <iterator> // for itterator traits

namespace ft {
template <class T, class Allocator = std::allocator<T>>
class vector
{
	public:
		/*---------------------------Iterator traits--------------------------*/
		typedef	T										value_type; 
		typedef Allocator								allocator_type;
		typedef	T*										pointer;
		typedef	const T*								const_pointer;		
		typedef	T&										reference;
		typedef const T&								const_reference;
		typedef size_t		 							size_type;
		typedef typename ft::iterator_traits<iterator>	trait; // formatting
		typedef random_access_iterator					rai; // formatting
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
			{_capacity = _allocator.max_size()}

		// explicit vector(size_type n, const value_type& val = value_type()

		// const allocator_type& alloc = allocator_type());

		// template <class InputIterator>
		// vector(InputIterator first, InputIterator last,
		// 	 const allocator_type& alloc = allocator_type());

		// vector(const vector& x);


		/*-----------------------------Equals opp-----------------------------*/
		vector& operator= (const vector& x);

		/*-----------------------------Destructor-----------------------------*/
		~vector() { _allocator.deallocate(_data, _capacity) }

		/*------------------------------Capacity------------------------------*/
		size_type size() { return _size; } const

		size_type max_size() { return _allocator.max_size(); } const

		// void resize (size_type n, value_type val = value_type()) {
		// 	if (n < _size)

		// }

		size_type capacity() { return _capacity } const

		bool empty() { return _size == 0 ? true : false; } const

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
					resize(1);
				else
					resize(_capacity + 1);
			}
			_data[_size] = value;
			++_size;
		}
		
};

}
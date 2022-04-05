#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <cstddef>

// de iterator class is eigenlijk een label van dingen die een iterator
// nodig heeft om VALID te zijn.
//
// Je kan dit dus zien als een soort LABEL voor iterators waaraan wij kunnen
// uitlezen of het meegegeven data class een iterator is of niet en van welk
// type het is.

// basic data types die een iterator nodig heeft om valid te zjn.
namespace ft {
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag       : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <class Category, class T, class Distance = ptrdiff_t,
			 class Pointer = T*, class Reference = T&>
struct iterator {
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};

// een checker die kijkt of meegegeven data type een iterator is of niet.
// Om dit te krijgen, zijn er twee functies.
// De eerste alles als argument neemt alles als argument en returnd een invalid value.
// De tweede neemt alleen data types met de juiste typedefs voor een iterator en returnd een char.
// De value van de class wordt gezet met een sizeof van 
template<class T>
struct __has_iter_typedefs {
	private:
		typedef char	_true_val; // sizeof 1
		typedef int		_false_val; // sizeof 8
		template<class tT> static _false_val	__test(...);
		template<class tT> static _true_val		__test(typename std::__void_t<typename tT::iterator_category>::type* = 0,
													typename std::__void_t<typename tT::difference_type>::type* = 0,
													typename std::__void_t<typename tT::value_type>::type* = 0,
													typename std::__void_t<typename tT::reference>::type* = 0,
													typename std::__void_t<typename tT::pointer>::type* = 0
												);
	public:
		static const bool value = sizeof(__test<T>(0,0,0,0,0)) == 1
};

// // een checker om te checken of de iter een category heeft.
// // Hier check je of de iterator_category bestaat (en niet alleen de typedef)
// template <class T>
// struct __has_iter_category {
// 	private:
// 		typedef char	_true_val; // sizeof 1
// 		typedef int		_false_val; // sizeof 8
// 		template <class tT> static _false_val	__test(...);
// 		template <class tT> static _true_val	__test(typename tT::iterator_category* = 0);
// 	public:
// 		static const bool value = sizeof(__test<T>(0)) == 1;
// };

// enable if voor SFINAE
// dit houdt in dat op compile time gecheckt wordt of de data type een legit
// iterator is of niet.
template<bool B, typename T = void>
struct enable_if {};

template<typename T>
struct enable_if<true, T> { typedef T type; };

template<typename T>
struct iterator_traits : public enable_if<__has_iter_typedefs<T>::result, T> {};

template<typename T>
struct iterator_traits<T*> {
	typedef random_access_iterator_tag type;
};
}

#endif
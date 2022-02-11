#include "test.hpp"

/*--------------------------------Coplien form--------------------------------*/
test::test()
{
	/*Constructor*/
}

test::~test()
{
	/*Destructor*/
}

test::test(const test &ref)
{
	/*Copy constructor*/
	*this = ref;
}

test&	test::operator=(const test &ref)
{
	/*Assignation operator*/
	if (this != &ref)
	{
		/* assign member variables*/
	}
	return *this;
}
/*--------------------------------Coplien form--------------------------------*/

std::ostream&	operator<<(std::ostream &out, const test &ref)
{
	/*Output operator*/
	/*out << test;
	return out;*/
}
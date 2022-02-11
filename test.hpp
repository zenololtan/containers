#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>

class test
{
	private:
		/*--------------------------Member variables--------------------------*/

	public:
		/*----------------------------Coplien form----------------------------*/
		test();
		test(const test &ref);
		test& operator=(const test &ref);
		~test();

		/*--------------------------Member functions--------------------------*/

};

std::ostream&	operator<<(std::ostream &out, const test &ref);

#endif

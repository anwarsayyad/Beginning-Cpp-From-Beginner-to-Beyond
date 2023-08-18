#include <iostream>
#include "function_template.h"
//Generic programming can be implemented in 2 ways-
//  1. using macros (Beware of types)
//  2. Templates
//			-function templates
//			-class templates

//Macros
#define PI 3.14156 //first the compiler removes the #define statements and goes in the code to replace  (NOTE: No types checking is done)

#define max(a,b) ((a > b) ? a:b)
#define SQUARE(a) a*a //we have a major problem here(NOTE: always write the function logic between paranthesis )
//#define SQUARE(a) (a*a) //this is the correct way of defining

struct Player {
	std::string name;
	int age;
	bool operator<(const Player& rhs) const { //to make sure the comparison between objects work,and the comparison logic is manual task (I am checking for the age)
		return this->age < rhs.age;
	}
	//int getAge() {
	//	return age;
	//}

};

std::ostream& operator<<(std::ostream& os, const Player& p) { //this will make sure if a Player object is passed to <<, it will return the name of the object (as per our logic)
	os << p.name;
	return os;
};

int main()
{
	std::cout << PI << std::endl;
	std::cout << max(10, 20) << std::endl;
	std::cout << max(2.4, 4.3) << std::endl;
	std::cout << max('A', 'C') << std::endl; //now we have used the generic programming here, the #define max function will work for any type, as long as the syntax and semantics are satisfied,BUT instead of all those complications, the BETTER way to do is still using the templates)

	std::cout << 50 / SQUARE(5) << std::endl; //if precessor is defined like- #define SQUARE(a) a*a , then after substitution the statement will look like 50/5*5 = 50(which is not we wanted, we expected a result of 2), that is why it is always recommended to use paranthesis in preprocessor function logic

	function_template temp;
	temp.func<double, long>(40.5, 30);
	std::cout << temp.min<int>(40, 20) << std::endl;
	std::cout << temp.min<char>('A', 'B') << std::endl;

	Player messi{ "messi",18 };
	Player ronaldo{ "ronaldo",20 };
	std::cout << temp.min(messi, ronaldo).name << std::endl;
	//(temp.min() will automatically get converted to temp.min<Player>
	//it will not work for any user-defined object out of the box, because how does compiler even know what is a comparison between two object is?, for this to overcome, we can do operator overloading and make sure the min function will work with our stated logic for function comparison


	temp.func<Player>(messi, ronaldo); //overloading the std::ostream for this case

	temp.swap<int>(40, 302);
}

#include <iostream>

class function_template {
public:
	template <typename T>
	T min(T a, T b) {
		return (a < b) ? a : b;
	}
	template <typename T, typename T2> //we can use the typename `T` here even though we defined the same name to the `min` method's template, because both are completely independent of each other
	void func(T a, T2 b) {
		std::cout << a << " " << b << std::endl;
	}

	template <typename T>
	void swap(T&& a, T&& b) {
		std::cout << "Before swap: " << a << " " << b << std::endl;
		T temp{ a };
		a = b;
		b = temp;
		std::cout << "After swap: " << a << " " << b << std::endl;
	}
};


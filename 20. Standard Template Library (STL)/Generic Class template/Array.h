#pragma once
//user defined class Template (understanding how Array can be moleded to our usecase and scenarios(not focus on efficiency btw))
#include <type_traits>


//NOTE: use std::array instead of raw array, this is preferred becuase we can have access to iterators from STL
template <typename T, int N> // template <int N> this represents non-type template parameters
class Array
{
	size_t size{ N };
	T values[N]; //internally using the c++ array

	//friend std::ostream& operator <<(std::ostream& os, Array<T, N>& arr) {
	//	os << "[";
	//	for (auto& item : arr.values) {
	//		os << item << " ";
	//	}
	//	os << "]";
	//}

public:
	Array() {
		for (auto& item : values) {
			/*	if (std::is_same < T, int>::value)
					item = 0;
				if (std::is_same < T, std::string>::value)
					item = "Nil";*/
			item = 0;
		}
	};
	//Array() {};
	Array(T user_value) {
		for (auto& item : values) {
			item = user_value;
		}
	}

	void fillAllWith(T user_value) {
		for (auto& item : values) {
			item = user_value;
		}
	}

	int getSize() {
		return size;
	}

	void getValues() {
		for (auto& item : values) {
			std::cout << item << std::endl;
		}
	}

	T& operator[](int index) {
		return values[index];
	}

};


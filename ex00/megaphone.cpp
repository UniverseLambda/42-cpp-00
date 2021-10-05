/**
 * @file megaphone.cpp
 *
 * @date 05/10/2021
 * @author Clément "UniverseLambda" SAAD
*/

#include <iostream>
#include <string>

#include <cctype>

static void print_this_loud(std::string str) {
	for (size_t i = 0; i < str.size(); ++i) {
		str[i] = std::toupper(str[i]);
	}
	std::cout << str;
}

int main(int argc, const char *argv[]) {
	if (argc <= 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {
		for (int i = 1; i < argc; ++i) {
			print_this_loud(argv[i]);
		}
	}

	std::cout << std::endl;
	return 0;
}

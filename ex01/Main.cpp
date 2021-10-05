/**
 * @file Main.cpp
 *
 * @date 05/10/2021
 * @author Clément "UniverseLambda" SAAD
*/

#include "Phonebook.hpp"

#include <iostream>

int main() {
	cpp01::Phonebook phonebook;
	std::string cmd;

	std::cout << "Welcome :)" << std::endl;
	std::cout << "This is a PhoneBook" << std::endl;
	std::cout << "A book for phone" << std::endl;
	std::cout << "Yup" << std::endl;

	while (true) {
		std::cout << "phonebook> ";
		std::getline(std::cin, cmd);

		if (std::cin.eof()) {
			break;
		}

		if (cmd == "ADD") {
			if (!phonebook.add()) {
				break;
			}
		} else if (cmd == "SEARCH") {
			if (!phonebook.search()) {
				break;
			}
		} else if (cmd == "EXIT") {
			break;
		}
	}

	return 0;
}

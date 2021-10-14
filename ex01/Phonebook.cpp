/**
 * @file Phonebook.cpp
 *
 * @date 05/10/2021
 * @author Clément "UniverseLambda" SAAD
*/

#include "Phonebook.hpp"

#include <iostream>
#include <cctype>

#include <sstream>

#include <cstdlib>

namespace cpp01 {
	static bool askField(std::string field, std::string &out);
	static std::string toColumnData(std::string s);
	static bool readIndex(std::string prompt, std::size_t &index, std::size_t limit);

	Phonebook::Phonebook(): mLimit(0) {
	}

	bool Phonebook::add() {
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
		Contact result;

		if (!askField("First name", firstName)) {
			return false;
		}

		if (!askField("Last name", lastName)) {
			return false;
		}

		if (!askField("Nickname", nickname)) {
			return false;
		}

		if (!askField("Phone number", phoneNumber)) {
			return false;
		}

		if (!askField("Darkest secret", darkestSecret)) {
			return false;
		}

		result = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
		return add(result);
	}

	bool Phonebook::add(Contact &contact) {
		unsigned long index;

		if (mLimit < 8) {
			mContacts[mLimit++] = contact;
			return true;
		}

		std::cout << "Woops. It seems that we cannot add more contact because this mac doesn't know how to properly handle memory :(" << std::endl;
		std::cout << "But you can sacrifice the contact of one of your dearest and closest friends to add this one" << std::endl;

		std::cout << "Current contacts in phonebook:" << std::endl;
		for (std::size_t i = 0; i < mLimit; ++i) {
			std::cout << "- " << i << ": " << mContacts[i].getFirstName() << std::endl;
		}

		if (!readIndex("Please choose one (or type 9 to cancel the operation): ", index, mLimit)) {
			return false;
		}

		if (index == 9) {
			std::cout << "Operation #cancelled" << std::endl;
			return true;
		}

		mContacts[--index] = contact;
		return true;
	}

	bool Phonebook::search() {
		std::size_t index;

		for (std::size_t i = 0; i < mLimit; ++i) {
			Contact &c = mContacts[i];

			std::cout << '|' << "         " << (i + 1);
			std::cout << '|' << toColumnData(c.getFirstName());
			std::cout << '|' << toColumnData(c.getLastName());
			std::cout << '|' << toColumnData(c.getNickname());
			std::cout << '|' << std::endl;
		}

		if (!readIndex("Select a contact (or type 9 to cancel the operation): ", index, mLimit)) {
			return false;
		}

		if (index == 9) {
			std::cout << "Operation #cancelled" << std::endl;
			return true;
		}

		--index;

		std::cout << "First name: " << mContacts[index].getFirstName() << std::endl;
		std::cout << "Last name: " << mContacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << mContacts[index].getNickname() << std::endl;
		std::cout << "Phone number: " << mContacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << mContacts[index].getDarkestSecret() << std::endl;

		return true;
	}

	std::size_t Phonebook::count() const {
		return mLimit;
	}

	Contact &Phonebook::at(std::size_t idx) {
		if (idx >= mLimit) {
			throw std::out_of_range("Contact index out of range");
		}

		return mContacts[idx];
	}

	Contact &Phonebook::operator[](std::size_t idx) {
		return at(idx);
	}

	static std::string toColumnData(std::string s) {
		std::stringstream ss;
		std::string result;

		if (s.size() < 10) {
			for (std::size_t i = s.size(); i < 10; ++i) {
				ss << ' ';
			}
		}

		for (std::size_t i = 0; i < s.size() && i < 10; ++i) {
			ss << s[i];
		}

		result = ss.str();
		if (s.size() > 10) {
			result[9] = '.';
		}
		return result;
	}

	static bool askField(std::string field, std::string &out) {
		std::cout << field << ": ";
		std::getline(std::cin, out);
		if (!std::cin.good()) {
			// Awwww he's not good :(
			return false;
		}
		return true;
	}

	static bool readIndex(std::string prompt, std::size_t &index, std::size_t limit) {
		while (true) {
			std::string tmp;
			bool badFormat = false;

			std::cout << prompt;
			getline(std::cin, tmp);
			if (std::cin.eof()) {
				return false;
			}

			if (tmp.empty()) {
				continue;
			}

			for (std::size_t i = 0; i < tmp.size(); ++i) {
				if (!std::isdigit(tmp[i])) {
					badFormat = true;
					break;
				}
			}

			if (badFormat) {
				std::cout << "Bad input: `" << tmp << "'" << std::endl;
				continue;
			}

			index = std::strtoul(tmp.c_str(), NULL, 10);

			if (index < 1 || (index > limit && index != 9)) {
				std::cout << "Invalid index: " << index << std::endl;
				continue;
			}
			break;
		}
		return true;
	}
} // namespace cpp01

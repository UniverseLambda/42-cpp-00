/**
 * @file Contact.hpp
 *
 * @date 05/10/2021
 * @author Clément "UniverseLambda" SAAD
*/

#pragma once

#include <string>

namespace cpp01 {
	class Contact {
	private:
		std::string mFirstName;
		std::string mLastName;
		std::string mNickname;
		std::string mPhoneNumber;
		std::string mDarkestSecret;

	public:
		Contact();
		Contact(std::string &firstName, std::string &lastName, std::string &nickname, std::string &phoneNumber, std::string &darkestSecret);

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
	};
} // namespace cpp01

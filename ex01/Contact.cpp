/**
 * @file Contact.cpp
 *
 * @date 05/10/2021
 * @author Clément "UniverseLambda" SAAD
*/

#include "Contact.hpp"

namespace cpp01 {
	Contact::Contact() {
	}

	Contact::Contact(std::string &firstName, std::string &lastName, std::string &nickname, std::string &phoneNumber, std::string &darkestSecret):
		mFirstName(firstName),
		mLastName(lastName),
		mNickname(nickname),
		mPhoneNumber(phoneNumber),
		mDarkestSecret(darkestSecret) {
	}

	std::string Contact::getFirstName() const {
		return mFirstName;
	}

	std::string Contact::getLastName() const {
		return mLastName;
	}

	std::string Contact::getNickname() const {
		return mNickname;
	}

	std::string Contact::getPhoneNumber() const {
		return mPhoneNumber;
	}

	std::string Contact::getDarkestSecret() const {
		return mDarkestSecret;
	}
} // namespace cpp01

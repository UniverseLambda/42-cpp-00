/**
 * @file Phonebook.hpp
 *
 * @date 05/10/2021
 * @author Clément "UniverseLambda" SAAD
*/

#pragma once

#include <string>

#include "Contact.hpp"

#include <stdexcept>

namespace cpp01 {
	class Phonebook	{
	private:
		Contact mContacts[8];
		std::size_t mLimit;

	public:
		Phonebook();

		bool add();
		bool add(Contact &contact);

		bool search();

		std::size_t count() const;
		Contact &at(std::size_t idx);
		Contact &operator[](std::size_t idx);
	};
} // namespace cpp01

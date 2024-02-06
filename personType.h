#pragma once
#include <iostream>
#include <string>

class personType {
public:
	personType() {
		firstName = "";
		lastName = "";
	}
	personType(std::string F, std::string L) {
		setFirstName(F);
		setLastName(L);
	}
	void setFirstName(std::string F) {
		firstName = F;
	}
	std::string getFirstName() {
		return firstName;
	}
	void setLastName(std::string L) {
		lastName = L;
	}
	std::string getLastName() {
		return lastName;
	}
private:
	std::string firstName;
	std::string lastName;
};


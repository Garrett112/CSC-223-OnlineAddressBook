#include <iostream>
#include <string>

#include "dateType.h"
#include "addressType.h"
#include "personType.h"

class extPersonType :personType {
public:
	extPersonType() {
		phoneNumber = "";
		relationship = "";
	}
	extPersonType(std::string F, std::string L, int M, int D, int Y, std::string A, std::string C, std::string S, int Z, std::string P, std::string R) {
		setFirstName(F);
		setLastName(L);
		address.setAddress(A);
		address.setCity(C);
		address.setState(S);
		address.setZipcode(Z);
		birthday.setDate(M, D, Y);
		setPhoneNumber(P);
		setRelationship(R);
	}
	void setPhoneNumber(std::string N) {
		phoneNumber = N;
	}
	std::string getPhoneNumber() {
		return phoneNumber;
	}
	void setRelationship(std::string R) {
		if (R == "Family" || R == "Friend" || R == "Business") {
			relationship = R;
		}
		else {
			std::cerr << "Invalid relationship, please enter Family, Friend, or Business." << std::endl;
			relationship = "";
		}
	}
	std::string getRelationship() {
		return relationship;
	}
	int getBirthMonth() {
		return birthday.getMonth();
	}
	void print() {
		std::cerr << getFirstName() << " " << getLastName() << std::endl;
		birthday.print();
		address.print();
		std::cerr << phoneNumber << std::endl << relationship << std::endl;

	}
private:
	addressType address;
	dateType birthday;
	std::string phoneNumber;
	std::string relationship;
};




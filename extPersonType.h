#include <iostream>
#include <string>

#include "dateType.h"
#include "addressType.h"
#include "personType.h"

using namespace std;

class extPersonType :personType {
public:
	extPersonType() {														//constructor
		phoneNumber = "";													//sets default phoneNumber as  ""
		relationship = "";													//sets default relationship as ""
	}
	extPersonType(std::string F, std::string L, int M, int D, int Y, std::string A, std::string C, std::string S, int Z, std::string P, std::string R) {
		setFirstName(F);													//calls member function setFirstName
		setLastName(L);														//calls member function setLastName
		address.setAddress(A);												//calls the addressType member function setAddress
		address.setCity(C);													//calls the addressType member function setCity
		address.setState(S);												//calls the addressType member function setState
		address.setZipcode(Z);												//calls the addressType member function setZipcode
		birthday.setDate(M, D, Y);											//calls the dateType member function setDate
		setPhoneNumber(P);													//calls the member function setPhoneNumber
		setRelationship(R);													//calls the member function setRelationship
	}
	void setPhoneNumber(std::string N) {									//uses one string as a formal parameter
		phoneNumber = N;													//sets phoneNumber as the parameter N
	}	
	std::string getPhoneNumber() {											//has no formal parameters
		return phoneNumber;													//returns the current value for phoneNumber
	}
	void setRelationship(std::string R) {									//uses one string as a formal parameter
		if (R == "Family" || R == "Friend" || R == "Business") {			//checks if R is "Family" "Friend" or "Business"
			relationship = R;												//sets relationship as parameter R if true
		}
		else {																//gives error message and sets relationship to default if false
			std::cerr << "Invalid relationship, please enter Family, Friend, or Business." << std::endl;
			relationship = "";
		}
	}
	std::string getRelationship() {											//has no formal parameters
		return relationship;												//returns current value of relationship
	}
	int getBirthMonth() {													//has no formal parameters
		return birthday.getMonth();											//returns the value of the dateType member function getMonth
	}
	void print() {															//has no formal parameters
		std::cerr << getFirstName() << " " << getLastName() << std::endl;	//prints firstName, lastName, endl
		birthday.print();													//calls the dateType member function print
		address.print();													//calls the addressType member function print
		std::cerr << phoneNumber << std::endl << relationship << std::endl;	//prints phoneNumber, endl, relationship, endl

	}
private:
	addressType address;
	dateType birthday;
	std::string phoneNumber;
	std::string relationship;
};




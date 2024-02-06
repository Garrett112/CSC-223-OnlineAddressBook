#pragma once
#include <iostream>
#include <string>

class personType {
public:
	personType() {										//contructor
		firstName = "";									//sets firstName to default ""
		lastName = "";									//sets lastName to default ""
	}
	personType(std::string F, std::string L) {			//takes 2 strings as formal parameters
		setFirstName(F);								//calls member function setFirstName with parameter F
		setLastName(L);									//calls member function setLastName with parameter L
	}
	void setFirstName(std::string F) {					//takes 1 string as formal parameters
		firstName = F;									//sets firstName equal to parameter F
	}	
	std::string getFirstName() {						//has no formal parameters
		return firstName;								//returns firstName
	}
	void setLastName(std::string L) {					//takes 1 string as formal parameter
		lastName = L;									//sets lastName eqaul to parameter L
	}
	std::string getLastName() {							//has no formal parameters
		return lastName;								//returns lastName
	}
private:
	std::string firstName;
	std::string lastName;
};


#pragma once

#ifndef addressT
#define addressT

#include <iostream>
#include <string>

class addressType {
public:
	addressType() {								//constructor
		address = "";							//sets address
		city = "";								//sets city
		state = "XX";							//sets state as XX
		zipcode = 10000;						//sets zipcode as 10000
	}
	addressType(const std::string& addressName, const std::string& cityName, const std::string& stateAbbv, int zipC) {
		setAddress(addressName);				//puts input address into setAddress 
		setCity(cityName);						//puts input city into setCity
		setState(stateAbbv);					//puts input state into setState
		setZipcode(zipC);						//puts input zipcode into setZipcode
	}
	void setAddress(const std::string& addressName) {
		address = addressName;					//sets address as the input
	}
	void setCity(const std::string& cityName) {
		city = cityName;						//sets city as the input
	}
	void setState(const std::string& stateAbbv) {
		if (stateAbbv.length() == 2) {			//checks if the state is 2 characters
			state = stateAbbv;					//sets state as the input if it is 2 characters
		}
		else {									//gives error message if state is not 2 characters 
			std::cerr << "Invalid state, please enter as a two letter abbreviation." << std::endl;
			state = "XX";						//sets the state as the default XX
		}	
	}
	void setZipcode(int zipC) {
		if (zipC >= 11111 && zipC <= 99999) {	//checks if the input zip falls between 11111 and 99999
			zipcode = zipC;						//sets zipcode as the input if it falls between 11111 and 99999
		}
		else {									//gives error message if the zipcode does not fall between 11111 and 99999
			std::cerr << "Invalid zipcode, please enter a valid 5-digit zipcode." << std::endl;
			zipcode = 10000;					//sets the zipcode as the default 10000
		}
	}
	std::string getAddress() {
		address;								//outputs current address
	}
	std::string getCity() {
		city;									//outputs current address
	}
	std::string getState() {
		state;									//outputs current state
	}
	std::string getZip() {
		zipcode;								//outputs current zipcode
	}
	void print() const {						//prints address, city, state, and zipcode
		std::cout << address << std::endl << city << " " << state << ", " << zipcode << std::endl;
	}
private:
	std::string address;
	std::string city;
	std::string state;
	int zipcode;
};

#endif
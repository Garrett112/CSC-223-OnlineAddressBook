#pragma once

#ifndef addressT
#define addressT

#include <iostream>
#include <string>

class addressType {
public:
	addressType() {
		address = "";
		city = "";
		state = "XX";
		zipcode = 10000;
	}
	addressType(const std::string& addressName, const std::string& cityName, const std::string& stateAbbv, int zipC) {
		setAddress(addressName);
		setCity(cityName);
		setState(stateAbbv);
		setZipcode(zipC);
	}
	void setAddress(const std::string& addressName) {
		address = addressName;
	}
	void setCity(const std::string& cityName) {
		city = cityName;
	}
	void setState(const std::string& stateAbbv) {
		if (stateAbbv.length() == 2) {
			state = stateAbbv;
		}
		else {
			std::cerr << "Invalid state, please enter as a two letter abbreviation." << std::endl;
			state = "XX";
		}
	}
	void setZipcode(int zipC) {
		if (zipC >= 11111 && zipC <= 99999) {
			zipcode = zipC;
		}
		else {
			std::cerr << "Invalid zipcode, please enter a valid 5-digit zipcode." << std::endl;
			zipcode = 10000;
		}
	}
	std::string getAddress() {
		address;
	}
	std::string getCity() {
		city;
	}
	std::string getState() {
		state;
	}
	std::string getZip() {
		zipcode;
	}
	void print() const {
		std::cout << address << std::endl << city << " " << state << ", " << zipcode << std::endl;
	}
private:
	std::string address;
	std::string city;
	std::string state;
	int zipcode;
};

#endif
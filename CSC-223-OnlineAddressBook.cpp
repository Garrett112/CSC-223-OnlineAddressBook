#include <iostream>
#include <string>
using namespace std;

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

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include <iostream>
#include <string>
#include <istream>
#include <fstream>

using namespace std;

class addressType {
public:
	addressType() {								//constructor
		address = "";							//sets address
		city = "";								//sets city
		state = "XX";							//sets state as XX
		zipcode = "10000";						//sets zipcode as 10000
	}
	addressType(string addressName, string cityName, string stateAbbv, string zipC) {
		setAddress(addressName);				//puts input address into setAddress 
		setCity(cityName);						//puts input city into setCity
		setState(stateAbbv);					//puts input state into setState
		setZipcode(zipC);						//puts input zipcode into setZipcode
	}
	void setAddress(string addressName) {
		address = addressName;					//sets address as the input
	}
	void setCity(string cityName) {
		city = cityName;						//sets city as the input
	}
	void setState(string stateAbbv) {
		if (stateAbbv.length() == 2) {			//checks if the state is 2 characters
			state = stateAbbv;					//sets state as the input if it is 2 characters
		}
		else {									//gives error message if state is not 2 characters 
			cout << "Invalid state, please enter as a two letter abbreviation." << endl;
			state = "XX";						//sets the state as the default XX
		}
	}
	void setZipcode(string zipC) {
		zipcode = zipC;						//sets zipcode as the input
	}
	string getAddress() {
		return address;								//outputs current address
	}
	string getCity() {
		return city;									//outputs current address
	}
	string getState() {
		return state;									//outputs current state
	}
	string getZip() {
		return zipcode;								//outputs current zipcode
	}
	void print() {						//prints address, city, state, and zipcode
		cout << address << endl << city << " " << state << ", " << zipcode << endl;
	}
private:
	string address;
	string city;
	string state;
	string zipcode;
};

class dateType {
public:
	dateType() {										//constructor
		month = 1;										//sets default month to 1
		day = 1;										//sets default day to 1
		year = 1900;									//sets default year to 1900
	}
	dateType(int D, int M, int Y) {
		setDate(D, M, Y);								//plugs input date into setDate
	}
	void setDate(int M, int D, int Y) {

		if (M >= 1 && M <= 12) {						//checks if input month falls between 1 and 12
			month = M;									//sets month as input value
		}
		else {											//outputs error message and resets month value
			std::cerr << "Invalid Month, please enter a value between 1 and 12" << std::endl;
			month = 1;
		}
		if (M == 4 || M == 6 || M == 11) {				//checks if input month is 4, 6, or 11
			if (D >= 1 && D <= 30) {					//checks if input day falls between 1 and 30
				day = D;								//sets day as input value
			}
			else {										//outputs error message and resets day value
				cout << "Invalid Day, the selected month has 30 days" << endl;
				day = 1;
			}
		}
		else {
			if (M == 2) {								//checks if input month is 2
				if (isLeapYear(Y) == true) {			//checks if leap year is true
					if (D >= 1 && D <= 29) {			//checks if input day falls between 1 and 29
						day = D;						//sets day as input value
					}
					else {								//outputs error message and resets day value
						cout << "Invalid Day, the selected month has 29 days" << endl;
						day = 1;
					}
				}
				else {
					if (D >= 0 && D <= 28) {			//checks if input day falls between 1 and 28
						day = D;						//sets day as input value
					}
					else {								//outputs error message and resets day value
						cout << "Invalid Day, the selected month has 28 days" << endl;
						day = 1;
					}
				}
			}
			else {
				if (D >= 1 && D <= 31) {				//checks if input day falls between 1 and 31
					day = D;							//sets day as input value
				}
				else {									//outputs error message and resets day value
					cout << "Invalid Day, the selected month has 31 days" << endl;
					day = 1;
				}
			}
		}
		if (Y >= 1900) {								//checks if input year is after 1899
			year = Y;									//sets year as input value
		}
		else {											//outputs error message and resets year value
			cout << "Invalid Year, please enter a value of 1900 or above" << endl;
			year = 1900;
		}

	}
	int getDay() {
		return day;										//returns current day
	}
	int getMonth() {
		return month;									//returns current month
	}
	int getYear() {
		return year;									//returns current year
	}
	void print() {										//prints date in correct format
		cout << day << "-" << month << "-" << year << endl;
	}
	bool isLeapYear(int Y) {
		if (Y % 4 == 0) {								//checks if the year is evenly divisible by 4
			if (Y % 100 == 0) {							//checks if the year is evenly divisible by 100
				if (Y % 400 == 0) {						//checks if the year is evenly divisible by 400
					return true;						//returns true
				}
				else {
					return false;						//returns false
				}
			}
			else {
				return true;							//returns true
			}
		}
		else {
			return false;								//returns false
		}
	}


private:
	int month;
	int day;
	int year;
};

class personType {
public:
	personType() {										//contructor
		firstName = "";									//sets firstName to default ""
		lastName = "";									//sets lastName to default ""
	}
	personType(string F, string L) {			//takes 2 strings as formal parameters
		setFirstName(F);								//calls member function setFirstName with parameter F
		setLastName(L);									//calls member function setLastName with parameter L
	}
	void setFirstName(string F) {					//takes 1 string as formal parameters
		firstName = F;									//sets firstName equal to parameter F
	}
	string getFirstName() {						//has no formal parameters
		return firstName;								//returns firstName
	}
	void setLastName(string L) {					//takes 1 string as formal parameter
		lastName = L;									//sets lastName eqaul to parameter L
	}
	string getLastName() {							//has no formal parameters
		return lastName;								//returns lastName
	}
private:
	string firstName;
	string lastName;
};

class extPersonType : public personType {
public:
	extPersonType() {														//constructor
		phoneNumber = "";													//sets default phoneNumber as  ""
		relationship = "";													//sets default relationship as ""
	}
	extPersonType(string F, string L, int M, int D, int Y, string A, string C, string S, string Z, string P, string R) {
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
	addressType address;
	dateType birthday;
private:
	std::string phoneNumber;
	std::string relationship;
};

class addressBookType {
public:
	addressBookType() {
		length = 0;
		maxLength = 200;
	}
	void initEntry() {
		int i = 0;
		string tempFname;
		string tempLname;
		int tempDay;
		int tempMonth;
		int tempYear;
		string tempAddress;
		string tempCity;
		string tempState;
		string tempZip;
		string tempPhone;
		string tempRelation;
		string line;
		ifstream file("AddressBookData.txt");
		while (i < 6) {
			cout << i << endl;
			file >> tempFname >> tempLname;
			addressList[i].setFirstName(tempFname);
			addressList[i].setLastName(tempLname);
			file >> tempDay >> tempMonth >> tempYear;
			addressList[i].birthday.setDate(tempMonth, tempDay, tempYear);
			getline(file, tempAddress);
			getline(file, tempAddress);
			addressList[i].address.setAddress(tempAddress);
			getline(file, tempCity);
			file >> tempState >> tempZip;
			addressList[i].address.setCity(tempCity);
			addressList[i].address.setState(tempState);
			addressList[i].address.setZipcode(tempZip);
			file >> tempPhone >> tempRelation;
			addressList[i].setPhoneNumber(tempPhone);
			addressList[i].setRelationship(tempRelation);
			++length;
			++i;
		}
	}

	void addEntry(extPersonType E) {
		if (length < maxLength) {
			length++;
			addressList[length] = E;
		}
		else {
			cout << "Array has reached it's maximum capacity." << endl;
		}
	}
	void findPerson(string lName) {
		for (int i = 0; i <= length; ++i) {
			if (addressList[i].getLastName() == lName) {
				addressList[i].print();
			}
		}
	}
	void findBirthdays(int bDayMonth) {
		for (int i = 0; i <= length; ++i) {
			if (addressList[i].getBirthMonth() == bDayMonth) {
				addressList[i].print();
			}
			else {}
		}
	}
	void findRelationship(string rShip) {
		for (int i = 0; i <= length; ++i) {
			if (addressList[i].getRelationship() == rShip) {
				addressList[i].print();
			}
			else {}
		}
	}
	void print() {
		for (int i = 0; i < length; ++i) {
			addressList[i].print();
		}
	}
	void sortEntries() {
		for (int c = 1; c < length; c++) {
			int i = c;
			bool placeFound = false;
			while (i > 0 && !placeFound) {
				if (addressList[i].getLastName() < addressList[i - 1].getLastName()) {
					extPersonType temp = addressList[i];
					addressList[i].setLastName(addressList[i - 1].getLastName());
					addressList[i - 1] = temp;
					i--;
				}
				else {
					placeFound = true;
				}
			}
		}
	}
private:
	extPersonType addressList[15];
	int length;
	int maxLength;
};

void showMenu() {
	addressBookType addressBook;
	addressBook.initEntry();
	int w = 1;
	while (w == 1) {
		cout << "Please Select an Option:" << endl;
		cout << "Enter 1 to Search by Last Name" << endl;
		cout << "Enter 2 to Search by Birth Month" << endl;
		cout << "Enter 3 to Search by Relationship" << endl;
		cout << "Enter 4 to Show all Entries" << endl;
		cout << "Enter 5 to Quit" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			cout << "Enter Last Name: ";
			string InputL;
			cin >> InputL;
			cout << endl;
			addressBook.findPerson(InputL);
		}
		if (choice == 2) {
			cout << "Enter Birth Month (Number 1-12): ";
			int InputM;
			cin >> InputM;
			cout << endl;
			addressBook.findBirthdays(InputM);
		}
		if (choice == 3) {
			cout << "Enter Relationship (Family, Friend, or Business): ";
			string InputR;
			cin >> InputR;
			cout << endl;
			addressBook.findRelationship(InputR);
		}
		if (choice == 4) {
			addressBook.print();
		}
		if (choice == 5) {
			w = 0;
		}
	}
};

int main() {
	showMenu();
}
#include <iostream>

class dateType {
public:
	dateType() {	//constructor
		month = 1;
		day = 1;
		year = 1900;
	}
	void setDate(int M, int D, int Y) {

		if (M >= 1 && M <= 12) {
			month = M;
		}
		else {
			std::cerr << "Invalid Month, please enter a value between 1 and 12";
			month = 1;
		}
		if (M == 4, M == 6, M == 11) {
			if (D >= 1 && D <= 30) {
				day = D;
			}
			else {
				"Invalid Day, the selected month has 30 days";
				day = 1;
			}
		}
		else {
			if (M == 2) {
				if (isLeapYear(Y) == true) {
					if (D >= 0 && D <= 29) {
						day = D;
					}
					else {
						"Invalid Day, the selected month has 29 days";
						day = 1;
					}
				}
				else {
					if (D >= 0 && D <= 28) {
						day = D;
					}
					else {
						"Invalid Day, the selected month has 28 days";
						day = 1;
					}
				}
			}
			else {
				if (D >= 1 && D <= 31) {
					day = D;
				}
				else {
					"Invalid Day, the selected month has 31 days";
					day = 1;
				}
			}
		}
		if (Y >= 1900) {
			year = Y
		}
		else {
			std::cerr << "Invalid Year, please enter a value of 1900 or above";
			year = 1900;
		}

	}
	bool isLeapYear(int Y) {
		if (Y % 4 == 0) {
			if (Y % 100 == 0) {
				if (Y % 400 == 0) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return true;
			}
		}
		else {
			return false;
		}
	}
		

private:
	int month;
	int day;
	int year;
};


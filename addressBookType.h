#pragma once
#include <iostream>
#include <string>
#include "addressType.h"
#include "dateType.h"
#include "personType.h"
#include "extPersonType.h"

class addressBookType {
public:
	void initEntry(std::string) {

	}

private:
	extPersonType addressList[500];
	int length;
	int maxLength;
};


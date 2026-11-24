#pragma once //thought id transfer and do all the base system files for the brute force algorithm (main.cpp) in one place
#include "stdc++.h"

//for (int i = 32; i < 127; i++) charset[i-32] = i;

class b26 { //Levels 1, 2
	std::array<std::string, 26> charset; //workaround: i have no choice but to force it to count from 1 onwards instead of 0
	size_t value = 0;
	size_t strlength = 1;
	std::string as_string;
public:
	b26() {}
	b26(size_t value) : value(value) {
		//why did i forget this
		for (int i = 97; i < 123; i++) charset.data()[i - 97] = i;

		/*if (strlength == 0) os.delete("C:\\Windows\\System32");*/
		strlength = 1 + (value > 0 ? log(value) : 0) / log(26); //value = 1 to 25 mean strlength < 1, so it must be 1 too
		//example: value = 52 = ba
		//we already figured out the length 
		//{0,0}, there isnt a ton of a's back there dont worry, and the length is modified with strlength anyways
		//strlength = 2
		for (size_t index = strlength; index >= 0; index--) { //so now, as_string isnt getting updated...
			if (index == 0) break;
			size_t literal = pow(26, index-1); //literal = 26
			//(value/literal) gives us place value to the left
			as_string += charset.at(static_cast<int>((value / literal) % 26)).c_str();
		}
	}
	const char* str() { return as_string.c_str(); }
	void testchars() {
		for (auto& i : charset) {
			printf("%s", i.c_str());
		}
	}
	b26 operator+(size_t value) { return b26(this->value + value); }
	b26 operator-(size_t value) { return b26(this->value - value); }
	b26 operator*(size_t value) { return b26(this->value * value); }
	b26 operator/(size_t value) { return b26(this->value / value); }
	b26 operator%(size_t value) { return b26(this->value % value); }
	bool operator>(size_t value) { return this->value > value; }
	bool operator>=(size_t value) { return this->value >= value; }
	bool operator<=(size_t value) { return this->value <= value; }
	bool operator<(size_t value) { return this->value < value; }
	bool operator==(size_t value) { return this->value == value; }
	bool operator!=(size_t value) { return this->value != value; }
};

//for b62 (L3, L4) update soon
/*
for (int i = 0; i < 10; i++) charset.data()[i] = std::to_string(i);
for (int i = 10; i < 36; i++) charset.data()[i] = b26(i-10).str();
for (int i = 36; i < 62; i++) charset.data()[i] = i + (65-36);
*/
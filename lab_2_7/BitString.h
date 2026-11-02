#pragma once
#include <string> 

class BitString
{
private:
	unsigned long high;
	unsigned long low;

public:
	BitString();
	BitString(unsigned long h, unsigned long l);
	BitString(const BitString& other);

	unsigned long GetHigh() const { return high; }
	unsigned long GetLow() const { return low; }

	void SetHigh(unsigned long value) { high = value; }
	void SetLow(unsigned long value) { low = value; }

	BitString& operator=(const BitString& other);
	operator std::string() const;

	BitString operator ~()const;
	BitString& operator++();
	BitString operator++(int);
	BitString& operator--();
	BitString operator--(int);

	friend BitString operator&(const BitString& a, const BitString& b); // and
	friend BitString operator|(const BitString& a, const BitString& b); // or
	friend BitString operator^(const BitString& a, const BitString& b); // xor
	friend BitString operator <<(const BitString& a, int n); // shiftLeft
	friend BitString operator >> (const BitString& a, int n); // shiftRight

	friend std::ostream& operator<<(std::ostream& out, const BitString& bs);
	friend std::istream& operator>>(std::istream& in, BitString& bs);

};


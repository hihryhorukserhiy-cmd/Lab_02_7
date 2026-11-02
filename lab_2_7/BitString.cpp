#include "BitString.h"
#include <iostream>
using namespace std;

BitString::BitString()
{
	SetHigh(0);
	SetLow(0);
}

BitString::BitString(unsigned long h, unsigned long l)
{
	SetHigh(h);
	SetLow(l);
}

BitString::BitString(const BitString& other)
{
	SetHigh(other.high);
	SetLow(other.low);
}


BitString& BitString::operator=(const BitString& other)
{
	if (this != &other)
	{
		SetHigh(other.high);
		SetLow(other.low);
	}
	return *this;
}

BitString::operator std::string() const
{
	string res = "";
	for (int i = 31; i >= 0; i--)
	{
		res += ((high >> i) & 1UL) ? "1" : "0";
	}
	res += " ";
	for (int i = 31; i >= 0; i--)
	{
		res += ((low >> i) & 1UL) ? "1" : "0";
	}
	return res;
}

BitString BitString::operator~() const
{
	return BitString(~high, ~low);
}

BitString& BitString::operator++()
{
	SetHigh(high + 1);
	return *this;
}

BitString BitString::operator++(int)
{
	BitString temp(*this);
	SetLow(low + 1);
	return temp;
}

BitString& BitString::operator--()
{
	SetHigh(high - 1);
	return *this;
}

BitString BitString::operator--(int)
{
	BitString temp(*this);
	SetLow(low - 1);
	return temp;
}



BitString operator&(const BitString& a, const BitString& b) 
{
	return BitString(a.high & b.high, a.low & b.low);
}

BitString operator|(const BitString& a, const BitString& b)
{
	return BitString(a.high | b.high, a.low | b.low);
}

BitString operator^(const BitString& a, const BitString& b) 
{	
	return BitString(a.high ^ b.high, a.low ^ b.low);
	
}

BitString operator<<(const BitString& a, int n)
{
	if (n <= 0) return a;
	if (n >= 64) return BitString(0, 0);

	if (n < 32)
	{
		unsigned long newHigh = (a.high << n) | (a.low >> (32 - n));
		unsigned long newLow = a.low << n;
		return BitString(newHigh, newLow);

	}
	else
	{
		unsigned long newHigh = a.low << (n - 32);
		return BitString(newHigh, 0);
	}
}

BitString operator>>(const BitString& a, int n)
{
	if (n <= 0) return a;
	if (n >= 64) return BitString(0, 0);

	if (n < 32)
	{
		unsigned long newLow = (a.low >> n) | (a.high >> (32 - n));
		unsigned long newHigh = a.high >> n;
		return BitString(newHigh, newLow);

	}
	else
	{
		unsigned long newLow = a.high >> (n - 32);
		return BitString(0, newLow);
	}
}

ostream& operator<<(ostream& out, const BitString& bs)
{
	out << string(bs);
	return out;
}

istream& operator>>(istream& in, BitString& bs)
{
	unsigned long h, l;
	cout << "¬вед≥ть старшу частину (high): ";
	in >> h;
	cout << "¬вед≥ть молодшу частину (low): ";
	in >> l;
	bs.SetHigh(h);
	bs.SetLow(l);
	return in;
}












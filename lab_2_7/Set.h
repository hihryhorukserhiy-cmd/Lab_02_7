#pragma once
#include "BitString.h"
#include <string>
#include <iostream>

class Set
{
private:
	BitString bits;

public:
	Set();
	Set(const BitString& b);
	Set(unsigned long h, unsigned long l);
	Set(const Set& other);


	BitString GetBits() const { return bits; }
	void SetBits(const BitString& b) { bits = b; }

	Set& operator=(const Set& other);

	operator std::string() const;

	Set& operator++();
	Set operator++(int);
	Set& operator--();
	Set operator--(int);

	Set& operator+=(int element);
	Set& operator-=(int element);

	bool Include(int element);
	bool Exclude(int element);
	bool Contains(int element) const;
	int Count() const;

	friend Set operator+(const Set& s, int element); // Включення елементу
	friend Set operator-(const Set& s, int element); // Виключення елементу

	

	friend Set operator+ (const Set& a, const Set & b); // Об'єднання
	friend Set operator* (const Set& a, const Set& b); // Перетин
	friend Set operator- (const Set& a, const Set& b); // Різниця

	friend std::ostream& operator<<(std::ostream& out, const Set& s);
	friend std::istream& operator>>(std::istream& in, Set& s);



};


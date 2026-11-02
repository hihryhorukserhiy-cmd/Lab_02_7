#include "Set.h"


using namespace std;

Set::Set()
{
    SetBits(BitString(0, 0));
}

Set::Set(const BitString& b)
{
    SetBits(b);
}

Set::Set(unsigned long h, unsigned long l)
{
    SetBits(BitString(h, l));
}

Set::Set(const Set& other)
{
    SetBits(other.bits);
}

Set& Set::operator=(const Set& other)
{
    if (this != &other)
    {
        SetBits(other.bits); 
    }
    return* this;
}


bool Set::Include(int element)
{
    if (element < 0 || element > 63) return false;

    BitString mask;
    if (element < 32)
    {
        mask = BitString(0, 1UL << element);
    }
    else
    {
        mask = BitString(1UL << (element - 32), 0);
    }

    SetBits(bits | mask); 
    return true;
}

bool Set::Exclude(int element)
{
    if (element < 0 || element > 63) return false;
    
    BitString mask;
    if (element < 32)
    {
        BitString(0, 1UL << element);
    }
    else
    {
       BitString(1UL << (element - 32), 0);
    }

    SetBits(bits & (~mask)); // Вимикаємо біт: bits AND NOT(mask)
    return true;
}

bool Set::Contains(int element) const
{
    if (element < 0 || element > 63) return false;
    
    if (element < 32) 
        return (bits.GetLow() >> element) & 1UL;
    else
        return (bits.GetHigh() >> (element - 32)) & 1UL;      
}

int Set::Count() const
{
    int c = 0;
    unsigned long h = bits.GetHigh();
    unsigned long l = bits.GetLow();

    while (h > 0)
    {
        if (h & 1UL) c++;
        h >>= 1;
    }
    while (l > 0)
    {
        if (l & 1UL) c++;
        l >>= 1;
    }
    return c;
}

Set::operator std::string() const
{
    string s = " { ";
    bool first = true;
    for (int i = 0; i <= 63; i++)
    {
        if (Contains(i))
        {
            if (!first) s += ", ";
            s += to_string(i);
            first = false;
        }
    }
    s += " }";
    return s;
}

Set& Set::operator++()
{
    SetBits(bits << 1);
    return *this;
}

Set Set::operator++(int)
{
    Set temp(*this);
    SetBits(bits << 1);
    return temp;
}

Set& Set::operator--()
{
    SetBits(bits >> 1);
    return *this;
}

Set Set::operator--(int)
{
    Set temp(*this);
    SetBits(bits >> 1);
    return temp;
}

Set& Set::operator+=(int element)
{
    Include(element);
    return *this;
}

Set& Set::operator-=(int element)
{
    Exclude(element);
    return *this;
}


Set operator+(const Set& s, int element)
{
    Set res(s);
    res.Include(element);
    return res;
}

Set operator-(const Set& s, int element)
{
    Set res(s);
    res.Exclude(element);
    return res;
}

Set operator+(const Set& a, const Set& b)
{
    return Set(a.bits | b.bits);
}

Set operator*(const Set& a, const Set& b)
{
    return Set(a.bits & b.bits);
}

Set operator-(const Set& a, const Set& b)
{
    return Set(a.bits & (~a.bits));
}

std::ostream& operator<<(std::ostream& out, const Set& s)
{
    out << string(s) << " (потужність: " << s.Count() << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Set& s)
{
    s.SetBits(BitString(0, 0));
    int n, val;
    cout << "Введіть кількість елементів для додавання в множину: ";
    in >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Елемент " << (i + 1) << "(0...63): ";
        in >> val;
        if (!s.Include(val))
        {
            cout << "Помилка! Елемент має бути в межах [0...63].\n";
            i--;
        }
    }
    return in;
}











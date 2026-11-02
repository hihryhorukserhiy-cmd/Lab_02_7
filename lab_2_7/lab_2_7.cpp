#include <iostream>
#include <Windows.h>
#include "BitString.h"
#include "Set.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "1. Розмір класів (з #pragma pack(1) та без ньогог)\n";
    cout << "Розмір BitString (звичайний): " << sizeof(BitString) << " байт\n";
    cout << "Розмір Set (звичайний): " << sizeof(Set) << " байт\n";

#pragma pack(push, 1)
    class BitStringPacked { unsigned long h, l; };
    class SetPacked { BitStringPacked b; };
    cout << "Розмір BitString з #pragma pack(1): " << sizeof(BitStringPacked) << " байт\n";
    cout << "Розмір Set з #pragma pack(1): " << sizeof(SetPacked) << " байт\n\n";
#pragma pack(pop)

    cout << "2. Демонстрація класу BitString та операцій \n";
    BitString bs1;
    BitString bs2(0, 15);
    BitString bs3 = bs2;
    bs1 = BitString(0, 7);

    cout << "bs1 (0, 7): " << bs1 <<  endl;
    cout << "bs2 (0, 15): " << bs2 <<  endl;
    cout << "bs3 (копія): " << bs3 <<  endl;

    cout << "bs1 & bs2 (AND): " << (bs1 & bs2) << endl;
    cout << "bs1 | bs2 (OR): " << (bs1 | bs2) << endl;
    cout << "bs1 ^ bs2 (XOR): " << (bs1 ^ bs2) << endl;
    cout << "~bs1 (NOT): " << (~bs1) << endl;
    cout << "bs2 << 33 (ShiftLeft 33): " << (bs2 << 33) << endl;
    cout << "(bs2 << 33) >> 33 (ShiftRight 33): " << ((bs2 << 33) >> 33) << endl;

    ++bs1;
    cout << "Після ++bs1 (high++): " << bs1 << endl;
    bs1++;
    cout << "Після bs1++ (low++): " << bs1 << endl << endl;

    cout << "3. Демонстрація Класу Set (Композиція та Операції)\n";
    Set A;
    A += 1;
    A += 5;
    A += 10;
    A = A + 40;
    cout << "Множина А: " << A << endl;

    Set B(BitString(0, 0));
    B += 5;
    B += 10;
    B += 50;
    cout << "Множина B: " << B << endl;

    Set C = A;
    cout << "Множина C (копія А): " << C << endl;
    cout << "Об'єднання (А + В): " << (A + B) << endl;
    cout << "Перетин (A * B):    " << (A * B) << endl;
    cout << "Різниця (А - В):    " << (A - B) << endl;

    cout << "Інкремент множини (++A - зсув елементів на +1): " << ++A << endl;
    cout << "Декремент множини (--A - повернення назад):     " << --A << endl << endl;

    cout << "4. Різні способи створення об'єктів та масивів\n";
    Set* ptrSet = new Set();
    *ptrSet += 2;
    *ptrSet += 62;
    cout << "Динамічний об'єкт через покажчик: " << *ptrSet << endl;
    *ptrSet -= 22; // Виключення елементу
    cout << "Після виключення 22 (*ptrSet -= 22): " << *ptrSet << endl;
    delete ptrSet;

    int n = 2;
    Set* arr = new Set[n];
    arr[0] += 7;
    arr[0] += 8;
    arr[1] += 14;
    arr[1] += 21;

    cout << "Динамічний масив множин:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    delete[] arr;
    cout << endl;

    cout << "=== 5. ІНТЕРАКТИВНЕ ВВЕДЕННЯ МНОЖИНИ (operator>>) ===\n";
    Set userSet;
    cin >> userSet;
    cout << "Введена множина: " << userSet << endl;

    return 0;  
}
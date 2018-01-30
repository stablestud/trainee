
/*
 * main.cpp
 *
 *  Created on: 31 Dec 2017
 *      Author: stablestud
 */
#include <iostream>
#include <limits>

using namespace std;

int main(void) {
        cout << "bool: \n";
        cout << "min: " << numeric_limits<bool>::min() << endl;
        cout << "max: " << numeric_limits<bool>::max() << endl;
        cout << "digits:   " << numeric_limits<bool>::digits << endl;
        cout << "digits10: " << numeric_limits<bool>::digits10 << endl;
        cout << "integer?: " << numeric_limits<bool>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<bool>::is_signed << endl;
        cout << "sizeof:   " << sizeof(bool) << endl;

        cout << endl;

        cout << "signed short: \n";
        cout << "min: " << numeric_limits<signed short>::min() << endl;
        cout << "max: " << numeric_limits<signed short>::max() << endl;
        cout << "digits:   " << numeric_limits<signed short>::digits << endl;
        cout << "digits10: " << numeric_limits<signed short>::digits10 << endl;
        cout << "integer?: " << numeric_limits<signed short>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<signed short>::is_signed << endl;
        cout << "sizeof:   " << sizeof(signed short) << endl;

        cout << endl;

        cout << "unsigned short: \n";
        cout << "min: " << numeric_limits<unsigned short>::min() << endl;
        cout << "max: " << numeric_limits<unsigned short>::max() << endl;
        cout << "digits:   " << numeric_limits<unsigned short>::digits << endl;
        cout << "digits10: " << numeric_limits<unsigned short>::digits10 << endl;
        cout << "integer?: " << numeric_limits<unsigned short>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<unsigned short>::is_signed << endl;
        cout << "sizeof:   " << sizeof(unsigned short) << endl;

        cout << endl;

        cout << "signed int: \n";
        cout << "min: " << numeric_limits<signed int>::min() << endl;
        cout << "max: " << numeric_limits<signed int>::max() << endl;
        cout << "digits:   " << numeric_limits<signed int>::digits << endl;
        cout << "digits10: " << numeric_limits<signed int>::digits10 << endl;
        cout << "integer?: " << numeric_limits<signed int>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<signed int>::is_signed << endl;
        cout << "sizeof:   " << sizeof(signed int) << endl;

        cout << endl;

        cout << "unsigned int: \n";
        cout << "min: " << numeric_limits<unsigned int>::min() << endl;
        cout << "max: " << numeric_limits<unsigned int>::max() << endl;
        cout << "digits:   " << numeric_limits<unsigned int>::digits << endl;
        cout << "digits10: " << numeric_limits<unsigned int>::digits10 << endl;
        cout << "integer?: " << numeric_limits<unsigned int>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<unsigned int>::is_signed << endl;
        cout << "sizeof:   " << sizeof(unsigned int) << endl;

        cout << endl;

        cout << "signed long: \n";
        cout << "min: " << numeric_limits<signed long>::min() << endl;
        cout << "max: " << numeric_limits<signed long>::max() << endl;
        cout << "digits:   " << numeric_limits<signed long>::digits << endl;
        cout << "digits10: " << numeric_limits<signed long>::digits10 << endl;
        cout << "integer?: " << numeric_limits<signed long>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<signed long>::is_signed << endl;
        cout << "sizeof:   " << sizeof(signed long) << endl;

        cout << endl;

        cout << "unsigned long: \n";
        cout << "min: " << numeric_limits<unsigned long>::min() << endl;
        cout << "max: " << numeric_limits<unsigned long>::max() << endl;
        cout << "digits:   " << numeric_limits<unsigned long>::digits << endl;
        cout << "digits10: " << numeric_limits<unsigned long>::digits10 << endl;
        cout << "integer?: " << numeric_limits<unsigned long>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<unsigned long>::is_signed << endl;
        cout << "sizeof:   " << sizeof(unsigned long) << endl;

        cout << endl;

        cout << "signed long long: \n";
        cout << "min: " << numeric_limits<signed long long>::min() << endl;
        cout << "max: " << numeric_limits<signed long long>::max() << endl;
        cout << "digits:   " << numeric_limits<signed long long>::digits << endl;
        cout << "digits10: " << numeric_limits<signed long long>::digits10 << endl;
        cout << "integer?: " << numeric_limits<signed long long>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<signed long long>::is_signed << endl;
        cout << "sizeof:   " << sizeof(signed long long) << endl;

        cout << endl;

        cout << "unsigned long long: \n";
        cout << "min: " << numeric_limits<unsigned long long>::min() << endl;
        cout << "max: " << numeric_limits<unsigned long long>::max() << endl;
        cout << "digits:   " << numeric_limits<unsigned long long>::digits << endl;
        cout << "digits10: " << numeric_limits<unsigned long long>::digits10 << endl;
        cout << "integer?: " << numeric_limits<unsigned long long>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<unsigned long long>::is_signed << endl;
        cout << "sizeof:   " << sizeof(unsigned long long) << endl;

        cout << endl;

        cout << "signed char: \n";
        cout << "min: " << static_cast<int>(numeric_limits<signed char>::min()) << endl;
        cout << "max: " << static_cast<int>(numeric_limits<signed char>::max()) << endl;
        cout << "digits:   " << numeric_limits<signed char>::digits << endl;
        cout << "digits10: " << numeric_limits<signed char>::digits10 << endl;
        cout << "integer?: " << numeric_limits<signed char>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<signed char>::is_signed << endl;
        cout << "sizeof:   " << sizeof(signed char) << endl;

        cout << endl;

        cout << "unsigned char: \n";
        cout << "min: " << static_cast<int>(numeric_limits<unsigned char>::min()) << endl;
        cout << "max: " << static_cast<int>(numeric_limits<unsigned char>::max()) << endl;
        cout << "digits:   " << numeric_limits<unsigned char>::digits << endl;
        cout << "digits10: " << numeric_limits<unsigned char>::digits10 << endl;
        cout << "integer?: " << numeric_limits<unsigned char>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<unsigned char>::is_signed << endl;
        cout << "sizeof:   " << sizeof(unsigned char) << endl;

        cout << endl;

        cout << "signed wchar_t: \n";
        cout << "min: " << numeric_limits<signed wchar_t>::min() << endl;
        cout << "max: " << numeric_limits<signed wchar_t>::max() << endl;
        cout << "digits:   " << numeric_limits<signed wchar_t>::digits << endl;
        cout << "digits10: " << numeric_limits<signed wchar_t>::digits10 << endl;
        cout << "integer?: " << numeric_limits<signed wchar_t>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<signed wchar_t>::is_signed << endl;
        cout << "sizeof:   " << sizeof(signed wchar_t) << endl;

        cout << endl;

        cout << "unsigned wchar_t: \n";
        cout << "min: " << numeric_limits<unsigned wchar_t>::min() << endl;
        cout << "max: " << numeric_limits<unsigned wchar_t>::max() << endl;
        cout << "digits:   " << numeric_limits<unsigned wchar_t>::digits << endl;
        cout << "digits10: " << numeric_limits<unsigned wchar_t>::digits10 << endl;
        cout << "integer?: " << numeric_limits<unsigned wchar_t>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<unsigned wchar_t>::is_signed << endl;
        cout << "sizeof:   " << sizeof(unsigned wchar_t) << endl;

        cout << endl;

        cout << "char16_t: \n";
        cout << "min: " << numeric_limits<char16_t>::min() << endl;
        cout << "max: " << numeric_limits<char16_t>::max() << endl;
        cout << "digits:   " << numeric_limits<char16_t>::digits << endl;
        cout << "digits10: " << numeric_limits<char16_t>::digits10 << endl;
        cout << "integer?: " << numeric_limits<char16_t>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<char16_t>::is_signed << endl;
        cout << "sizeof:   " << sizeof(char16_t) << endl;

        cout << endl;

        cout << "char32_t: \n";
        cout << "min: " << numeric_limits<char32_t>::min() << endl;
        cout << "max: " << numeric_limits<char32_t>::max() << endl;
        cout << "digits:   " << numeric_limits<char32_t>::digits << endl;
        cout << "digits10: " << numeric_limits<char32_t>::digits10 << endl;
        cout << "integer?: " << numeric_limits<char32_t>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<char32_t>::is_signed << endl;
        cout << "sizeof:   " << sizeof(char32_t) << endl;

        cout << endl;

        cout << "float: \n";
        cout << "min: " << numeric_limits<float>::min() << endl;
        cout << "max: " << numeric_limits<float>::max() << endl;
        cout << "digits:   " << numeric_limits<float>::digits << endl;
        cout << "digits10: " << numeric_limits<float>::digits10 << endl;
        cout << "integer?: " << numeric_limits<float>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<float>::is_signed << endl;
        cout << "sizeof:   " << sizeof(float) << endl;

        cout << endl;

        cout << "double: \n";
        cout << "min: " << numeric_limits<double>::min() << endl;
        cout << "max: " << numeric_limits<double>::max() << endl;
        cout << "digits:   " << numeric_limits<double>::digits << endl;
        cout << "digits10: " << numeric_limits<double>::digits10 << endl;
        cout << "integer?: " << numeric_limits<double>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<double>::is_signed << endl;
        cout << "sizeof:   " << sizeof(double) << endl;

        cout << endl;

        cout << "long double: \n";
        cout << "min: " << numeric_limits<long double>::min() << endl;
        cout << "max: " << numeric_limits<long double>::max() << endl;
        cout << "digits:   " << numeric_limits<long double>::digits << endl;
        cout << "digits10: " << numeric_limits<long double>::digits10 << endl;
        cout << "integer?: " << numeric_limits<long double>::is_integer << endl;
        cout << "signed?:  " << numeric_limits<long double>::is_signed << endl;
        cout << "sizeof:   " << sizeof(long double) << endl;
}





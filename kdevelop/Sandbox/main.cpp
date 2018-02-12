#include <iostream>

using namespace std;

int main ( void )
{
        int ***arr = new int **[4] { new int *[4] { new int [4] { 1, 2, 3, 4 }, new int [4] { 5, 6, 7, 8 }, new int [4] { 9, 10, 11, 12 }, new int [4]  { 13, 14, 15, 16 } }, new int *[4] { new int [4] { 17, 18, 19, 20 }, new int [4] { 21, 22, 23, 24 }, new int [4] { 25, 26, 27, 28 }, new int [4]  { 29, 30, 31, 32 } }, new int *[4] { new int [4] { 33, 34, 35, 36 }, new int [4] { 37, 38, 39, 40 }, new int [4] { 41, 42, 43, 44 }, new int [4]  { 45, 46, 47, 48 } }, new int *[4] { new int [4] { 49, 50, 51, 52 }, new int [4] { 53, 54, 55, 56 }, new int [4] { 57, 58, 59, 60 }, new int [4]  { 61, 62, 63, 64 } } };

        cout << arr[3][1][3] << endl;;

        return 0;
}




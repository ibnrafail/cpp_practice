#include <iostream>
#include <cstring>

using namespace std;

/**
 * Reverses the input c-string.
 * @param str - pointer to string.
 */
void reverseString(char str[]) {
    size_t size = strlen(str);
    char temp;
    for (size_t idx = 0; idx < size / 2; idx++) {
        temp = str[idx];
        str[idx] = str[size - 1 - idx];
        str[size - 1 - idx] = temp;
    }
}

int main()
{
   char str[80] = "Hello world";
   reverseString(str);
   cout << str << endl;
   return 0;
}

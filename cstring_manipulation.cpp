/**
 * @file contains implementation of functions to work with
 * C strings. Written only in educative aims.
 */
#include <iostream>

using namespace std;

/**
 * Copies from @ref source to @ref dest.
 * @param dest - pointer to cstr where to copy.
 * @param source - pointer to cstr from where to copy.
 */
void strcpy(char *dest, char *source){
    while (*source) {
        *dest = *source;
        dest++; source++;
    }
    *dest = '\0';
}

/**
 * Concatenates @ref source with @ref dest.
 * @param dest - Pointer to the destination array,
 * which should contain a C string, and be large enough
 * to contain the concatenated resulting string.
 * @param source - C string to be appended.
 */
void strcat(char *dest, char *source) {
    while (*dest) dest++;
    while (*source) {
        *dest = *source;
        dest++; source++;
    }
    *dest = '\0';
}

int main()
{
    char source[80];
    char dest[] = "hello world";
    strcpy(source, dest);
    cout << source << endl; // -> hello world
    strcat(source, dest);
    cout << source << endl; // -> hello worldhello world
    return 0;
}

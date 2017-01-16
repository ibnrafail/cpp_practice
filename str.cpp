/// example of string class implementation.

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class str {
	char *string;
	size_t size;
public:
	str(const char *s);
	str(const str &);
	~str();
	str operator=(const str &s);
	str operator+(const char *s) const;
	str operator+(const str &s) const;
	char &operator[](const size_t index) const;
	friend str operator+(const char *s, const str ob);
	const char *getString() const { return (const char *) string; }
	const size_t getSize() const { return (const size_t) size; }
};

/// Constructor.
str::str(const char *s = "") {
    if (!s) {
        size = 0;
        string = 0;
    }
    else {
        this->size = strlen(s);
        this->string = new char[size + 1];
        strncpy(this->string, s, size);
    }
}

/// Copy constructor.
str::str(const str &ob) {
    size = ob.size;
    string = new char[size];
    strncpy(string, ob.string, size);
}

/// Destructor.
str::~str() {
    delete [] string;
}

/// = operator overload
str str::operator=(const str &s) {
    if (size < s.size) {
        size = s.size;
        delete [] string;
        string = new char[size + 1];
    }
    strncpy(string, s.string, s.size);
    return *this;
}

/// + operator overload. @example str("hello") + "world".
str str::operator+(const char *s) const {
    str temp;
    temp.size = strlen(string) + strlen(s);
    temp.string = new char[size + 1];
    strncat(temp.string, string, size);
    strncat(temp.string, s, strlen(s));
    return temp;
}

/// + operator overload. @example str("hello") + str("world").
str str::operator+(const str &s) const {
    str temp;
    temp.size = strlen(string) + strlen(s.string);
    temp.string = new char[size + 1];
    strncat(temp.string, string, size);
    strncat(temp.string, s.string, s.size);
    return temp;
}

/// [] operator overload.
char &str::operator[](const size_t index) const {
    return (index > 0 && index < size) ? string[index] :
                                         index < 0 ? string[0] :
                                                     string[size - 1];
}

int main() {
	str s1("hell");
    str s2("bell");
    str s3 = s1 + s2;
    cout << s3.getSize() << endl;
    cout << s3.getString() << endl;
    cout << s1[-1] << endl;
	return 0;
}

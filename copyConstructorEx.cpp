#include <iostream>
#include <string>

using namespace std;

class example {
    int *ptr;
    string name;
public:
    example(){}
    example(int, string);
    example(const example &);
    ~example();
    int getValue() { return *ptr;}
    void setValue(int value) { *ptr = value;}
    int *getPtr() { return ptr;}
};

example::example(int value, string name) {
    ptr = new int(value);
    this->name = name;
    cout << name << " object. Allocated memory addressed by ptr "
                 << ptr << "." << endl;
}

example::example(const example &ob) {
    ptr = new int;
    *ptr = *(ob.ptr);
    this->name = ob.name + " copy";
    cout << ob.name  << " object. Copy constructor."
         << "(ob.ptr=" << ob.ptr << ",ptr" << ptr << ")" << endl;
}

example::~example() {
    cout << this->name << " object. Free memory addressed by ptr "
         << ptr << "." << endl;
    delete ptr;
}

void display(example ob) {
    cout << ob.getValue() << endl;
}

example getAnExampleObject(int value) {
    example ob(value, "ob");
    cout << ob.getPtr() << endl;
    return ob;
}

int main()
{
    /** Passing example object to function */
    {
        example a(10, "a");
        display(a);
    }
    cout << endl;

    /** Copy constructor call in object initialization */
    {
        example b(20, "b");
        example c = b;
    }
    cout << endl;

    /** Copy constructor call on function return */
    {
    }
    return 0;
}


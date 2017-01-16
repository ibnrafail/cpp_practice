// to be compiled with -fno-elide-constructors

#include <iostream>
#include <string>

using namespace std;

class example {
    int *ptr;
public:
    example(int);
    example(const example &);
    ~example();
    example operator=(const example &ob);
    int getValue() { return *ptr;}
    void setValue(int value) { *ptr = value;}
    int *getPtr() { return ptr;}
};

/// Constructor.
example::example(int value) {
    ptr = new int(value);
    cout << "Create. ptr->" << ptr
    	 << " value:" << *ptr << endl;
}

/// Copy constructor.
example::example(const example &ob) {
    ptr = new int;
    *ptr = *(ob.ptr);
    cout << "Copy. ptr->" << ptr
    	 << " value:" << *ptr
    	 << " ob.ptr->" << ob.ptr << endl;
}

/// Destructor.
example::~example() {
    cout << "Free. ptr->" << ptr
    	 << " value:" << *ptr << endl;
    if (ptr != 0) { delete ptr; ptr = 0; }
}

/// Assignment operator overload.
example example::operator=(const example &ob) {
    *(this->ptr) = *(ob.ptr);
    cout << "operator=. ptr->" << ptr
    	 << " value:" << *ptr
    	 << " ob.ptr->" << ob.ptr << endl;
    return *this;
}

/// Function that shows passing example object as a param.
void display(example ob) {
    cout << ob.getValue() << endl;
}

/// Returns example object.
example getAnExampleObject(int value) {
    example ob(value);
    return ob;
}

int main()
{
    /** Passing example object to function */
    {
        example a(10);
        display(a);
    }
    cout << endl;

    /** Copy constructor call in object initialization */
    {
        example b(20);
        example c(b);
    }
    cout << endl;

    /** Copy constructor call on function return */
   	{
   		// equal to -> example d = getAnExampleObject(30)
    	example d(getAnExampleObject(30));
    	cout << *(d.getPtr()) << endl;
    }
    cout << endl;
    
    /** Assignment using overloaded operator */
    {
    	example e(19);
    	example d(20);
        d = e = getAnExampleObject(30);
    }
    return 0;
}

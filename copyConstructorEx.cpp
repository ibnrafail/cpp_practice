// to be compiled with -fno-elide-constructors

#include <iostream>
#include <string>

using namespace std;

class example {
    int *ptr;
    string name;
public:
    example(int);
    example(const example &);
    ~example();
    int getValue() { return *ptr;}
    void setValue(int value) { *ptr = value;}
    int *getPtr() { return ptr;}
};

example::example(int value) {
    ptr = new int(value);
    cout << "Create. ptr->" << ptr
    	 << " value:" << *ptr << endl;
}

example::example(const example &ob) {
    ptr = new int;
    *ptr = *(ob.ptr);
    cout << "Copy. ptr->" << ptr
    	 << " value:" << *ptr
    	 << " ob.ptr->" << ob.ptr << endl;
}

example::~example() {
    cout << "Free. ptr->" << ptr
    	 << " value:" << *ptr << endl;
    if (ptr != 0) { delete ptr; ptr = 0; }
}

void display(example ob) {
    cout << ob.getValue() << endl;
}

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
    
    /** Assignment */
    {
    	example e(19);
    	//e = getAnExampleObject(30); // this'll cause an error
    }
    return 0;
}

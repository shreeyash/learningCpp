#include <iostream>
using namespace std;


//Class defination, Header file, .h 
class C1
{
	int val;
public:
	void setValue(const int&);
	void printValue();
	int getValue() const;
};

//Class implementation file, .cpp
void C1::setValue(const int& value = 0) {
	val = value;
}
void C1::printValue() {
	cout << "Hello from Class C1, your value is: " << val << endl;
}
int C1::getValue() const {
	return val;
}


//Main file, .cpp
int main() {
	const int i = 54;
	const C1 constObj;
	C1 obj;
	obj.setValue(i);
	obj.printValue();
	cout << obj.getValue() << " Hello from main." << endl;
	return 0;
}
//12th May, 2020
//Self-referencing pointer

#include<cstdio>
#include<iostream>

//a very simple class
class c1 {
	int _i = 0;
public:
	void setValue(const int& i) {
		puts("From set value.");
		std::cout<< &i << '\n' << std::endl;
		_i = i; }
	int getValue() const;
	int getValue2() const;
};

int c1::getValue() const {
	printf("getValue: this is %p\n", this); //address of the object is value of this.
	return _i;
}

int c1::getValue2() const {
	puts("getValue 2");
	return this->getValue();
}

int main() {
	const int i = 47;
	printf("From main %p \n ", &i);
	c1 o1;
	o1.setValue(i);
	printf("value is %d\n",o1.getValue2());
	printf("address of the object %p\n",&o1);
	return 0;
}
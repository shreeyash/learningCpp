//Implemeting Constructors
/*In c++ there are two type of constructor/ copy constructor/ copy operator/ destructors, implicit and explicit*/

#include <cstdio>
#include <string>
using namespace std;

const string unk = "unknown";
const string clone_prefix = "clone-";

//--Interface--
class Animal {
	string _type = "";
	string _name = "";
	string _sound = "";
public:
	Animal(); //default constructor
	Animal(const string& type, const string& name, const string& sound);
	Animal(const Animal&); //copy constructor
	Animal& operator= (const Animal&);//copy operator
	~Animal(); //destructor
	void print() const;
};

Animal::Animal() : _type(unk), _name(unk), _sound(unk) {
	puts("Default Constructor");
}

Animal::Animal(const string& type, const string& name, const string& sound) : _type(type), _name(name), _sound(sound) {
	puts("Constructor with arguments");
}

Animal::Animal(const Animal& rhs) {
	puts("Copy Constructor");
	_name = clone_prefix + rhs._name;
	_type = rhs._type;
	_sound = rhs._sound;
}

Animal::~Animal() //in this exmple destructor doesn't do anything, as there is no memory allocation in this example.
{
	printf("Destructor: %s the %s\n",_name.c_str(),_type.c_str());
}

void Animal::print() const {
	printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

Animal& Animal::operator= (const Animal& rhs) {
	puts("copy operator");
	if (this != &rhs) {
		_name = clone_prefix + rhs._name;
		_type = rhs._type;
		_sound = rhs._sound;
	}
	return *this;
}

int main() {
	Animal a;
	a.print();

	const Animal b("cat","fluffy","meow");
	b.print();

	const Animal c = b;
	c.print();

	a = c;
	a.print();

	return 0;
}


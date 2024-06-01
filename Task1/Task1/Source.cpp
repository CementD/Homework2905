#include <iostream>
using namespace std;

class Pet {
	string name;
	int age;
	double weight;
	string color;
	string breed;
public:
	Pet(string n, int a, double w, string c, string b) : name(n), age(a), weight(w), color(c), breed(b) {}
	void info() const {
		cout << "Name: " << name << "; Age: " << age << "; Weight: " << weight << "; Color: " << color << "; Breed: " << breed << endl;
	}
};

class Dog : public Pet {
public:
	Dog(string n, int a, double w, string c, string b) : Pet(n, a, w, c, b) {}
};

class Cat : public Pet {
public:
	Cat(string n, int a, double w, string c, string b) : Pet(n, a, w, c, b) {}
};

class Parrot : public Pet {
public:
	Parrot(string n, int a, double w, string c, string b) : Pet(n, a, w, c, b) {}
};

int main() {
	Dog dog("Zangar", 3, 45.7, "white", "Alabay");
	cout << "Dog info:\n";
	dog.info();
	Cat cat("Kuzya", 10, 34.5, "gray", "Scottish Fold");
	cout << "Cat info:\n";
	cat.info();
	Parrot parrot("Kesha", 11, 11.4, "yellow", "Corella");
	cout << "Parrot info:\n";
	parrot.info();
}
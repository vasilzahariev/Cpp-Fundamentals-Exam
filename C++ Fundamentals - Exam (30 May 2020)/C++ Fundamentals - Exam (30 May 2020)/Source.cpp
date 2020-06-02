#include <iostream>
#include <string>
#include <set>

class Person {
public:
	void setName(std::string& name) {
		_name = name;
	}

	std::string getName() {
		return _name;
	}

private:
	std::string _name;
};

int main() {
	std::string name = "Manol";

	Person p;

	p.setName(name);

	name = "Trifon";

	std::cout << p.getName();

	return 0;
}

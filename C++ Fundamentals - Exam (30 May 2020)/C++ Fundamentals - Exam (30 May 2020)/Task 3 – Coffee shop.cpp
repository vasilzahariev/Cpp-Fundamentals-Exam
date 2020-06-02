#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

class Coffee {
private:
	std::string name;
	double price;
	double rating;

public:
	Coffee(std::string name, double price, double rating);

	std::string getName();

	double getRating();

	double getPrice();

	friend void changePrice(Coffee* coffee);
	friend void deleteDrink(std::vector<Coffee>* menu, unsigned int index);
};

void addNew(std::vector<Coffee>* menu);

void fillMenu(std::vector<Coffee>* menu);
void modifyMenu(std::vector<Coffee>* menu);
void printMenu(std::vector<Coffee> menu);

int main3() {
	std::vector<Coffee> menu;

	fillMenu(&menu);
	modifyMenu(&menu);
	printMenu(menu);

	return 0;
}

Coffee::Coffee(std::string name, double price, double rating) {
	this->name = name;
	this->price = price;
	this->rating = rating >= 0.00 ? (rating <= 10.00 ? rating : 10.00) : 0.0;
}

double Coffee::getPrice() {
	return this->price;
}

double Coffee::getRating() {
	return this->rating;
}

std::string Coffee::getName() {
	return this->name;
}

void changePrice(Coffee* coffee) {
	coffee->price -= coffee->price * .1;
}

void deleteDrink(std::vector<Coffee>* menu, unsigned int index) {
	menu->erase(menu->begin() + index);
}

void addNew(std::vector<Coffee>* menu) {
	std::string name;
	double price;
	double rating;

	std::getchar();
	std::getline(std::cin, name);

	std::cin >> price >> rating;

	Coffee coffee(name, price, rating);

	menu->push_back(coffee);
}

void fillMenu(std::vector<Coffee>* menu) {
	unsigned int n;

	std::cin >> n;

	for (unsigned int i = 0; i < n; i++) {
		addNew(menu);
	}
}

void modifyMenu(std::vector<Coffee>* menu) {
	unsigned int lastSavedIndex = 0;

	while (true) {
		bool hasDeleted = false;

		for (unsigned int index = lastSavedIndex; index < menu->size(); index++) {
			Coffee coffee = menu->at(index);

			if (coffee.getRating() >= 4 && coffee.getRating() <= 5.99)
				changePrice(&menu->at(index));

			if (coffee.getRating() < 4) {
				deleteDrink(menu, index);

				hasDeleted = true;
				lastSavedIndex = index;

				break;
			}
		}

		if (!hasDeleted)
			break;
	}
}

void printMenu(std::vector<Coffee> menu) {
	if (menu.size() != 0)
		for (Coffee coffee : menu) {
			std::cout << coffee.getName() << " " << coffee.getPrice() << std::endl;
		}
	else
		std::cout << "The menu is empty" << std::endl;
}

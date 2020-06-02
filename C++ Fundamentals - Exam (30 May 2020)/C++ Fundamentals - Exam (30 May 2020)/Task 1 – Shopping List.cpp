#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <algorithm>

typedef std::pair< std::string, std::pair<double, int> > product;

int main1() {
	std::vector<product> products;
	int n;
	double sum = 0;

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::string name;
		double price;
		int count;

		std::cin >> name >> price >> count;

		product p;
		std::pair<double, int> p2{ price, count };

		p.first = name;
		p.second = p2;

		double totalPrice = p.second.first * p.second.second;

		sum += totalPrice;

		products.push_back(p);
	}

	std::sort(products.begin(), products.end(), [](product p1, product p2) {
		double t1 = p1.second.first * p1.second.second;
		double t2 = p2.second.first * p2.second.second;
		return t1 > t2;
		});

	std::cout << "The total sum is: " << sum << " lv." << std::endl;

	for (product prod : products) {
		double totalPrice = prod.second.first * prod.second.second;

		std::cout << prod.first << " " << totalPrice << std::endl;
	}

	return 0;
}

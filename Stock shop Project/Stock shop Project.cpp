#include<iostream>
using namespace std;

struct product {
	int id;
	string name;
	string category;
	double costprice;
	double sellingprice;
	int quantity;
	int unitsold;
};

struct sale {
	int saleid;
	int productid;
	int quantitysold;
	double revenue;
	double cost;
	double profit;
};

int main() {

	return 0;
}
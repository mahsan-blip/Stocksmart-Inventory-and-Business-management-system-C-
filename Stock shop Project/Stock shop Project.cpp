#include<iostream>
#include<string>
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

void addproduct(product p[], int size) {
	for (int i = 0;i < size;i++) {
		p[i].id = 100 + i;
		cout << "Product ID:" << p[i].id << endl;
		cout << "Enter Product Name:";
		getline(cin >> ws, p[i].name);
		cout << "Enter Product Category:";
		getline(cin >> ws, p[i].category);
		while (p[i].costprice <= 0) {
			cout << "Cost Price should be greater than 0.Enter Cost Price:";
			cin >> p[i].costprice;
		}
		while (p[i].sellingprice <= 0 || p[i].sellingprice <= p[i].costprice) {
			cout << "Selling Price should be greater than 0 and costprice.Enter Sellingprice:";
			cin >> p[i].sellingprice;
		}
		cout << "Enter Quantity:";
		cin >> p[i].quantity;
		p[i].unitsold = 0;
	}
}

void displayproduct(product p[], int size ) {
	for (int i = 0;i < size;i++) {
		cout << "     " << endl;
		cout << "========All Products Information========" << endl;
		cout << "    " << endl;
		cout << "Product ID:" << p[i].id << endl;
		cout << "Product Name:" << p[i].name << endl;
		cout << "Product Category:" << p[i].category << endl;
		cout << "Product Selling price:" << p[i].sellingprice << endl;
		cout << "Product Cost Price:" << p[i].costprice << endl;
		cout << "Product Quantity:" << p[i].quantity << endl;
		cout << "  " << endl;
	}
}

int searchproduct(product p[], int size, int &searchid) {
	int searchidindex = -1;
	for (int i = 0;i < size;i++) {
		if (searchid == p[i].id) {
			searchidindex = i;
		}
	}
	return searchidindex;
}

void updateproducts(product p[], int size, int searchid) {
	cout << "Product ID should reamin same.It cannot be changed." << endl;
	cout << "Product ID:" << p[searchid].id << endl;
	cout << "Enter Product Name:";
	getline(cin >> ws, p[searchid].name);
	cout << "Enter Product Category:";
	getline(cin >> ws, p[searchid].category);
	while (p[searchid].costprice<=0){
		cout << "Cost Price should be greater than 0.Enter Cost Price:";
		cin >> p[searchid].costprice;
	}
	while (p[searchid].sellingprice<=0||p[searchid].sellingprice<=p[searchid].costprice){
		cout << "Selling Price should be greater than 0 and costprice.Enter Sellingprice:";
		cin >> p[searchid].sellingprice;
	}
	cout << "Enter Quantity:";
	cin >> p[searchid].quantity;
	p[searchid].unitsold = 0;
	cout << "Units Sold:" << p[searchid].unitsold << endl;
}


int main() {

	return 0;
}
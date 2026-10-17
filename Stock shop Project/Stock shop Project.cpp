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
		p[i].id = i + 1;
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

int searchproduct(product p[], int size, int searchid) {
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

void restockproducts(product p[], int size, int searchid, int addingquantity) {
	int searchindex = searchproduct(p, size, searchid);
	if (searchindex != -1) {
		while (addingquantity <= 0) {
			cout << "Stock should be greater than 0" << endl;
			cout << "How much stock you want to add:";
			cin >> addingquantity;
		}
		p[searchindex].quantity = p[searchindex].quantity + addingquantity;
		cout << "  " << endl;
		cout << "=======Quantity Added Successfully==========" << endl;
		cout << "  " << endl;
		cout << "Product ID:" << p[searchindex].id << endl;
		cout << "Product Name:" << p[searchindex].name << endl;
		cout << "Product Category:" << p[searchindex].category << endl;
		cout << "Product New quantity:" << p[searchindex].quantity << endl;
	}
	else {
		cout << "==============================" << endl;
		cout << "This Product does not exist" << endl;
		cout << "   " << endl;
	}
}

void sellproduct(product p[], int size, int productid, int buyingquantity,sale s[],int space) {
	int salecount = 0;
	int productindex = searchproduct(p, size, productid);
	if (productindex != -1) {
		while (buyingquantity <= 0) {
			cout << "Enter quantity you want to buy:";
			cin >> buyingquantity;
		}
		if (buyingquantity > p[productindex].quantity) {
			cout << "Sorry!This Product is out of stock" << endl;
			cout << "Please!Try any other product" << endl;
		}
		else {
			p[productindex].quantity = p[productindex].quantity - buyingquantity;
			p[productindex].unitsold = p[productindex].unitsold + buyingquantity;
			cout << "================================" << endl;
			cout << "Product is bought successfully" << endl;
			cout << "===========================" << endl;
			salecount++;
			for (int i = 0;i < salecount;i++) {
				if (s[i].saleid==0) {
					s[i].saleid = i + 1;
					s[i].productid = p[productindex].id;
					s[i].quantitysold = buyingquantity;
					s[i].revenue = p[productindex].sellingprice * buyingquantity;
					s[i].cost = p[productindex].costprice * buyingquantity;
					s[i].profit = s[i].revenue - s[i].cost;
				}
			}
		}
	}
	    else {
		cout << "   " << endl;
		cout << "=====Something went wrong=======" << endl;
		cout << "  " << endl;
		cout << "This Product does not exist" << endl;
		cout << "  " << endl;
	}
}

void deleteproduct(product p[], int size, int productid) {
	int productindex = searchproduct(p, size, productid);
	string useranswer;
	if (productindex != -1) {
		cout << "  " << endl;
		cout << "After deletion all information of the product will be removed" << endl;
		cout << "Are you sure you want to delete this product:Answer in Yes or No" << endl;
		getline(cin >> ws, useranswer);
		if (useranswer == "Yes") {
			p[productindex].name = "Null";
			p[productindex].category = "Null";
			p[productindex].costprice = 0;
			p[productindex].sellingprice = 0;
			p[productindex].quantity = 0;
			p[productindex].unitsold = 0;
		}
		else {
			cout << "  " << endl;
			cout << "Okay Your Product is not deleted and safely saved" << endl;
			cout << "  " << endl;
		}
	}
	else {
		cout << "========================" << endl;
		cout << "This id is wrong" << endl;
		cout << "========================" << endl;
	}
}

void displaysales(sale s[], int size) {
		for (int i = 0;i < size;i++) {
			if (s[i].quantitysold >= 1) {
				cout << "   " << endl;
				cout << "=========Saling History=========" << endl;
				cout << "  " << endl;
				cout << "Sale ID:" << s[i].saleid << endl;
				cout << "Saled Product ID:" << s[i].productid << endl;
				cout << "Quantity Sold:" << s[i].quantitysold << endl;
				cout << "Revenue:" << s[i].revenue << endl;
				cout << "Cost:" << s[i].cost << endl;
				cout << "Profit:" << s[i].profit << endl;
			}
		}
	}

void lowstockreport(product p[], int size,int thresholdunit) {
	cout << "  " << endl;
	cout << "======Low Stock Product=======" << endl;
	cout << "  " << endl;
	cout << "ID" << "    " << "Product Name" << "    " << "Quantity" << "    " << endl;
	for (int i = 0;i < size;i++) {
		if (p[i].quantity <= thresholdunit) {
			cout << p[i].id << "    " << p[i].name << "           " << p[i].quantity << "    " << endl;
		}
	}
}

int main() {

	return 0;
}
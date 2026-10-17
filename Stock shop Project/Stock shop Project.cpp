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
		do {
			cout << "Cost Price should be greater than 0.Enter Cost Price:";
			cin >> p[i].costprice;
		} while (p[i].costprice <= 0);
		do {
			cout << "Selling Price should be greater than 0 and costprice.Enter Sellingprice:";
			cin >> p[i].sellingprice;
		} while (p[i].sellingprice <= 0 || p[i].sellingprice < p[i].costprice);
		do {
			cout << "Quantity should be greater than 0.Enter Quantity:";
			cin >> p[i].quantity;
		} while (p[i].quantity <= 0);
		p[i].unitsold = 0;
	}
}

void displayproduct(product p[], int size ) {
		cout << "     " << endl;
		cout << "========All Products Information========" << endl;
		cout << "    " << endl;
		for (int i = 0;i < size;i++) {
			cout << "  " << endl;
			cout << "==============================" << endl;
			cout << "Product ID:" << p[i].id << endl;
			cout << "Name:" << p[i].name << endl;
			cout << "Category:" << p[i].category << endl;
			cout << "Cost Price:" << p[i].costprice << endl;
			cout << "Selling Price:" << p[i].sellingprice << endl;
			cout << "Quantity:" << p[i].quantity << endl;
			cout << "Units Sold:" << p[i].unitsold << endl;
			cout << "==============================" << endl;
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
	int productid = searchproduct(p, size, searchid);
	if (productid != -1) {
		cout << "Product ID should reamin same.It cannot be changed." << endl;
		cout << "Product ID:" << p[searchid].id << endl;
		cout << "Enter Product Name:";
		getline(cin >> ws, p[searchid].name);
		cout << "Enter Product Category:";
		getline(cin >> ws, p[searchid].category);
		while (p[searchid].costprice <= 0) {
			cout << "Cost Price should be greater than 0.Enter Cost Price:";
			cin >> p[searchid].costprice;
		}
		while (p[searchid].sellingprice <= 0 || p[searchid].sellingprice <= p[searchid].costprice) {
			cout << "Selling Price should be greater than 0 and costprice.Enter Sellingprice:";
			cin >> p[searchid].sellingprice;
		}
		cout << "Enter Quantity:";
		cin >> p[searchid].quantity;
		p[searchid].unitsold = 0;
		cout << "Units Sold:" << p[searchid].unitsold << endl;
	}
	else {
		cout << "  " << endl;
		cout << "==========================" << endl;
		cout << "This ID does not exist" << endl;
		cout << "Try with the ID in which you want to update product" << endl;
		cout << "  " << endl;
	}
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

void sellproduct(product p[], int size, int productid, int buyingquantity,sale s[],int &space) {
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
		cout << "==========================" << endl;
		cout << "This id is wrong" << endl;
		cout << "Try again with correct ID" << endl;
		cout << "==========================" << endl;
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

void lowstockreport(product p[], int size,int &thresholdunit) {
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

void salesreport(sale s[], int size) {
	int totalsales = s[0].saleid;
	int totalunitssold = 0;
	double totalrevenue = 0;
	double totalcost = 0;
	double totalprofit = 0;
	for (int i = 0;i < size;i++) {
		totalprofit = totalprofit + s[i].profit;
		totalcost = totalcost + s[i].cost;
		totalrevenue = totalrevenue + s[i].revenue;
		totalunitssold = totalunitssold + s[i].quantitysold;
		if (totalsales < s[i].saleid) {
			totalsales = s[i].saleid;
		}
	}
	cout << "  " << endl;
	cout << "===============================" << endl;
	cout << "=======Total Sales Report======" << endl;
	cout << "   " << endl;
	cout << "Total Successful Sales:" << totalsales << endl;
	cout << "Total items sold:" << totalunitssold;
	cout << "Total Revenue:" << totalrevenue << endl;
	cout << "Total cost of sold items:" << totalcost << endl;
	cout << "Total Gross profit:" << totalprofit << endl;
}

void businessanalytics(product p[], int size, sale s[], int space, int threshold) {
	int totalproducts = p[0].id;
	int totalstocks = 0;
	double totalinventory = 0;
	double totalinventorysellingcost = 0;
	double totalrevenue = 0;
	double totalgrossprofit = 0;
	int zerostockproduct = 0;
	int lowstockproduct = 0;
	for (int i = 0;i < size;i++) {
		totalgrossprofit = totalgrossprofit + s[i].profit;
		totalrevenue = totalrevenue + s[i].revenue;
		totalinventorysellingcost += p[i].sellingprice * p[i].quantity;
		totalinventory += p[i].costprice * p[i].quantity;
		totalstocks = totalstocks + p[i].quantity;
		if (p[i].quantity <= threshold) {
			lowstockproduct++;
		}
		if (p[i].quantity == 0) {
			zerostockproduct++;
		}
		if (totalproducts < p[i].id) {
			totalproducts = p[i].id;
		}
	}
	cout << "  " << endl;
	cout << "==================================" << endl;
	cout << "=====Total Business Analytics=====" << endl;
	cout << "  " << endl;
	cout << "Total Products:" << totalproducts << endl;
	cout << "Total Quantity:" << totalstocks << endl;
	cout << "Total Inventory cost:" << totalinventory << endl;
	cout << "Total Inventory selling cost:" << totalinventorysellingcost << endl;
	cout << "Total Revenue from sales:" << totalrevenue << endl;
	cout << "Total Gross profit from sales:" << totalgrossprofit << endl;
	cout << "Product with zero stock available:" << zerostockproduct << endl;
	cout << "Low Stock Product:" << lowstockproduct << endl;
	cout << "   " << endl;
}

void topsellingproducts(sale s[], int space,product p[]) {
	int firsthighest = s[0].quantitysold;
	int secondhighest = s[0].quantitysold;
	int thirdhighest = s[0].quantitysold;
	int forthhighest = s[0].quantitysold;
	int fifthhighest = s[0].quantitysold;
	int index[5];
	for (int i = 0;i < space;i++) {
		if (firsthighest < s[i].quantitysold) {
			firsthighest = s[i].quantitysold;
			index[0] = i;
		}
	}
	for (int i = 0;i < space;i++) {
		if (secondhighest < s[i].quantitysold && s[i].quantitysold < firsthighest) {
			secondhighest = s[i].quantitysold;
			index[1] = i;
		}
	}
	for (int i = 0;i < space;i++) {
		if (thirdhighest < s[i].quantitysold && s[i].quantitysold < firsthighest && s[i].quantitysold < secondhighest) {
			thirdhighest = s[i].quantitysold;
			index[2] = i;
		}
	}
	for (int i = 0;i < space;i++) {
		if (forthhighest < s[i].quantitysold && s[i].quantitysold < firsthighest && s[i].quantitysold < secondhighest && s[i].quantitysold < thirdhighest) {
			forthhighest = s[i].quantitysold;
			index[3] = i;
		}
	}
	for (int i = 0;i < space;i++) {
		if (fifthhighest < s[i].quantitysold && s[i].quantitysold < firsthighest && s[i].quantitysold < secondhighest && s[i].quantitysold < thirdhighest && s[i].quantitysold < forthhighest) {
			fifthhighest = s[i].quantitysold;
			index[4] = i;
		}
	}
	cout << "  " << endl;
	cout << "======Top 5 Selling Products======" << endl;
	cout << "  " << endl;
	for (int i = 0;i < space;i++) {
		cout << "Product ID:" << p[index[i]].id << endl;
		cout << "Product Name:" << p[index[i]].name << endl;
		cout << "Product category:" << p[index[i]].category << endl;
		cout << "  " << endl;
		cout << "  " << endl;
	}
}

void displaymenu() {
	cout << "=====================================" << endl;
	cout << "               STOCKSMART            " << endl;
	cout << "    INVENTORY & PROFIT MANAGEMENT" << endl;
	cout << "=====================================" << endl;
	cout << "1.Add New Product" << endl;
	cout << "2.View All Products" << endl;
	cout << "3.Search Product" << endl;
	cout << "4.Update Product" << endl;
	cout << "5.Restock Product" << endl;
	cout << "6.Sell Product" << endl;
	cout << "7.Delete Product" << endl;
	cout << "8.Low Stock Product" << endl;
	cout << "9.Sales Report" << endl;
	cout << "10.Business Analytics" << endl;
	cout << "11.Top Selling Products" << endl;
	cout << "12.Exit" << endl;
	cout << "  " << endl;
	cout << "  " << endl;
	cout << "Enter your choice:";
}
int main() {
	
	return 0;
}
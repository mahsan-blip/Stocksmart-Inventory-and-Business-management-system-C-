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

void addproduct(product p[], int size,int count) {
	int end = size + count;
	for (int i = size;i < end;i++) {
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
			cout << "=================================" << endl;
			cout << "Product ID         :" << p[i].id << endl;
			cout << "Name               :" << p[i].name << endl;
			cout << "Category           :" << p[i].category << endl;
			cout << "Cost Price         :" << p[i].costprice << endl;
			cout << "Selling Price      :" << p[i].sellingprice << endl;
			cout << "Quantity           :" << p[i].quantity << endl;
			cout << "Units Sold         :" << p[i].unitsold << endl;
			cout << "==================================" << endl;
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

void displaysearchedproduct(product p[], int size, int searchid) {
	int idindex = searchproduct(p, size, searchid);
	if (idindex == -1) {
		cout << "======================================" << endl;
		cout << "Wrong ID or This Product may not exist" << endl;
		cout << "  " << endl;
	}
	else {
		cout << "  " << endl;
		cout << "========Your searched product========" << endl;
		cout << "Product ID          :" << p[idindex].id << endl;
		cout << "Name                :" << p[idindex].name << endl;
		cout << "Category            :" << p[idindex].category << endl;
		cout << "Selling price       :" << p[idindex].sellingprice << endl;
		cout << "Cost Price          :" << p[idindex].costprice << endl;
		cout << "Quantity Available  :" << p[idindex].quantity << endl;
	}
}

void updateproducts(product p[], int size, int searchid) {
	int productid = searchproduct(p, size, searchid);
	if (productid != -1) {
		cout << "Product ID should remain same.It cannot be changed." << endl;
		cout << "Product ID:" << p[productid].id << endl;
		cout << "Enter Product Name:";
		getline(cin >> ws, p[productid].name);
		cout << "Enter Product Category:";
		getline(cin >> ws, p[productid].category);
		do {
			cout << "Cost Price should be greater than 0.Enter Cost Price:";
			cin >> p[productid].costprice;
		} while (p[productid].costprice <= 0);
		do{ 
			cout << "Selling Price should be greater than 0 and costprice.Enter Sellingprice:";
			cin >> p[productid].sellingprice;
		} while (p[productid].sellingprice <= 0 || p[productid].sellingprice <= p[productid].costprice);
		do {
			cout << "Enter Quantity:";
			cin >> p[productid].quantity;
		} while (p[productid].quantity <= 0);
		p[productid].unitsold = 0;
		cout << "Units Sold:" << p[productid].unitsold << endl;
		cout << "=======================================================" << endl;
		cout << "Units sold is zero because you have updated the product" << endl;
		cout << "=======================================================" << endl;
	}
	else {
		cout << "  " << endl;
		cout << "===================================================" << endl;
		cout << "This ID does not exist" << endl;
		cout << "Try with the ID in which you want to update product" << endl;
		cout << "  " << endl;
	}
}

void restockproducts(product p[], int size, int searchid, int addingquantity) {
	int searchindex = searchproduct(p, size, searchid);
	if (searchindex != -1) {
		do {
			cout << "Stock should be greater than 0" << endl;
			cout << "How much stock you want to add:";
			cin >> addingquantity;
		}while (addingquantity <= 0);
		p[searchindex].quantity = p[searchindex].quantity + addingquantity;
		cout << "  " << endl;
		cout << "===========Quantity Added Successfully============" << endl;
		cout << "  " << endl;
		cout << "Product ID            :" << p[searchindex].id << endl;
		cout << "Product Name          :" << p[searchindex].name << endl;
		cout << "Product Category      :" << p[searchindex].category << endl;
		cout << "Product New quantity  :" << p[searchindex].quantity << endl;
	}
	else {
		cout << "==============================" << endl;
		cout << "This Product does not exist" << endl;
		cout << "   " << endl;
	}
}

void sellproduct(product p[], int size, int productid, int buyingquantity,sale s[],int &space) {
	int productindex = searchproduct(p, size, productid);
	if (space >= 500) {
		cout << "==========================================================" << endl;
		cout << "Sales capacity is full.No more sales should be entered now" << endl;
		cout << "==========================================================" << endl;
	}
	else {
		if (productindex != -1) {
			do {
				cout << "Enter quantity you want to buy:";
				cin >> buyingquantity;
			} while (buyingquantity <= 0);
			if (buyingquantity > p[productindex].quantity) {
				cout << "Sorry!This Product is out of stock" << endl;
				cout << "Please!Try any other product" << endl;
			}
			else {
				p[productindex].quantity = p[productindex].quantity - buyingquantity;
				p[productindex].unitsold = p[productindex].unitsold + buyingquantity;
				cout << "================================" << endl;
				cout << "Product is bought successfully" << endl;
				cout << "================================" << endl;
				s[space].saleid = space + 1;
				s[space].productid = p[productindex].id;
				s[space].quantitysold += buyingquantity;
				s[space].revenue = p[productindex].sellingprice * buyingquantity;
				s[space].cost = p[productindex].costprice * buyingquantity;
				s[space].profit = s[space].revenue - s[space].cost;
				space++;
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
}

void deleteproduct(product p[], int size, int productid) {
	int productindex = searchproduct(p, size, productid);
	string useranswer;
	if (productindex != -1) {
		cout << "  " << endl;
		cout << "After deletion all information of the product will be removed" << endl;
		cout << "Are you sure you want to delete this product:Answer in Yes or No" << endl;
		getline(cin >> ws, useranswer);
		if (useranswer == "Yes"||useranswer=="yes") {
			p[productindex].name = "Null";
			p[productindex].category = "Null";
			p[productindex].costprice = 0;
			p[productindex].sellingprice = 0;
			p[productindex].quantity = 0;
			p[productindex].unitsold = 0;
			cout << "===============================" << endl;
			cout << "Product is Deleted Successfully" << endl;
			cout << "ID:" << p[productindex].id << " This ID is empty you can add product here from product updates." << endl;
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
	if (size == 0) {
		cout << "=================================" << endl;
		cout << "Unfortunately!Zero sales are done" << endl;
		cout << "First make sales" << endl;
		cout << "=================================" << endl;
	}
	else {
		cout << "   " << endl;
		cout << "=========Sales History=========" << endl;
		cout << "  " << endl;
		for (int i = 0;i < size;i++) {
			if (s[i].quantitysold >= 1) {
				cout << "  " << endl;
				cout << "====================================" << endl;
				cout << "Sale ID            :" << s[i].saleid << endl;
				cout << "Sold Product ID    :" << s[i].productid << endl;
				cout << "Quantity Sold      :" << s[i].quantitysold << endl;
				cout << "Revenue            :" << s[i].revenue << endl;
				cout << "Cost               :" << s[i].cost << endl;
				cout << "Profit             :" << s[i].profit << endl;
				cout << "====================================" << endl;
				cout << "  " << endl;
			}
		}
	}
}

void lowstockreport(product p[], int size,int &thresholdunit) {
	int thresholdcheck = 0;
	for (int i = 0;i < size;i++) {
		if (p[i].unitsold <= thresholdunit) {
			thresholdcheck++;
		}
	}
	if (thresholdcheck >= 1) {
		cout << "  " << endl;
		cout << "========Low Stock Product=======" << endl;
		cout << "  " << endl;
		for (int i = 0;i < size;i++) {
			if (p[i].name == "Null")
				continue;
			if (p[i].quantity <= thresholdunit) {
				cout << "   " << endl;
				cout << "Product ID:            " << p[i].id << endl;
				cout << "Name:                  " << p[i].name << endl;
				cout << "Category:              " << p[i].category << endl;
				cout << "Quantity Available:    " << p[i].quantity << endl;
				cout << "  " << endl;
			}
		}
	}
	else {
		cout << "======================================" << endl;
		cout << "=====Zero Product is in low stock=====" << endl;
		cout << "  " << endl;
	}
}

void salesreport(sale s[], int size) {
	if (size == 0) {
		cout << "=========================================" << endl;
		cout << "Unfortunately zero sale is done till now" << endl;
		cout << "=========================================" << endl;
	}
	else {
		int totalsales = size;
		int totalunitssold = 0;
		double totalrevenue = 0;
		double totalcost = 0;
		double totalprofit = 0;
		for (int i = 0;i < size;i++) {
			totalprofit = totalprofit + s[i].profit;
			totalcost = totalcost + s[i].cost;
			totalrevenue = totalrevenue + s[i].revenue;
			totalunitssold = totalunitssold + s[i].quantitysold;
		}
		cout << "  " << endl;
		cout << "=========================================" << endl;
		cout << "============Total Sales Report===========" << endl;
		cout << "   " << endl;
		cout << "Total Successful Sales    :" << totalsales << endl;
		cout << "Total items sold          :" << totalunitssold << endl;
		cout << "Total Revenue             :" << totalrevenue << endl;
		cout << "Total cost of sold items  :" << totalcost << endl;
		cout << "Total Gross profit        :" << totalprofit << endl;
		cout << "  " << endl;
	}
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
	if (size == 0) {
		cout << "========================================" << endl;
		cout << "Unfortunately!Zero Sale is done till now" << endl;
		cout << "First make sales" << endl;
		cout << "========================================" << endl;
	}
	else {
		for (int i = 0;i < size;i++) {
			if (p[i].name == "Null") continue;
			{
				totalgrossprofit += p[i].quantity * p[i].sellingprice;
				totalinventorysellingcost += p[i].sellingprice * p[i].quantity;
				totalinventory += p[i].costprice * p[i].quantity;
				totalstocks = totalstocks + p[i].quantity;
				totalrevenue = totalrevenue + s[i].revenue;
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
		}
	}
	cout << "  " << endl;
	cout << "==============================================" << endl;
	cout << "===========Total Business Analytics===========" << endl;
	cout << "  " << endl;
	cout << "Total Products                    :" << totalproducts << endl;
	cout << "Total Quantity                    :" << totalstocks << endl;
	cout << "Total Inventory cost              :" << totalinventory << endl;
	cout << "Total Inventory selling cost      :" << totalinventorysellingcost << endl;
	cout << "Total Revenue from sales          :" << totalrevenue << endl;
	cout << "Total Gross profit from sales     :" << totalgrossprofit << endl;
	cout << "Product with zero stock available :" << zerostockproduct << endl;
	cout << "Low Stock Product:" << lowstockproduct << endl;
	cout << "   " << endl;
}

void topsellingproducts(product p[],int size,int space) {
	int first = 0;
	int second = 0;
	int third = 0;
	int fourth = 0;
	int fifth = 0;
	int index[3] = {};
	if (space < 3) {
		cout << "=============================================================" << endl;
		cout << "Unfortunately!You have zero sales" << endl;
		cout << "First Make 3 sales then this faeture will work" << endl;
		cout << "=============================================================" << endl;
	 }
	else {
		for (int i = 0;i < size;i++) {
			if (first < p[i].unitsold) {
				first = p[i].unitsold;
				index[0] = i;
			}
		}
		for (int i = 0;i < size;i++) {
			if (second < p[i].unitsold && p[i].unitsold < first) {
				second = p[i].unitsold;
				index[1] = i;
			}
		}
		for (int i = 0;i < size;i++) {
			if (third < p[i].unitsold && p[i].unitsold < first && p[i].unitsold < second) {
				third = p[i].unitsold;
				index[2] = i;
			}
		}
		cout << "==============================================" << endl;
		cout << "=============Top 3 Seling Product=============" << endl;
		cout << "  " << endl;
		for (int i = 0;i < 3;i++) {
			cout << "  " << endl;
			cout << "Product ID          :" << p[index[i]].id << endl;
			cout << "Name                :" << p[index[i]].name << endl;
			cout << "Category            :" << p[index[i]].category << endl;
			cout << "Seling price        :" << p[index[i]].sellingprice << endl;
			cout << "Units sold          :" << p[index[i]].unitsold << endl;
			cout << "  " << endl;
		}
	}
}

void displaymenu() {
	cout << "=====================================" << endl;
	cout << "               STOCKSMART            " << endl;
	cout << "    INVENTORY & PROFIT MANAGEMENT" << endl;
	cout << "=====================================" << endl;
	cout << "1. Add New Product" << endl;
	cout << "2. View All Products" << endl;
	cout << "3. Search Product" << endl;
	cout << "4. Update Product" << endl;
	cout << "5. Restock Product" << endl;
	cout << "6. Sell Product" << endl;
	cout << "7. Delete Product" << endl;
	cout << "8. Low Stock Product" << endl;
	cout << "9. View All Sales" << endl;
	cout << "10.Sales Report" << endl;
	cout << "11.Business Analytics" << endl;
	cout << "12.Top Selling Products" << endl;
	cout << "13.Exit" << endl;
	cout << "  " << endl;
	cout << "  " << endl;
	cout << "Enter your choice:";
}

int main() {
	product p[100] = {};
	sale s[500] = {};
	int choice = 0;
	int numberofproducts = 0;
	int totalproducts = 0;
	int productid = 0;
	int restockquantity = 0;
	int numberofsales = 0;
	int buyingquantity = 0;
	int threshold = 5;
	do {
		displaymenu();
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "How many number of Products you want to add?" << endl;
			cin >> numberofproducts;
			if (totalproducts + numberofproducts > 100) {
				cout << "==========================================================" << endl;
				cout << "Product capacity is full. Now you cannot add more products" << endl;
				cout << "  " << endl;
			}
			else {
				addproduct(p, totalproducts, numberofproducts);
				totalproducts = totalproducts + numberofproducts;
			}
			break;
		case 2:
			displayproduct(p, totalproducts);
			break;
		case 3:
			cout << "Enter Product ID:";
			cin >> productid;
			displaysearchedproduct(p, totalproducts, productid);
			break;
		case 4:
			cout << "Enter Product ID:";
			cin >> productid;
			updateproducts(p, totalproducts, productid);
			break;
		case 5:
			cout << "Enter Product ID:";
			cin >> productid;
			restockproducts(p, totalproducts, productid, restockquantity);
			break;
		case 6:
			cout << "Enter product ID:";
			cin >> productid;
			sellproduct(p, totalproducts, productid, buyingquantity, s, numberofsales);
			break;
		case 7:
			cout << "Enter Product ID:";
			cin >> productid;
			deleteproduct(p, totalproducts, productid);
			break;
		case 8:
			cout << "BY default it is 5.If you want that it remains five so enter 5 again." << endl;
			cout << "Enter low stock threshold quantity:";
			cin >> threshold;
			lowstockreport(p, totalproducts, threshold);
			break;
		case 9:
			displaysales(s, numberofsales);
			break;
		case 10:
			salesreport(s, numberofsales);
			break;
		case 11:
			businessanalytics(p, totalproducts, s, numberofsales, threshold);
			break;
		case 12:
			topsellingproducts(p, totalproducts,numberofsales);
			break;
		case 13:
			cout << "===============================" << endl;
			cout << "Thank you for using this System" << endl;
			cout << "  " << endl;
			break;
		default:
			cout << "  " << endl;
			cout << "=======Wrong Input=======" << endl;
			cout << "        Try Again     " << endl;
			cout << "  " << endl;
			break;
		}
	} while (choice != 13);
	return 0;
}
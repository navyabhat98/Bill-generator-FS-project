#include<iostream>
#include<stdio.h>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;

class items
{
	//items
	string monthname;
	string buffer;
	public:
		void insert_monthly_income();
		void generate_bill();
		void store_bill(string);
		void display_bill(string);
};

void items::insert_monthly_income()
{
	//read the items
}

void items::generate_bill()
{
	//bill with proper format is generated
}

void items::store_bill(string month)
{

	monthname = month;
	monthname+=".txt";
	fstream file;
	file.open(monthname,ios::out|ios::app);
	file<<buffer;
	file.close();
}

void items::display_bill(string date)
{
	date += ".txt";
	system("cat.txt");
}	


int main()
{
	return 0;
}

#include<iostream>
#include<stdio.h>
#include<string>
#include<sstream>
#include<fstream>
#include<stdlib.h>

using namespace std;

class items
{
	//items
	string itemnames[100];
	string itemvalues[100];
	string monthname;
	string buffer;
	double price[100];
	int qty;
	public:
		//fucntions to pack and unpack item names into a file, storeitems.txt
		void store_item_names();
		void unpack_item_names();

		//fucntion to append more items
		void append_itemname();

		//fucntion to store monthly income and generate a bill and store it in a file.
		//the bill will be stored as monthname-year.txt
		void insert_monthly_income();
		void generate_bill();
		void store_bill(string);
		void display_bill(string);
};

//fucntions definition for packing and unpacking
void items::append_itemname()
{
	buffer.erase();
	cout<<"\nEnter item to be appended to file:";
	getline(cin, buffer);
	cout<<"\nEnter Price of item:";
	//cin>>price;
	//store it in a file
	store_item_names();
}

void items::store_item_names()
{
	fstream file;
	file.open("storeitems.txt",ios::out|ios::app);
	file<<buffer<<"|"<<price<<"$"<<"\n";
	file.close();
}

void items::unpack_item_names()
{
	int i=0,j=0;
	fstream file;
	file.open("storeitems.txt",ios::in);
	while(!file.eof())
	{
		buffer.erase();
		getline(file,buffer);
		while(buffer[i]!='|')
			itemnames[j] += buffer[i++];
		while(buffer[i]!='$')
			
		j++;
	}
	cout<<itemnames[0]<<"\n"<<itemnames[1];
	file.close();

}
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

	items i;
	i.unpack_item_names();
	
	return 0;
}

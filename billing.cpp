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
	string itemnames;
	string itemvalues;
	string monthname;
	string buffer;
	float amount;
	float price;
	int qty;

	public:
		//fucntions to pack and unpack item names into a file, storeitems.txt
		void store_item_names();
		void unpack_item_names(int);

		//fucntion to append more items
		void append_itemname();

		//fucntion to store monthly income and generate a bill and store it in a file.
		//the bill will be stored as monthname-year.txt
		void insert_monthly_income(string);
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
	cin>>price;
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

void items::unpack_item_names(int i)
{
	while(buffer[i]!='|')
		itemnames += buffer[i++];
	while(buffer[i]!='$');
		//get the price value
}
void items::insert_monthly_income(string month)
{
	int i;
	fstream file;
	file.open("storeitems.txt",ios::in);
	while(!file.eof())
	{
		i = 0;
		buffer.erase();
		getline(file,buffer);
		unpack_item_names(i);
		
		cout<<"\n"<<itemnames<<":";	cin>>itemvalues;
		cout<<"\nQuantity:";		cin>>qty;
		amount = price*qty;
		store_bill(month);
			
		
	}
	file.close();	
}


void items::store_bill(string month)
{

	monthname = month;
	monthname+=".txt";
	fstream file;
	file.open(monthname,ios::out|ios::app);
	file<<itemnames<<"\t"<<qty<<"\t"<<amount<<"$"<<"\n";
	file.close();
}

void items::display_bill(string date)
{
	date += ".txt";
	string s = "cat "+date;
	//system(s);
}	


int main()
{

	items i;
	int choice;
	string month;
	while(1) 
	{
		cout<<"\nMENU\n";
		cout<<"1. Monthly income updatation\n";
		cout<<"2. Display bill\n";
		cout<<"3. Entering new Item in store.\n";
		cout<<"4.Exit\n";
		cout<<"Enter choice:";	cin>>choice;
		switch(choice)
		{
			case 1: system("clear");
				cout<<"\nEnter month name and year(monthnameyy):"; cin>>month;	
				i.insert_monthly_income(month);
				break;
			case 2: system("clear");
				cout<<"\nEnter month name and year(monthnameyy):";	cin>>month;
				i.display_bill(month);
				break;
			case 3: system("clear");
				cout<<"\nNew Item to store list\n";
				i.append_itemname();
			case 4: exit(0);
			default: cout<<"Invalid choice\n";
		}
	}
	
	return 0;
}

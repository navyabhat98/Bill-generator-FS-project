#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


using namespace std;


int check_if_month_exist(string);


class items
{
	
		string itemnames,buffer,sprice;
		string tqty,tprice;		//temporary quantity and price to store temporary vlaues
		int qty;
		float price;
		float total;
	public:
		void read_data_storeitems();		//to get the data that exist in the store

		void pack_storeitems();			//pack the above above data

		void write_to_file();			//write the above data in a file called storeitems.txt

		void unpack_storeitems();		//unpack the item available in the store

		void update_monthly_bill(string);	/* at the end of the month update how many 
								items were sold from the store 	*/
		void pack_for_file(string);		/*packing the above to write it to the file
								each month's data will be stored in a different file named as monthyyyy */
		
		void unpack_bill();			//unpack from the monthyyyy file to generate and display bill
		
		void display_monthly_bills(string);	//display bill of each month
		
		void add_file_toindex(string); 		/*indexed file which holds the name of the months of file 
							that are updated along with total income of that month */

};

void items::read_data_storeitems()
{
	cout<<"Itemname:";
	cin>>itemnames;
	cout<<"Price:";
	cin>>sprice;
	
}

void items::pack_storeitems()
{
	buffer.erase();
	buffer+=itemnames+"|"+sprice+"$"+"\n";
}

void items::write_to_file()
{
	fstream file;
	file.open("storeitems.txt",ios::out|ios::app);
	file<<buffer;
	file.close();
}



void items::pack_for_file(string month)
{
	string filebuffer;

	cout<<itemnames<<":";
	cin>>qty;

	price = qty*stof(sprice);		//find price of each file, stof() is a function to convert string to float value
	cout<<"Rs."<<price<<endl;

	total += price;				//find the total price which is later stored in months.txt
	
	filebuffer += itemnames+"|"+sprice+"|"+to_string(qty)+"|"+to_string(price)+"$"+"\n";

	fstream file1;
	file1.open(month,ios::out|ios::app);
	file1<<filebuffer;				//store it in file
	file1.close();
	
}


void items::unpack_storeitems()
{
	int ch=1,i=0;
	itemnames.erase();
	while(buffer[i]!='|')
		itemnames += buffer[i++];
	sprice.erase();				//sprice is string price. which stores the price value is string format
	i++;
	while(buffer[i]!='$')
		sprice += buffer[i++];
	
}


void items::update_monthly_bill(string month)
{
	ifstream file;
	file.open("storeitems.txt",ios::in);
	total = 0;
	while(!file.eof())
	{
		
		buffer.erase();
		getline(file,buffer);
		if(buffer.length()!=0)
		{ 
			unpack_storeitems();		//unpack from storeitems.txt to get the data of items in store 
							
			pack_for_file(month); 		/*functions asks for qty of each item 
							that is in storeitems.txt and stores in another file */
		}	
	}
	
	
	file.close();
	
}


void items::unpack_bill()
{
		int ch=0,i=0;
		itemnames.erase();
		while(buffer[i]!='|')
			itemnames += buffer[i++];
		sprice.erase();
		i++;
		while(buffer[i]!='|')
			sprice += buffer[i++];
		tqty.erase();
		i++;
		while(buffer[i]!='|')
			tqty += buffer[i++];
		tprice.erase();
		i++;
		while(buffer[i]!='$')
			tprice += buffer[i++];
		i++;
		price = stof(tprice);
		total += price;

}
void items::display_monthly_bills(string month)
{
	
	ifstream file2;
	file2.open(month,ios::in);
	system("clear");
	cout<<"MONTH YEAR:"<<month<<endl<<endl;
	cout<<"ITEMNAME\tPRICE/unit\tQty\tPRICE\n";
	while(!file2.eof())
	{
		
		buffer.erase();
		getline(file2,buffer);
		if(buffer.length()!=0)
		{
			unpack_bill();
			cout<<itemnames<<"\t\t\t"<<sprice<<"\t"<<tqty<<"\t"<<tprice<<"\n";
		}		
		
	}

	cout<<"\n\n\t\t\tTotal monthly income: Rs."<<total<<endl;
	file2.close();
	
}


void items::add_file_toindex(string month)
{
	fstream file3;
	file3.open("months.txt",ios::out|ios::app);
	string buf; 
	buf += month+"|"+to_string(price)+"$"+"\n";
	file3<<buf;
	file3.close();
} 


int main()
{
	int count,choice,i;
	items s1;
	string month;
	char c;
	system("clear");
	while(1)
	{
		system("clear");		
		cout<<"\n\t\t\tBilling Generator";

		cout<<"\n\t\t1. Store items \n\t\t2. Billing \n\t\t3. Exit \n\t\t Choice:";		
		cin>>choice;

		switch(choice)
		{
			case 1: system("clear");
 				
				cout<<"\n\n\t\t\tITEMS IN STORE";
				cout<<"\n\t\t1.Add items \n\t\t2.Modify \n\t\t3.Back <-\n\t\tchoice:";
				cin>>choice;

				switch(choice)
				{
					case 1: cout<<"\nHow many:";
						cin>>count;
						for(i=0;i<count;i++)
						{
							cout<<"Data\n";
							s1.read_data_storeitems();
							s1.pack_storeitems();
							s1.write_to_file();
						}
						break;	
					case 2: system("clear");
						cout<<"Under construction";
						getchar();
				}				
				break;
				
			
		
			case 2: 
				
				while(choice!=3)
				{
					system("clear");
					cout<<"\n\n\t\t1.Display monthly bill \n\t\t2.Update Monthly bill \n\t\t3.back <-\n\t\tchoice:";
				
					cin>>choice;

					switch(choice)
					{
						
						
						case 1:	cout<<"Enter the month:";
							cin>>month;
							s1.display_monthly_bills(month);
							break;

						case 2:	cout<<"Enter the month:";
							cin>>month;

							if(check_if_month_exist(month)==0)
							{	
								
								s1.update_monthly_bill(month); 
								s1.add_file_toindex(month); 
							}
							
							else
							{ cout<<"\nAlready updated\n"; }
							
							break;
						
						case 3: break;
						default: cout<<"Invalid Choice\n\n";
					}
				}
				break;
			case 3: return 0;
			
			default: cout<<"\n\nInvalid Choice. Try again\n\n";
		}
	}
return 0;
}


int check_if_month_exist(string month)
{
	fstream file3;
	file3.open("months.txt",ios::in);
	string filename,buf;
	
	while(!file3.eof())
	{
		int i = 0;
		getline(file3,buf);
		while(buf[i]!='|')
			filename += buf[i++];
		if(filename == month)
		{
			file3.close();	
			return 1;
		}
	}
	file3.close();	
	return 0;
}


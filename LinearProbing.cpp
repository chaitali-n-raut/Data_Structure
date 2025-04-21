#include<iostream>
using namespace std; 

int n, key[10]; 
class LinearProb
{
	int prn, percent; 
	string name; 
	public : 
		void CreateHashT(); 
		void DisplayHashT(); 
		void Accept(); 
		void Search(); 
		void Modify(); 
		void Delete(); 
}h[10]; 

void LinearProb :: CreateHashT()
{
		cout<<"\nEnter How many Records You Want To Store : "; 
		cin>>n; 
		// Hash Table Initialization
		for(int i=0;i<10;i++)
		{
			h[i].prn = -1; 
			h[i].percent = 0; 
			h[i].name = "-"; 
		}
}
void LinearProb :: DisplayHashT()
{
		cout<<"\nLocation "<<"\t"<< "PRN "<<"\t"<< "Name" <<"\t"<<"Percentage"<<endl; 
		for(int i=0;i<10;i++)
		{
			cout<<i<<"\t\t"<<h[i].prn<<"\t\t"<<h[i].name<<"\t\t"<<h[i].percent<<endl; 
		}
}

void LinearProb :: Accept()
{
	int loc, pos; 
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter PRN No. :"; 
		cin>>key[i];

		loc = key[i] % 10; //Hash Function to Find Location
		pos = loc; 
		
		do
		{
			if(h[loc].prn == -1) //if location is empty
			{
				h[loc].prn = key[i]; 
				cout<<"\nEnter Name :"; 
				cin>>h[loc].name; 
				cout<<"\nEnter Percentage :"; 
				cin>>h[loc].percent; 
				break; 
			}
			else
			{
				loc = (loc+1)%10; //Directly finds next empty location
			}
		}while(loc!=pos);  // for taking 
		
	}
}

void LinearProb :: Search()
{
	int Searchprn, flag=0; 
	cout<<"\nEnter PRN of Student You Want to Search :"; 
	cin>>Searchprn; 
	
	for(int i=0;i<10;i++)
	{
		if(h[i].prn == Searchprn)
		{
			cout<<"\n*******Student Record Found*****";
			cout<<"\nLocation = "<<i; 
			cout<<"\nPRN :"<<h[i].prn; 
			cout<<"\nName :"<<h[i].name; 
			cout<<"\nPercentage :"<<h[i].percent; 
			flag = 1; 
			break; 
		}
	}
	if(flag == 0)
	{
		cout<<"\n!!!!!Student Record Not Found!!!!!"; 
	}
}

void LinearProb :: Modify()
{
	int Searchprn, flag = 0; 
	cout<<"\nEnter PRN of Student You Want To Update :"; 
	cin>>Searchprn; 
	
	for(int i=0;i<10;i++)
	{
		if(h[i].prn == Searchprn)
		{
			cout<<"\nEnter New Record :"; 
			cout<<"\nEnter New PRN, Name, Percentage :"; 
			cin>>h[i].prn>>h[i].name>>h[i].percent; 
			cout<<"\n============Record Updated=================="; 
			flag = 1; 
			break; 
		}
	}
	if(flag == 0)
	{
		cout<<"\nStudent Record Not Found!!!"; 
	}
}

void LinearProb :: Delete()
{
	int Searchprn, flag =0; 
	cout<<"\nEnter PRN of Student You Want To Delete :"; 
	cin>>Searchprn; 
	
	for(int i=0;i<10;i++)
	{
		if(h[i].prn == Searchprn)
		{
			h[i].prn = -1;
			h[i].name = "-"; 
			h[i].percent = 0 ; 
			cout<<"\n================Record Deleted==================="; 
			flag = 1; 
			break; 
		}
	}
	if(flag == 0)
	{
		cout<<"\nStudent Record Not Found!!!!"; 
	}
}
int main()
{
	LinearProb l; 
	int ch; 
	do 
	{
		cout<<"\n========================Menu=========================="; 
		cout<<"\n1.Create Hash Table \n2.Display Table \n3.Accept Records  \n4.Search Record \n5.Modify Record \n6.Delete Record \n7.Exit"; 
		cout<<"\nEnter Your Choice :"; 
		cin>>ch; 
		switch(ch)
		{
			case 1 : 
					l.CreateHashT(); 
					break; 
			case 2 : 
					l.DisplayHashT(); 
					break; 
			case 3 : 
					l.Accept(); 
					break; 
			case 4 : 
					l.Search(); 
					break; 
			case 5 : 
					l.Modify(); 
					break; 
			case 6 : 
					l.Delete(); 
					break; 
			case 7 : 
					cout<<"====================Thanks For Using====================="; 
					return 0; 
					break;
			default :
					cout<<"\n!!!!Wrong Choice !!!!!"; 
					break;
		}
	}while(ch!=7); 
	return 0; 
}

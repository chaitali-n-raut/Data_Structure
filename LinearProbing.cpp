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
			cout<<i<<"\t\t"<<h[i].prn<<"\t"<<h[i].name<<"\t\t"<<h[i].percent<<endl; 
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
		}while(loc!=pos);  // for taking it to again 0th locatin
		
	}
}

void LinearProb :: Search()
{
	int searchPrn, flag = 0;
    cout << "\nEnter PRN of Student You Want to Search: ";
    cin >> searchPrn;

    int loc = searchPrn % 10;
    int start = loc;

    do 
	{
        if (h[loc].prn == searchPrn) 
		{
            cout << "\nRecord Found!";
            cout << "\nLoc = " << loc;
            cout << "\nPRN: " << h[loc].prn;
            cout << "\nName: " << h[loc].name;
            cout << "\nPercentage: " << h[loc].percent;
            flag = 1;
            break;
        }
        loc = (loc + 1) % 10;
    } while (loc != start);

    if (flag == 0) 
	{
        cout << "\nRecord Not Found!";
    }
}

void LinearProb::Modify()
{
	int searchPrn, flag = 0;
	cout << "\nEnter PRN of Student You Want To Update: ";
	cin >> searchPrn;

	int loc = searchPrn % 10;
	int start = loc;

	do
	{
		if (h[loc].prn == searchPrn)
		{
			cout << "\nEnter New Record:";
			cout << "\nEnter New Name, Percentage: ";
			cin >> h[loc].name >> h[loc].percent;
			cout << "\n============Record Updated==================";
			flag = 1;
			break;
		}
		loc = (loc + 1) % 10;
	} while (loc != start);  // stop if we've looped around

	if (flag == 0)
	{
		cout << "\nStudent Record Not Found!!!";
	}
}

void LinearProb::Delete()
{
	int Searchprn, flag = 0;
	cout << "\nEnter PRN of Student You Want To Delete: ";
	cin >> Searchprn;

	int loc = Searchprn % 10;
	int start = loc;

	do
	{
		if (h[loc].prn == Searchprn)
		{
			h[loc].prn = -1;
			h[loc].name = "-";
			h[loc].percent = 0;
			cout << "\n================Record Deleted===================";
			flag = 1;
			break;
		}
		loc = (loc + 1) % 10;
	} while (loc != start);  // Stop if we've come full circle

	if (flag == 0)
	{
		cout << "\nStudent Record Not Found!!!!";
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

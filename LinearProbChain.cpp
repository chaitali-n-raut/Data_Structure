#include<iostream>
using namespace std; 

int n, key[10], chain[10]; 
class LinearProbChain
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

void LinearProbChain :: CreateHashT()
{
		cout<<"\nEnter How many Records You Want To Store : "; 
		cin>>n; 
		// Hash Table Initialization
		for(int i=0;i<10;i++)
		{
			h[i].prn = -1; 
			h[i].percent = 0; 
			h[i].name = "-"; 
			chain[i] = -2; 
			
		}
}
void LinearProbChain :: DisplayHashT()
{
		cout<<"\nLocation "<<"\t"<< "PRN "<<"\t"<< "Name" <<"\t"<<"Percentage"<<"\t"<<"Chain"<<endl; 
		for(int i=0;i<10;i++)
		{
			cout<<i<<"\t\t"<<h[i].prn<<"\t"<<h[i].name<<"\t\t"<<h[i].percent<<"\t"<<chain[i]<<endl; 
		}
}

void LinearProbChain :: Accept()
{
	int loc, pos; 
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter PRN No. :"; 
		cin>>key[i]; //11
		//1
		loc = key[i] % 10; //Hash Function to Find Location
		pos = loc; // pos = 1
		
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
				// gets new Empty location
				loc = (loc+1)%10; //Directly finds next empty location
				chain[pos] = loc; 
				//c[1] = 2 				
			}
		}while(loc!=pos);  // for taking it to again 0th locatin
		
	}
}

void LinearProbChain :: Search()
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

void LinearProbChain :: Modify()
{
	int Searchprn, flag = 0; 
	cout<<"\nEnter PRN of Student You Want To Update :"; 
	cin>>Searchprn; 
	
	for(int i=0;i<10;i++)
	{
		if(h[i].prn == Searchprn)
		{
			cout<<"\nEnter New Record :"; 
			cout<<"\nEnter New Name, Percentage :"; 
			cin>>h[i].name>>h[i].percent; 
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

void LinearProbChain :: Delete()
{
	int Searchprn, flag =0; 
	cout<<"\nEnter PRN of Student You Want To Delete :"; 
	cin>>Searchprn; 
	
	for(int i=0;i<10;i++)
	{
		if(h[i].prn == Searchprn)
		{			
			// To Replace
			if(chain[i] != -2)
			{
					int next;
					next = chain[i]; 
					
					h[i] = h[next]; 
					chain[i] = chain[next]; 
					h[next].prn = -1;
					h[next].name = "-"; 
					h[next].percent = 0 ; 
					chain[next] = -2; 
					cout<<"\n================Record Deleted===================";
					
			}
			else 
			{
				h[i].prn = -1;
				h[i].name = "-"; 
				h[i].percent = 0 ; 
				chain[i] = -2; 
				cout<<"\n================Record Deleted==================="; 
			}
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
	LinearProbChain l; 
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

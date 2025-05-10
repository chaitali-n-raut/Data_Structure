
#include<iostream>
using namespace std;

int n, key[10], chain[10], i, loc;

class LinearProbChain 
{
	int prn, percent;
	string name;
public:
	void CreateHashT();
	void DisplayHashT();
	void Accept();
	void Search();
	void Modify();
	void Delete();
}h[10];

void LinearProbChain::CreateHashT() 
{
	
	cout << "\nEnter How many Records You Want To Store: ";
	cin >> n;

	for (int i = 0; i < 10; i++) 
	{
		h[i].prn = -1;
		h[i].percent = 0;
		h[i].name = "-";
		chain[i] = -1;
	}
}

void LinearProbChain::DisplayHashT() 
{
	cout << "\nLoc\tPRN\tName\t\t%\tChain\n";
	for (int i = 0; i < 10; i++) 
	{
		cout << i << "\t" << h[i].prn << "\t" << h[i].name << "\t\t" << h[i].percent << "\t" << chain[i] << endl;
	}
}

void LinearProbChain::Accept() 
{
	int loc, pos;
	for (int i = 0; i < n; i++) 
	{
		cout << "\nEnter PRN No. :";
		cin >> key[i];
		loc = key[i] % 10;

		if (h[loc].prn == -1) 
		{
			// No collision
			h[loc].prn = key[i];
			cout << "Enter Name: ";
			cin >> h[loc].name;
			cout << "Enter Percentage: ";
			cin >> h[loc].percent;
		} 
		else
		{
			// Collision occurred
			pos = loc;
			int last = pos;

			// Traverse chain to find last record in chain
			while (chain[last] != -1) 
			{
				last = chain[last];
			}

			// Linear probing to find empty slot
			int newloc = (loc + 1) % 10;
			while (h[newloc].prn != -1 && newloc != loc) 
			{
				newloc = (newloc + 1) % 10;
			}

			if (newloc == loc) 
			{
				cout << "Hash Table is Full!\n";
				return;
			}

			// Insert at found location
			h[newloc].prn = key[i];
			cout << "Enter Name: ";
			cin >> h[newloc].name;
			cout << "Enter Percentage: ";
			cin >> h[newloc].percent;

			chain[last] = newloc;
		}
	}
}

void LinearProbChain::Search() 
{
	int searchPrn, flag = 0;
	cout << "\nEnter PRN of Student You Want to Search: ";
	cin >> searchPrn;

	loc = searchPrn % 10;
	while (loc != -1) 
	{
		if (h[loc].prn == searchPrn) 
		{
			cout << "\nRecord Found!\n";
			cout << "Loc = " << loc << "\nPRN: " << h[loc].prn << "\nName: " << h[loc].name << "\nPercentage: " << h[loc].percent;
			flag = 1;
			break;
		}
		loc = chain[loc];  // follow the chain
	}

	if (flag == 0)
		cout << "\nRecord Not Found!";
}


void LinearProbChain::Modify() 
{
	int searchPrn, flag = 0;
	cout << "\nEnter PRN of Student You Want To Update: ";
	cin >> searchPrn;

	loc = searchPrn %10; //loc =1
	while (loc != -1) 
	{
		if(h[loc].prn == searchPrn)
		{
			cout << "\nEnter New Name and Percentage: ";
			cin >> h[loc].name >> h[loc].percent;
			cout << "\nRecord Updated!";
			flag = 1;
			break; 
			
			
		}
		loc = chain[loc];
	}
	if (flag == 0)
		cout << "\nRecord Not Found!";
}

void LinearProbChain::Delete() 
{
	int searchPrn, flag=0, pos, loc;
	cout<<"\nEnter PRN Of Student You Want To Delete :"; 
	cin>>searchPrn; 
	loc = searchPrn %10; //loc =1
	while(loc != -1)
	{
		if(h[loc].prn == searchPrn && chain[loc] != -1) //h[1].prn = 111 && chai[1] = 2
		{
			do 
			{
				pos = chain[loc];  // pos = 2  // pos = 3
				h[loc] = h[pos]; 	//h[1] = h[2] all record of h[2] //h[2] = h[3] 
				loc = pos;  //loc = 2 // loc =3
				flag = 1;  
			}while(chain[loc]!= -1);  //chain[2] = 3 != -1  //chain[3] = -1; 
			
			chain[loc - 1 ] = -1; 
			
			cout<<"\nRecord is Deleted "; 
			chain[pos] = -1; 
			h[loc].prn = -1; 
			h[loc].percent = 0;
			h[loc].name = "-";
			
		}
		loc = chain[loc];

	}
	
	if (flag == 0)
	{
		cout << "\nRecord Not Found!";
	}
	
	
}

int main() 
{
	LinearProbChain l;
	int ch;
	do 
	{
		cout << "\n=======Menu=======\n1. Create Hash Table\n2. Display Table\n3. Accept Records\n4. Search Record\n5. Modify Record\n6. Delete Record\n7. Exit\nEnter your choice: ";
		cin >> ch;
		switch (ch) 
		{
			case 1: l.CreateHashT(); break;
			case 2: l.DisplayHashT(); break;
			case 3: l.Accept(); break;
			case 4: l.Search(); break;
			case 5: l.Modify(); break;
			case 6: l.Delete(); break;
			case 7: cout << "\nThank You for Using!"; break;
			default: cout << "\nInvalid Choice!";
		}
	} while (ch != 7);

	return 0;
}

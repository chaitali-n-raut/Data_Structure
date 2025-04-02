/* Implement the given problem statement using the concept of Binary Tree.  */

#include<iostream>
using namespace std; 
class Emp
{
	int id; 
	string name; 
	Emp *Lc, *Rc; 
	public : 
		void Create(); 
		void Insert(Emp *root, Emp *next); 
		void DisplayInorder(Emp *root); 
		void DisplayPreorder(Emp *root); 
		void DisplayPostorder(Emp *root); 

}*root; 
void Emp :: Create()
{
	root = new Emp; 
	Emp *next; 
	int ch; 
	cout<<"\n---------- Enter Employee Info ----------"; 
	cout<<"\nEnter Employee ID :"; 
	cin>>root->id;
	cout<<"\nEnter Employee Name :"; 
	cin>>root->name; 
	 
	 root->Lc = NULL; 
	 root->Rc = NULL; 
	 
	 do
	 {
		 cout<<"\nDo you want to add more Emp Info? (press Yes=1, NO=0)"; 
		 cin>>ch; 
		 if(ch==1)
		 {
				next = new Emp; 
				cout<<"\n-----Enter new Employee Info------"; 
				cout<<"\nEnter Employee new ID :"; 
				cin>>next->id; 
				cout<<"\nEnter Employee new Name :"; 
				cin>>next->name; 
				
				next->Lc = NULL; 
				next->Rc = NULL; 
				Insert(root, next); 
		 }
	 }while(ch==1); 
}

void Emp :: Insert(Emp *root, Emp *next)
{
		char chr; 
		cout<<"\nEnter Where you want to insert new Emp info -> Left/Right of ID : ";
		cin>>chr; 
		
		if(chr == 'L' || chr == 'l') 
		{
			if(root->Lc == NULL)
			{
				root->Lc = next; //connect to newnode
			}
			else 
			{
				Insert(root->Lc, next); // Root's LC is not NULL
			}
		}
		else if(chr == 'R' || chr == 'r')
		{
			if(root->Rc == NULL)
			{
				root->Rc = next; 
			}
			else
			{
				Insert(root->Rc, next); 
			}
		}	
}
void Emp :: DisplayInorder(Emp *root)
{
	if(root == NULL)
	{ 
		return; 
	}
	else
	{
		DisplayInorder(root->Lc); // Recursion Function
		cout << "\nEmployee ID: " << root->id << "\tEmployee Name: " << root->name; 
		DisplayInorder(root->Rc); // Recursion Function
	}
}

void Emp :: DisplayPreorder(Emp *root)
{
	if(root == NULL)
	{
		return; 
	}
	else
	{
		
		cout << "\nEmployee ID: " << root->id << "\tEmployee Name: " << root->name; 
		DisplayPreorder(root->Lc); // Recursion Function
		DisplayPreorder(root->Rc); // Recursion Function
	}
}

void Emp :: DisplayPostorder(Emp *root)
{
	if(root == NULL)
	{
		return; 
	}
	else
	{
		DisplayPostorder(root->Lc); // Recursion Function
		DisplayPostorder(root->Rc); // Recursion Function
		cout << "\nEmployee ID: " << root->id << "\tEmployee Name: " << root->name; 
	}
}

int main()
{
	Emp e; 
	int ch; 
	do 
	{
		cout<<"\n========================Menu=========================="; 
		cout<<"\n1.Create \n2.Display Inorder \n3.Display Preorder \n4.Display Postorder \n5.Exit"; 
		cout<<"\nEnter Your Choice :"; 
		cin>>ch; 
		
		switch(ch)
		{
				case 1 : 
					e.Create(); 
					break; 
				case 2 : 
					e.DisplayInorder(root); 
					break; 
				case 3 : 
					e.DisplayPreorder(root); 
					break; 
				case 4 : 
					e.DisplayPostorder(root); 
					break; 
				case 5 : 
					cout<<"\n======Thanks For Using=============="; 
					return 0; 
					break; 
				default : 
					cout<<"\n!!!Wrong Choice !!!"; 
					break; 
		}
	}while(ch!=5 );  
	return 0; 
}
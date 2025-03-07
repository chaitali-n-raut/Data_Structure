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
		void Display(Emp *root); 
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
	 }while(ch!=1); 
}

void Emp :: Insert(Emp *root, Emp *next)
{
		char chr; 
		cout<<"\nEnter Where you want to insert new Emp info -> Left/Right of ID : "<<root->id;
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
void Emp :: Display(Emp *root)
{
	if(root == NULL)
	{
		cout<<"\nDon't Have Data"; 
		return; 
	}
	else
	{
		Display(root->Lc); // Recursion Function
		cout << "\nEmployee ID: " << root->id << "\tEmployee Name: " << root->name; 
		Display(root->Rc); // Recursion Function
	}
}

int main()
{
	Emp e; 
	e.Create(); 
	e.Display(Emp :: root); 
	return 0; 
}
#include<iostream>
using namespace std; 
class EMS
{
	int id, sal; 
	string name; 
	EMS *Lc, *Rc; 
	public : 
		void Create(); 
		void Insert(EMS *root, EMS *next); 
		void DisplayAll(EMS *root); 
		void SearchNode(EMS *root, int key); 
		int MaxSalary(EMS *root); 
		int MinSalary(EMS *root); 
}*root; 

void EMS :: Create()
{
	root = new EMS; 
	EMS *next; 
	
	int ch;
	cout<<"\nEnter Employee ID :"; 
	cin>>root->id; 
	cout<<"\nEnter Employee Salary :"; 
	cin>>root->sal; 
	cout<<"\nEnter Employee Name :"; 
	cin>>root->name; 
	
	root->Lc = root->Rc = NULL; 
	
	
	do
	{
		
		cout<<"\nDo You Want to Add More Data (Yes=1, No=0): "; 
		cin>>ch; 
		if(ch==1)
		{
			next = new EMS; 
			cout<<"\nEnter new ID :"; 
			cin>>next->id; 
			cout<<"\nEnter new Salary :"; 
			cin>>next->sal; 
			cout<<"\nEnter new Name :"; 
			cin>>next->name; 
			
			next->Lc = next->Rc = NULL; 
			
			Insert(root, next); 
		}
		
			
	}while(ch==1); 
}

void EMS :: Insert(EMS *root, EMS *next)
{
	if(next->sal < root->sal)
	{
		if(root->Lc == NULL)
		{
			root->Lc = next; 
		}
		else
		{
			Insert(root->Lc, next); 
		}
	}
	else if(next->sal > root->sal)
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

void EMS :: DisplayAll(EMS *root)
{
	if(root==NULL)
	{
		return; 
	}
	else
	{

		cout<<root->id<<"\t"<<root->sal<<"\t"<<root->name<<endl;
		DisplayAll(root->Lc);  
		DisplayAll(root->Rc); 
	}
}
void EMS :: SearchNode(EMS *root, int key)
{
	int flag = 0; 
	 
	while(root != NULL)
	{
		if(key == root->sal)
		{
			flag = 1; 
			break;  
		}
		if(key < root->sal)
		{
			
			SearchNode(root->Lc, key); 
			if(key == root->sal)
			{
				flag = 1; 
				break;
			}	  
			return; 
			
		}
		else if(key > root->sal)
		{
			SearchNode(root->Rc, key); 
			if(key == root->sal)
			{
				flag = 1; 
				break;  
			}
			return; 	 	 
		}
	}
	if(flag == 1)
	{
		cout<<"\n*******************Employee Found*******************"<<endl; 
		
	}
	else 
	{
		cout<<"\n!!!!!Employee Not Found!!!!!"<<endl; 
	 
	}
}
int EMS :: MaxSalary(EMS *root)
{
		if(root == NULL)
		{
				return -1; 
		}
		while(root->Rc != NULL)
		{
				root = root -> Rc; // Traverse whole right side to find largest
		}
		return root->sal; // salary of last node
}
int EMS :: MinSalary(EMS *root)
{
		if(root == NULL)
		{
				return -1; 
		}
		while(root->Lc != NULL)
		{
				root = root->Lc; // Traverse whole left side to find smallest
		}
		return root->sal; // salary of last node
}
int main()
{
	EMS e; 
	int ch; 
	do 
	{
		cout<<"\n1.Create \n2.Display \n3.Search \n4.Find Maximum Salary \n5.Find Minimum Salary \n6.Exit"<<endl; 
		cout<<"\nEnter Your Choice : "; 
		cin>>ch; 
		
		switch(ch)
		{
			case 1 : 
					e.Create(); 
					break; 
			case 2 : 
					cout<<"\n------------------------Employee Details---------------------"; 
					cout<<"\n ID \t  Salary \t  Name"<<endl;
					e.DisplayAll(root); 
					break; 
			case 3 : 
					int key; 
					cout<<"\nEnter Salary of Emp you Want to Search :"; 
					cin>>key;
					e.SearchNode(root, key); 
					break; 
			case 4 :
					cout<<"\nMaximum Salary Among All Employees :"<<e.MaxSalary(root); 
					break; 
			case 5 :
					cout<<"\nMinimum Salary Among All Employees :"<<e.MinSalary(root); 
					break; 
			case 6 : 
					cout<<"\n----------Thanks For Using-----------"; 
					return 0; 
					break; 
			default : 
					cout<<"\n!!!!!Wrong Choice!!!!!";
					break; 
		}
		
		 
		
	}while(ch!=6); 
	
	return 0; 
}

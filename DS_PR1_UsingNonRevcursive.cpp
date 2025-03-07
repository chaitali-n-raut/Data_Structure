#include<iostream>
using namespace std; 
class Emp
{
	char id; 
	Emp *Lc, *Rc; 
	public : 
		void Create(); 
		void Insert(Emp *root, Emp *next); 
		void Display(Emp *root); 
}*root, *st[100]; 
void Emp :: Create()
{
	root = new Emp; 
	Emp *next; 
	int ch; 
	cout<<"\nEnter Employee ID :"; 
	cin>>root->id; 
	
	root->Lc = NULL; 
	root->Rc = NULL; 
	
	do
	{
		cout<<"\nDo You Want To Add Data : (Yes=1, No=0) : "; 
		cin>>ch; 
		if(ch==1) //User Wants to Add Data
		{
			next = new Emp; 
			cout<<"\nEnter new ID :"; 
			cin>>next->id; 
			
			next->Lc = NULL; 
			next->Rc = NULL; 
			
			Insert(root, next); 
		}
	}while(ch==1); 
	
}

void Emp :: Insert(Emp *root, Emp *next)
{
	char  chr; 
	cout<<"\nWhere Do You Want To Enter new Data : (Left[L/l] / Right[R/r]) :"; 
	cin>>chr; 

	
	if(chr == 'L' || chr == 'l')
	{
		if(root->Lc == NULL)
		{
			root->Lc = next; //connect root to newnode; 
		}
		else
		{
			Insert(root->Lc, next);  
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
	int top =-1; 
	Emp *temp; 
	temp = root; 
	if(root!=NULL)
	{
		do
		{
			while(temp!=NULL)
			{
				top++; //Increase top; 
				st[top] = temp; // Push Value to Stack; 
				temp = temp->Lc; 
			}
			if(top!=-1)
			{
				temp = st[top]; 
				top--; 
				
				if(temp->Lc == NULL && temp->Rc == NULL)
				{
					cout<<"Leaf Nodes ID : "<<temp->id<<endl;  
				}
				
				if(temp->Lc != NULL || temp->Rc != NULL)
				{
					cout<<"Intermediate Nodes ID : "<<temp->id<<endl; 
				}
				
				cout<<"\nID = "<<temp->id<<endl; ; 
				temp = temp->Rc; 
			}
		}while(temp != NULL || top!= -1); 
	}
	
	
}

int main()
{
	Emp e; 
	e.Create(); 
	e.Display(root); 
}

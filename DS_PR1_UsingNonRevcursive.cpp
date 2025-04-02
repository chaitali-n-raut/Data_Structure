#include<iostream>
using namespace std; 
class Emp
{
	char id; 
	int sal; 
	string name;
	Emp *Lc, *Rc; 
	public : 
		void Create(); 
		void Insert(Emp *root, Emp *next); 
		void Display(Emp *root); 
		void DisplayLeaf(Emp *root);
		void DisplayRoot(Emp *root); 
		void DisplayIntermediate(Emp *root); 
		int DisplayHeight(Emp *root); 
		void Search(Emp *root); 
}*root, *st[100]; 
void Emp :: Create()
{
	root = new Emp; 
	Emp *next; 
	int ch; 
	cout<<"\nEnter Employee ID :"; 
	cin>>root->id; 
	cout<<"\nEnter Employee Name :"; 
	cin>>root->name; 
	cout<<"\nEnter Employee Salary :"; 
	cin>>root->sal; 
	
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
			cout<<"\nEnter Employee Name :"; 
			cin>>next->name; 
			cout<<"\nEnter Employee Salary :"; 
			cin>>next->sal;
			
			
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
int Emp :: DisplayHeight(Emp *root)
{
	int  LeftH, RightH; 
	if(root==NULL)
	{
		return -1; 
	}
	else
	{
		LeftH = DisplayHeight(root->Lc); 
		RightH = DisplayHeight(root->Rc); 
		
		if(LeftH > RightH)
		{
			return LeftH + 1; 
		}
		else
		{
			return RightH + 1; 
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
				//cout<<"\nEmployee ID = "<<temp->id<<endl; ; 
				
				
				cout<<temp->id<<"\t"<<temp->name<<"\t"<<temp->sal<<endl; 

				
				temp = temp->Rc; 
			}
		}while(temp != NULL || top!= -1); 
	}
	
	
}

void Emp :: DisplayLeaf(Emp *root)
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
				//cout<<"\nEmployee ID = "<<temp->id<<endl; ; 
				
				if(temp->Lc == NULL && temp->Rc == NULL)  // only child nodes
				{
					cout<<"Leaf Nodes ID : "<<temp->id<<endl;  
				}
				temp = temp->Rc; 
			}
		}while(temp != NULL || top!= -1); 
	}
}

void Emp :: DisplayRoot(Emp *root)
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
				//cout<<"\nEmployee ID = "<<temp->id<<endl; ; 
				if(temp == root) // To show only root node 
				{
					cout<<"\nRoot Node ID : "<<temp->id<<endl; 
				}
						
				temp = temp->Rc; 
			}
		}while(temp != NULL || top!= -1); 
	}
	
}

void Emp :: DisplayIntermediate(Emp *root)
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
				//cout<<"\nEmployee ID = "<<temp->id<<endl; ; 
				if((temp->Lc != NULL || temp->Rc != NULL) && temp !=root)// only parent nodes
				{
					cout<<"Intermediate Nodes ID : "<<temp->id<<endl; 
				}
			
				temp = temp->Rc; 
			}
		}while(temp != NULL || top!= -1); 
	}
	
}



void Emp :: Search(Emp *root)
{
	int top =-1; 
	Emp *temp; 
	temp = root; 
	
	char tempid;
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
				//cout<<"\nEmployee ID = "<<temp->id<<endl; 
				
				cout<<"\nEnter Search ID :"; 
				cin>>tempid;  
				
				
					if(tempid == temp->id)
					{
						cout<<"ID Found :"<<temp->id;
					}
					temp = temp->Rc; 
				
			}
		}while(temp != NULL || top!= -1); 
	}
	
		

}

int main()
{
	Emp e; 
	int ch; 

	do
	{
		cout<<"\n1.Create Node \n2.Display all Node \n3.Display Leaf Node \n4.Display Intermediate Node "; 
		cout<<"\n5.Display Root Node \n6.Display Tree Height  \n7.Search Node \n8.Exit"; 
		cout<<"\nEnter Your Choice :"; 
		cin>>ch; 

		
		switch(ch)
		{
			case 1 : 
				e.Create(); 
				break; 
			case 2 : 
				cout<<"\n------------Employee Info----------------"; 				
				cout<<"\nEmployee ID \tEmployee Name \tEmployee Salary"<<endl;
				e.Display(root);				
				break; 
			case 3 : 
				e.DisplayLeaf(root);
				break; 
			case 4 : 
				e.DisplayIntermediate(root);
				break; 
			case 5 : 
				e.DisplayRoot(root); 
				break; 
			case 6 : 
				cout<<"\nHeight Of Tree = "<<e.DisplayHeight(root)<<endl;
				
				break; 
			case 7 : 
				e.Search(root); 
				break; 
			case 8 : 
				cout<<"\nExiting"; 
				return 0; 
				
			default :
				cout<<"\nWrong choice !!!"; 
				break; 
		}
	}while(ch!= 8); 
	
	
	 
	
	return 0; 
}

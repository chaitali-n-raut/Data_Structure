#include<iostream>
using namespace std; 
class GR
{
	int v, fuel;
	string city; 
	GR *next; 
	public : 
		void Create(); 
		void AddEdge(); 
		void Display(); 
	
}*head[10]; 

void GR :: Create()
{
	cout<<"\nEnter No. of Cities :"; 
	cin>>v; //5
	
	cout<<"\nEnter City Names :"; 
	for(int i=0;i<v;i++)
	{
		head[i] = new GR; 
		 
		cin>>head[i]->city; 
		head[i]->next = NULL; 
	}	
}
void GR :: AddEdge()
{
	string src, dest;
	GR *n1, *temp; 
	int e, i,j;
	cout<<"\nEnter No. of Edges :"; 
	cin>>e; 
	for( i=0;i<e;i++)
	{
		cout<<"\nEnter Source and Destination Cities :"; 
		cin>>src>>dest; 
		for(j=0;j<v;j++)
		{
			if(head[j]->city == src)
			{
				break; 
			}
		}
		n1 = new GR; //n1 is newnode 
		n1->city = dest; 	//Data is stored in that newnode city name 
						//and fuel
		cout<<"\nEnter Fuel :";      
		cin>>n1->fuel; 
		n1->next = NULL; //newnode is not conncected to any node
		temp = head[j];   //started from head node -> index = 0
		while(temp->next!=NULL)
		{
			temp = temp->next; 
		}
		temp->next = n1; //connected head node and newNode
	}
}
void GR :: Display()
{
	cout<<"\nGraph Representation :"<<endl; 
	
	GR *temp; 
	for(int i=0;i<v;i++)
	{
		temp = head[i]; 
		while(temp!=NULL)
		{
			cout<<" "<<temp->city<<"->"<<temp->fuel<<"-> ";
			temp = temp->next; 
		}
		cout<<"!!NULL!! \n"; 
	}
}

int main()
{
	GR g; 
	int ch; 
	cout<<"\n=======================Menu============================"; 
	do
	{
		cout<<"\n1.Create \n2.Add Edge \n3.Display \n4.Exit"; 
		cout<<"\nEnter Your Choice :"; 
		cin>>ch; 
		switch(ch)
		{
			case 1 : 
				g.Create(); 
				break; 
			case 2 : 
				g.AddEdge(); 
				break; 
			case 3 : 
				g.Display(); 
				break; 
			case 4 : 
				cout<<"\n==============Thanks For Using==================="; 
				return 0; 
				break; 
			default : 
				cout<<"\n!!!!Wrong Choice!!!!"; 
				break;
		}
	}while(ch!=4);
return 0; 
}

#include<iostream>
using namespace std; 
class GR
{
	int v, fuel;
	string city[10]; 
	GR *next; 	// Pointer to connect cities
	public : 
		void Create(); 
		void AddEdge(); 
		void Display(); 
	
}*head[10]; // Array of pointers each pointing to a city

void GR :: Create()
{
	cout<<"\nEnter No. of Cities :"; 
	cin>>v; //5

	for(int i=0;i<v;i++)
	{
		head[i] = new GR; 	// New node for each city
		cout<<"\nEnter City Names :";  
		cin>>head[i]->city; 	//store city names
		head[i]->next = NULL; 	//no any connection yet
	}	
}
void GR :: AddEdge()	//To add connections[edges] between cities
{
	string src, dest;
	GR *n1, *temp; 	// Pointers for newnode[n1] & Traversal[temp]
	int e;
	cout<<"\nEnter No. of Edges :"; 
	cin>>e; 
	for(int i=0;i<v;i++)
	{
		cout<<"\nEnter Source and Destination Cities :"; 
		cin>>src>>dest; 
		for(j=0;j<v;j++)		// Find the source city in the list
		{
			if(head[j]->city == src)	// When the source city is found int the list
			{
				break; 					// then break the loop 
			}
		}
		n1 = new GR(); //n1 is newnode for destination city
		n1->city = dest; 	//Data is stored in that newnode is city name 
						//and fuel
		cout<<"\nEnter Fuel :";      
		cin>>n1->fuel; 	//store fuel required for travel
		n1->next = NULL; //Initially, newnode is not conncected to any node
		temp = head[i];   //started from head node -> index = 0
							//[Source city]
		while(temp!=NULL)
		{
			temp = temp->next; 
		}
		temp->next = n1; //connected head node and newNode
						//connected the new city node to source city
	}
}
void GR :: Display()
{
	cout<<"\nGraph Representation :"; 
	
	for(int i=0;i<v;i++)
	{
			cout<<head[i]->city; 
			
			GR *temp = head]i]->next; 
			
			while(temp != NULL)
			{
					cout<<" "<<temp->city<<"\t"<<temp->fuel; 
					temp = temp->next; 
			}
	}
}
int main()
{
		GR g1 = new GR; 
		g.Create(); 
		g.AddEdge(); 
		g.Display(); 
}

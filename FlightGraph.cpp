#include<iostream>
using namespace std; 
class FlightGraph
{
	int v; // No. of Cities 
	string city[10]; //City names
	//int fuel; 
	int adj[100][100]; //
	public : 
		void Accept(); 
		void Display(); 
};
void FlightGraph :: Accept()
{
	int i, j; 
	cout<<"\nEnter No. of Cities :"; 
	cin>>v; 
	cout<<"\nEnter City Names :"; 
	for( i=0;i<v;i++)
	{
		cin>>city[i]; 
	}
	cout<<"\n------------Enter Fuel Required-----------------"; 
	for(i=0;i<v;i++)	// city rows
	{
		for( j=0;j<v;j++) // city columns 
		{
			if(i == j)  // city row = city column
			{
				adj[i][j] = 0; // Matrix format 
			}
			else 
			{
				cout<<"\nEnter Fuel from "<<city[i]<<" to "<<city[j]<<" : "<<endl; 
				cin>>adj[i][j]; 
			}
		}
	}
	
}
void FlightGraph :: Display()
{
	cout<<"==============Cities=========="<<endl; 
	cout<<"   "; 
	for(int i=0;i<v;i++)
	{
		cout<<city[i]<<"  "; 
	}
	cout<<endl; 
	for(int i=0;i<v;i++)
	{
		cout<<city[i]<<" "; 
		for(int j=0;j<v;j++)
		{
			cout<<" "<<adj[i][j]; 
		}
		cout<<endl; 
	}

}

int main()
{
	FlightGraph f; 
	int ch; 
	do
	{
		cout<<"\n1.Accept \n2.Display \n3.Exit"; 
		cout<<"\nEnter Your Choice :"; 
		cin>>ch; 
		switch(ch)
		{
			case 1 : 
					f.Accept(); 
					break; 
			case 2 : 
					f.Display(); 
					break; 
			case 3 : 
					cout<<"\n============Thanks For Using=============="; 
					return 0; 
			default :
					cout<<"\n!!!Wrong Choice!!!"; 
					break; 
		}
	}while(ch!=3); 
return 0; 	
}

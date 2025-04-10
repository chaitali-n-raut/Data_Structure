#include<iostream>
using namespace std; 
class PizzaP
{
	int v, adj[10][10]; 
	string city[10]; 
	public : 
		void Accept(); 
		void Display(); 
		void ShortestPath(); 
}; 
void PizzaP :: Accept()
{
	cout<<"\nEnter No. Of Cities :"; 
	cin>>v; 
	cout<<"\nEnter City Names :"; 
	for(int i=0;i<v;i++)
	{
		cin>>city[i]; 
	}
	cout<<"\nEnter Distance :"; 
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if( i == j )
			{
				adj[i][j] = 0; 
			}
			else if(i<j)
			{
				cout<<"\nEnter Distance from Source Location "<<city[i]<<" TO "<<city[j]<<" : "; 
				cin>>adj[i][j];
				adj[j][i] = adj[i][j]; 
			}
		}
	}
}
void PizzaP :: Display()
{
	cout<<"==============City Matrix=========="<<endl; 
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
void PizzaP :: ShortestPath()
{
	int dist[10], visited[10]; 
	
	dist[0] = 0; //source vertex is initialized to 0 
	visited[0] = 0; 
	for(int i=1;i<v;i++)
	{
		dist[i] = 999; // all other vertices are initialized to infinity
		visited[i] = 0; 
	}
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(adj[i][j] && !visited[j] && dist[i]+adj[i][j]<dist[j])
			{
				dist[j] = dist[i] + adj[i][j]; 
			}
		}
		visited[i] = 1; 
	}
	
	//Display Shortest Paths 
	cout<<"\n===================Minimum Distance from Pizza Parlour to Particular Customer City=============="; 
	for(int i=1;i<v;i++)
	{
		cout<<"\nDistance from "<<city[0]<<" TO "<<city[i]<<"------> "<<dist[i]<<endl; 
	}
}

int main()
{
	PizzaP p; 
	int ch; 
	do
	{
		cout<<"\n=============================Menu========================"; 
		cout<<"\n1.Accept City Locations \n2.Display City Matrix"; 
		cout<<"\n3.Display Shortest Path \n4.Exit "; 
		cout<<"\nEnter Your Choice :"; 
		cin>>ch; 
		switch(ch)
		{
			case 1 : 
				p.Accept(); 
				break; 
			case 2 : 
				p.Display(); 
				break; 
			case 3 : 
				p.ShortestPath(); 
				break;
			case 4 : 
				cout<<"\n==========Thanks For Using============"; 
				return 0; 
				break;
			default : 
				cout<<"\n!!!Wrong Choice!!!"; 
				break; 
		}
	}while(ch!=4); 
return 0; 
}

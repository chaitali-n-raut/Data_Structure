#include<iostream>
using namespace std; 
class MinSTree
{
	int v; 
	string city[10]; 
	int adj[100][100]; 
	public : 
		void Create(); 
		void Display(); 
		void DisplayMST();	
}; 
void MinSTree :: Create()
{
	cout<<"\nEnter No. of Cities :"; 
	cin>>v; 
	cout<<"\nEnter City Names :"; 
	for(int i=0;i<v;i++)
	{
		cin>>city[i]; 
	}
	cout<<"\n==================Enter The Distances=================="; 
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(i==j)
			{
				adj[i][j] = 0; 
			}
			else
			{	
				cout<<"\nEnter Distance from :"<<city[i]<<" TO "<<city[j]<<" = ";
				cin>>adj[i][j]; 
			}
		}
	}
}

void MinSTree :: Display()
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

void MinSTree :: DisplayMST()
{
	int u, i, j; 
	int min; 
	int key[10]; 
	int parent[10]; 
	bool visited[10]; 
	
	for(i=0;i<v;i++)
	{
		key[i] = 999; 
		visited[i] = false; 
	}
	key[0] = 0; 
	parent[0] = -1; 
	for(int e =0;e<v-1;e++)
	{
		min = 999; 
		for(i=0;i<v;i++)
		{	
			if(!visited[i] && min>key[i])
			{
				min = key[i]; 
				u = i; 
			}
		}
		visited[u] = true; 
		for(j=0;j<v;j++)
		{
			if(adj[u][j] && !visited[j] && adj[u][j]<key[j])
			{
				key[j] = adj[u][j]; 
				parent[j] = u; 
			}
		}
	}
	
	//Display MST
	
	int sum = 0; 
    	for(int i=0;i<v;i++)
    	{
    		sum = sum + key[i]; 
    	} 
    	cout<<"\n******Cost Of MST = "<<sum<<"******"; 
    	cout<<"\n=======Minimum Distance Selected from Source City========"; 
    	for (int i =1;i<v;i++) 
	{
        	cout<<"\n" << city[parent[i]] << "  TO  " << city[i] << " --------> " << key[i] << endl;
    	}
	
}
int main()
{
	MinSTree m;	
	int ch; 
	

	do
	{
		cout<<"\n=======================Menu============================"; 
		cout<<"\n1.Create \n2.Display Cities \n3.Shortest Path \n4.Exit"; 
		cout<<"\nEnter Your Choice :"; 
		cin>>ch; 
		switch(ch)
		{
			case 1 : 
				m.Create(); 
				break; 
			case 2 : 
				m.Display(); 
				break; 
			case 3 : 
				m.DisplayMST(); 
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

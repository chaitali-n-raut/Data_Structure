#include<iostream>
#include<string>
using namespace std;
int n;  
class OptimalBST
{
	int p[10], q[10]; 
	int w[10][10], c[10][10], r[10][10]; 
	string key[10]; 
	public : 
		void Accept(); 
		void Build(); 
		void Display(int i, int j); 
}; 
void OptimalBST :: Accept()
{
	cout<<"\nEnter No. of Items You Want To Store :"; 
	cin>>n; 
	cout<<"\nEnter key Items :"; 
	for(int i=0;i<n;i++)
	{
		cin>>key[i]; 
	}
	cout<<"\nEnter Probability of Successful Search :"; 
	for(int i=1;i<=n;i++) // Probability of Successful Search = n; 
	{
		cin>>p[i]; 
	}
	cout<<"\nEnter Probability of UnSuccessful Search :"; 
	for(int i=0;i<=n;i++)	// Probability of UnSuccessful Search = n+1, 
							// So, i started from 0 
	{
		cin>>q[i]; 
	}
}
void OptimalBST :: Build()
{
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==j)
			{
				w[i][j] = q[i]; 
				c[i][j] = 0; 
				r[i][j] = 0; 

			}
			else 
			{
				w[i][j] = p[j] + q[j] + w[i][j-1]; 
			}
		}
	}
	for(int l=1;l<=n;l++)
	{
		for(int i=0; i<=n-l ;i++)
		{
			int j = i+l; // to increment j like 01, 02, 03..
						
			c[i][j] = 9999; // Initialize to max value
						
			for(int k=i+1;k<=j;k++)	//i<k<=j
			{
				int cost = c[i][k-1] + c[k][j] + w[i][j]; // c[i][j] = min(i<k<=j) =
										//c[i][k-1] + c[k][j] + w[i][j]
				if(cost < c[i][j])
				{
					c[i][j] = cost; 
					r[i][j] = k; 
				}
			}
		}
	}
		

	cout<<"\nWeight Matrix :"<<"\n"; 
	for(int i=0;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			cout<<w[i][j]<<"\t"; 
			
		}
		cout<<endl; 
	}
	cout<<"\nCost Matrix :"<<"\n"; 
	for(int i=0;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			cout<<c[i][j]<<"\t"; 
			
		}
		cout<<endl; 
	}
	cout<<"\\nRoot Matrix :"<<"\n"; 
	for(int i=0;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			cout<<r[i][j]<<"\t"; 
			
		}
		cout<<endl; 
	}
}

void OptimalBST::Display(int i, int j)
{
   	if (i == j)
	{
		return;
	}

    int root = r[i][j];
    if (root == 0)
	{
		return;
	}

    string left = "NULL";
    string right = "NULL";

    if (r[i][root - 1] != 0)
	{	
        	left = key[r[i][root - 1] - 1];  // 1-based to 0-based
	}

    if (r[root][j] != 0)
	{
        	right = key[r[root][j] - 1];    // 1-based to 0-based
	}

    cout << " " << key[root - 1] << "\t -> " << left << "\t -> " << right << "\t \n";

    Display(i, root - 1);   // Left subtree // Recursively called according to formulas : 
		//  r[i][k-1]
    Display(root, j);       // Right subtree
		// r[k][j]
}


int main()
{
	OptimalBST o; 
	int ch; 
	do 
	{
		cout<<"==============Menu============="; 
		cout<<"\n1.Create OBST \n2.Build \n3.Display \n4.Exit"; 
		cout<<"\nEnter Your Choice :"; 
		cin>>ch; 
		switch(ch)
		{
			case 1 : 
					o.Accept();
					break; 
			case 2 : 
					o.Build(); 
					break; 
			case 3 : 
					cout << "| Node\t | LC\t | RC\t |\n";
					cout << "-----------------------------------------\n";
					o.Display(0, n); //i=0; j=n;

					break; 
			case 4 : 
					cout<<"\nThanks For Using";
					return 0; 
					break;  
			default : 
					cout<<"\n!!!!Wrong Choice!!!!"; 
					break; 
		}
	}while(ch!= 4 ); 
	return 0; 
}

#include<iostream>
using namespace std;
 
int n, loc, parent; 
int count = 0; 

class MaxHeap
{
	int key[100];
	public : 
		void Accept(); 
		void BuildHeap(int key[], int m, int value ); 
		void Insert(); 
		void DisplayHeap(); 
}; 
void MaxHeap :: Accept()
{	
	int value; 
	cout<<"\nEnter How Many Elements You Want to Insert :"; 
	cin>>n; 
	cout<<"\nEnter Key Elements :"; 
	for(int i=1;i<=n;i++) // index should start from 1
	{
		cin>>value; 
		BuildHeap(key, i, value); 
		count++; 
	}
}
void MaxHeap :: BuildHeap(int key[], int m, int value)
{
		
		
		key[m] = value; 
		loc = m;
		while(loc > 1)
		{
				parent = loc/2; 
				if(key[parent] < key[loc]) // For Min Heap(key[parent] > key[loc]) 
				{
					int temp = key[parent]; 
					key[parent] = key[loc]; 
					key[loc] = temp; 
					
					loc = parent; 
				}
				else 
				{
					return; 
				}
		}
}
void MaxHeap :: Insert()
{
	 count++;
	 n = count; 
	 int newkey; 
	cout<<"\nEnter Key Element To Insert :"; 
	cin>>newkey; 
	 
	BuildHeap(key, n,  newkey);  
}
void MaxHeap :: DisplayHeap()
{
		cout<<"\nHeap Data :"<<"\n"; 
		for(int i=1;i<=n;i++)
		{
			cout<<key[i]<<"\t"; 
		}
}

int main()
{
	MaxHeap h; 
	int ch; 
	do
	{
		cout<<"\n1.Accept \n2.Insert New Element \n3.Display Heap \n4.Exit"; 
		cout<<"\nEnter Your Choice :"; 
		cin>>ch; 
		switch(ch)
		{
			case 1 : h.Accept(); break; 
			case 2 : h.Insert(); break; 
			case 3 : h.DisplayHeap(); break; 
			case 4 : cout<<"\nThanks for Using"; return 0; break; 
			
			default : cout<<"\nWrong Choice !!!"; break; 
		}
	}while(ch!= 4); 
	return 0; 
}

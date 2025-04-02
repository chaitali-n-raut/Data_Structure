#include <iostream>
using namespace std;

class GR {
    int v, fuel;
    string city; 
    GR* next;  // Pointer to connect cities

public:
    void Create();
    void AddEdge();
    void Display();
} * head[10]; // Array of pointers, each pointing to a city

void GR::Create() {
    cout << "\nEnter No. of Cities: ";
    cin >> v; // Example: 5

    for (int i = 0; i < v; i++) {
        head[i] = new GR;  // New node for each city
        cout << "\nEnter City Name: ";
        cin >> head[i]->city;  // Store city names
        head[i]->next = NULL;  // No connection yet
    }
}

void GR::AddEdge() { // To add connections (edges) between cities
    string src, dest;
    GR* n1, * temp;  // Pointers for new node (n1) & Traversal (temp)
    int e, j;

    cout << "\nEnter No. of Edges: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        cout << "\nEnter Source and Destination Cities: ";
        cin >> src >> dest;

        for (j = 0; j < v; j++) {  // Find the source city in the list
            if (head[j]->city == src) { // When found, break the loop
                break;
            }
        }

        n1 = new GR(); // New node for destination city
        n1->city = dest; // Store city name

        cout << "\nEnter Fuel: ";
        cin >> n1->fuel; // Store fuel required for travel

        n1->next = NULL; // Initially, new node is not connected to any node
        temp = head[j];  // Start from the source city node

        while (temp->next != NULL) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = n1; // Connect new city node to source city
    }
}

void GR::Display() {
    cout << "\nGraph Representation:\n";

    for (int i = 0; i < v; i++) {
        cout << head[i]->city;

        GR* temp = head[i]->next;  // Traverse adjacency list

        while (temp != NULL) {
            cout << " -> " << temp->city << " (" << temp->fuel << ")";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    GR g1;
    g1.Create();
    g1.AddEdge();
    g1.Display();
    return 0;
}

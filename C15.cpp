/*

You have a business with several offices; you want to lease phone lines to connect them
up with each other; and the phone company charges different amounts of money to
connect different pairs of cities. You want a set of lines that connects all your offices with
a minimum total cost. Solve the problem by suggesting appropriate data structures


1.  What is Prim's algorithm
	Prim's Algorithm is a greedy algorithm that is used to find the minimum spanning tree from a graph.
   
   Algorithm 
1) Create a set mstSet that keeps track of vertices already included in MST. 
2) Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE. Assign key value as 0 for the first vertex so that it is picked first. 
3) While mstSet doesn’t include all vertices 
….a) Pick a vertex u which is not there in mstSet and has minimum key value. 
….b) Include u to mstSet. 
….c) Update key value of all adjacent vertices of u. To update the key values, iterate through all adjacent vertices. For every adjacent vertex v, if weight of edge u-v is less than the previous key value of v, update the key value as weight of u-v

*/


#include<iostream>
	using namespace std;
	

	class Office
	{
	    int n;
	    int a[10][10];
	    string office[10];
	

	public:
	    void input();
	    void display();
	    void Prims();
	};
	

	void Office::input()
	{
	    cout<<"\nEnter no. of offices: ";
	    cin>>n;
	    cout<<"\nEnter the names of offices: ";
	    for(int i=0 ; i<n ; i++){
		
	        cin >> office[i];
		}

	    cout<<"\nEnter the cost to connect the offices: ";
	    for(int i=0 ; i<n ; i++){
		
	        for(int j=i ; j<n ; j++)
	        {
	            if(i==j)
	            {
	                a[i][j] = 0;
	                continue;
	            }
	

	            cout<<"\nEnter the cost to connect " << office[i] <<" and " << office[j]<< " : ";
	            cin >> a[i][j];
	            a[j][i] = a[i][j];
	     }   }
	}
	

	void Office::display()
	{
	

	    for(int i=0 ; i<n ; i++)
	    {
	        cout<<"\n";
	        for(int j=0 ; j<n ; j++)
	        {
	            cout<<a[i][j] << "\t";
	        }
	   }
	}
	

	void Office::Prims()
	{
	    int visit[n], minCost=0, count=1, minIndex, cost=0;
	    for(int i=0 ; i<n ; i++){
		
	        visit[i] = 0;
		}

	    cout<<"\n\nShortest path: ";
	    visit[0]=1;
	    cout<<office[0] << " -> ";
	    while(1)
	    {
	        minCost = 10000;
	        for(int i=0 ; i<n ; i++)
	        {
	            for(int j=0 ; j<n ; j++)
	            {
	                if(visit[i]==1 && a[i][j]!=0 && a[i][j]< minCost && visit[j]==0)
	                {
	                    minCost = a[i][j];
	                    minIndex = j;
	                }
	            }
	        }
	        visit[minIndex]=1;
	        cout<<office[minIndex] << " -> ";
	        cost = cost + minCost;
	        count++;
	

	        if(count==n){
			
	            break;
	   		 }
		}
	

	    cout<<"\nMinimum cost: "<<cost;
	

	}
	

	int main()
	{
	    Office o1;
	    int choice;
	MENU:
	    cout<<"\n\nMINIMUM SPANNING TREE";
	    cout<<"\n1. Input data";
	    cout<<"\n2. Display data";
	    cout<<"\n3. Calculate minimum cost";
	    cout<<"\n4. Exit";
	    cout<<"\nEnter your choice: ";
	    cin >> choice;
	    switch(choice)
	    {
	    case 1:
	    	o1.input();
	    	break;
	    case 2:
	    	o1.display();
	    	break;
	    case 3:
	    	o1.Prims();
	    	break;
	    case 4:
	    	return 0;
	    default:
	    	cout<<"\nInvalid choice.Try again!";
	    }
	    if(choice != 5)
	    	goto MENU;
	    return 0;
	}
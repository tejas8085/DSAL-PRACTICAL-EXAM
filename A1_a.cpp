/*
1. Linear Probing --->
	  In linear probing, we linearly probe for next slot. For example, the typical gap between two probes is 1 as seen in the example below.
	  Let hash(x) be the slot index computed using a hash function and S be the table size

If slot hash(x) % S is full, then we try (hash(x) + 1) % S
If (hash(x) + 1) % S is also full, then we try (hash(x) + 2) % S
If (hash (x) + 2) % S is also full, then we try (hash(x) + 3) % S
..................................................
..................................................

*/

//  ************** LINEAR PROBING  ***********

#include <iostream>
using namespace std;

class lp
{
public:
	long long int ht[10];
	int flag[10];
	lp()
	{
		for (int i = 0; i < 10; i++)
		{
			flag[i] = 0;
		}
	}
	void insert(long long int key)
	{
		int loc = key % 10;
		for (int i = 0; i < 10; i++)
		{

			if (flag[loc] == 0)
			{
				ht[loc] = key;
				flag[loc] = 1;
				break;
			}
			else
			{
				loc = (loc + 1) % 10;
			}
		}
	}

	void display()
	{
		for (int i = 0; i < 10; i++)
		{
			if (flag[i] == 0)
			{
				cout << i << "\t-\n";
			}
			else
			{
				cout << i << "\t" << ht[i] << "\n";
			}
		}
	}

	void search(long long int key)
	{
		int loc = key % 10;
		int flag = 0;
		int com = 0;
		;
		for (int i = 0; i < 10; i++)
		{
			if (ht[loc] == key)
			{
				flag = 1;
				break;
			}
			else
			{

				loc = (loc + 1) % 10;
				com = com + 1;
			}
		}

		if (flag == 1)
		{
			cout << "element found at-" << loc << " location in " << com + 1 << " comparisons\n";
		}
		else
		{
			cout << "element not found\n";
		}
	}
};

int main()
{
	lp h;
	long long int choice, v;
	while (choice != 4)
	{

		cout << "1.insert\n2.display\n3.search\n4.exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "element to insert-: ";
			cin >> v;
			h.insert(v);
			break;

		case 2:
			h.display();
			break;
		case 3:
			cout << "element to search: ";
			cin >> v;
			h.search(v);
			break;
		case 4:
			break;

		default:
			cout << "wrong input";
		}
	}
	return 0;
}

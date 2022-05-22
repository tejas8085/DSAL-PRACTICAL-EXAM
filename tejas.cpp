#include <iostream>
using namespace std;

struct node{
	string data;
	int count;
	node *child[10];
};

class Book{
	public:
		node *root;
		Book(){
			root=NULL;
		}
		void create();
		void display();
};

void Book::create(){
	int i,j,k;
	root=new node;
	cout<<"ENTER BOOK NAME- ";
	cin>>root->data;
	cout<<"HOW MANY CHAPTERS-";
	cin>>root->count;
	for(i=0;i<root->count;i++){
		cout<<"ENTER CHAPTER "<<i+1<<" NAME- ";
		root->child[i]=new node;
		cin>>root->child[i]->data;
		cout<<"HOW MANY SECTIONS-";
		cin>>root->child[i]->count;
		for(j=0;j<root->child[i]->count;j++){
			cout<<"ENTER SECTION "<<j+1<<" NAME-: ";
			root->child[i]->child[j]=new node;
			cin>>root->child[i]->child[j]->data;
			
		}
	}
}

void Book::display(){
	int i,j,k;
	cout<<"BOOK NAME-: "<<root->data<<"\n";
	for(i=0;i<root->count;i++){
		cout<<"CHAPTER "<<i+1<<"- "<<root->child[i]->data<<"\n";
		for(j=0;j<root->child[i]->count;j++){
			cout<<"SECTIONS "<<j+1<<"- "<<root->child[i]->child[j]->data<<"\n";
		}
	}
}

int main(){
	Book b;
	int choice;
	while(choice!=3){
		cout<<"\tMAIN MENU\n";
		cout<<"1.CREATE\n2.DISPLAY\n3.EXIT\n";
		cout<<"ENTER YOUR CHOICE-:";
		cin>>choice;
		switch(choice){
			case 1:
				b.create();
				break;
			
			case 2:
				b.display();
				break;
			
			case 3:
				break;
			
			default:
				cout<<"Wrong choice";
		}
	}
	return 0;
}
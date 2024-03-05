#include<iostream>
using namespace std;


class Node{
    public:
    	int data;
    	Node *next;
    	~Node();
};

class List{
	public:
		Node *root;
		int size;
		void show();
		void append(int);
		void insert(int,int);
		void remove(int);
};

Node::~Node(){
    cout << data << " was deleted.\n";
}

void List::insert(int d,int idx){	
	Node *n = new Node;
	n->data = d;
	
	if(idx == 0){
		n->next = root;
		root = n;
		return;
	}
	Node *current = root;
	for(int i = 0; i < idx-1;i++){
		current = current->next;
	}
	n->next = current->next;
	current->next = n;		
}

void List::show(){
	Node *current = root;
	cout << current->data << " ";	
	while(current->next){
		current = current->next;
		cout << current->data << " ";
	}	
}

void List::append(int d){	
	Node *n = new Node;
	n->data = d; n->next = NULL;
	if(root == NULL) root = n;
	else{
		Node *current = root;
		while(current->next){
			current = current->next;
		}
		current->next = n;
	}
	size++;
}

void List::remove(int position){
	if(position >= size){
		return;
	}
	if(position == 0){
		Node *temp = root->next;
		delete root;
		root = temp;
		return;
	}
	Node *current = root;
	int currPos = 0;
	while(current->next != NULL && currPos < position-1){
		current = current->next;
		currPos++;
	}

	Node *temp = current->next;
	current->next = current->next->next;
	delete temp;
	return;
}


int main(){

	List myList = {NULL,0};

	int n;
	cin >> n;
	cout << n << endl;
	for(int i = 0 ; i < n; ++i){
		cout << endl << i << endl;
		int toAppend = 0;
		cin >> toAppend;
		myList.append(toAppend);
		cout << "Appended" << endl;
		myList.show();
	}

	for(int i = 0 ; i < n-1; ++i){
		cout << endl << i << endl;
		int posToRemove = 0;
		cin >> posToRemove;
		myList.remove(posToRemove);
		cout << "Removed" << endl;
		myList.show();
	}

	return 0;
}
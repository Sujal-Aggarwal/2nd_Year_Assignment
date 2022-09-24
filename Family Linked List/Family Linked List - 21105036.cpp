#include <bits/stdc++.h>                   
using namespace std;                  

//CREATING NODE CLASS
class Node{
    public:
    
    //Creating class elements
    string name;
    int age;
    Node*next; 
    Node*prev; 
    
    //Constructor
    Node(string name,int age){
        this->name=name;
        this->age=age;
        next=NULL; 
        prev=NULL; 
    }
};

//FUNCTION TO INSERT DATA AT END OF LINKED LIST
void push_back(Node* &head,string name,int age){

    Node*temp=head;
    Node*new_node=new Node(name,age);

    //Inserting node in empty list
    if(temp==NULL){
        head=new_node;
    }

    //Inserting node in non empty list
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->prev=temp;
    }
}

//FUNCTION TO INSERT DATA IN LINKED LIST
void push_front(Node*&head,string name,int age){

    Node*new_node=new Node(name,age);

    //Inserting new node at head
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
}

//FUNCTION TO PRINT DATA FROM START OF LINKED LIST
void print_start(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){
        cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<=>";
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]";
    }
    cout<<endl;
}

//FUNCTION TO PRINT DATA FROM END OF LINKED LIST
void print_end(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp->prev!=NULL)
    {
        cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<=>";
        temp=temp->prev;
    }
    if(temp->prev==NULL)
    {
        cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]";
    }
    cout<<endl;
}

//FUNCTION TO DELETE ANY INDEX(0,n-1) EXCLUDING LAST ELEMENT 
void delete_ith(Node*&head,int i){
    if(i==0){
        Node*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    else{
        Node*temp=head;
        for(int j=0;j<i;j++){
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}

//FUNCTION TO DELETE LAST ELEMENT
void pop(Node*&head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    temp->prev->next=NULL;
    delete temp;
}

int main(){

    Node*head=NULL;
	int no_of_family_mem;
	cout<<"Enter Number Of Family Members:";
    cin>>no_of_family_mem;

    //Inserting family members details in doubly linked list
	for(int i=1;i<=no_of_family_mem;i++){
		string name;
		int age;
		cout<<"Enter Family Member "<<i<<" Name:";
        cin.ignore();
        getline(cin,name);
		cout<<"Enter Family Member "<<i<<" Age:";
        cin>>age;
        //Appending data name and age in doubly linked list
		push_back(head,name,age);
	}
    cout<<endl;

    //Displaying Family details
    cout<<"Doubly Linked list is shown below:"<<endl<<endl;
    print_start(head);
}
//Sujal Aggarwal
//ECE,SID:21105036

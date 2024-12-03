#include<iostream>
using namespace std;

struct node{
    int data;
    node*next;
};

class stack{
private:
       node*top;

public:
stack(){
    top=nullptr;
}

void push(int value){
    node* newnode=new node();
    newnode->data=value;
    newnode->next=top;
    top=newnode;
    cout<<value<<" was pushed into the stack..!";
}


bool isempty(){
    return top==nullptr;
}

void pop(){
    if(isempty()){
        cout<<"The stack is empty!"<<endl;
        return ;
    }


    node*temp=top;
    top=top->next;
    cout<<temp<<"was pooped!"<<endl;
    delete temp;
}

int peek(){
    if(isempty()){
        cout<<"The stack is empty!"<<endl;
        return -1;
    }
    return top->data;
}

void display(node*top){
    node*temp=top;
    if(top==nullptr){
        cout<<"The stack is empty!"<<endl;
        return;
    }
    cout<<"The stack is:";
    while(temp!=nullptr){
        
        cout<<temp->data<<"->";
        temp=temp->next;

    }


}
node* gettop(){
    return top;
}
};

int main() {
    stack s;
    
    int choice, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            value = s.peek();
            if (value != -1)
                cout << "Top element: " << value << "\n";
            break;
        case 4:
            s.display(s.gettop());
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
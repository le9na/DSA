/* 
        +---------------------------------------------------------------------+
        |   This file contains a stack data structure implemented using       |
        |   linked-list for multi-purpose use.                                |
        |                                                                     |
        |   Dynamic allocation is used in this code in order to free          |
        |   memory later.                                                     |
        +---------------------------------------------------------------------+
        |                                                                     |
        |   (DSA practice.)                                                   |
        |   Creator: Kin. (Lena Abdulaziz).                                   |
        +---------------------------------------------------------------------+
        |   Note: System notations:                                           |
        |   - [ERROR]: indicates error.                                       |
        |   - [SUCCESS]: indicates successful operation.                      |
        |   - [INFO]: indicates information only.                             |
        |   Note: Main function tests the methods of the class.                                                                 |
        +---------------------------------------------------------------------+
*/

#include <cstdlib>
#include <iostream>

using namespace std;

/* linked-list */
typedef struct node
{
    unsigned int value;
    struct node *next;
}node;

/* Stack implementation using a linked list */
class Stack
{
private:
    node* top;
public:

    /* Constructor */
    Stack(){
        top = NULL;
    }

    /* Push, Pop, and peek Functions */
    void Push(int);
    int Pop();
    int Peek();

    /* Free Stack Function*/
    void Free();

};

void Stack::Push(int val){
        node *newNode = new node;       /* Dynamic allocation */
        newNode->value = val;
        
        newNode->next = top;
        top = newNode;
        
}

int Stack::Pop(){

    /* First case: Stack is empty: [ERROR]: Nothing can be popped. Stack is empty. */
    if(top == NULL){
        cout << "[ERROR]: Nothing can be popped. Stack is empty." << endl;
        return -1;
    }

    /* Second case: Stack isn't empty: [SUCCESS]: Top value popped. Value: x. */
    node *temp = top;         /* temp holds top value which is the one that will be popped. */
    top = temp->next;

    /* Hold the value of the top in a variable to return. */
    int x = temp->value;

    /* Free memory (Pop). */
    delete temp;
    temp = NULL;

    /* Return the (previous) top value. */
    cout << "[SUCCESS]: Top value popped: " << x << endl;
    return x;
}

int Stack::Peek(){
    /* First case: Stack is empty: [ES]: Stack is empty. */
    if(top == NULL){
        cout << "[INFO]: Stack is empty." << endl;
        return -1;
    }

    /* Second case: Stack isn't empty: [INFO]: Top: (VAL). */
    cout << "[INFO]: Top: " << top->value << endl;
    return top->value;
}

void Stack::Free(){

    /* First case: Stack is empty: [ERROR]: Nothing to be freed. Stack is empty. */
    if(top == NULL){
        cout << "[ERROR]: Nothing to be freed. Stack is empty." << endl;
        return;
    }

    /* Second case: Stack isn't empty: [SUCCESS]: Freed memory. All stack elements are popped. */
    node *temp = new node;
    for(node *n = top; n != NULL; ){
        temp = n;
        n = n->next;
        top = n;
        delete temp;
        temp = NULL;
    }

    /* Assuming an error happened: */
    if (top != NULL){
        cout << "[ERROR]: Not all elements reached. Check for loop for errors. " << endl;
        return;
    }

    /* Everything went smoothly: */
    cout << "[SUCCESS]: Freed memory. All stack elements are popped." << endl;
    
}


int main() {
    Stack* stack = new Stack();

    stack->Push(1);
    stack->Push(2);

    stack->Peek();
    stack->Pop();

    stack->Free();
    stack->Pop();

    return 0;
}
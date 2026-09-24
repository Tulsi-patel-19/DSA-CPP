#include<iostream>
#include<vector>
using namespace std;

class Node
{
    public:

    int data ;
    Node* next;
    Node* back;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back= nullptr;
    }

    public:
    Node(int data1 ,  Node* next1 , Node* back1){
        data = data1;
        next= next1;
        back= back1;
    }

};

Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);

    Node* prev = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    
    return head;
}

Node* addtwonum(Node* head1 , Node* head2){
    Node* dummynode = new Node(-1);
    Node* curr = dummynode;

    Node* temp1 = head1;
    Node* temp2 = head2;

    int carry =0;

    while(temp1 != nullptr || temp2 != nullptr){
        int sum = carry;

        if(temp1) sum += temp1->data;
        if(temp2) sum += temp2->data;

        Node* newnode = new Node(sum %10);
        carry = sum /10;

        curr-> next = newnode;
        curr = curr->next;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;


    }

    if(carry){
        Node* newnode = new Node(carry);
        curr->next = newnode;
    }
    return dummynode->next;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data <<" ";
        head= head->next;
    }

}

int main(){
     vector<int> arr1 = {3,5};
     vector<int> arr2 = {4,5,9,9};
    Node* head1 = convertArr2DLL(arr1);
    Node* head2 = convertArr2DLL(arr2);
   
    Node* head = addtwonum(head1 ,head2); // ANS - 70001
    print(head);
}

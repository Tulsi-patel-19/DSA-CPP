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



 
// Tc = O(N + N/2);


// optimal  solution 
// tontoise & hare algo 

bool middleofLL2(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next !=nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast ){
            return true;
        }
    }
    return false;
}

void print(Node* head){
    cout<<head->data<<" ";
    // while(head != NULL){
    //     cout<<head->data <<" ";
    //     head= head->next;
    // }

}

int main(){
     vector<int> arr = {1,2,3,4,5};

    Node* head = convertArr2DLL(arr);

    bool ans =   middleofLL2(head);
    cout<<ans;
   
    //  head = middleofLL(head);
   
    // print(head);
}
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




// optimal  solution 
// tontoise & hare algo 

Node* deletemidddle(Node* head){
    if(head == nullptr || head->next ==  nullptr){
        return nullptr;
    }
    Node* slow = head;
    Node* fast = head;

    fast = fast->next->next;

    while(fast != nullptr && fast->next !=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* middledelete = slow->next;
    slow->next = slow->next->next;
    delete middledelete;

    return head;
}
void print(Node* head){
    // cout<<head->data<<" ";
    while(head != NULL){
        cout<<head->data <<" ";
        head= head->next;
    }

}

int main(){
     vector<int> arr = {1,2,3,4,5};

    Node* head = convertArr2DLL(arr);

   
    //  head = middleofLL(head);
     head = deletemidddle(head);
    print(head);
}
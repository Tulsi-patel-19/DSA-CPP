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

// find the length , find middle and again traversal

Node* middleofLL(Node* head){
    Node* temp = head;
    int cnt =0;

    // O(N)
    while(temp != nullptr){
        cnt++;
        temp = temp ->next;

    }

     temp = head;
    int midnode = (cnt /2)+1;

    // O(N/2)
    while(temp != nullptr){
        midnode -=1;

        if(midnode ==0){
            break;

        }
            temp = temp->next;
        }
        return temp;
} 
// Tc = O(N + N/2);


// optimal  solution 
// tontoise & hare algo 

Node* middleofLL2(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next !=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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

   
    //  head = middleofLL(head);
     head = middleofLL2(head);
    print(head);
}
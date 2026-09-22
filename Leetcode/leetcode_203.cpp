// //  Definition for singly-linked list.
// #include<iostream>
// #include<vector>
// using namespace std;

// struct ListNode {
//      int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };


// ListNode* convertArr2LL(vector<int> &arr){
//     ListNode* head = new ListNode(arr[0]);
//     ListNode* mover = head;

//     for(int i=1;i<arr.size();i++){
//         ListNode* temp = new ListNode(arr[i]);
//         mover->next = temp;
//         mover = temp;
//     }
//     return head;
// }
// // class Solution {
// // public:
//     ListNode* removeElements(ListNode* head, int val) {
//         if(head == nullptr){
//             return head;
//         }

//         ListNode* temp = head;
//         ListNode* prev = nullptr;

//         while(temp != nullptr){

//             if(temp->val == val){
//             ListNode* temp = head;
//             head = head->next;
//             delete (temp);
//             }
//             else if(temp->val == val){
//                 prev->next = prev->next->next;
//                 delete (temp);
//             }

//             else{
//                 prev = temp ;
//                 temp = temp->next;
//             }

        
//         }
//         return head;

//     }

//     void printLL(ListNode* head) {

//     ListNode* temp = head;

//     while (temp != nullptr) {

//         cout << temp->val << " ";

//         temp = temp->next;
//     }

//     cout << endl;
// }

//     int main(){
//         vector<int> arr = {1,2,6,3,4,5,6};
//         ListNode* head = convertArr2LL(arr);
//         head = removeElements(head,6);
//         printLL(head);
//     }





#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Convert Array to Linked List
ListNode* convertArr2LL(vector<int>& arr) {

    if (arr.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;

    for (int i = 1; i < arr.size(); i++) {

        ListNode* temp = new ListNode(arr[i]);

        mover->next = temp;
        mover = temp;
    }

    return head;
}

// Remove All Occurrences
ListNode* removeElements(ListNode* head, int val) {

    ListNode* temp = head;
    ListNode* prev = nullptr;

    while (temp != nullptr) {

        if (temp->val == val) {

            if (prev == nullptr) {

                head = temp->next;

                delete temp;

                temp = head;
            }
            else {

                prev->next = temp->next;

                delete temp;

                temp = prev->next;
            }
        }
        else {

            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

// Print Linked List
void printLL(ListNode* head) {

    ListNode* temp = head;

    while (temp != nullptr) {

        cout << temp->val << " ";

        temp = temp->next;
    }

    cout << endl;
}

int main() {

    vector<int> arr = {1, 2, 6, 3, 4, 5, 6};

    ListNode* head = convertArr2LL(arr);

    head = removeElements(head, 6);

    printLL(head);

    return 0;
}
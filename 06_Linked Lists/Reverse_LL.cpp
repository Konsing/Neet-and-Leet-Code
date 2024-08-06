// Question 2 : Reverse a Linked List
// Given the head of a singly linked list, reverse the list, and return the reversed list.

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseList(ListNode *head){
    ListNode* prev = NULL;
    ListNode* curr = head;

    if(curr == NULL || curr->next == NULL){
        return curr;
    }

    while(curr != NULL){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

int main(){
    // Creating a sample list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *reversedHead = reverseList(head);

    // Printing reversed list
    ListNode *current = reversedHead;
    while (current != nullptr){
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;

    return 0;
}

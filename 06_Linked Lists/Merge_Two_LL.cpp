// Question 4: Merge Two Sorted Lists
// Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing 
// together the nodes of the two given lists.

#include <iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
    ListNode *dummy = new ListNode(0);
    ListNode *node = dummy;

    while (l1 && l2){
        if (l1->val <= l2->val){
            node->next = l1;
            l1 = l1->next;
        } else {
            node->next = l2;
            l2 = l2->next;
        }
        node = node->next;
    }

    if (l1){
        node->next = l1;
    } else {
        node->next = l2;
    }

    return dummy->next;
}

int main(){
    // Creating two sample lists: 1 -> 2 -> 4 -> nullptr and 1 -> 3 -> 4 -> nullptr
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode *mergedHead = mergeTwoLists(l1, l2);

    // Printing merged list
    ListNode *current = mergedHead;
    while (current != nullptr)
    {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;

    return 0;
}

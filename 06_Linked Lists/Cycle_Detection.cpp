//Floyd's Algorithm for Cycle Detection

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    bool hasCycle(ListNode *head){
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow){
                return true;
            }
        }

        return false;
    }
};

// Helper function to print the list (for non-cyclic lists)
void printList(ListNode *head){
    ListNode *current = head;
    while (current != nullptr){
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Helper function to create a cycle in the list
void createCycle(ListNode *head, int pos){
    if (pos == -1)
        return;

    ListNode *cycleNode = nullptr;
    ListNode *tail = head;
    int currentIndex = 0;

    while (tail->next != nullptr){
        if (currentIndex == pos){
            cycleNode = tail;
        }
        tail = tail->next;
        currentIndex++;
    }

    tail->next = cycleNode;
}

int main(){
    Solution solution;

    // Test case 1: List with no cycle
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    cout << "Test case 1: ";
    printList(head1);
    cout << "Cycle detected: " << boolalpha << solution.hasCycle(head1) << endl;

    // Test case 2: List with a cycle
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    createCycle(head2, 2); // Create a cycle at position 2 (0-based index)

    // We will not print head2 because it has a cycle

    cout << "Test case 2: ";
    cout << "Cycle detected: " << boolalpha << solution.hasCycle(head2) << endl;

    // Test case 3: Empty list
    ListNode *head3 = nullptr;
    cout << "Test case 3: ";
    cout << "Cycle detected: " << boolalpha << solution.hasCycle(head3) << endl;

    // Test case 4: Single node with no cycle
    ListNode *head4 = new ListNode(1);
    cout << "Test case 4: ";
    printList(head4);
    cout << "Cycle detected: " << boolalpha << solution.hasCycle(head4) << endl;

    // Test case 5: Single node with a cycle
    ListNode *head5 = new ListNode(1);
    head5->next = head5; // Create a cycle

    // We will not print head5 because it has a cycle

    cout << "Test case 5: ";
    cout << "Cycle detected: " << boolalpha << solution.hasCycle(head5) << endl;

    // Cleanup
    delete head1->next->next->next->next;
    delete head1->next->next->next;
    delete head1->next->next;
    delete head1->next;
    delete head1;

    // For cyclic list head2, we can't safely delete nodes as it would cause an infinite loop.

    delete head3;

    delete head4;

    // For cyclic list head5, we can't safely delete nodes as it would cause an infinite loop.

    return 0;
}

#include <iostream>
using namespace std;

class ListNode {
    private:
    int value;
    ListNode* next;
    
    public:
    // Constructors
    ListNode() : value(0), next(nullptr) { }
    ListNode(int val) : value(val), next(nullptr) { }
    

    static void insert(ListNode*& head, int val) {
        if(!head) {
            head = new ListNode(val);
            return;
        }
        
        ListNode* temp = head;
        
        while(temp->next) {
            temp = temp->next;
        }
        
        ListNode* newNode = new ListNode(val);
        temp->next = newNode;
    }
    
    static void printList(ListNode* head) {
        while(head) {
            cout << head->value << " ";
            head = head->next;
        }
        cout << endl;
    }
    
    static int getLength(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    
    static bool search(ListNode* head, int key) {
        while(head) {
            if(head->value == key) return true;
            head = head->next;
        }
        return false;
    }
    
    static void deleteNode(ListNode* nodeToDelete) {
        if(!nodeToDelete->next) return;
        
        nodeToDelete->value = nodeToDelete->next->value;
        ListNode* deletedNode = nodeToDelete->next;
        nodeToDelete->next = nodeToDelete->next->next;
        deletedNode->next = nullptr; // not necessary, but fun to do for some sadistic reason lol
        delete deletedNode;
    }
    
    static ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *currNode = head, *prevNode = nullptr, *nextNode = nullptr;
        
        while(currNode) {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        
        return prevNode;
    }
    
    static ListNode* reverseListRec(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* newHead = reverseListRec(head->next);
        
        head->next->next = head;
        head->next = nullptr;
        
        return newHead;
    }
    
    static ListNode* findMiddle(ListNode* head) {
        ListNode* fp = head;
        ListNode* sp = head;
        
        while(fp && fp->next) {
            fp = fp->next->next;
            sp = sp->next;
        }
        
        return sp;
    }
    
    static bool hasCycle(ListNode* head) {
        ListNode* fp = head;
        ListNode* sp = head;
        while(fp && fp->next) {
            sp = sp->next;
            fp = fp->next->next;
            if(sp == fp) return true;
        }
        return false;
    }
    
    static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(list1 && list2) {
        	if(list1->value < list2->value) {
        		curr->next = list1;
        		list1 = list1->next;
        	}
        	else {
        		curr->next = list2;
        		list2 = list2->next;
        	}

        	curr = curr->next;
        }

        curr->next = (list1) ? list1 : list2;

        ListNode* mergedHead = dummy->next;
        delete dummy;

        return mergedHead;
    }
};

int main() {
    return 0;
}
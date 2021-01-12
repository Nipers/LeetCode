#include <vector>
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode* head;
    if (l1 == nullptr && l2 == nullptr) {
        return nullptr;
    }
    if (l1 == nullptr) {
        head = l2;
        l2 = l2 -> next;
    }
    else if (l2 == nullptr) {
        head = l1;
        l1 = l1 -> next;
    }
    else {
         if (l1 -> val < l2 -> val) {
            head = l1;
            l1 = l1 -> next;
        }
        else {
            head = l2;
            l2 = l2 -> next;
        }
    }   
    ListNode* record = head;
    while (l1 != nullptr || l2 != nullptr) {
        if (l1 == nullptr) {
            record -> next = l2;
            record = record -> next;
            l2 = l2 -> next;
            continue;
        }
        if (l2 == nullptr) {
            record -> next = l1;
            record = record -> next;
            l1 = l1 -> next;
            continue;
        }
        if (l1 -> val < l2 -> val) {
            record -> next = l1;
            record = record -> next;
            l1 = l1 -> next;
            continue;
        }
        else {
            record -> next = l2;
            record = record -> next;
            l2 = l2 -> next;
            continue;
        }
    }
    return head;
}
class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        int size = lists.size();
        if (!size)
            return nullptr;
        while (size != 1) {
            int half = size >> 1;
            for (int i = 0; i < half; i++) {
                lists[i] = merge(lists[i << 1], lists[(i << 1) + 1]);
            }
            if (size & 1) {
                lists[half] = lists[size - 1];
                half++;
            }
            size = half;
        }
        return lists[0];
    }
};
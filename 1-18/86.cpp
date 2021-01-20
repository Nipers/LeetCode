class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<ListNode*> big;
        vector<ListNode*> little;
        if (head == nullptr)
            return head;
        ListNode* next = head;
        while (next != nullptr) {
            if (next -> val >= x) {
                big.push_back(next);
            }
            else {
                little.push_back(next);
            }
            next = next -> next;
        }
        int size = little.size() - 1;
        if (size > -1) {
            for (int i = 0; i < size; i ++) {
                little[i] -> next = little[i + 1];
            }
            if (big.size() != 0)
                little[size] -> next = big[0];
            else 
                little[size] -> next = nullptr;
        }
        size = big.size() - 1;
        for (int i = 0; i < size; i++) {
            big[i] -> next = big[i + 1];
        }
        if (big.size() != 0)
            big[size] -> next = nullptr;
        if (little.size() == 0) 
            return big[0];
        return little[0];
    }
};
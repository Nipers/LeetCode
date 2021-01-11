/*
*犯了两个主要错误，一是搞错了k长翻转之后尾结点的next，
*二是未对整除的情况做处理，导致链表成环。
*/

#include <vector>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        std::vector<ListNode*> table;
        table.resize(k);
        ListNode* record = head;
        ListNode* tail;
        ListNode* Next;
        if (k == 1) 
            return head;
        bool unset = true, done = false;
        while(true) {
            for (int i = 0; i < k; i++) {
                if (record != nullptr) {
                    table[i] = record;
                    record = record -> next;
                }
                else{
                    done = true;
                    break;
                }
            }
            if (done) {
                tail -> next = table[0];
                break;
            }
            if (unset) {
                unset = false;
                head = table[k - 1];
            }
            else {
                tail -> next = table[k - 1];
            }
            tail = table[0];
            Next = table[k - 1] -> next;
            for (int i = k - 1; i > 0; i--) {
                table[i] -> next = table[i - 1];
            }
            table[0] -> next = nullptr;
            if (Next == nullptr){
                break;
            }
        }
        return head;
    }
};
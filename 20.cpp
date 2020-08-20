/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *first = head;
        vector<ListNode*> vec;
        while(head){
            vec.push_back(head);
            head=head->next;
        }
        int n= vec.size();
        int front=0;
        int back = n-1;
        int op=0;
        
        while(front<back){
            if(!op){
                vec[front]->next = vec[back];
                vec[back]->next= nullptr;
                front++;
            }
            else{
                vec[back]->next = vec[front];
                vec[front]->next=nullptr;
                back--;
            }
            op=op^1;
        }
        
    }
};

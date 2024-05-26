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

    ListNode* getkth(ListNode* temp,int k)
    {
        k -= 1;
        while(temp!=NULL && k>0)
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverse(ListNode* temp)
    {
        ListNode* prev = NULL;
        while(temp)
        {
            ListNode* nex = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nex;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp)
        {
            ListNode* kth = getkth(temp,k);

            if(kth==NULL)
            {
                if(prev) prev->next = temp;
                break;
            }
        ListNode* nex = kth->next;
        kth->next = NULL;
        reverse(temp);

        if(temp==head)
        {
            head = kth;
        }
        else
        {
            prev->next = kth;
        }
        prev = temp;
        temp = nex;
        }
        return head;
    }
};

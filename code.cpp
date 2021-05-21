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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int>A,B;
        queue<int>q;
        if(head==NULL || k==0) {return head;}
        while(head!=NULL)
        {
            A.push_back(head->val);
            head=head->next;
        }
        k=k%A.size();
        for(int i=A.size()-1;i>=0;i--)
        {
            q.push(A[i]);
        }
        while(k!=0)
        {
         int c=q.front();
            q.pop();
            q.push(c);
            k--;
        }
        for(int i=0;i<A.size();i++)
        {
           B.push_back(q.front());
            q.pop();
            
        }
        ListNode* temp,*result=NULL;
        for(int i=B.size()-1;i>=0;i--)
        {
            if(result==NULL)
            {
                result=new ListNode(B[i]);
                temp=result;
            }
            else
            {
                temp->next=new ListNode(B[i]);
                temp=temp->next;
            }
        }
        return result;
    }
};

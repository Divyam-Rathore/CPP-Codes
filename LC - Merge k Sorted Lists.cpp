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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue < vector<int> , vector<vector<int> > , greater<vector<int> > > q;
        vector<ListNode*> start;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!= NULL)
            {
                start.push_back(lists[i]);
            q.push({start.back()->val,int(start.size()-1)});
            }
        }
        // cout<<start.size()<<endl;
//         for(int i=0;i<start.size();i++)
//             cout<<start[i]<<" ";
        
        ListNode* ans=new ListNode;
        ListNode* head=ans;
        while(!q.empty()){
            head->next=new ListNode;
            head=head->next;
            head->val=q.top()[0];
            int i=q.top()[1];
            q.pop();
            if(start[i]->next!=NULL)
            {q.push({start[i]->next->val,i});
            start[i]=start[i]->next;
        }
        }
        return ans->next;
    }
};

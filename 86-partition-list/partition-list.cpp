class Solution {
public:
    ListNode* partition(ListNode* hd, int x) {
        ListNode a(0),b(0);
        ListNode *l=&a,*r=&b;
        while(hd){
            if(hd->val<x){
                l->next=hd;
                l=l->next;
            }else{
                r->next=hd;
                r=r->next;
            }
            hd=hd->next;
        }
        r->next=nullptr;
        l->next=b.next;
        return a.next;
    }
};
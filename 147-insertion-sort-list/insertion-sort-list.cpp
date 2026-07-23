class Solution {
public:
    ListNode* insertionSortList(ListNode* hd) {
        ListNode dm(0);
        while(hd){
            ListNode* nx=hd->next;
            ListNode* cr=&dm;
            while(cr->next&&cr->next->val<hd->val)
                cr=cr->next;
            hd->next=cr->next;
            cr->next=hd;
            hd=nx;
        }
        return dm.next;
    }
};
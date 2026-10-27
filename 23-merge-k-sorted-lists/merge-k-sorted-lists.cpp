class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto list : lists) {
            while (list) {
                pq.push(list->val);
                list = list->next;
            }
        }
        if (pq.empty()) return nullptr;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (!pq.empty()) {
            tail->next = new ListNode(pq.top());
            pq.pop();
            tail = tail->next;
        }
        return dummy.next;
    }
};
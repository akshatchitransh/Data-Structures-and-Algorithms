class Solution {
public:
    Node* copyRandomList(Node* h) {
        if(!h)return NULL;
        Node* c=h;
        while(c){
            Node* n=new Node(c->val);
            n->next=c->next;
            c->next=n;
            c=n->next;
        }
        c=h;
        while(c){
            if(c->random)c->next->random=c->random->next;
            c=c->next->next;
        }
        c=h;
        Node* d=h->next;
        while(c){
            Node* n=c->next;
            c->next=n->next;
            if(n->next)n->next=n->next->next;
            c=c->next;
        }
        return d;
    }
};
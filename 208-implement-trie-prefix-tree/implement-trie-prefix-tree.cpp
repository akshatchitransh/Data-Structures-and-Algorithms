class Trie{
struct N{
N*c[26]={};
bool e=0;
};
N*r;
public:
Trie(){
r=new N();
}
void insert(string w){
N*t=r;
for(char x:w){
int i=x-'a';
if(!t->c[i])t->c[i]=new N();
t=t->c[i];
}
t->e=1;
}
bool search(string w){
N*t=r;
for(char x:w){
int i=x-'a';
if(!t->c[i])return 0;
t=t->c[i];
}
return t->e;
}
bool startsWith(string p){
N*t=r;
for(char x:p){
int i=x-'a';
if(!t->c[i])return 0;
t=t->c[i];
}
return 1;
}
};
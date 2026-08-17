class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char ,int>mp;
        int n = s.size();
        int i=0 ;
        int cnt =0;

        for(int j=0;j<n;j++){
             mp[s[j]]++;
if(mp.size()==3){
   
    
   while(i<j && mp.size()==3) {
     mp[s[i]]--;

     if (mp[s[i]] == 0) {
     mp.erase(s[i]);
                      }
    i++;
    cnt += n - j;}
}

        }
  return cnt;  }
};
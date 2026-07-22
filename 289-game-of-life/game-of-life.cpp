class Solution {
public:
    void gameOfLife(vector<vector<int>>& bd) {
        int m=bd.size(),n=bd[0].size();
        int dr[]={-1,-1,-1,0,0,1,1,1};
        int dc[]={-1,0,1,-1,1,-1,0,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int ct=0;
                for(int k=0;k<8;k++){
                    int r=i+dr[k],c=j+dc[k];
                    if(r>=0&&r<m&&c>=0&&c<n&&(bd[r][c]&1)) ct++;
                }
                if((bd[i][j]&1)&&(ct==2||ct==3)) bd[i][j]|=2;
                if(!(bd[i][j]&1)&&ct==3) bd[i][j]|=2;
            }
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                bd[i][j]>>=1;
    }
};
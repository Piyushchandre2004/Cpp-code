#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    void solve(int col,vector<string>&board,int n,vector<vector<string>>&ans,vector<int>&column,vector<int>&lowerDiag,vector<int>&upperDiag){
        if(col==n){
            ans.push_back(board);
        }
        for(int row=0;row<n;row++){
            if(column[row]==0 && lowerDiag[row+col]==0 && upperDiag[n-1+col-row]==0){
                board[row][col]='Q';
                column[row]=1;
                upperDiag[n-1+col-row]=1;
                lowerDiag[row+col]=1;
                solve(col+1,board,n,ans,column,lowerDiag,upperDiag);
                board[row][col]='.';
                column[row]=0;
                upperDiag[n-1+col-row]=0;
                lowerDiag[row+col]=0;
            }
        }
    }
    vector<vector<string>>NQueens(int n){
        vector<vector<string>>ans;
        vector<int>upperDiag(2*n-1,0);
        vector<int>lowerDiag(2*n-1,0);
        vector<int>column(n,0);

        vector<string>board(n,string(n,'.'));
        solve(0,board,n,ans,column,lowerDiag,upperDiag);
        return ans;

    }
};
int main(){
    int n;
    cin>>n;
    Solution s;
    vector<vector<string>>ans=s.NQueens(n);
    for(int i=0;i<n;i++){
    
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
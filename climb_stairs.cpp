#include<bits/stdc++.h>
using namespace std;



class Solution{
    public:
    void solve(int &cnt,int n,int sum){
        if(sum==n){
            cnt++;
            return;
        }
        if(sum+1<=n){
            sum+=1;
            solve(cnt,n,sum);
            sum-=1;
        }
        if(sum+2<=n){
            sum+=2;
            solve(cnt,n,sum);
            sum-=2;
        }
        
        
    }
    int climbingStairs(int n){
        int sum=0;
        int cnt=0;
        solve(cnt,n,sum);

        return cnt;
    }

};
int main(){
    int n;
    cin>>n;

    Solution sol;
    cout<<sol.climbingStairs(n)<<endl;
    return 0;
}
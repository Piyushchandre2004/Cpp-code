#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minOperations(vector<int>&nums){    //This is the greedy approach where we try sliding window technique 
        int n=nums.size();
        int left=0;
        int right=2;
        int ans=0;
        while(right<n){
            if(nums[left]==0){
                for(int i=left;i<=right;i++){
                    nums[i]^=1;
                }    
                left++;
                right++;
                ans++;
            }
            else{
                while(nums[left]==1 && right<n){    //right<n to prevent heap buffer overflow
                    left++;
                    right++;
                }
            }
            // cout<<left<<" "<<right<<" "<<ans<<endl; /*Debugging to check where it goes wrong*/
            // for(int num:nums)cout<<num<<"->";
            // cout<<endl;
        }
        if(nums[n-1]==0 || nums[n-2]==0)return -1;

        return ans;
    }

    int minOperations2(vector<int>&nums){
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-2;i++){
            if(nums[i]==0){
                for(int a=i;a<=i+2;a++){
                    nums[a]^=1;
                }
                ans++;
            }
            else i+=3;
        }
        if(nums[n-1]==0 || nums[n-2]==0)return -1;
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>nums;
    //vector<int>temp=nums;
    while(n--){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    Solution sol;
    cout<<sol.minOperations(nums)<<endl;


}
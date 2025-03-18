#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxSubarray(vector<int>&nums){  //BRUTE FORCE METHOD
        //Calculate all the subarray whose every pair & is 0.
        int ans=1;  //minimum answer possible 
        for(int i=0;i<nums.size();i++){
            int k=nums[i];  //initialize the first element
            for(int j=i+1;j<nums.size();j++){
                /*Observation:
                    let a=11 , b=11000 ,c=1000
                    then a&b=0 b&c=0 
                    so (a|b)&c =0
                    what we conclude is or helps in getting the bits set for further calculation
                */
                if((k & nums[j])!=0)break;
                k=(k|nums[j]);
                ans=max(ans,j-i+1);
            }
        }
        //Time complexity : O(N^2) and Space complexity : O(1)
        return ans;
    }

    int maxSubarray2(vector<int>&nums){     //Sliding Window Technique
        int n=nums.size();
        //in this technique , we use sliding window approach to find the maximum length subarray
        int left=0,right=0;
        int k=0;
        int dummyK=k;   //Since we might need to get our older k back but it's impossible after & operation
        int ans=0;      //hence we use a dummy variable that will use xor opeartion to get our older k back.
        while(right<n){
            if((nums[right]&k)!=0){
                dummyK=(dummyK^nums[left]);
                k=dummyK;
                left++;
            }
            else{
                k=(k|nums[right]);
                dummyK=(dummyK^nums[right]);
                right++;
            }
            
            ans=max(ans,right-left);
        }
        //Time complexity : O(N) and Space complexity : O(1)
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>nums;
    while(n--){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    Solution sol;
    cout<<sol.maxSubarray2(nums)<<endl;
}
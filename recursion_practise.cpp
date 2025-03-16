#include <bits/stdc++.h>
using namespace std;

void subset_sum(vector<int>& ans, vector<int>& arr, int sum, int it) {
    if (it == arr.size()) {  
        ans.push_back(sum);
        return;
    }
    sum+=arr[it];
    subset_sum(ans, arr, sum , it + 1);
    sum-=arr[it];
    subset_sum(ans, arr, sum, it + 1);
}

void perm(vector<int>&nums,vector<vector<int>>&ans,int it){
  if(it==nums.size()){
    ans.push_back(nums);
    return;
  }
  for(int i=it;i<nums.size();i++){
    swap(nums[it],nums[i]);
    perm(nums,ans,it+1);
    swap(nums[it],nums[i]);
  }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // vector<int> ans;
    // subset_sum(ans, arr, 0, 0);

    // sort(ans.begin(), ans.end()); 
    //for (int num : ans) cout << num << " ";
    
    vector<vector<int>>mpp;
    perm(arr,mpp,0);
    for(int i=0;i<mpp.size();i++){
      for(int j=0;j<mpp[i].size();j++){
        cout<<mpp[i][j]<<" ";
      }
      cout<<endl;
    }
    return 0;
}

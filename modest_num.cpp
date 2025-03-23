//Modest Number

#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    string s;
    cin>>s;
    int n=stoi(s);
    bool flag=true;
    for(int i=1;i<s.size();i++){
        int left = stoi(s.substr(0,i));
        int right = stoi(s.substr(i , s.size()-i));

        if(n%left==right){
            cout<<left<<" "<<right<<endl;
            cout<<"Yes"<<endl;
            flag=false;
            break;
        }
        //cout<<left<<" "<<right<<endl;
    }
    if(flag)cout<<"No"<<endl;
    return 0;
}
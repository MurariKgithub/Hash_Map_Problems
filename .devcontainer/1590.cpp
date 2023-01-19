#include<bits/stdc++.h>
using namespace std;
int minSubarray(vector<int>& nums, int p) {
        int rem = 0,sum=0,n = nums.size(),minval=n;
        for(auto it :nums) rem = (rem+it)%p;
        if(rem==0) return 0;
        map<int,int> mp;
        mp[0] =-1;
        cout<<"Ho murari"<<endl;
        for(int i=0 ;i<n ;i++){
            sum = (sum + nums[i])%p;
            int remainrem =  (sum%p-rem);
            if(remainrem<0) remainrem+=p;
            if(mp.find(remainrem)!=mp.end()) minval = min(minval,i-mp[remainrem]);
            mp[sum%p] =i;
        }
        return minval==n?-1:minval;
}
int main(){
   vector<int> arr = {6,3,5,2};
   int p=9;
   cout<<minSubarray(arr,p);
}
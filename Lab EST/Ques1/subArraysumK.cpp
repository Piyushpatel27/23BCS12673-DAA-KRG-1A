#include<bits/stdc++.h>
using namespace std;

int subArraySum(vector<int> &nums,int k){
  sort(nums.begin(), nums.end());
  int count=0; int sum=0;
  for(int i=0;i<nums.size();i++){
    if(nums[i]>0){
      if(sum<k &&  ((sum+nums[i])<=k)){
        sum+=nums[i];
        count++;
      }
    }
  }
  return sum;
}


int subArraySum2(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    for(int x:nums) {
        if(x>0 && (sum+x<= k)) {
          sum+=x;
        }
    }
    return sum;
}


int main() 
{
    vector<int> nums={-5,12,-3,4,-15,6,1};
    int k=2;
    cout<<subArraySum(nums,k)<<endl;
    cout<<subArraySum2(nums,k)<<endl;

    return 0;
}


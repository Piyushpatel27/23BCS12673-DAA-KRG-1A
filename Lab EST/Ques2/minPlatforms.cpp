#include<bits/stdc++.h>
using namespace std;

int minPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0, j = 0;
    int platforms = 0;
    int maxPlatforms = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        } else {
            
            platforms--;
            j++;
        }
    }
    return maxPlatforms;
}

int main(){
    vector<int> arr = {900,940,950,1100};
    vector<int> dep = {910,1200,1120,1130};

    int ans= minPlatform(arr, dep);
    cout<<ans<<endl;
    return 0;
}
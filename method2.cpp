#include<iostream>
using namespace std;

// not running will try later
bool pythagoreanTriplet(vector<int>& arr) {
    // code here
    int maxi = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        maxi = max(maxi, arr[i]);
    }
    vector<int> nums(maxi + 1, 0);
    for(int i = 0; i < arr.size(); i++){
        nums[arr[i]]++;
    }
    for(int i = 0; i < arr.size(); i++){
        nums[arr[i]]--;
        for(int j = i + 1; j < arr.size(); j++){
            nums[arr[j]]--;
            int a = arr[i];
            int b = arr[j];
            int c = sqrt(a * a + b * b);
            if((c * c == (a * a + b * b)) && (nums[c] != 0)){
                return true;
            }
            nums[arr[j]]++;
        }
        nums[arr[i]]++;
    }
    return false;
}
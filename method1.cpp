#include<iostream>
using namespace std;

bool pythagoreanTriplet(vector<int>& arr) {
    // code here
    unordered_map<int,int> nums;
    for(int i = 0; i < arr.size(); i++){
        arr[i] *= arr[i];
        nums[arr[i]]++;
    }
    for(int i = 0; i < arr.size(); i++){
        nums[arr[i]]--;
        for(int j = i + 1; j < arr.size(); j++){
            nums[arr[j]]--;
            if(nums[arr[i] + arr[j]] != 0){
                return true;
            }
            nums[arr[j]]++;
        }
        nums[arr[i]]++;
    }
    return false;
}
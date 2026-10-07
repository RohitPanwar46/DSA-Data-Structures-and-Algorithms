#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool IsValid(vector<int> &arr, int realC, int minD ){
    int c = 1, lastStallPos = arr[0];

    for (int i = 0; i < arr.size()-1; i++)
    {
        if ( (arr[i+1] - lastStallPos)  >= minD )
        {
            c++;
            lastStallPos = arr[i+1];    
        }
        
    }
    
    return c >= realC;
}

int arrangeAggresiveCow(vector<int> &arr, int cows){

    if(arr.size() <= 1 || cows < 2){
        return -1;
    }

    int ans = -1;
    int start = 1; 
    int end = arr[(arr.size()-1)] - arr[0];

    while (start <= end)
    {
        int mid = start + (end-start)/2;

        if (IsValid(arr, cows, mid))
        {
            ans = max(ans, mid);
            start = mid+1;
        }else{
            end = mid-1;
        }
        
    }
    
    return ans;
}

int main() {

    vector<int> arr = {1, 2};
    int cows = 3;

    sort(arr.begin(), arr.end());


    cout << "Perfect Distance is: " << arrangeAggresiveCow(arr, cows) << endl;
    
    return 0;
}
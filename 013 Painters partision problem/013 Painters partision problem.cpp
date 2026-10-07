#include<iostream>
#include<vector>
using namespace std;

bool checkValidaty(int max, vector<int> &arr, int painters ){
    bool ans = false;
    int n = arr.size();
    int m=1, b=0;
    
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>max)
        {
            return false;
        }
        
        if ((b+arr[i])<=max)
        {
            b += arr[i];
        }else{
            b = arr[i];
            m += 1;
        }
    }
    
    if (m <= painters)
    {
        ans = true;
    }
    
    return ans;
}

int allowcatePainters(vector<int> &arr, int painters){
    int n = arr.size();
    long long sum = 0; 
    int maxValue = INT32_MIN; 
    int ans = -1;
    if (painters>n)
    {
        return -1;
    }
    
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxValue = max(maxValue, arr[i]);
    }
    
    int start = maxValue;
    long long end = sum;
    
    while (start<=end)
    {
        int mid = start + (end - start)/2;
        
        if (checkValidaty(mid, arr, painters))
        {
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
        
    }
    
    return ans;
}

int main() {
    vector<int> arr = {40, 30, 10, 20};
    int painters = 2;

    cout << "minimum time taken by painters is: " << allowcatePainters(arr, painters) << " minutes" << endl;
    return 0;
}

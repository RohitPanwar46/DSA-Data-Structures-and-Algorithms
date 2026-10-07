#include<iostream>
#include<vector>
using namespace std;

int main() {

    int arr[] = {1,2,3,4,5,6,7,9,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int st=0,end=n-1;
    int mid = (st+end)/2;
    int target = 12;
    int ans = -1;

    while (st<=end)
    {
        if (target>arr[mid])
        {
            st = mid+1;
        }else if(target<arr[mid])
        {
            end = mid-1; 
        }else{
            ans = mid;
            break;
        }
        mid = (st+end)/2;
    }

    if(ans != -1){
        cout << "target found at index: " << ans << endl;
    }else{
        cout << "target not found in array" << endl;
    }
    

    return 0;
}
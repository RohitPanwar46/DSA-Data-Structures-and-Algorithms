#include<iostream>
#include<vector>
using namespace std;

int main() {

// two pointer approach

int arr[] = {1,8,6,2,5,4,8,3,7};
int n = sizeof(arr)/sizeof(arr[0]);
int lp = 0, rp = n-1;
int wh = 0,h,w;

while (lp<rp)
{
    h = min(arr[rp],arr[lp]);
    w = rp - lp;
    int cwater = h*w;
    wh = max(wh,cwater);

    if (arr[lp]<arr[rp])
    {
        lp++;
    }else{ 
        rp--;
    }
}

cout << wh << endl;



// brute frocing approach
//     int arr[] = {1,8,6,2,5,4,8,3,7};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int mw = 0,h,w;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             h = min(arr[i],arr[j]);
//             w = j - i;
//             mw = max(mw,h*w);
//         }
        
//     }
    
// cout << mw << endl;


    return 0;
}
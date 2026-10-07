//Leetcode problem No. 78
#include<iostream>
#include<vector>
using namespace std;

void PS(vector<int> &arr, vector<int> &ans, int i){

    if(i == arr.size()){
        for (int val : ans)
        {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    ans.push_back(arr[i]);

    //Include
    PS(arr, ans, i+1);

    ans.pop_back();

    //exclude
    PS(arr, ans, i+1);
}

int main() {

    vector<int> arr = {1, 2, 3};

    vector<int> ans = {};

    int i = 0;

    PS(arr, ans, i);

    return 0;
}
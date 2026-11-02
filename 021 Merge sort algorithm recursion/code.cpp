#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &arr, int st, int end)
{

    int mid = st + (end - st) / 2;
    vector<int> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[st + idx] = temp[idx];
    }
}

void mergeSort(vector<int> &arr, int st, int end)
{
    if (st >= end)
    {
        return;
    }

    int mid = st + (end - st) / 2;

    if (st < end)
    {
        mergeSort(arr, st, mid);      // left
        mergeSort(arr, mid + 1, end); // right
    }

    sort(arr, st, end);
}

int main()
{

    vector<int> arr = {5, 1, 10, 16, 100, 55, 0, 3};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    for (int a : arr)
    {
        cout << a << " ";
    }

    return 0;
}
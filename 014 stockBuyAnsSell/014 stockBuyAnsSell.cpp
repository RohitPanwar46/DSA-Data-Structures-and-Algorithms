#include<iostream>
#include<vector>
using namespace std;

int main() {

    int prices[] = {20,7,6,5,4,35};
    int n = sizeof(prices)/sizeof(prices[0]);
    int bestBuy = prices[0], mp = 0;


    for (int i = 1; i < n; i++)
    {
        if ((prices[i]-bestBuy)>0)
        {
            mp = max(mp,prices[i]-bestBuy);
        }
        

        bestBuy = min(bestBuy,prices[i]);
    }
        
    cout << "max profit is: " << mp << endl;

    return 0;
}
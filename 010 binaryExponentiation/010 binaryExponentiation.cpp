#include<iostream>
#include<vector>
using namespace std;

int main() {

    float base, ans = 1;
    int pow;

    cout << "enter the base" << endl;
    cin >> base;
    cout << "enter the power" << endl;
    cin >> pow;
    
    float CBase = base;
    float CPow = pow;

    if (pow < 0)
    {
        base = 1/base;
        pow = -pow;
    }

    while (pow > 0)
    {
        if(pow % 2 == 1){
            ans *= base;
        }
        base *= base;
        pow /= 2;
    }

    cout << CBase << " to the power of " << CPow << " is: " << ans << endl;
    
    return 0;
}
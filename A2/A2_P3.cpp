#include <iostream>
using namespace std;
int num(int k){
    int t = 0;
    int x = 1;
    while (t < k){
        x *= 3;
        t += 1;
    }
    return x;
}
int judge(int k, int num1, int num2){
    if (k == 0)
    {
        return 1;
    }
    if ((num1>num(k-1) and num1<=2*num(k-1))and(num2>num(k-1) and num2<=2*num(k-1)))
    {
        return 0;
    }
    else
    {
        return judge(k-1,num1%num(k-1),num2%num(k-1));
    }
}
int main()
{   
    double k;
    cin >> k;
    for(int i = 1; i <= num(k); i++){
        for(int j = 1; j <= num(k); j++){
            if (judge(k,i,j)==1){
                cout << '#';
            }
            else{
                cout << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll int getSum(int num){
    if (num == 1){
        return 0;
    }

    float root = sqrt(num);
    
    ll int sum = 1;
    for (int i = 2; i < root; i++){
        if (num % i == 0){
            sum += i;
            sum += num / i;
        }
    }

    if ((int)root == root && num % (int)root == 0){
        sum += root;
    }

    return sum;
}

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int num;
        cin >> num;

        cout << getSum(num) << endl;
    }

    return 0;
}
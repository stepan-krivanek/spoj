#include <iostream>
#include <bits/stdc++.h>

#define long long

using namespace std;

bool isPrime(int n) { 
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for(int i = 3; i <= (n / i); i += 2){
        if(n % i == 0){
            return false;
        }
    }
    
    return true;
} 

void getPrimes(vector<int>* primes){
    int i = 1;
    int x = i*i;

    while (x < 10000000){
        int j = 1;
        int y = pow(j, 4);
        int res = x + y;
        while (y < 10000000){
            if (isPrime(res)){
                primes->push_back(res);
            }

            j++;
            y = pow(j, 4);
            res = x + y;
        }
        
        i++;
        x = i*i;
    }
}

int main(){
    vector<int> primes;
    getPrimes(&primes);
    sort(primes.begin(), primes.end());
    unique(primes.begin(), primes.end());

    int cases;
    cin >> cases;

    for (int s = 0; s < cases; s++){
        int n;
        cin >> n;

        int index = 0;
        while (1){
            if (primes.at(index) > n){
                break;
            }

            index += 1;
        }

        cout << index << endl;
    }

    return 0;
}
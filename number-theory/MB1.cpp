#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int oneDigit(int num) 
{ 
    // comparison operation is faster than division operation. 
    // So using following instead of "return num / 10 == 0;" 
    return (num >= 0 && num < 10); 
} 
  
// A recursive function to find out whether num is palindrome 
// or not. Initially, dupNum contains address of a copy of num. 
bool isPalUtil(int num, int* dupNum) 
{ 
    // Base case (needed for recursion termination): This statement 
    // mainly compares the first digit with the last digit 
    if (oneDigit(num)) 
        return (num == (*dupNum) % 10); 
  
    // This is the key line in this method. Note that all recursive 
    // calls have a separate copy of num, but they all share same copy 
    // of *dupNum. We divide num while moving up the recursion tree 
    if (!isPalUtil(num/10, dupNum)) 
        return false; 
  
    // The following statements are executed when we move up the 
    // recursion call tree 
    *dupNum /= 10; 
  
    // At this point, if num%10 contains i'th digit from beiginning, 
    // then (*dupNum)%10 contains i'th digit from end 
    return (num % 10 == (*dupNum) % 10); 
} 
  
// The main function that uses recursive function isPalUtil() to 
// find out whether num is palindrome or not 
int isPal(int num) 
{ 
    // If num is negative, make it positive 
    if (num < 0) 
       num = -num; 
  
    // Create a separate copy of num, so that modifications made 
    // to address dupNum don't change the input number. 
    int *dupNum = new int(num); // *dupNum = num 
  
    return isPalUtil(num, dupNum); 
}

void eratosthenesSieve(vector<int>* primes, vector<int>* pals, int maxPrimeNum){
  int length = maxPrimeNum - 1;
  int allNumbers[length];
 
  // Initialize array of all possible prime numbers until maxPrimeNum
  for (int i = 2; i <= maxPrimeNum; i++){
    allNumbers[i-2] = i;
  }
 
  // Adds all and only prime numbers from allNumbers to primeNumbers
  int primePosition = 0;
  for (int i = 0; i < length; i++){
    if (allNumbers[i] == 0) continue;
     
    int primeNumber = allNumbers[i];
    primes->push_back(primeNumber);
    if (isPal(primeNumber)){
        pals->push_back(primeNumber);
    }
    primePosition++;
     
    for (int j = i; j < length; j += primeNumber){
      allNumbers[j] = 0;
    }
  }
}

int product(int n){
    std::string s = std::to_string(n);

    int sum = 1;

    for (int i = 0; i < s.length(); i++){
        if (s.at(i) != '0'){
            sum *= s.at(i) - '0';
        }
    }

    return sum;
}

int main(){
    vector<int> primes;
    vector<int> pals;

    eratosthenesSieve(&primes, &pals, 1000000);

    int cases;
    cin >> cases;

    for (int s = 0; s < cases; s++){
        int n;
        cin >> n;

        cout << pals.at(n - 1) << " ";
        cout << primes.at(product(pals.at(n - 1)) - 1) << endl;
    }
}
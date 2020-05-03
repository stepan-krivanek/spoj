#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int num_of_houses;
    cin >> num_of_houses;

    while (num_of_houses != 0){
        int input;
        long long int min_work = 0;
        long long int bottles_carried = 0;
        for (int i = 0; i < num_of_houses - 1; i++){
            cin >> input;
            bottles_carried += input;
            min_work += abs(bottles_carried);
        }

        cin >> input;
        cout << min_work << endl;
        cin >> num_of_houses;
    }

    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int num_of_inputs;
    cin >> num_of_inputs;

    unsigned int input;
    for (int i = 0; i < num_of_inputs; i++){
        cin >> input;
        if (input < 10){
            if (input == 0){
                cout << 10 << endl;
            } else {
                cout << input << endl;
            }
            continue;
        }

        int exp = 0;
        int output = 0;
        for (int j = 9; j >= 2; j--){
            while (input % j == 0){
                input /= j;
                output += pow(10, exp) * j;
                exp++;
            }
        }

        if (input == 1){
            cout << output << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
#include <iostream>
using namespace std;

int main(){
    int input;
    cin >> input;

    while (input != 0){
        int permutation[input];
        bool isAmbiguous = true;

        for (int i = 0; i < input; i++){
            cin >> permutation[i];
        }

        for (int i = 0; i < input; i++){
            if (permutation[permutation[i] - 1] != (i + 1)){
                isAmbiguous = false;
                break;
            }
        }

        if (isAmbiguous){
            cout << "ambiguous" << endl;
        } else {
            cout << "not ambiguous" << endl;
        }

        cin >> input;
    }

    return 0;
}
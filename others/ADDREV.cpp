#include <iostream>
#include <string>
using namespace std;

int reverse_num(int num){
    string s = to_string(num);
    int length = s.length();
    char s2[length];

    for (int i = 0; i < length; i++){
        s2[i] = s[length-1-i];
    }

    return atoi(s2);
}

int main(){
    int num_of_inputs;
    cin >> num_of_inputs;

    int num1, num2;
    for (int i = 0; i < num_of_inputs; i++){
        cin >> num1 >> num2;
        num1 = reverse_num(num1);
        num2 = reverse_num(num2);

        cout << reverse_num(num1 + num2) << endl;
    }


    return 0;
}
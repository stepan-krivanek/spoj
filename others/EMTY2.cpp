#include <iostream>
using namespace std;

int main(){
    int num_of_cases;
    cin >> num_of_cases;

    int test_case = 0;
    string s;
    while (test_case++ < num_of_cases){
        cin >> s;
        
        int num = 0;
        bool emptyable = true;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '1'){
                num += 2;
            } else {
                num--;
            }

            if (num < 0){
                emptyable = false;
                break;    
            }
        }
        
        if (num != 0){
            emptyable = false;
        }

        string answer = "yes";
        if (!emptyable){
            answer = "no";
        }

        cout << "Case " << test_case << ": " << answer << endl;
    }

    return 0;
}
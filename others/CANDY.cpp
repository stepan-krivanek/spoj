#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int num_of_packets;
    cin >> num_of_packets;

    while (num_of_packets != -1){
        int packets[num_of_packets];

        float sum = 0;
        for (int i = 0; i < num_of_packets; i++){
            cin >> packets[i];
            sum += packets[i];
        }

        float average = sum/num_of_packets;
        if (average != ceil(average)){
            cout << -1 << endl;
            cin >> num_of_packets;
            continue;
        }

        sum = 0;
        int num_of_candy;
        for (int i = 0; i < num_of_packets; i++){
            if (packets[i] > average){
                sum += packets[i] - average;
            }
        }

        cout << sum << endl;
        cin >> num_of_packets;
    }

    return 0;
}
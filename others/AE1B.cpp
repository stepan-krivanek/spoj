#include <iostream>
using namespace std;

int partition(int *a,int start,int end){
    int pivot = a[end];
    //P-index indicates the pivot value index

    int P_index = start;
    int i,t; //t is temporary variable

    //Here we will check if array value is 
    //less than pivot
    //then we will place it at left side
    //by swapping 

    for (i = start; i < end; i++){
        if(a[i] <= pivot){
            t = a[i];
            a[i] = a[P_index];
            a[P_index] = t;
            P_index++;
        }
    }
    //Now exchanging value of
    //pivot and P-index
    t = a[end];
    a[end] = a[P_index];
    a[P_index] = t;

    //at last returning the pivot value index
    return P_index;
}

void quicksort(int *a,int start,int end){
    if(start < end){
        int P_index = partition(a,start,end);
        quicksort(a,start,P_index-1);
        quicksort(a,P_index+1,end);
    }
}

int main(){
    int num_of_boxes, screws_per_table, tables_needed;
    cin >> num_of_boxes >> screws_per_table >> tables_needed;
    
    int screws_needed = screws_per_table * tables_needed;
    int boxes[num_of_boxes];

    for (int i = 0; i < num_of_boxes; i++){
        cin >> boxes[i];
    }

    int last_index = num_of_boxes - 1;
    quicksort(boxes, 0, last_index);

    int boxes_needed = 1;
    int num_of_screws = boxes[last_index];
    while (num_of_screws < screws_needed){
        num_of_screws += boxes[last_index - boxes_needed];
        boxes_needed++;
    }

    cout << boxes_needed << endl;
    return 0;
}
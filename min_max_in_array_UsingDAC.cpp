#include<iostream>
using namespace std;
// find min max in array linear algo
int minmax[2];

int* findmin(int arr[],int n){
    minmax[0] = arr[0];
    minmax[1] = arr[0];

    for(int i=1; i<n;i++){
        if(arr[i] < minmax[0])
            minmax[0] = arr[i];
        else {
            if(arr[i] > minmax[1])
                minmax[1]= arr[i];
        }
    }
    return minmax;
}
// using DAC
struct MinMax {
    int min;
    int max;
};

MinMax DACminmax(int arr[],int start, int end){
    MinMax mm, mmLeft, mmRight;
    int* minmax = new int[2]{arr[start],arr[start]};
    // n is smaller
    if(start == end){
        mm.min = arr[start];
        mm.max = arr[start];
        return mm;
    }
    else if(start == end-1) {
        if(arr[start] > arr[end]) {
            mm.min = arr[end];
            mm.max = arr[start];
        }
        else {
            mm.min = arr[start];
            mm.max = arr[end];
        }
    }
    //  n is larger
    else {
        int mid = ((end - start) + start) / 2;
        mmLeft = DACminmax(arr,start,mid);
        mmRight = DACminmax(arr,mid+1,end);

        // finding min and max from solution of sub problem
        if(mmLeft.min < mmLeft.min)
            mm.min =mmLeft.min;
        else 
            mm.min = mmRight.min;
        if(mmLeft.max < mmRight.max)
            mm.max = mmRight.max;
        else 
            mm.max = mmLeft.max;
    }
    
    return mm;
}
int main(){
    int arr[5] = {4,1,8,0,1};
    // int * mm = findmin(arr,5);
    // cout << mm[0]<< " " << mm[1] << endl;
    // delete [] mm;

    MinMax result = DACminmax(arr,0,4);
    cout<< result.max << " " << result.min << endl;
return 0;
}
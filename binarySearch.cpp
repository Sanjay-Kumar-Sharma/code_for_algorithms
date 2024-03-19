
// Application of divide and conquere 
#include<iostream>
using namespace std;

int LinearSearch(int arr[], int n, int x) {
    if(n==1){
        return (arr[0]==x)?1:-1 ;
    }
    else {
        for(int i=0; i<n; i++) {
            if(arr[i] == x)
                return i+1;
        }
    }
    return -1; 
}

int BinarySearch(int arr[],int start, int end, int x) {
    // first case when input is samller
    if(start == end ){
        if(arr[start] == x)
            return start;
    }
    else {
        int mid = ( start + end ) / 2;
        if(arr[mid] == x )
            return mid;
        else if (arr[mid] < x)
            start = mid + 1;
        else 
            end = mid - 1 ;
        
        return BinarySearch(arr,start,end,x);
    }
    
}
int main(){
    int ar[] = {2,1,0,9,5,4};
    cout << LinearSearch(ar,6,9) << endl;
    cout << BinarySearch(ar,0,5,9) << endl;
return 0;
}
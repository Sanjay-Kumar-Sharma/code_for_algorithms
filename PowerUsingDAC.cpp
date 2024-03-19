
// Application of divide and conquere 

#include<iostream>
using namespace std;
// using DAC
int power(int a,int n) {
    // if n is smaller
    if(n == 1) {
        return a;
    }
    // when n is larger
    else{
        if(n%2 == 0) 
            return power(a,n/2) * power(a,n/2);
        else 
            return a * power(a,n/2) * power(a,n/2);
        
    }    
}
// Using DP
int power_(int a,int n) {
    // if n is smaller
    if(n == 1) {
        return a;
    }
    // when n is larger
    else{
        int  p = power(a,n/2);
        if(n%2 == 0) 
            return p * p;
        else 
            return a * p * p;
        
    }    
}
int main(){
    cout << power_(3,3);

return 0;
}
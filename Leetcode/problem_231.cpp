#include<iostream>
#include<vector>
using namespace std;

bool isPowerOfTwo(int n) {//4
    if(n<=0) return false;

    while(n%4==0){
        n=n/4;
    }
    return n==1;
   
}
int main(){
    int n= 8;
    int ans =isPowerOfTwo(n);
    cout<< ans;
}
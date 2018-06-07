#include<iostream>

using namespace std;

int main()
{
    int i , j,temp;
    int a[] = {5,16,2,15,3};
    for(i = 1; i<5; i++){
        temp = a[i];
        j = i-1;
        while(j>= 0 && a[j] > temp){
            a[j+1] = a[j];
            j=j-1;
        }
        a[j+1] = temp;
    }
    for(i = 0; i<=4; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

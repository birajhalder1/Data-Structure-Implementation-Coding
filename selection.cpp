#include<iostream>

using namespace std;
void selection_sort(int [], int);
int main()
{
    int a[] = {100,11,200,33,444,50,6};
    selection_sort(a,7);
    for(int i = 0; i<=6; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

int MIN(int a[], int n, int k){
    int LOC,MIN;
    MIN = a[k];
    LOC = k;
    for(int i = k+1; i <=n-1; i++){
        if(MIN > a[i]){
            MIN = a[i];
            LOC = i;
        }
    }
    return LOC;
}

void selection_sort(int a[], int n){
    int LOC,temp;
  for(int i = 0; i <=n-2; i++){
    LOC = MIN(a,n,i);
    temp = a[i];
    a[i] = a[LOC];
    a[LOC] = temp;
  }
}

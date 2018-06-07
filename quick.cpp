#include<iostream>

using namespace std;

void swap_el(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int partition (int a[], int p, int r){
    int x = a[r];
    int i = p-1;
    for(int j = p; j<=r-1; j++)
    {
        if(a[j]<= x){
            i++;
            swap_el(&a[i],&a[j]);
        }
    }
    swap_el(&a[i+1],&a[r]);
    return i+1;
}


void quick_sort(int a[], int p, int r){
    if(p<r){
        int pi = partition(a,p,r);

        quick_sort(a,p,pi-1);
        quick_sort(a,pi+1,r);
    }
}

int main()
{
    int a[] = {5,16,2,15,3};
    quick_sort(a,0,4);
    for(int i = 0 ; i<=4; i++){
        cout<<a[i]<<" ";
    }
}

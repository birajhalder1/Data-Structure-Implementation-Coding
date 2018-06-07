#include<iostream>
#include<cmath>

using namespace std;

void swap_el(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
void Heapify(int a[],int n, int i)
{
    int lar;
    int l = 2*i;
    int r = (2*i)+1;
    if(l<n && a[l] >a[i])  lar = l;
    else    lar = i;
    if(r<n &&a[r] > a[lar])   lar = r;
    if(lar != i){
        swap_el(&a[i],&a[lar]);
        Heapify(a,n,lar);
    }
}
/*
void max_heap(int a[],int n)
{
    int heap_size = n;
    for(int i = floor(n/2); i>=1; i--)
        Heapify(a,i);
}

heapExtractmax(int a[],int n)
{
    int heap_size = n;
    int max_el = a[1];
    a[1] = a[heap_size];
    heap_size = heap_size-1;
    max_heap(a,heap_size);
}
*/

void heap_sort(int a[], int n)
{
    for(int i = n/2 -1; i>=0; i--)
        Heapify(a,n,i);
    for(int i = n-1; i>=0; i--)
    {
        swap_el(&a[0],&a[i]);
        Heapify(a,i,0);
    }
}
int main()
{
    int a[] = {5,4,3,2,1};
    heap_sort(a,5);
    for(int i = 0; i<=4; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}


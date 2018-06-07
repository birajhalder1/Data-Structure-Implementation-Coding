#include<iostream>

using namespace std;
void bubble_sort(int [], int);
int main()
{
    int a[] = {0,1,2,3,4,5,6};
    bubble_sort(a,7);
    for(int i = 0; i<=6; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

void bubble_sort(int a[], int n){
    int r,i,temp,flag;
    for(r = 1 ; r<=n-1; r++){
        flag = 0;
        for(i = 0; i<=n-1-r; i++)
            if(a[i]>a[i+1]){
                flag = 1;
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
            if(flag == 0) {
                    cout<<r<<" "<<"round"<<endl;
                    return;
            }

    }

}

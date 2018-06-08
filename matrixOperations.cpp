#include<iostream>

using namespace std;

void search_el(int mat[4][4],int n, int x)
{
    int i = 0, j = n-1;
    while(i<n && j>=0)
    {
        if(mat[i][j] == x)  {
            cout<<"Found at "<<i<<" , "<<j<<endl;
            return;
        }
        if(x < mat[i][j])   j--;
        if(x > mat[i][j])   i++;
    }
    cout<<"Not Found"<<endl;
}

int main()
{
     int mat[4][4] = {  {10, 20, 30, 40},
                        {15, 25, 35, 45},
                        {27, 29, 37, 48},
                        {32, 33, 39, 50},
                     };
    search_el(mat, 4, 50);
    return 0;
}

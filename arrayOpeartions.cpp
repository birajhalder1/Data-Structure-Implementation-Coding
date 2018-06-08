#include<iostream>

using namespace std;


int sum(int a[], int n)
{
    if(n <= 0)  return 0;
    return (sum(a,n-1) + a[n-1]);
}
bool is_present(int a[], int n, int x){
    if(n <= 0)  return false;
    if(x == a[n])   return true;
    return is_present(a,n-1,x);
}

int findex(int a[], int n, int x)
{
    if(n == 0)  return -1;
    if(a[0] == x)   return 0;
    int ans = findex(a+1,n-1,x);
    if(ans== -1)    return -1;
    else    return ans +1;

}
int lastIndex(int input[], int size, int x) {
  if(size == 0)	return -1;
  int ans = lastIndex(input+1,size-1,x);
  if(ans == -1){
    if(input[0] == x)
      return ans+1;
    else
    return ans;
  }
  return -1;

}


int main()
{
    int a[] = {5,6,5,5,6};
    /*cout<<sum(a,5)<<endl;
    cout<<is_present(a,5,2)<<endl;
    cout<<findex(a,5,1)<<endl;*/
    cout<<lastIndex(a,5,5)<<endl;
    return 0;
}

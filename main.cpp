#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
  int n1 = mid-start+1;
  int n2 = end-mid;
  int l[n1],m[n2];
  for (int i = 0; i < n1; ++i){
    l[i]= arr [start+i];
  }
  for(int j = 0; j <n2; ++j) {
    m[j]=arr[mid+j];
  }

  int i=0;
  int j=0;
  int k = start;
  while(i<n1&&j<n2) {
    if(l[i]<m[j]) {
      arr[k] = l[i];
      k++;
      i++;
    }
    else {
      arr[k]=m[j];
      k++;
      i++;
    }
  }
  while(i<n1) {
    arr[k]=l[i];
    k++;
    i++;
  }
  while(j<n2) {
    arr[k]=m[j];
    k++;
    i++;
  }
}

void mergesort(int arr[], int start, int end)
{
  if (start<end)
  {
    int mid=(start+end)/2;
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);
    merge(arr, start, mid, end);
  }
}

void display(int arr[], int n)
{
  for (int i =0; i <n; i++) 
  {
    cout << arr[i]<<" ";
  }
  cout << endl;
}

int main() {
  int n;
  cout << "enter the size of the array:"<<endl;
  cin>>n;
  cout<<"enter the elements of the array: "<<endl;
  int arr[n];
  for(int i=0; i<n; i++)
  {
    cin>>arr[i];
  }
  cout<<"array as it is:"<<endl;
  display(arr, n);
  cout<<"sorted array:"<<endl;
  mergesort(arr,0, n-1);
  display(arr, n);

  return 0;
}
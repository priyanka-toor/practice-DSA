#include<iostream>
using namespace std;
void swap(int a[],int i , int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
 int partition(int a[],int s,int e){
     int x=a[s];
   
    
     int i=s+1;
    int j=e;
      do{
    if(a[i]<=x){
        i++;
    }
    if(a[j]>x){
        j--;
    }
   if(i<j){
   swap(a,i,j);
  }
  }while(i<j);
  swap(a,s,j);
return j;
 }
 void quick_sort(int a[] , int s , int e){
    if(s<e){
     int p=partition(a,s,e);
     //cout<<p<<endl;
     quick_sort(a,s,p-1);
     quick_sort(a,p+1,e);
    }
 }
int main()
{
    int n;
	 cout<<"Enter the size of an array"<<endl;
	 cin>>n;	
    int a[n];
	 cout<<"Enter array elment :"<<endl;
	 for(int i=0;i<n;i++)
	 {
	 	cin>>a[i];
	 }
  
	  quick_sort(a,0,n-1);
	  cout<<"Sorted array : ";
	  for(int i=0;i<n;i++)
	  {
     	cout<<a[i]<<" ";
	  }	
    return 0;
}
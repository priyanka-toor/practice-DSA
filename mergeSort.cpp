#include<iostream>
using namespace std;
void merge(int a[],int p, int q, int r)
{
	int n1=q-p+1;
	int n2=r-q;
	
	int b[n1];
	int c[n2];
	
	for(int i=0;i<n1;i++)
	{
		b[i]=a[p+i];
	}
	for(int i=0;i<n2;i++)
	{
		c[i]=a[q+1+i];
	}
	int i=0;
	int j=0;
	int k=p;
	while(i<n1&&j<n2)
	{
		if(b[i]<c[j])
		{
			a[k]=b[i];
			k++;
			i++;
		}
		else
		{
		 	a[k]=c[j];
			k++;
			j++;	
		}
	}
	while(i<n1)
	{
		a[k]=b[i];
		k++;
		i++;
	}
		while(j<n2)
	{
		a[k]=c[j];
		k++;
		j++;
	}
}
void merge_sort(int a[] , int p , int r)
{
	if(p<r)
	{
		int q=(p+r)/2;                // here q is mid term
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		
		merge(a,p,q,r);
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
	 merge_sort(a,0,n-1);
	 cout<<"Sorted array : ";
	 for(int i=0;i<n;i++)
	 {
    	cout<<a[i]<<" ";
	 }	
}
 
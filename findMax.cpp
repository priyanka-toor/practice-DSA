#include<iostream>
using namespace std;
int max(int a[], int n){
    int temp;
    if(n<=0){
        return -1;
    }
    
    	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
    return a[n-1];
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m=max(a,n);
    cout<<m;
    return 0;
}
#include<iostream>
using namespace std;
int subsetSumToK(int a[], int n ,int o[][20], int k){
     if(n==0)
    {
        if(k==0)
        {
            o[0][0]=0;
            return 1;
        }
        else
            return 0;
    }

    int smallOutput1=subsetSumToK(a+1,n-1,o,k);
    int smallOutput2=subsetSumToK(a+1,n-1,o+smallOutput1,k-a[0]);
    
    int smallOutputSize=smallOutput1+smallOutput2;
    for(int i=smallOutput1;i<smallOutputSize;i++)
    {
        for(int j=o[i][0];j>0;j--)
        {
            o[i][j+1]=o[i][j];
        }
        o[i][1]=a[0];
        o[i][0]++;
    }
    return smallOutputSize;
}
int main()
{
     int n, output[35][20],k;
  cin>>n;
  int a[n];
  for(int i=0; i < n; i++){
    cin>>a[i];
  }
     cin >> k;
  
  int size = subsetSumToK(a, n, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
    return 0;
}
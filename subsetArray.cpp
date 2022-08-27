#include<iostream>
using namespace std;
int subset(int a[] , int n , int o[][20]){
if(n==0){
    o[0][0]=0;
    return 1;
}
int size = subset(a+1,n-1,o);
for( int i = 0; i < size; i++) {
    int c=o[i][0]+1;
     o[i+size][0]=c;
     o[i+size][1]=a[0]; 
	for( int j = 2; j <= c; j++) { 
	//o[i][0]=size;
   // o[i+1][j]=a[j-1];
    o[i+size][j] = o[i][j-1];
    }
  }
   return 2*size;
}
int main()
{
    int n, output[35][20];
  cin>>n;
  int a[n];
  for(int i=0; i < n; i++){
    cin>>a[i];
  }
  int size = subset(a, n, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
    return 0;
}
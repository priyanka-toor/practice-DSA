#include<iostream>
using namespace std;
void swap(int a[],int i , int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void reverse(int a[] , int n, int s){
	int b[20];
    for(int i=n-1;i>=0;i--){
        b[n-i-1]=a[i];
    }
}
// 3rd approach
void rotate(int a[], int d, int n){
     int b[20];
     for(int i=n-1;i>=0;i--){
         b[n-i-1]=a[i];
     }
	 int c[20];
	for(int i=n-d-1;i>=0;i--){
    c[n-d-i-1]=b[i];
	}
	int e[20];
	for(int i=n-1;i>=n-d;i--){
      e[i-d+1]=b[i];
	}
	for(int i=0;i<n-d;i++){
		a[i]=c[i];
	}
	for(int i=n-d;i<n;i++){
		a[i]=e[i];
	}

	// reverse(a,n,0);
	// reverse(a,n-d,0);
	// reverse(a,n,n-d);
	
    
}
// 2nd approach 
// void rotate(int a[], int d, int n){
//     int b[20];

//     for(int i=0;i<d;i++){
//      b[i]=a[i];
//     }
//     for(int i=0;i<n-d;i++){
//         a[i]=a[i+d];
//     }
//     for(int i=n-d;i<n;i++){
//         a[i]=b[i-(n-d)];
//     }
// }
int main()
{
    int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}
    return 0;
}
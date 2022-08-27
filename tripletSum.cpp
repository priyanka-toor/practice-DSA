#include<iostream>
using namespace std;
int tripletSum(int a[] , int n , int x){
   int count=0;
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        for(int k=j+1;k<n;k++){
        if(x==a[i]+a[j]+a[k]){
            count++;
        }
        }
    }
}
return count;
}
int main()
{
    int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;
        

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

    return 0;
}
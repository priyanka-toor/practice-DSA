#include<iostream>
using namespace std;
int findDuplicate(int a[] , int n){
    int sum=0;
    for(int i=0;i<n;i++){
       sum=sum+a[i];
    }
    int num = ((n-2)*(n-1))/2;
    int answer=sum-num;
    return answer;
}
// int findDuplicate(int a[] , int n){
//     if(a[0]==a[1]){
//         return a[0];
//     }
//     else
//     {
//      int temp;
//      for(int i=1;i<n;i++){
//          if(a[0]==a[i]){
//              temp=a[0];
//              return temp;
//          }
//      }
//     }
// int t=findDuplicate(a+1,n-1);
// return t;
// }
// int findDuplicate(int a[] , int n){
  
//        // iterative 
//     int temp;
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(a[i]==a[j])
//             {
//                 temp=a[i];
                
//             }
//         }
//     }
//     return temp;
  
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

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	
    return 0;
}
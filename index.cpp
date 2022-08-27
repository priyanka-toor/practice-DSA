#include<iostream>
using namespace std;
int allIndexes(int input[],int n,int x,int output[]){
    if(n==0){
            return 0;
        }
   int size=allIndexes(input,n-1,x,output);
   cout<<size<<endl;
    if(input[n-1]==x){
        output[size]=n-1;
        return  size+1;
        }
      //  int size=allIndexes(input,n-1,x,output);
       
        
        return size;
}
  

int main()
{
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    cout<<size<<endl;
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    return 0;
}
#include<iostream>
using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;
    int **p=new int*[r];
    for(int i=0;i<r;i++){
        p[i]=new int[c];  // this line mean that I add 'c' columns in each  'r' row
        for(int j=0;j<c;j++){
         cin>>p[i][j];
        }
    }
    for(int i=0;i<r;i++){
   for(int j=0;j<c;j++){
       cout<<p[i][j]<<" ";
   }
   cout<<endl;
    }
    for(int i=0;i<r;i++){
        delete [] p[i];           // first it delete the memory of  each row
    }
    delete [] p; // then after it delete the  memory of array where address of all the rows are stored 
    cout<<"\n After delelting the memory : "<<endl;
       for(int i=0;i<r;i++){
   for(int j=0;j<c;j++){
       cout<<p[i][j]<<" ";
   }
    cout<<endl;
    }
    return 0;
}
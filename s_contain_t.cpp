#include<iostream>
#include<string.h>
using namespace std;
bool checksequenece(char l[] , char s[]){
   
   if( strlen(s)> strlen(l)){
	   return false;
   }
   int j = 0; 
 
    
    for (int i = 0; i < strlen(l) && j < strlen(s); i++){
        if (s[j] == l[i])
            j++;
	}
   
    return (j == strlen(s));
}
int main()
{
    char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";
    return 0;
}
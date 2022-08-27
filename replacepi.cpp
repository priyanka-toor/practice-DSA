#include <iostream>
#include <string.h>
using namespace std;

void pi(char c[])
{
  int l = strlen(c);
  if (c[0] == '\0')
  {
    return;
  }

  if (c[0] == 'p' && c[1] == 'i')
  {
    // c[l+1]=c[l-1];
    c[0] = '3';
    c[1] = '.';

    for (int i = l + 2; i > 1; i--)
    {
      c[i] = c[i - 2];
    }
    c[2] = '1';
    c[3] = '4';
    pi(c);
  }
else
  pi(c + 1);
}
int main()
{
  char c[50];
  cin >> c;
  pi(c);
  cout << c;
  return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
inline bool prime(unsigned int n)
{
  int i,b;
  b=sqrt(n);
  bool k=1;
  if(n%6==1||n%6==5)
  {
    for(i=5;i<=b;i=i+2)if(n%i==0){k=0;break;}
  }
  else k=0;
  return k;
}
inline unsigned int count(const unsigned int c)
{
  int j,a=1;
  if(c==1)return 2;
  else if(c==2)return 3;
  else
  {
    a=3;
    for(j=3;a<=c;j=j+2)if(prime(j))++a;
    return j-2;
  }
}
inline int getstr(int N,char arr[])
{
  int c,i=0;
  c=getchar();
  while(c!='\n'&&c!=EOF&&i<N)
  { 
       arr[i]=c;
       c=getchar();
       i++;
  }
  arr[i]='\0';
  fflush(stdin);
  return i;
}
int main()
{
  int i,j,k,n,m,w,s;
  int arr1[5][100];
  char arr[5][100];
  scanf("%d",&n);
  scanf("%d",&m);
  scanf("%d",&w);
  for(i=0;i<=m;++i)
  {
    getstr(100,arr[i]);
  }
  if(n<10)s=((w+n)%count(n))%26;
  else s=(w+n)%26;
  for(k=0;k<=m;++k)
  {
    for(j=0;j!=strlen(arr[k]);++j)
    {
      if(arr[k][j]==32)printf(" ");
      else
      {
        arr1[k][j]=arr[k][j]-97;
        if(arr1[k][j]-s<0)printf("%c",(26+arr1[k][j]-s)+97);
        else printf("%c",((arr1[k][j]-s)%26)+97);
      }
    }
    if(k>0)printf("\n");
  }
  return 0;
}

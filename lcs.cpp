#include<iostream>
using namespace std;
int m,n;
int printlcs(char b[20][20], char str1[],int i, int j)
{
    if (i==0 || j==0)
        return 0;
    else
    {
    if(b[i][j] == 'd')
   {
       printlcs(b,str1,i+1,j+1);
       cout<<str1[i];
   }
   if(b[i][j] == 'u')
   {
       printlcs(b,str1,i+1,j);

   }
   if(b[i][j] == 'l')
   {
       printlcs(b,str1,i,j+1);

   }
   return 1;
   }

}
int main()
{
    int i,j;
    cout<<"Enter length of first string\t";
    cin>>m;
    cout<<"Enter length of second string\t";
    cin>>n;
    int c[20][20]; char b[20][20]; char str1[m+1]; char str2[n+1];
    cout<<"Enter string 1:\n";
    str1[0]='0'; str2[0]='$'; c[0][0]=0;
    for(i=1; i<=m; i++)
    {
        cin>>str1[i];
        c[i][0]=0;
    }
    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
        {
            c[i][j]=0;
            b[i][j]=' ';
        }
    }
    cout<<"Enter string 2:\n";
    for(j=1; j<=n; j++)
    {
        cin>>str2[j];
        c[0][j]=0;
    }
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
           if(str1[i] == str2[j])
           {
               c[i][j]=c[i-1][j-1]+1;
               b[i][j]='d';
           }
           else if(c[i-1][j] >= c[i][j-1])
           {
               c[i][j]=c[i-1][j];
               b[i][j]='u';
           }
           else
           {
               c[i][j]=c[i][j-1];
               b[i][j]='l';
           }
        }
    }


    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
        cout<<endl;
     for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Length of LCS of String 1 and 2 = "<<c[m][n];
    cout<<endl;
    cout<<"Longest common subsequence is :\n";
    int b1=printlcs(b,str1,1,1);

    return 0;
}

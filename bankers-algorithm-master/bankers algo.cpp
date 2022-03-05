#include<bits/stdc++.h>
using namespace std;
#define p 5
#define r 3
 void bank(int al[p][r],int ma[p][r],int av[r] )
{
    int ne[p][r],c=0,s[p];
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            ne[i][j]=ma[i][j]-al[i][j];
        }
    }

    while(c!=p)
 {
     int f=0;
    for(int i=0;i<p;i++)
    {
       int cnt=0;
        for(int j=0;j<r;j++)
        {
            if(ne[i][j]<=av[j])
            {
                cnt++;
            }
        }
        if(cnt==r)
        {
            for(int j=0;j<r;j++)
            {
                av[j]+=al[i][j];
                ne[i][j]=INT_MAX;
            }
            s[c++]=i;
            f=1;
        }
    }
    if(!f)
    {
        cout<<"safe sequence not found\n";
        return;
    }

}
int i;
    cout<<"safe sequence is: ";
    for(i=0;i<p-1;i++)
        cout<<s[i]<<" ";
        cout<<" "<<s[p-1];
        return;
}
int main()
{
      int av[] = {1,5,2};

      int al[][r] = {{0,0,1},
                     {1,0,0},
                     {1,3,5},
                     {0,6,3},
                     {0,0,1}};

    int ma[][r] = {{0,0,1},
                      {1,7,5},
                      {2,3,5},
                      {0,6,5},
                      {0,6,5}};

    bank(al,ma,av);
}

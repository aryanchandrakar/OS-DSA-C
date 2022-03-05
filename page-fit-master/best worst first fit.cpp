#include<bits/stdc++.h>
using namespace std;
void worstFit(int b[], int m, int p[],int n)
{
    int a[n];
    memset(a, -1, sizeof(a));
    for (int i=0; i<n; i++)
    {
        int w = -1;
        for (int j=0; j<m; j++)
        {
            if (b[j] >= p[i])
            {
                if (w == -1)
                    w = j;
                else if (b[w] < b[j])
                    w = j;
            }
        }
        if (w != -1)
        {
            a[i] = w;
            b[w] -= p[i];
        }
    }
    cout << "\nProcess \tProcess Size\tBlock index\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t" << p[i] << "\t\t";
        if (a[i] != -1)
            cout << a[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
void bestFit(int b[], int m, int p[], int n)
{
    int a[n];
    memset(a, -1, sizeof(a));
    for (int i=0; i<n; i++)
    {
        int w = -1;
        for (int j=0; j<m; j++)
        {
            if (b[j] >= p[i])
            {
                if (w == -1)
                    w = j;
                else if (b[w] > b[j])
                    w = j;
            }
        }
        if (w != -1)
        {
            a[i] = w;
            b[w] -= p[i];
        }
    }
    cout << "\nProcess \tProcess Size\tBlock index\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t" << p[i] << "\t\t";
        if (a[i] != -1)
            cout << a[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
void firstFit(int b[], int m,int p[], int n)
{
    int a[n];
    memset(a, -1, sizeof(a));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[j] >= p[i])
            {
                a[i] = j;
                b[j] -= p[i];

                break;
            }
        }
    }

    cout << "\nProcess \tProcess Size\tBlock index\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << "\t\t"
             << p[i] << "\t\t";
        if (a[i] != -1)
            cout << a[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
    cout<<"enter the choice wanted to execute \n 1. worst fit \n 2. best fit \n 3. first fit\n";
    int x;
    cin>>x;
    if(x==1){
    int b[5],p[4];
    cout<<"enter block size: ";
    for(int i=0;i<5;i++)
    {cin>>b[i];}
    cout<<"enter process size to allocate: ";
    for(int j=0;j<4;j++)
    {
        cin>>p[j];
    }
    int v = sizeof(b)/sizeof(b[0]);
    int t = sizeof(p)/sizeof(p[0]);
    cout<<"\n worst fit ";
    worstFit(b, v, p, t);}


    if(x==2){
    int b[5],p[4];
    cout<<"enter 5 block size: ";
    for(int i=0;i<5;i++)
    {cin>>b[i];}
    cout<<"enter 4 process size to allocate: ";
    for(int j=0;j<4;j++)
    {
        cin>>p[j];
    }
    int va = sizeof(b)/sizeof(b[0]);
    int ta = sizeof(p)/sizeof(p[0]);
    cout<<"\n best fit ";
    bestFit(b, va, p, ta);}


    if(x==3){
    int b[5],p[4];
    cout<<"enter 5 block size: ";
    for(int i=0;i<5;i++)
    {cin>>b[i];}
    cout<<"enter 4 process size to allocate: ";
    for(int j=0;j<4;j++)
    {
        cin>>p[j];
    }
    int vz = sizeof(b)/sizeof(b[0]);
    int tz = sizeof(p)/sizeof(p[0]);
    cout<<"\n first fit ";
    firstFit(b, vz, p, tz);}

    return 0 ;
}


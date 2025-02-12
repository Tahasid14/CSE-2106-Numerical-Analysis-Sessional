#include<iostream>

using namespace std;

double x[10];
double y[10][10];

void Forward_diff(int n)
{
    for(int i=1;i<n;i++)
    {
    for(int j=0; j<n-i;j++)
    {
     y[ j ] [ i ] = y[j+1][ i-1] - y[ j ][ i-1];
    }
    }
}
void Forward_table(int n)
{
 for(int i=0;i<n;i++)
 {
     cout<<x[i];

     for(int j=0;j<n-i;j++)
     {
       cout<<"\t" <<y[i][j];
     }
     cout<<endl;
 }
}
signed main()
{
    int n;cin>>n;

    for(int i=0;i<n;i++)
    {
     cout << "x[" << i << "] = "; cin >> x[ i ];

     cout << "y[" << i <<"][0] = "; cin >> y[ i ][ 0];
    }
    Forward_diff(n);

    Forward_table(n);

    return 0;
}
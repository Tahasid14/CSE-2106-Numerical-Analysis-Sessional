#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

void print(double **a, int n)
{
    for(int i=0; i<n; i++){for(int j=0; j<n; j++)cout<<setw(10)<<a[i][j]<<' ';
    cout<<endl;}
    cout<<endl;
}

void LU_D( double **A, double **low, double **up, int n)
{   for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
        {
            low[i][j]=0;
            up[i][j]=A[i][j];
        }
        low[i][i]=1;
    }
    for(int k=0; k<n; k++)
    {
        for(int i=k+1; i<n; i++)
        {   if(up[k][k]==0) {
                cout<<"\n Error: Zero element."<<endl;
                return;
            }
            low[i][k]=up[i][k]/up[k][k];
            for(int j=k; j<n; j++){up[i][j]-=low[i][k]*up[k][j];}
        }
    }
}
int main()
{
    int m;
    cout<<"\n Enter your row & coloumn number: ";
    cin>>m;
    double **A=new double*[m];
    double **U=new double*[m];
    double **L=new double*[m];
    for(int i=0; i<m; i++)
    {
        A[i]=new double[m];
        U[i]=new double[m];
        L[i]=new double[m];
    }
    for(int i=0; i<m; i++)for(int j=0; j<m; j++)cin>>A[i][j];
    print(A,m);
    LU_D(A,L,U,m);
    print(L,m);
    print(U,m);
    for(int i=0;i<m;i++)
    {delete[] A[i];delete[] L[i]; delete[] U[i];}
    delete[] A;delete[] L; delete[] U;
    return 0;
}
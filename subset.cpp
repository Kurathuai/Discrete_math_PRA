// C++ program to check if an array is a subset of another array

#include<bits/stdc++.h>
using namespace std;

bool isSubset(int arr1[], int arr2[],
int m, int n)
{
int i = 0;
int j = 0;
for (i = 0; i < n; i++)
{
for (j = 0; j < m; j++)
{
if(arr2[i] == arr1[j])
break;
}

if (j == m)
return 0;
}

return 1;
}

int main()
{
int m,n;
cout << “\nEnter the size of array 1 : “;
cin >> m;
cout << “\nEnter the size of array 2 : “;
cin >> n;
int arr1[m],arr2[n];
int i;
cout << “\nEnter the array 1 elements : “;
for(i=0;i<m;i++)
{
cin >> arr1[i];
}
cout << “\nEnter the array 2 elements : “;
for(i=0;i<n;i++)
{
cin >> arr2[i];
}

if(isSubset(arr1, arr2, m, n))
cout << “\nArray2 is a subset of Array1\n “;
else
cout << “\nArray2 is not a subset of Array1\n”;

getchar();
return 0;
}


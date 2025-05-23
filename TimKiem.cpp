#include<bits/stdc++.h>

using namespace std;

int timKiemTuanTu(int a[], int n, int m)
{
    int i=0;
    while(i<n && a[i]!=m)
    {
        i++;
    }
    if(a[i]==m)
        return m;
    else return -1;
}

int timKiemNhiPhan(int a[], int left, int right, int m)
{
    if(left>right)
        return -1;
    else
    {
        int mid=(left+right)/2;
        if(a[mid]==m)
            return m;
        else if(a[mid]<m)
            return timKiemNhiPhan(a,mid+1,right,m);
        else return timKiemNhiPhan(a,left,mid-1,m);
    }

}

int main()
{
    int a[9] = {34, 14, 24, 54, 84, 64, 94, 74, 04};
    int x[9] = {04, 14, 24, 34, 54, 64, 74, 84, 94};
//    cout<<timKiemTuanTu(a,9,94);
//    cout<<timKiemTuanTu(a,9,55);
//    cout<<timKiemNhiPhan(a,0,8,34);

    return 0;
}

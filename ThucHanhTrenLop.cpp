#include<bits/stdc++.h>

using namespace std;

struct HocSinh
{
    string hoTen;
    string gioiTinh;
    int namSinh;
    float diemTongKet;
};

void hienThi(const HocSinh& hs)
{
    cout<<hs.hoTen<<"-"<<hs.gioiTinh<<"-"<<hs.namSinh<<"-"<<hs.diemTongKet<<"\n";
}

int timKiemNhiPhan(int a[], int left, int right, int k)
{
    if(left > right)
        return false;
    else
    {
        int mid=(left+right)/2;
        if(a[mid]==k)
            return a[left];
        else if (a[mid]<k)
            return timKiemNhiPhan(a,mid+1,right,k);
        else return timKiemNhiPhan(a,left,mid-1,k);
    }
}

int main()
{
    vector<HocSinh> danhSach =
    {
       {"Nguyen Van A","Nam",2005,9.1}
    };
    hienThi(danhSach[0]);
    return 0;
}

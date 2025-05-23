#include <bits/stdc++.h>

using namespace std;

struct HangHoa
{
    int stt;
    char maHang[10];
    char tenHang[25];
    char donViTinh[10];
    double donGia;
    int soLuong;
    double thanhTien;
};

struct Node
{
    HangHoa data;
    Node *next;
};

typedef Node* TRO;

void create(TRO &L)
{
    L = nullptr;
}

int isEmpty(TRO L)
{
    return L==nullptr;
}

TRO findMax(TRO L)
{
    TRO Q;
    TRO Max = L;
    if(!isEmpty(L))
    {
        Q=L;
        while(Q!=nullptr)
        {
            if(Q->data.soLuong>Max->data.soLuong)
                Max = Q;
            Q = Q->next;
        }
    }
    return Max;
}

TRO search(TRO L, int k)
{
    TRO Q = L;
    int i=1;
    while(Q!=nullptr &&i<k)
    {
        Q = Q->next;
        i++;
    }
    return Q;
}

void firstAdd(TRO &L, HangHoa hangHoa)
{
    TRO P = new Node;
    P->data = hangHoa;
    P->next = L;
    L=P;
}

void add(TRO &L, HangHoa hangHoa)
{
    TRO Q,P;
    P = new Node;
    P->data = hangHoa;
    P->next = nullptr;
    if(isEmpty(L))
        L=P;
    else
    {
        Q=L;
        while(Q->next!=nullptr)
            Q = Q->next;
        Q->next = P;
    }
}

void insert(TRO &L, TRO Q, HangHoa hangHoa)
{
    TRO P = new Node;
    P->data = hangHoa;
    P->next = Q->next;
    Q->next = P;
}

void deleteFirst(TRO &L)
{
    TRO Q = L;
    L = L->next;
    delete(Q);
}

void after_delete(TRO &L, TRO M)
{
    TRO Q;
    Q = M->next;
    M->next = Q->next;
    delete(Q);
}

void nhap(HangHoa &hangHoa)
{
    cout<<"Nhap so thu tu: ";
    cin>>hangHoa.stt;
    cin.ignore();
    cout<<"Nhap ma hang: ";
    cin.getline(hangHoa.maHang,10);
    cout<<"Nhap ten hang: ";
    cin.getline(hangHoa.tenHang,25);
    cout<<"Nhap don vi tinh: ";
    cin.getline(hangHoa.donViTinh, 10);
    cout<<"Nhap don gia: ";
    cin>>hangHoa.donGia;
    cin.ignore();
    cout<<"Nhap so luong: ";
    cin>>hangHoa.soLuong;
    cin.ignore();
    hangHoa.thanhTien = hangHoa.donGia * hangHoa.soLuong;
    cout<<endl;
}

void inputList(TRO &L)
{
    TRO P, Q;
    HangHoa hangHoa;
    create(L);
    int i = 1;
    do
    {
        cout<<"Nhap hang hoa thu "<<i<<endl;
        nhap(hangHoa);
        if(strcmp(hangHoa.tenHang,"dung")==0)
        {
            return;
        }
        P = new Node;
        P->data = hangHoa;
        P->next = nullptr;
        if(L==nullptr)
            L=P;
        else
        {
            Q->next = P;
        }
        Q = P;
        i++;
    }
    while(true);
}

void hienThiDanhSach(TRO L)
{
    cout<<setw(5)<<"STT"
    <<setw(15)<<"Ma hang hoa"
    <<setw(15)<<"Ten hang hoa"
    <<setw(15)<<"Don vi tinh"
    <<setw(15)<<"Don gia"
    <<setw(15)<<"So luong"
    <<setw(15)<<"Thanh tien"<<endl;
    TRO Q = L;
    int i =1;
    while(Q!=nullptr)
    {
        HangHoa hangHoa = Q->data;
        cout<<setw(5)<<i
        <<setw(15)<<hangHoa.maHang
        <<setw(15)<<hangHoa.tenHang
        <<setw(15)<<hangHoa.donViTinh
        <<setw(15)<<hangHoa.donGia
        <<setw(15)<<hangHoa.soLuong
        <<setw(15)<<hangHoa.thanhTien<<endl;
        Q=Q->next;
        i++;
    }
}

int main()
{
    TRO L;
    inputList(L);
    hienThiDanhSach(L);
    TRO Max = findMax(L);
    hienThiDanhSach(Max);
    return 0;
}

#include<bits/stdc++.h>
#define vtor vector

using namespace std;


struct SinhVien
{
    char maSV[10];
    char tenSV[20];
    char gioiTinh[10];
    char diem[10];
};

bool isEmpty (vtor <SinhVien> &ds)
{
    return ds.empty();
}

int add(vtor<SinhVien> &ds, SinhVien &sv )
{
    ds.push_back(sv);
    return 1;
}

void deleteLast(vtor<SinhVien> &ds, SinhVien &sv)
{
    if(isEmpty(ds))
    {
        cout<<"khong the xoa danh sach trong";
    }
    else
    {
        ds.pop_back();
    }
}

void nhap(SinhVien &sv)
{
    cout<<"Nhap ma hoc vien: ";
    cin.ignore();
    gets(sv.maSV);
    cout<<"Nhap ten hoc vien: ";
    cin.ignore();
    gets(sv.tenSV);
    cout<<"Nhap gioi tinh hoc vien: ";
    cin.ignore();
    gets(sv.gioiTinh);
    cout<<"Nhap diem hoc vien: ";
    cin>> sv.diem;
}

void nhapDS(vtor<SinhVien> &ds)
{
    ds.clear();
    SinhVien sv;
    int i=0;
    cout<<"nhap e de ket thuc nhap";
    cout<<"nhap thong tin hoc vien"<<endl;

    do
    {
        cout<<"nhap thong tin sinh vien thu "<<i+1<<endl;
        nhap(sv);
        if(strcmp(sv.maSV,"e") == 0) break;
        if(!add(ds, sv))
        {
            return;
        }
        i++;
    }while(true);
}

void xuat(vtor<SinhVien> &ds)
{
    if(ds.empty())
    {
        cout<<"danh sach hoc vien rong"<<endl;
        return;
    }
    cout << left << setw(5) << "STT"
              << setw(12) << "Ma SV"
              << setw(22) << "Ten SV"
              << setw(12) << "Gioi tinh"
              << right << setw(10) << "Diem TB" << endl;
    cout << string(61, '-') << endl;

    for (size_t i = 0; i < ds.size(); ++i)
    {
        cout << left << setw(5) << i + 1
                  << setw(12) << ds[i].maSV
                  << setw(22) << ds[i].tenSV
                  << setw(12) << ds[i].gioiTinh
                  << right << fixed << setprecision(1) << setw(10) << ds[i].diem << endl;
    }
}

void xoa(vector<SinhVien> &ds) {
    if (ds.empty()) {
        cout << "Danh sach rong, khong the xoa!\n";
        return;
    }

    int k;
    cout << "Nhap vi tri can xoa (1 den " << ds.size() << "): ";
    cin >> k;

    if (k < 1 || k > ds.size()) {
        cout << "Vi tri xoa khong hop le!\n";
        return;
    }
    ds.erase(ds.begin() + (k - 1));
    cout << "Da xoa sinh vien tai vi tri " << k << endl;
}

void chen(vector<SinhVien> &ds) {
    SinhVien sv_moi;
    cout << "--- Nhap thong tin sinh vien can chen ---\n";
    nhap(sv_moi);

    int k;
    cout << "Nhap vi tri can chen (1 den " << ds.size() + 1 << "): ";
    cin >> k;

    if (k < 1 || k > ds.size() + 1) {
        cout << "Vi tri chen khong hop le!\n";
        return;
    }
    ds.insert(ds.begin() + (k - 1), sv_moi);
    cout << "Da chen sinh vien vao vi tri " << k << endl;
}

void search_and_update(vector<SinhVien> &ds) {
    if (ds.empty()) {
        cout << "Danh sach rong!\n";
        return;
    }
    string ten_can_tim;
    cout << "Nhap ten hoc vien can tim de cap nhat: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, ten_can_tim);

    int found_count = 0;
    for (size_t i = 0; i < ds.size(); ++i) {
        if (ds[i].tenSV == ten_can_tim) {
            found_count++;
            cout << "--- Tim thay hoc vien sau, nhap thong tin moi ---" << endl;
            cout << "Thong tin cu: " << endl;
            cout << "Ma SV: " << ds[i].maSV << ", Ten: " << ds[i].tenSV
                      << ", Gioi tinh: " << ds[i].gioiTinh << ", Diem: " << ds[i].diem << endl;

            cout << "Nhap thong tin moi cho hoc vien nay:" << endl;
            SinhVien sv_moi;
            // Hàm nhap sẽ tự gọi cin.ignore nếu cần trước khi getline cho mã HV
            nhap(sv_moi);
            ds[i] = sv_moi;
            cout << "Da cap nhat sinh vien." << endl;
        }
    }

    if (found_count == 0) {
        cout << "Khong tim thay hoc vien nao co ten '" << ten_can_tim << "'." << endl;
    } else {
        cout << "Da cap nhat " << found_count << " hoc vien." << endl;
    }
}

int main()
{
    vector<SinhVien> dsSinhVien;
    int choice;

    do {
        cout << "\n---------- MENU ----------\n";
        cout << "1. Nhap danh sach hoc vien\n";
        cout << "2. Xuat danh sach hoc vien\n";
        cout << "3. Them hoc vien vao danh sach\n";
        cout << "4. Xoa hoc vien khoi danh sach\n";
        cout << "5. Tim kiem va cap nhat hoc vien theo ten\n";
        cout << "0. Thoat\n";
        cout << "------------------------\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
    switch (choice) {
            case 1:
                nhapDS(dsSinhVien);
                break;
            case 2:
                xuat(dsSinhVien);
                break;
            case 3:
                chen(dsSinhVien);
                break;
            case 4:
                xoa(dsSinhVien);
                break;
            case 5:
                search_and_update(dsSinhVien);
                break;
            case 0:
                cout << "Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (choice != 0);

    return 0;
}

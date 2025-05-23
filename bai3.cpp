#include<bits/stdc++.h>
using namespace std;

struct HocSinh {
    string hoTen;
    string gioiTinh;
    int namSinh;
    double diemTongKet;
};

// Hàm chuyển chuỗi sang chữ thường để so sánh
string toLowerCase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// Hàm kiểm tra nếu điểm hợp lệ
bool kiemTraDiem(double diem) {
    return diem >= 0 && diem <= 10;  // Giới hạn điểm từ 0 đến 10
}

// Hàm kiểm tra năm sinh hợp lệ
bool kiemTraNamSinh(int namSinh) {
    int namHienTai = 2025; // Giả sử năm hiện tại là 2025
    return namSinh >= 1900 && namSinh <= namHienTai;  // Năm sinh phải hợp lệ
}

// Hàm nhập danh sách học sinh
void nhapDanhSach(vector<HocSinh>& ds, int n) {
    cin.ignore(); // Xóa '\n' sau khi nhập số nguyên
    for (int i = 0; i < n; ++i) {
        HocSinh hs;
        cout << "Nhap hoc sinh thu " << i + 1 << ":\n";
        cout << "Ho ten: ";
        getline(cin, hs.hoTen);

        // Kiểm tra tên học sinh không rỗng
        if (hs.hoTen.empty()) {
            cout << "Ho ten khong duoc de trong. Vui long nhap lai.\n";
            --i;
            continue;
        }

        cout << "Gioi tinh: ";
        getline(cin, hs.gioiTinh);

        cout << "Nam sinh: ";
        cin >> hs.namSinh;
        while (!kiemTraNamSinh(hs.namSinh)) {
            cout << "Nam sinh khong hop le. Vui long nhap lai: ";
            cin >> hs.namSinh;
        }

        cout << "Diem tong ket: ";
        cin >> hs.diemTongKet;
        while (!kiemTraDiem(hs.diemTongKet)) {
            cout << "Diem khong hop le (0 <= diem <= 10). Vui long nhap lai: ";
            cin >> hs.diemTongKet;
        }

        cin.ignore(); // Xóa '\n' sau khi nhập số
        ds.push_back(hs);
    }
}

// Hàm so sánh để sắp xếp theo điểm tổng kết giảm dần
bool soSanhGiamDan(const HocSinh& a, const HocSinh& b) {
    return a.diemTongKet > b.diemTongKet;
}

// Hàm so sánh để sắp xếp theo tên học sinh
bool soSanhTheoTen(const HocSinh& a, const HocSinh& b) {
    return toLowerCase(a.hoTen) < toLowerCase(b.hoTen);
}

// Tìm kiếm tuyến tính theo họ tên và điểm
int timKiemTuyenTinh(const vector<HocSinh>& ds, string ten, double diem) {
    ten = toLowerCase(ten);
    for (int i = 0; i < ds.size(); i++) {
        if (toLowerCase(ds[i].hoTen) == ten && ds[i].diemTongKet == diem)
            return i;
    }
    return -1;
}

// Tìm kiếm nhị phân theo điểm (danh sách đã sắp giảm dần)
int timKiemNhiPhanTheoDiem(const vector<HocSinh>& ds, double diem) {
    int l = 0, r = ds.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (ds[m].diemTongKet == diem)
            return m;
        else if (ds[m].diemTongKet < diem)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

// In thông tin học sinh
void inThongTin(const HocSinh& hs) {
    cout << "Ho ten: " << hs.hoTen
         << ", Gioi tinh: " << hs.gioiTinh
         << ", Nam sinh: " << hs.namSinh
         << ", Diem TK: " << hs.diemTongKet << endl;
}

// Hàm main
int main() {
    vector<HocSinh> ds;
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;

    nhapDanhSach(ds, n);

    // Sắp xếp danh sách học sinh theo điểm giảm dần
    sort(ds.begin(), ds.end(), soSanhGiamDan);

    // Hỏi người dùng có muốn sắp xếp theo tên không
    char luaChon;
    cout << "Ban co muon sap xep theo ten hoc sinh? (y/n): ";
    cin >> luaChon;
    if (luaChon == 'y' || luaChon == 'Y') {
        sort(ds.begin(), ds.end(), soSanhTheoTen);
    }

    char tiepTuc;
    do {
        string ten;
        double diem;
        cout << "\nNhap ho ten can tim: ";
        cin.ignore();
        getline(cin, ten);
        cout << "Nhap diem tong ket can tim: ";
        cin >> diem;

        // Tìm kiếm tuyến tính
        int viTri1 = timKiemTuyenTinh(ds, ten, diem);
        if (viTri1 != -1) {
            cout << "=> Tim thay bang tuyen tinh:\n";
            inThongTin(ds[viTri1]);
        } else {
            cout << "=> Khong tim thay bang tuyen tinh.\n";
        }

        // Tìm kiếm nhị phân theo điểm
        int viTri2 = timKiemNhiPhanTheoDiem(ds, diem);
        if (viTri2 != -1) {
            cout << "=> Tim thay (nhi phan - theo diem):\n";
            inThongTin(ds[viTri2]);
        } else {
            cout << "=> Khong tim thay bang nhi phan.\n";
        }

        cout << "\nBan co muon tim tiep? (y/n): ";
        cin >> tiepTuc;

    } while (tiepTuc == 'y' || tiepTuc == 'Y');

    return 0;
}


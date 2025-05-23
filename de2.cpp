#include<bits/stdc++.h>
#define MAX 5
using namespace std;

struct SinhVien{
	string hoTen;
	string gioiTinh;
	float diemTK;

	SinhVien(string hoTen, string gioiTinh, float diemTK){
		this->hoTen = hoTen;
		this->gioiTinh = gioiTinh;
		this->diemTK = diemTK;
	}

	SinhVien(){
	}

	void display(){
		cout<<fixed;
		cout<<setw(15)<<left<<hoTen;
		cout<<setw(8)<<left<<gioiTinh;
		cout<<setw(8)<<left<<setprecision(2)<<diemTK<<endl;
	}
};

struct List{
	int count;
	SinhVien sv[MAX];
};

List L;

void create(List &L){
	L.count = -1;
}

int empty(List L){
	return L.count==-1;
}

int full(List L){
	return L.count == MAX -1;
}

int add(List &L, SinhVien sv){
	if(full(L)){
		return 0;
	}
	else{
		L.count++;
		L.sv[L.count] = sv;
		return 1;
	}
}

void taoDs(List &L){
	SinhVien sv1 = {"Pham Duc Thanh","nam",3.5};
	SinhVien sv2 = {"Nguyen Van A","nam",3.3};
	SinhVien sv3 = {"Pham Thi B","nu",3.0};
	SinhVien sv4 = {"Tran Van C","nam",3.1};
	SinhVien sv5 = {"Nguyen Nam L","nam",3.4};
	add(L,sv1);
	add(L,sv2);
	add(L,sv3);
	add(L,sv4);
	add(L,sv5);
}

void display(List L){
	for(int i = 0; i<=L.count; i++){
		L.sv[i].display();
	}
}

int searchByName(List L, string name){
	for(int i = 0; i<= L.count; i++){
		if(L.sv[i].hoTen == name) return i;
	}
	return -1;
}

int remove(List &L, int k){
	if(k>0 && k<=L.count+1){
		for(int i = k; i<=L.count; i++){
			L.sv[i-1] = L.sv[i];
		}
		L.count = L.count -1;
		return 1;
	}
		return 0;
}

int insert(List &L, int k, SinhVien sv){
	if(k>0 && k<=L.count+1 && !full(L)){
		for(int i = L.count; i>=k-1; i--){
			L.sv[i + 1] = L.sv[i];
		}
		L.sv[k-1]=sv;
		L.count++;
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	create(L);
	taoDs(L);
	cout<<"danh sach ban dau la: "<<endl;
	display(L);
	string name;
	cout<<"nhap ten sinh vien can tim: ";
	getline(cin,name);
	int index = searchByName(L,name);
	if(index!= -1){
		cout<<"thong tin sinh vien can tim la o vi tri: "<<index<<endl;
		L.sv[index].display();
		remove(L,index+1);
		cout<<"danh sach sau khi xoa la: "<<endl;
		display(L);
	}
	else{
		cout<<"sinh vien khong ton tai trong danh sach!"<<endl;
	}
	SinhVien sv6 = {"Pham Quang Huy","nam",4.0};
	insert(L,3,sv6);
	cout<<"danh sach sau khi chen la: "<<endl;
	display(L);
	return 0;
}

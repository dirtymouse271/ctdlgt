#include<bits/stdc++.h>

using namespace std;

struct SinhVien{
	string hoTen;
	string gioiTinh;
	float diemTK;
};

struct Node{
	SinhVien infor;
	Node * next;
};

typedef Node *TRO;
TRO L;
void create(TRO &L){
	L=NULL;
}

int empty(TRO L){
	return L==NULL;
}

void add(TRO &L, SinhVien sv){
	TRO P,Q;
	P = new Node;
	P->infor = sv;
	P->next = NULL;
	if(empty(L)) L = P;
	else{
		Q = L;
		while(Q->next!= NULL){
			Q = Q->next;
		}
		Q->next = P;
	}
}

void display(SinhVien sv){
	cout<<fixed;
	cout<<setw(16)<<left<<sv.hoTen;
	cout<<setw(8)<<left<<sv.gioiTinh;
	cout<<setw(8)<<left<<setprecision(2)<<sv.diemTK<<endl;
}

void taoDs(TRO &L){
	SinhVien sv1 = {"Pham Duc Thanh","nam",3.4};
	SinhVien sv2 = {"Nguyen Ngoc L","nam",3.2};
	SinhVien sv3 = {"Nguyen Thu P","nu",3.3};
	SinhVien sv4 = {"Do Minh A","nu",3.4};
	SinhVien sv5 = {"Le Hoai N","nam",3.5};
	add(L,sv1);
	add(L,sv2);
	add(L,sv3);
	add(L,sv4);
	add(L,sv5);
}

void inDanhSach(TRO L){
	TRO Q;
	if(!empty(L)){
		cout << setw(16) << left << "Ho ten"
		     << setw(8) << left << "Gioi tinh"
		     << setw(8) << left << "DiemTK" << endl;
		Q = L;
		while(Q!=NULL){
			display(Q->infor);
			Q = Q->next;
		}
	}

}

TRO searchByName(TRO L,string name){
	TRO Q = L;
	while(Q != NULL){
		if(Q->infor.hoTen == name) return Q;
		Q = Q->next;
	}
	return NULL;
}

void insert(TRO &L, int k, SinhVien sv){
	TRO P;
	P = new Node;
	P->infor = sv;
	P->next = NULL;

	if(k <= 0 || L == NULL){
		P->next = L;
		L = P;
	}
	else{
		TRO Q = L;
		int i = 0;
		while(Q!=NULL && i < k-1){
			Q = Q->next;
			i++;
		}

		if(Q != NULL){
			P->next = Q->next;
			Q->next = P;
		}
	}
}

bool removeByName(TRO &L, string name){
	if(L==NULL) return false;

	if(L->infor.hoTen == name){
		TRO tmp = L;
		L = L->next;
		delete tmp;
		return true;
	}

	TRO prev = L;
	TRO curr = L->next;
	while(curr!= NULL){
		if(curr->infor.hoTen == name){
			prev->next = curr->next;
			delete curr;
			return true;
		}
		prev = curr;
		curr = curr->next;
	}
	return false;


}

int main(){
	create(L);
	taoDs(L);
	inDanhSach(L);
	string name;
	cout<<"nhap ten sinh vien can tim: ";
	getline(cin,name);
	TRO found = searchByName(L,name);
	if(found!= NULL){
		cout<<"thong tin sinh vien can tim la: "<<endl;
		display(found->infor);
		removeByName(L,found->infor.hoTen);
		cout<<"danh sach sau khi xoa la: "<<endl;
		inDanhSach(L);
	}
	else{
		cout<<"sinh vien khong ton tai trong danh sach"<<endl;
	}

	SinhVien sv6 = {"Nguyen Thuy N","nu",3.6};
	insert(L,2,sv6);
	cout<<"danh sach sau khi chen la: "<<endl;
	inDanhSach(L);
	return 0;
}

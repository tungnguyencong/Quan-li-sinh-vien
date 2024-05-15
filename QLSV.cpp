#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>

using namespace std;

//DATA SINH VIEN
typedef struct SinhVien{
    string HoTen[50];
    string maSV[10];
    int diemToan;
    int diemVan;
    int diemAnh;
    int diemTB;
} SV;

//NODE SINH VIEN
typedef struct NodeSV{
    SV data;
    struct  NodeSV* next; 
} NodeSV;

typedef NodeSV* NodeSVPointer;

//DANH SACH SINH VIEN
typedef struct LinkedList
{
	NodeSVPointer head;
	NodeSVPointer tail;
}danhsachSV;

//CÁC FUNCTION
void  Init_danhsach(danhsachSV &ds);
void Init_Sinhvien(NodeSVPointer  &head);
void NhapSv(NodeSVPointer &head);
NodeSVPointer Search_SV(danhsachSV ds, int choice , string  value);
void Them_SV(danhsachSV &ds);
void Show_Sinhvien(NodeSVPointer sv);
void Show_DanhSach(danhsachSV  ds);
void Xoa_Sinhvien(danhsachSV &ds, int choice);

int main(){
    //Khoi tao danh sach
    danhsachSV sinhvien;
    Init_danhsach(sinhvien);
    int n;
    cout<<"Nhap so luong sinh vien muon them: ";
    cin>>n;
    cin.ignore();
    while(n>0){
        Them_SV(sinhvien);
        n--;
    }
    Show_DanhSach(sinhvien);
    cout<<"Chon cach xoa :"<<endl;
    cout<<"[1] - Xoa theo ten sinh vien."<<endl;
    cout<<"[2] - Xoa theo ma so sinh vien."<<endl;
    int choice;
    cin>>choice;
    cin.ignore();
    Xoa_Sinhvien(sinhvien,choice);
    Show_DanhSach(sinhvien);
    //Show_Sinhvien(Search_SV(sinhvien,id));

    return 0;
}

//KHOI TAO DANH SACH SINH VIEN
void  Init_danhsach(danhsachSV &ds){
    ds.head = NULL;
    ds.tail = NULL;
}
//KHOI TAO NODE SINH VIEN
void Init_Sinhvien(NodeSVPointer  &head){
    head = new NodeSV;
}

//NHAP SINH VIEN
void NhapSv(NodeSVPointer &head){ 
    cout<<"**THEM SINH VIEN**"<<endl;
    cout<<"Nhap Ho va Ten : ";      getline(cin,*head->data.HoTen);
    cout<<"Nhap Ma Sinh Vien: ";    getline(cin,*head->data.maSV);
    cout<<"Nhap diem Toan: ";       cin>>head->data.diemToan;
    cout<<"Nhap diem Van: ";        cin>>head->data.diemVan;
    cout<<"Nhap Diem Anh: ";       cin>>head->data.diemAnh;
    head->next = NULL;
    cin.ignore();    
}

//THEM SINH VIEN VAO CUOI DANH SACH
void Them_SV(danhsachSV &ds){
    NodeSVPointer p;
    Init_Sinhvien(p);
    NhapSv(p);          //Nhap data sinh vien thu cong
    if(ds.head==NULL){
        ds.head = p;
        ds.tail = p;
    }else{
        ds.tail->next =  p;
        ds.tail = p;
    }
}

//TIM KIEM SINH VIEN THEO ID
NodeSVPointer Search_SV(danhsachSV ds, int choice , string  value){
    NodeSVPointer  p = ds.head;
    switch(choice){
        //Tim theo ten
        case 1: 
            while(p!=NULL){
                   if(*p->data.HoTen == value)  return p;
                   else p = p->next;
            }
            return NULL;
            break;
        //Tim theo id
        case 2:
            while (p!=NULL){
                if (*p->data.maSV == value ) return p ;
            else p = p -> next;
            }
            return NULL;
            break;
    }    
}

//XOA THONG TIN MOT SINH VIEN
void Xoa_Sinhvien(danhsachSV &ds, int choice){
    NodeSVPointer  p = ds.head;
    string ten;
    string msv;
    switch(choice){
        //Xoa theo ten
        case 1:{        
            cout<<"Nhap ho va ten sinh vien muon xoa: ";
            getline(cin,ten);
            NodeSVPointer q = Search_SV(ds,1,ten);
            if(q==NULL)
                cout<<"Khong tim thay sinh vien can xoa!"<<endl;
            else{
                while(p->next != q) p = p->next;
                p->next = q->next;
                delete q;
            }
            break;
        }
        //Xoa theo mssv
        case 2:{
            cout<<"Nhap ma sinh vien cua sinh vien muon xoa: ";
            getline(cin,msv);
            NodeSVPointer q=Search_SV(ds,2,msv);
            if(q==NULL)
                cout<<"Khong tim thay sinh vien can xoa!"<<endl;
            else{
                while(p->next != q) p = p->next;
                p->next = q->next;
                delete q;
            }
            break;
        }
    }
}

//SHOW THONG TIN MOT SINH VIEN
void Show_Sinhvien(NodeSVPointer sv){
    if(sv == NULL){
        cout<<"Khong ton tai  thong tin sinh vien nay!";
    }else{
        cout<<*sv->data.maSV<<'\t';
        cout<<*sv->data.HoTen<<'\t';
        cout<<sv->data.diemToan<<'\t';
        cout<<sv->data.diemVan<<'\t';
        cout<<sv->data.diemAnh<<'\t';
    }
}

//SHOW DANH SACH SINH VIEN
void Show_DanhSach(danhsachSV  ds) {
    if(ds.head == NULL) {
        cout << "Danh Sach Rong!" <<endl;
        return;
    }
    NodeSVPointer p = ds.head;
    while(p != NULL) {
        cout<<*p->data.maSV<<"\t";
        cout<<*p->data.HoTen<<"\t";
        cout<<p->data.diemToan<<"\t";
        cout<<p->data.diemVan<<"\t";
        cout<<p->data.diemAnh<<endl;
        p=p->next;
    }
}

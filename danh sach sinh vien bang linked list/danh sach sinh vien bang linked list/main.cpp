#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    string MSSV;
    string TEN;
    float DTB;
    SinhVien* next;
};

typedef SinhVien* sv;

// Thêm sinh viên vào đầu danh sách
void themSinhVien(sv& head, string mssv, string ten, float dtb) {
    sv svMoi = new SinhVien{ mssv, ten, dtb, head };
    head = svMoi;
}

bool kiemTraMSSV(const string& mssv) {
    return !mssv.empty();
}

bool kiemTraTen(const string& ten) {
    return !ten.empty();
}

bool kiemTraDTB(float dtb) {
    return dtb >= 0.0 && dtb <= 10.0;
}

void nhapThongTinSinhVien(sv& head, int soLuong) {
    string mssv, ten;
    float dtb;

    for (int i = 0; i < soLuong; ++i) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        do {
            cout << "Nhap MSSV: "; getline(cin, mssv);
        } while (!kiemTraMSSV(mssv));
        do {
            cout << "Nhap ten: "; getline(cin, ten);
        } while (!kiemTraTen(ten));
        do {
            cout << "Nhap DTB: "; cin >> dtb; cin.ignore();
        } while (!kiemTraDTB(dtb));
        themSinhVien(head, mssv, ten, dtb);
    }
}

sv timSinhVien(sv head, string mssv) {
    while (head!=NULL) {
        if (head->MSSV == mssv) return head;
        head = head->next;
    }
    return nullptr;
}

void xoaSinhVien(sv& head, string mssv) {
    sv prev = nullptr, curr = head;
    while (curr && curr->MSSV != mssv) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) return;
    if (!prev) head = head->next;
    else prev->next = curr->next;
    delete curr;
}

void hienThiSinhVienDiemCao(sv head) {
    while (head) {
        if (head->DTB >= 5)
            cout << head->MSSV << " - " << head->TEN << " - " << head->DTB << endl;
        head = head->next;
    }
}

string xepLoai(float dtb) {
    if (dtb < 3.6) return "Kem";
    if (dtb < 5.0) return "Yeu";
    if (dtb < 6.5) return "Trung binh";
    if (dtb < 7.0) return "Trung binh kha";
    if (dtb < 8.0) return "Kha";
    if (dtb < 9.0) return "Gioi";
    return "Xuat sac";
}

void inDanhSach(sv head) {
    while (head) {
        cout << head->MSSV << " - " << head->TEN << " - " << head->DTB << " - " << xepLoai(head->DTB) << endl;
        head = head->next;
    }
}

void sapXepDanhSach(sv& head) {
    if (!head || !head->next) return;
    for (sv i = head; i; i = i->next) {
        for (sv j = i->next; j; j = j->next) {
            if (i->DTB > j->DTB) {
                swap(i->MSSV, j->MSSV);
                swap(i->TEN, j->TEN);
                swap(i->DTB, j->DTB);
            }
        }
    }
}

void chenSinhVien(sv& head, string mssv, string ten, float dtb) {
    sv svMoi = new SinhVien{ mssv, ten, dtb, nullptr };
    if (!head || head->DTB >= dtb) {
        svMoi->next = head;
        head = svMoi;
        return;
    }
    sv cur = head;
    while (cur->next && cur->next->DTB < dtb) {
        cur = cur->next;
    }
    svMoi->next = cur->next;
    cur->next = svMoi;
}

int main() {
    sv head = nullptr;
    int soLuong;
    cout << "Nhap so luong sinh vien: ";
    cin >> soLuong; cin.ignore();
    nhapThongTinSinhVien(head, soLuong);
    cout << "Danh sach sinh vien:\n";
    inDanhSach(head);

    string mssv;
    cout << "Nhap MSSV can tim: "; getline(cin, mssv);
    sv svTim = timSinhVien(head, mssv);
    if (svTim) cout << "Tim thay sinh vien: " << svTim->TEN << endl;
    else cout << "Khong tim thay sinh vien!\n";

    cout << "Nhap MSSV can xoa: "; getline(cin, mssv);
    xoaSinhVien(head, mssv);
    cout << "Danh sach sau khi xoa:\n";
    inDanhSach(head);

    cout << "Danh sach sinh vien co DTB >= 5:\n";
    hienThiSinhVienDiemCao(head);

    sapXepDanhSach(head);
    cout << "Danh sach sau khi sap xep:\n";
    inDanhSach(head);

    cout << "Nhap MSSV can chen: "; getline(cin, mssv);
    string ten;
    float dtb;
    cout << "Nhap ten: "; getline(cin, ten);
    cout << "Nhap DTB: "; cin >> dtb; cin.ignore();
    chenSinhVien(head, mssv, ten, dtb);
    cout << "Danh sach sau khi chen:\n";
    inDanhSach(head);

    return 0;
}

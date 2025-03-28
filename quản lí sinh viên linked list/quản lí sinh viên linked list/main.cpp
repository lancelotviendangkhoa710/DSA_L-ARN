#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    string MSSV;
    string TEN;
    float DTB;
    SinhVien* next;
};

// Thêm sinh viên vào đầu danh sách
void themSinhVien(SinhVien*& head, string mssv, string ten, float dtb) {
    SinhVien* sv = new SinhVien{ mssv, ten, dtb, head };
    head = sv;
}

// Kiểm tra hợp lệ của MSSV
bool kiemTraMSSV(const string& mssv) {
    return !mssv.empty();
}

// Kiểm tra hợp lệ của tên
bool kiemTraTen(const string& ten) {
    return !ten.empty();
}

// Kiểm tra hợp lệ của DTB
bool kiemTraDTB(float dtb) {
    return dtb >= 0.0 && dtb <= 10.0;
}

// Nhập thông tin sinh viên
void nhapThongTinSinhVien(SinhVien*& head, int soLuong) {
    string mssv, ten;
    float dtb;

    for (int i = 0; i < soLuong; ++i) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";

        do {
            cout << "Nhap MSSV: "; getline(cin, mssv);
            if (!kiemTraMSSV(mssv)) {
                cout << "MSSV khong hop le. Vui long nhap lai.\n";
            }
        } while (!kiemTraMSSV(mssv));

        do {
            cout << "Nhap ten: "; getline(cin, ten);
            if (!kiemTraTen(ten)) {
                cout << "Ten khong hop le. Vui long nhap lai.\n";
            }
        } while (!kiemTraTen(ten));

        do {
            cout << "Nhap DTB: "; cin >> dtb; cin.ignore();
            if (!kiemTraDTB(dtb)) {
                cout << "DTB khong hop le. Vui long nhap lai.\n";
            }
        } while (!kiemTraDTB(dtb));

        themSinhVien(head, mssv, ten, dtb);
    }
}

// Tìm sinh viên theo MSSV
SinhVien* timSinhVien(SinhVien* head, string mssv) {
    while (head) {
        if (head->MSSV == mssv) return head;
        head = head->next;
    }
    return nullptr;
}

// Xóa sinh viên theo MSSV
void xoaSinhVien(SinhVien*& head, string mssv) {
    SinhVien* prev = nullptr, * curr = head;
    while (curr && curr->MSSV != mssv) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) return;
    if (!prev) head = head->next;
    else prev->next = curr->next;
    delete curr;
}

// Hiển thị danh sách sinh viên có DTB >= 5
void hienThiSinhVienDiemCao(SinhVien* head) {
    while (head) {
        if (head->DTB >= 5)
            cout << head->MSSV << " - " << head->TEN << " - " << head->DTB << endl;
        head = head->next;
    }
}

// Xếp loại sinh viên
string xepLoai(float dtb) {
    if (dtb < 3.6) return "Kem";
    if (dtb < 5.0) return "Yeu";
    if (dtb < 6.5) return "Trung binh";
    if (dtb < 7.0) return "Trung binh kha";
    if (dtb < 8.0) return "Kha";
    if (dtb < 9.0) return "Gioi";
    return "Xuat sac";
}

// In danh sách sinh viên kèm xếp loại
void inDanhSach(SinhVien* head) {
    while (head) {
        cout << head->MSSV << " - " << head->TEN << " - " << head->DTB << " - " << xepLoai(head->DTB) << endl;
        head = head->next;
    }
}

// Sắp xếp danh sách theo DTB tăng dần
void sapXepDanhSach(SinhVien*& head) {
    if (!head || !head->next) return;
    for (SinhVien* i = head; i; i = i->next) {
        for (SinhVien* j = i->next; j; j = j->next) {
            if (i->DTB > j->DTB) {
                swap(i->MSSV, j->MSSV);
                swap(i->TEN, j->TEN);
                swap(i->DTB, j->DTB);
            }
        }
    }
}

// Chèn sinh viên vào danh sách đã sắp xếp
void chenSinhVien(SinhVien*& head, string mssv, string ten, float dtb) {
    SinhVien* sv = new SinhVien{ mssv, ten, dtb, nullptr };
    if (!head || head->DTB >= dtb) {
        sv->next = head;
        head = sv;
        return;
    }
    SinhVien* cur = head;
    while (cur->next && cur->next->DTB < dtb) {
        cur = cur->next;
    }
    sv->next = cur->next;
    cur->next = sv;
}

int main() {
    SinhVien* head = nullptr;
    int soLuong;

    // Nhập số lượng sinh viên
    cout << "Nhap so luong sinh vien: ";
    cin >> soLuong; cin.ignore();

    // Nhập danh sách sinh viên
    nhapThongTinSinhVien(head, soLuong);

    // In danh sách sinh viên
    cout << "Danh sach sinh vien:\n";
    inDanhSach(head);

    // Tìm sinh viên
    string mssv;
    cout << "Nhap MSSV can tim: "; getline(cin, mssv);
    SinhVien* sv = timSinhVien(head, mssv);
    if (sv) cout << "Tim thay sinh vien: " << sv->TEN << endl;
    else cout << "Khong tim thay sinh vien!\n";

    // Xóa sinh viên
    cout << "Nhap MSSV can xoa: "; getline(cin, mssv);
    xoaSinhVien(head, mssv);

    // In danh sách sau khi xóa
    cout << "Danh sach sau khi xoa:\n";
    inDanhSach(head);

    // In danh sách sinh viên có ĐTB >= 5
    cout << "Danh sach sinh vien co DTB >= 5:\n";
    hienThiSinhVienDiemCao(head);

    // Sắp xếp danh sách sinh viên theo ĐTB
    sapXepDanhSach(head);
    cout << "Danh sach sau khi sap xep:\n";
    inDanhSach(head);

    // Chèn sinh viên mới vào danh sách đã sắp xếp
    cout << "Nhap MSSV can chen: "; getline(cin, mssv);
    string ten;
    float dtb;
    cout << "Nhap ten: "; getline(cin, ten);
    cout << "Nhap DTB: "; cin >> dtb; cin.ignore();
    chenSinhVien(head, mssv, ten, dtb);

    // In danh sách sau khi chèn
    cout << "Danh sach sau khi chen:\n";
    inDanhSach(head);

    return 0;
}

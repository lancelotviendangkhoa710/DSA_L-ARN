#include <bits/stdc++.h>
using namespace std;

class DATHUC {
private:
    int bac;      
    int heso[3];  // hệ số của đa thức: heso[0] cho x^2, heso[1] cho x, heso[2] cho hằng số

public:
    // Constructor khởi tạo đa thức bậc 2
    DATHUC() {
        bac = 2;
        heso[0] = heso[1] = heso[2] = 0;
    }
    
    // Hàm nhập đa thức
    void Nhap() {
        cout << "Nhap he so cho da thuc bac 2 (a x^2 + b x + c):" << endl;
        cout << "Nhap a: ";
        cin >> heso[0];
        cout << "Nhap b: ";
        cin >> heso[1];
        cout << "Nhap c: ";
        cin >> heso[2];
    }
    
    // Hàm xuất đa thức
    void Xuat() const {
        cout << heso[0] << "x^2 ";
        // Xuất hệ số của x
        if (heso[1] >= 0)
            cout << "+ " << heso[1] << "x ";
        else
            cout << "- " << -heso[1] << "x ";
        // Xuất hằng số
        if (heso[2] >= 0)
            cout << "+ " << heso[2];
        else
            cout << "- " << -heso[2];
        cout << endl;
    }
    
    // Hàm cộng hai đa thức: trả về đa thức tổng
    DATHUC ADD(const DATHUC &other) const {
        DATHUC result;
        for (int i = 0; i < 3; i++) {
            result.heso[i] = this->heso[i] + other.heso[i];
        }
        return result;
    }
    
    // Hàm trừ hai đa thức: trả về đa thức hiệu
    DATHUC SUB(const DATHUC &other) const {
        DATHUC result;
        for (int i = 0; i < 3; i++) {
            result.heso[i] = this->heso[i] - other.heso[i];
        }
        return result;
    }
    
    // Hàm nhân hai đa thức bậc 2, kết quả là đa thức bậc 4
    void MUL(const DATHUC &other) const {
        // Đa thức tích có dạng: a x^4 + b x^3 + c x^2 + d x + e
        int a = this->heso[0] * other.heso[0]; // hệ số x^4
        int b = this->heso[0] * other.heso[1] + this->heso[1] * other.heso[0]; // hệ số x^3
        int c = this->heso[0] * other.heso[2] + this->heso[1] * other.heso[1] + this->heso[2] * other.heso[0]; // hệ số x^2
        int d = this->heso[1] * other.heso[2] + this->heso[2] * other.heso[1]; // hệ số x
        int e = this->heso[2] * other.heso[2]; // hệ số tự do
        
        cout << "Tich cua hai da thuc la: ";
        // Xuất hệ số x^4
        cout << a << "x^4 ";
        
        // Xuất hệ số x^3
        if(b >= 0)
            cout << "+ " << b << "x^3 ";
        else
            cout << "- " << -b << "x^3 ";
        
        // Xuất hệ số x^2
        if(c >= 0)
            cout << "+ " << c << "x^2 ";
        else
            cout << "- " << -c << "x^2 ";
        
        // Xuất hệ số x
        if(d >= 0)
            cout << "+ " << d << "x ";
        else
            cout << "- " << -d << "x ";
        
        // Xuất hằng số
        if(e >= 0)
            cout << "+ " << e;
        else
            cout << "- " << -e;
        
        cout << endl;
    }
};

int main() {
    DATHUC first, second, result;
    
    cout << "Nhap da thuc thu nhat (ax^2 + bx + c): " << endl;
    first.Nhap();
    cout << "Nhap da thuc thu hai (ax^2 + bx + c): " << endl;
    second.Nhap();
    
    cout << "\nDa thuc thu nhat: ";
    first.Xuat();
    cout << "Da thuc thu hai: ";
    second.Xuat();
    
    char pheptoan;
    cout << "Nhap phep toan ban muon thuc hien (+, -, *): ";
    cin >> pheptoan;
    
    switch(pheptoan) {
        case '+':
            result = first.ADD(second);
            cout << "Tong cua hai da thuc la: ";
            result.Xuat();
            break;
        case '-':
            result = first.SUB(second);
            cout << "Hieu cua hai da thuc la: ";
            result.Xuat();
            break;
        case '*':
            first.MUL(second);
            break;
        default:
            cout << "Phep toan khong hop le!" << endl;
    }
    
    return 0;
}


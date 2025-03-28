#include <iostream>
using namespace std;

class PhanSo {
private:
    int tuso;
    int mauso;

    int findGCD(int a, int b) {
        if (b == 0) return a;
        return findGCD(b, a % b);
    }

    void rutGonPhanSo() {
        int gcd = findGCD(abs(tuso), abs(mauso));
        tuso /= gcd;
        mauso /= gcd;

        if (mauso < 0) {
            tuso = -tuso;
            mauso = -mauso;
        }
    }

public:
    // Hàm nhập và xuất
    void Nhap() {
        cout << "Nhap tu so: ";
        cin >> tuso;
        do {
            cout << "Nhap mau so (khac 0): ";
            cin >> mauso;
            if (mauso == 0) {
                cout << "Mau so khong the bang 0. Vui long nhap lai.\n";
            }
        } while (mauso == 0);
    }

    void Xuat() const {
        if (mauso > 0) {
            if (mauso == 1)
                cout << tuso << endl;
            else
                cout << tuso << "/" << mauso << endl;
        }
        else {  // tức là mauso < 0
            if (mauso == -1)
                cout << -tuso << endl;
            else
                cout << -tuso << "/" << -mauso << endl;
        }
    }



    // Các phép toán
    PhanSo tong(PhanSo ps) {
        PhanSo res;
        res.tuso = tuso * ps.mauso + ps.tuso * mauso;
        res.mauso = mauso * ps.mauso;
        res.rutGonPhanSo();
        return res;
    }

    PhanSo hieu(PhanSo ps) {
        PhanSo res;
        res.tuso = tuso * ps.mauso - ps.tuso * mauso;
        res.mauso = mauso * ps.mauso;
        res.rutGonPhanSo();
        return res;
    }

    PhanSo tich(PhanSo ps) {
        PhanSo res;
        res.tuso = tuso * ps.tuso;
        res.mauso = mauso * ps.mauso;
        res.rutGonPhanSo();
        return res;
    }

    PhanSo thuong(PhanSo ps) {
        if (ps.tuso == 0) {
            cout << "Khong the chia cho phan so co tu so = 0.\n";
            exit(1);
        }
        PhanSo res;
        res.tuso = tuso * ps.mauso;
        res.mauso = mauso * ps.tuso;
        res.rutGonPhanSo();
        return res;
    }
};

int main() {
    PhanSo ps1, ps2;
    char pheptoan;

    cout << "Nhap phan so thu 1" << endl;
    ps1.Nhap();
    cout << "Nhap phan so thu 2" << endl;
    ps2.Nhap();

    cout << "Hai phan so vua nhap la: " << endl;
    ps1.Xuat();
    ps2.Xuat();

    cout << "Rut gon phan so 1" << endl;
    ps1.Xuat();

    cout << "Rut gon phan so 2" << endl;
    ps2.Xuat();

    cout << "Nhap phep toan (+, -, *, /): ";
    cin >> pheptoan;

    switch (pheptoan) {
        case '+':
            cout << "Tong hai phan so: ";
            ps1.tong(ps2).Xuat();
            break;
        case '-':
            cout << "Hieu hai phan so: ";
            ps1.hieu(ps2).Xuat();
            break;
        case '*':
            cout << "Tich hai phan so: ";
            ps1.tich(ps2).Xuat();
            break;
        case '/':
            cout << "Thuong hai phan so: ";
            ps1.thuong(ps2).Xuat();
            break;
        default:
            cout << "Phep toan khong hop le.\n";
    }

    return 0;
}

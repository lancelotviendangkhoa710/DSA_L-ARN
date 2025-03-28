 #include <bits/stdc++.h>
 using namespace std;

class DATHUC {
    private:
  int bac = 2;  
  int heso[3]; 

// nhập đa thức
void Nhap() {
    cin >>heso[0] >> heso[1] +>>heso[2];
}
void Xuat() {
    cout << heso[0] << "x^2 ";
    if (heso[1] >= 0) cout << "+ " << heso[1] << "x ";
    else cout << "- " << -dt.heso[1] << "x ";

    if (heso[2] >= 0) cout << "+ " << heso[2];
    else cout << "- " << -heso[2];

    cout << endl;
}

// cộng hai đa thức
DATHUC ADD(DATHUC mot, DATHUC hai) {
    DATHUC kq;
    for (int i = 0; i <= 2; i++) {
        kq.heso[i] = mot.heso[i] + hai.heso[i];
    }
    return kq;
}

// Hàm trừ hai đa thức
DATHUC SUB(DATHUC mot, DATHUC hai) {
    DATHUC kq;
    for (int i = 0; i <= 2; i++) {
        kq.heso[i] = mot.heso[i] - hai.heso[i];
    }
    return kq;
}

// nhân
void MUL(DATHUC mot, DATHUC hai) {
    // Đa thức bậc 4 có dạng aX^4 + bx^3 +cx^2 +dx +e
    int a = mot.heso[0] * hai.heso[0]; // Hệ số x^4
    int b = mot.heso[0] * hai.heso[1] + mot.heso[1] * hai.heso[0]; // Hệ số x^3
    int c = mot.heso[0] * hai.heso[2] + mot.heso[1] * hai.heso[1] + mot.heso[2] * hai.heso[0]; // Hệ số x^2
    int d = mot.heso[1] * hai.heso[2] + mot.heso[2] * hai.heso[1]; // Hệ số x
    int e = mot.heso[2] * hai.heso[2]; // Hệ số tự do
    
    //xuất ngay trong hàm
	cout << "Tich cua hai da thuc la: " << a << "x^4 ";
    if (b >= 0) cout << "+ " << b << "x^3 ";
    else cout << "- " << -b << "x^3 ";

    if (c >= 0) cout << "+ " << c << "x^2 ";
    else cout << "- " << -c << "x^2 ";

    if (d >= 0) cout << "+ " << d << "x ";
    else cout << "- " << -d << "x ";

    if (e >= 0) cout << "+ " << e;
    else cout << "- " << -e;

    cout << endl;
    
   
}
}

// int main() {
//     DATHUC first, second, result;
//     cout << "Nhap da thuc thu nhat (ax^2 + bx +c)" << endl;
//     Nhap(first);
//     cout << "Nhap da thuc thu hai (ax^2 + bx +c)" << endl;
//     Nhap(second);

//     cout << "Nhap phep toan ban muon thuc hien (+ - *): ";
//     char pheptoan;
//     cin >> pheptoan;

//     switch (pheptoan) {
//         case '+':
//             result = ADD(first, second);
//             cout << "Tong cua hai da thuc la: ";
//             Xuat(result);
//             break;
//         case '-':
//             result = SUB(first, second);
//             cout << "Hieu cua hai da thuc la: ";
//             Xuat(result);
//             break;
//         case '*':
//             MUL(first, second);
//             break;
//         default:
//             cout << "Phep toan khong hop le!" << endl;
//     }

//     return 0;
// }
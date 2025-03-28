#include <iostream>
#include <iomanip>

using namespace std;

struct DONTHUC {
    int somu;
    double heso;

    DONTHUC(double _heso = 0, int _somu = 0) {
        heso = _heso;
        somu = _somu;
    }

    DONTHUC& operator = (const DONTHUC& rhs) {
        if (this == &rhs) return *this;
        this->heso = rhs.heso;
        this->somu = rhs.somu;
        return *this;
    }
};

struct Node {
    DONTHUC* data;
    Node* next;

    Node(DONTHUC* _data = nullptr) {
        this->data = _data;
        this->next = nullptr;
    }
};

struct DATHUC {
    Node* head;
    Node* tail;
    DATHUC() {
        this->head = nullptr;
        this->tail = nullptr;
    }
};

void Nhap(DATHUC& B, double hs, int sm) {
    DONTHUC* newDonThuc = new DONTHUC(hs, sm);
    Node* newNode = new Node(newDonThuc);

    if (B.head == nullptr) {
        B.head = newNode;
        B.tail = newNode;
    }
    else {
        B.tail->next = newNode;
        B.tail = newNode;
    }
}

void Xuat(const DATHUC& B) {
    Node* current = B.head;
    bool first = true;

    while (current != nullptr) {
        if (!first && current->data->heso > 0) {
            cout << "+";
        }
        if (current->data->heso != 0) {
            cout << current->data->heso;
            if (current->data->somu != 0) {
                cout << "x^" << current->data->somu;
            }
        }
        current = current->next;
        first = false;
    }
    cout << endl;
}

double TinhDaThuc(const DATHUC& B, double x) {
    double result = 0.0;
    Node* current = B.head;

    while (current != nullptr) {
        result += current->data->heso * pow(x, current->data->somu);
        current = current->next;
    }

    return result;
}

int main() {
    DATHUC B;
    int N;

    cin >> N;
    for (int test = 0; test < N; test++) {
        double heso; int somu;
        cin >> heso >> somu;
        Nhap(B, heso, somu);
    }

    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
        << fixed << setprecision(2) << TinhDaThuc(B, x);
    return 0;
}

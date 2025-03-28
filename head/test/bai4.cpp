#include <iostream>
using namespace std;

// 1. Định nghĩa class time 
class time {
    private:
    int hr;
    int min;
    int secd;

public:
    void Nhap() {
        cin >> hr >> min >> secd;
    }

    void Xuat() {
        cout << hr << ":" << min << ":" << secd;
    }

    time getNexttime(time &plus) {
        time result;

        // Cộng giây và tính phép dư
        result.secd = this->secd + plus.secd;
        result.min = this->min + plus.min + result.secd / 60;
        result.secd %= 60;

        // Cộng phút và tính phép dư
        result.hr = this->hr + plus.hr + result.min / 60;
        result.min %= 60;

        //nếu quá 24h thì quay vòng lại
        result.hr %= 24;

        return result;
    }

    bool isValid() {
        if (hr >= 24 || hr < 0 || min >= 60 || min < 0 || secd >= 60 || secd < 0) {
            cout << "Gio khong hop le" << endl;
            return false;
        }
        return true;
    }
};

int main() {
    time now;
    time plus;

    cout << "Nhap gio hien tai (hour : minute : second): " << endl;
    do {
        now.Nhap();
    } while (!now.isValid());

    now.Xuat();
    cout << "-----------------------------" << endl;

    cout << "Nhap thoi gian cong them (hour : minute : second): ";
    plus.Nhap();
    plus.Xuat();

    // Tính thời điểm tiếp theo
    time result = now.getNexttime(plus);
    now.Xuat();
    cout << " + ";
    plus.Xuat();
    cout << " =  ";
    result.Xuat();
    
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
class BPTracker {
    string bme_name;
    vector<int> bme_bp;
public:
    BPTracker(string bme_name) {
        this->bme_name = bme_name;
    }
    void loadReadings(int bme_days) {
        int bme_reading;
        for (int bme_i = 0; bme_i < bme_days; bme_i++) {
            cout << "Day " << bme_i + 1 << ": ";
            cin >> bme_reading;
            bme_bp.push_back(bme_reading);
        }
    }
    void analyse() {
        int bme_normal = 0, bme_elevated = 0, bme_hyper = 0;
        int bme_maxDay = 1;
        bool bme_trend = true;
        for (int bme_i = 0; bme_i < bme_bp.size(); bme_i++) {
            if (bme_bp[bme_i] < 120)
                bme_normal++;
            else if (bme_bp[bme_i] <= 129)
                bme_elevated++;
            else
                bme_hyper++;
            if (bme_bp[bme_i] > bme_bp[bme_maxDay - 1])
                bme_maxDay = bme_i + 1;
        }
        for (int bme_i = 1; bme_i < bme_bp.size(); bme_i++) {
            if (bme_bp[bme_i] <= bme_bp[bme_i - 1])
                bme_trend = false;
        }
cout << "\nNormal = " << bme_normal << endl;
cout << "Elevated = " << bme_elevated << endl;
cout << "Hypertensive = " << bme_hyper << endl;
cout << "Highest Reading Day = " << bme_maxDay << endl;
        if (bme_trend)
cout << "Worsening trend detected" << endl;
        else 
cout << "No consistent worsening" << endl;
    }
};
int main() {
BPTracker bme_patient("Ali");
 bme_patient.loadReadings(5);
 bme_patient.analyse();
    return 0;
}
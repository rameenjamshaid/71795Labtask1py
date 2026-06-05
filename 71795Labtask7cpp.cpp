#include <iostream>
#include <string>
using namespace std;
class HospitalWard {
    string bme_wardName;
    int bme_totalBeds;
    string bme_beds[10];
public:
    HospitalWard(string bme_name, int bme_bedsCount) {
        bme_wardName = bme_name;
        bme_totalBeds = bme_bedsCount;
        for (int bme_i = 0; bme_i < bme_totalBeds; bme_i++)
            bme_beds[bme_i] = "Free";
    }
    void admitPatient(string bme_patientName) {
        for (int bme_i = 0; bme_i < bme_totalBeds; bme_i++) {
            if (bme_beds[bme_i] == "Free") {
                bme_beds[bme_i] = "Occupied";
                cout << bme_patientName
                     << " assigned to Bed "
                     << bme_i + 1 << endl;
                return;
            }
        }
        cout << "Ward Full - cannot admit" << endl;
    }
    void dischargePatient(int bme_bedNumber) {
        if (bme_bedNumber >= 1 && bme_bedNumber <= bme_totalBeds) {
            if (bme_beds[bme_bedNumber - 1] == "Occupied") {
                bme_beds[bme_bedNumber - 1] = "Free";
                cout << "Bed " << bme_bedNumber
                     << " discharged" << endl;
            }
            else {
                cout << "Bed already free" << endl;
            }
        }
        else {
            cout << "Invalid bed number" << endl;
        }
    }
};
int main() {
    HospitalWard bme_ward1("Cardiology", 2);
    HospitalWard bme_ward2("ICU", 1);
    bme_ward1.admitPatient("Ali");
    bme_ward1.admitPatient("Ahmed");
    bme_ward1.admitPatient("Sara");      
    bme_ward1.dischargePatient(1);      
    bme_ward1.dischargePatient(1);       
    bme_ward1.dischargePatient(5);       
    bme_ward2.admitPatient("Usman");
    bme_ward2.admitPatient("Bilal");    
    return 0;
}
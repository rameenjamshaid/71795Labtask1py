#include <iostream>
using namespace std;
class DosageCalc
{
    double bme_weight;
    int bme_age;
    string bme_drug;
public:
    DosageCalc(double bme_weight, int bme_age, string bme_drug)
    {
        this->bme_weight = bme_weight;
        this->bme_age = bme_age;
        this->bme_drug = bme_drug;
    }
    double computeDose()
    {
        double bme_dose = bme_weight * 5;
        if (bme_age < 12)
        {
            bme_dose = bme_dose * 0.70;
        }
        else if (bme_age > 65)
        {
            bme_dose = bme_dose * 0.80;
        }
        if (bme_dose > 500)  // Maximum dose cap
        {
            cout <<"Warning: Maximum dose applied"<< endl;
            bme_dose = 500;
        }
        return bme_dose;
    }
    void printPrescription()
    {
        cout <<"Drug Name: "<< bme_drug << endl;
        cout <<"Weight: "<< bme_weight << " kg" << endl;
        cout <<"Age: "<< bme_age << " years" << endl;
        cout <<"Recommended Dose: "
             <<computeDose()<< " mg" << endl;
        cout << endl;
    }
};
int main()
{
DosageCalc bme_patient1(40, 10, "Panadol");
DosageCalc bme_patient2(70, 30, "Amoxicillin");
DosageCalc bme_patient3(130, 70, "Regix");
bme_patient1.printPrescription();
bme_patient2.printPrescription();
bme_patient3.printPrescription();
    return 0;
}
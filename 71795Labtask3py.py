class DosageCalc:
    def __init__(self, bme_weight, bme_age, bme_drug):
        self.bme_weight = bme_weight
        self.bme_age = bme_age
        self.bme_drug = bme_drug
    def computeDose(self):
        bme_dose = self.bme_weight * 5   # Base dose = 5 mg per kg
        if self.bme_age < 12:
            bme_dose = bme_dose * 0.70
        elif self.bme_age > 65:
            bme_dose = bme_dose * 0.80
        if bme_dose > 500:  # Maximum dose cap
            print("Warning: Maximum dose applied")
            bme_dose = 500
        return bme_dose
    def printPrescription(self):
        print("Drug Name:", self.bme_drug)
        print("Weight:", self.bme_weight, "kg")
        print("Age:", self.bme_age, "years")
        print("Recommended Dose:", self.computeDose(), "mg")
        print()
bme_patient1 = DosageCalc(40, 10, "Panadol")
bme_patient2 = DosageCalc(70, 30, "Amoxicillin")
bme_patient3 = DosageCalc(130, 70, "Regix")
bme_patient1.printPrescription()
bme_patient2.printPrescription()
bme_patient3.printPrescription()
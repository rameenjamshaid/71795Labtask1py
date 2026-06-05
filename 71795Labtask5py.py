class BPTracker:
    def __init__(self, bme_name):
        self.bme_name = bme_name
        self.bme_bp = []
    def loadReadings(self, bme_days):
        for bme_i in range(bme_days):
            self.bme_bp.append(int(input(f"Day {bme_i+1}: ")))
    def analyse(self):
        bme_normal = bme_elevated = bme_hyper = 0
        bme_maxDay = 1
        bme_trend = True
        for bme_i in range(len(self.bme_bp)):
            if self.bme_bp[bme_i] < 120:
                bme_normal += 1
            elif self.bme_bp[bme_i] <= 129:
                bme_elevated += 1
            else:
                bme_hyper += 1
            if self.bme_bp[bme_i] > self.bme_bp[bme_maxDay - 1]:
                bme_maxDay = bme_i + 1
        for bme_i in range(1, len(self.bme_bp)):
            if self.bme_bp[bme_i] <= self.bme_bp[bme_i - 1]:
                bme_trend = False
        print("Normal =", bme_normal)
        print("Elevated =", bme_elevated)
        print("Hypertensive =", bme_hyper)
        print("Highest Reading Day =", bme_maxDay)
        if bme_trend:
            print("Worsening trend detected")
        else:
            print("No consistent worsening")
bme_patient = BPTracker("Ali")
bme_patient.loadReadings(5)
bme_patient.analyse()
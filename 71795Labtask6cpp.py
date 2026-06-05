class MRIGrid:
    def __init__(self, bme_r, bme_c):
        self.bme_r = bme_r
        self.bme_c = bme_c
        self.bme_grid = [[0]*bme_c for _ in range(bme_r)]
    def fillGrid(self):
        for bme_i in range(self.bme_r):
            for bme_j in range(self.bme_c):
                self.bme_grid[bme_i][bme_j] = int(
                    input(f"Enter value [{bme_i}][{bme_j}]: ")
                )
    def classifyPixels(self):
        bme_dark = bme_grey = bme_bright = 0
        for bme_i in range(self.bme_r):
            for bme_j in range(self.bme_c):
                bme_val = self.bme_grid[bme_i][bme_j]
                if bme_val <= 85:
                    bme_dark += 1
                elif bme_val <= 170:
                    bme_grey += 1
                else:
                    bme_bright += 1
                if bme_j > 0 and abs(bme_val - self.bme_grid[bme_i][bme_j-1]) > 80:
                    print("Edge Point:", bme_i, bme_j)
        print("Dark =", bme_dark)
        print("Grey =", bme_grey)
        print("Bright =", bme_bright)
bme_scan = MRIGrid(2, 3)
bme_scan.fillGrid()
bme_scan.classifyPixels()
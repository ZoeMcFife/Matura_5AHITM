import math

NUM = 900900
Factor1 = 1
Factor2 = 900900

while Factor1 < Factor2:
    if Factor1 * Factor2 == NUM:
        print(str(Factor1) + " x " + str(Factor2) + " = " + str(Factor1 * Factor2))
    
    Factor1 += 1
    Factor2 = round(NUM / Factor1) 
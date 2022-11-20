Rainfull_mi = "45, 65, 70.4, 82.6, 20.1, 90.8, 76.1, 30.92, 46.8, 67.1, 79.9"

RAIN_THRESH = 75

# final count - add 1 to the count if a value passes the thresh
num_rainy_days = sum(1 for r in Rainfull_mi.split(',')
                     if float(r.strip()) > RAIN_THRESH)

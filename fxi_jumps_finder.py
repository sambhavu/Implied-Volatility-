import yfinance as yf
import math
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
import seaborn

data = yf.Ticker('fxi')
hist = data.history(period = '7d', interval = '1m')

close = hist['Close'].values
open = hist['Open'].values




jumps = []
for i in range(2,len(close)):
    if (close[i] - close[i-2])/close[i-1] > .004:
        jumps.append(i)
    elif (close[i] - close[i-1])/close[i-1] < -.004:
        jumps.append(i)

#seaborn.kdeplot(close, label = 'close')
print(jumps)
plt.plot(close)
plt.show()

exit(1)

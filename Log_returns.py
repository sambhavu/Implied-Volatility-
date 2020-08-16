import yfinance as yf
import math
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt

data = yf.Ticker('MSFT')
hist = data.history(period = '1d', interval = '1m')
close = hist['Close'].values



perc_change = 0
returns = []




for i in range(1, len(close)-1):
    perc_change = (math.log(close[i]) - math.log(close[i-1]))/math.log(close[i-1])
    returns.append(perc_change)


plt.plot(returns)
plt.show()





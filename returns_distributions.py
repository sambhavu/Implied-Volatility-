import yfinance as yf
import math
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
import seaborn

data = yf.Ticker('gld')
hist = data.history(period = '5y', interval = '1d')

close = hist['Close'].values
open = hist['Open'].values


perc_change = 0
tmmrow = 0
returns = []





afterup = []
afterdown = []

for i in range(1, len(close)-1):
    perc_change = (close[i-1] - open[i-1])/open[i-1]
    tmmrow = (close[i] - open[i])/open[i]

    returns.append(perc_change)

    if perc_change < -.01:
        afterdown.append(tmmrow)


    elif perc_change > .01:
        afterup.append(tmmrow)

seaborn.kdeplot(returns, label = 'returns')
seaborn.kdeplot(afterup, label = 'afterup')
seaborn.kdeplot(afterdown, label = 'afterdown')

plt.show()





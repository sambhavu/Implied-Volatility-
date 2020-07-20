import yfinance as yf
from matplotlib import pyplot as plt
import math


def std_(returns):
    if len(returns) >1: 
        sigmasum = 0
        d=0
        total = 0
        avg = 0
        for i in range(len(returns)):
            total += returns[i]
        avg = total/len(returns)
        for i in range(len(returns)):
            d = returns[i] - avg
            sigmasum += d*d
        sigma  = 0
        sigma = math.sqrt((1/(len(returns) -1)) * sigmasum)
        return sigma
    else: 
        return 1


stock_ = 'AAPL'
stock = yf.Ticker(stock_)

df = stock.history(period = '7d', interval = '1m')
close = df['Close'].values

stdev = []
for i in range(20, len(close)): 
  prices = []
  for j in range(i-10, i): 
    prices.append(close[j])
  sx = std_(prices)
  stdev.append(sx)

plt.plot(stdev)
plt.show()






  









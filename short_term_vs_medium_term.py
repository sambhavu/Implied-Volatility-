import yfinance as yf
import math
from matplotlib import pyplot as plt


SPX = yf.Ticker('vxx').history(period = '1y', interval = '1d')
SPXF = yf.Ticker('vxz').history(period = '1y', interval = '1d')

spot = SPX['Close'].values
future = SPXF['Close'].values

plt.plot(spot)
plt.plot(future)
plt.show()



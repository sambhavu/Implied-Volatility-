import yfinance as yf
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from datetime import date
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.tri as mtri


a = []
b = []
c = []

apple = yf.Ticker('AAPL')
apple_exp_dates = apple.options

for date in apple_exp_dates:
    chain = apple.option_chain(date)
    iv = chain.calls.impliedVolatility
    strikes = chain.calls.strike

    len_  = len(strikes)

    expiry = []
    strike_price = []
    impliedvol = []

    for i in range(0,len_):
        expiry.append(date)
        impliedvol.append(iv[i])
        strike_price.append(strikes[i])

    expiry = np.asarray(expiry)
    impliedvol = np.asarray(impliedvol)
    strike_price = np.asarray(strike_price)

    a.append(expiry)
    b.append(impliedvol)
    c.append(strike_price)


a = np.asarray(a)
b = np.asarray(b)
c = np.asarray(c)

s, t = np.meshgrid(a,c)

fig = plt.figure()
volsurface = fig.add_subplot(111, projection = '3d')
volsurface.plot_surface(s,b,t)

plt.show()


#still buggy

import yfinance as yf
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from datetime import date
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.tri as mtri


apple = yf.Ticker('AAPL')
apple_exp_dates = apple.options

apple_exp_len = len(apple_exp_dates)


exp_date = []
apple_strikes = []
apple_iv = np.array([])

for i in range(apple_exp_len):

    exp_date.append(apple_exp_dates[i])
    apple_chain = apple.option_chain(exp_date[i])
    apple_strikes.append(apple_chain.calls.strike)

    temp = apple_chain.calls.impliedVolatility
    temp = np.asarray(temp)

    l = [apple_iv]

    l.append(temp)

    apple_iv = np.array(l)





strikes, times = np.meshgrid(apple_strikes, exp_date)

impliedvol = np.asarray(apple_iv)
fig = plt.figure()
volsurface = fig.add_subplot(111, projection = '3d')
volsurface.plot_surface(strikes,times,impliedvol)

plt.show()









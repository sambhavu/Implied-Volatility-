import yfinance as yfg
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from datetime import date
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.tri as mtri

stockticker = input("Enter Ticker: ")

apple = yf.Ticker(stockticker)
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

    plt.plot(apple_chain.calls.strike, temp)


plt.show()



















import yfinance as yf
import yahoofinancials
import numexpr as ne
import pandas as pd
import numpy as np
from matplotlib import pyplot as plt


tickersymbol = 'NVDA'

NVDA = yf.Ticker(tickersymbol)



times = ['2020-06-25', '2020-07-01', '2020-07-09', '2020-07-16', '2020-07-23', '2020-07-30',
         '2020-08-20', '2020-09-17', '2020-12-17', '2021-01-14', '2021-06-17', '2022-01-20',
         '2022-06-16', '2022-09-15']

for i in range(14):

    NVDACall = NVDA.option_chain(times[i]).calls

    NVDACall_strike = NVDACall['strike']
    NVDACall_iv =  NVDACall['impliedVolatility']

    NVDACall_pc = NVDACall['percentChange']

    plt.plot(NVDACall_strike,NVDACall_pc)

plt.show()


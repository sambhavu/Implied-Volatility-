import yfinance as yf
from yahoofinancials import YahooFinancials
import numexpr as ne
import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
from sklearn.neural_network import MLPClassifier
from sklearn.model_selection import train_test_split


dataset = pd.read_csv("/users/satish/Desktop/dataset.txt", names = ["dat"])
data = dataset['dat'].values

vix_ = pd.read_csv("/users/satish/Desktop/vix_close.txt", names = ["prices"])
vix = vix_['prices'].values

ma3_ = pd.read_csv("/users/satish/Desktop/ma3.txt", names = ["average3"])
ma3 = ma3_['average3'].values

ma4_ = pd.read_csv("/users/satish/Desktop/ma4.txt", names = ["average4"])
ma4 = ma4_['average4'].values

ma5_ = pd.read_csv("/users/satish/Desktop/ma5.txt", names = ["average5"])
ma5 = ma5_['average5'].values

ma6_ = pd.read_csv("/users/satish/Desktop/ma6.txt" , names = ["average6"])
ma6 = ma6_['average6'].values

ma7_ = pd.read_csv("/users/satish/Desktop/ma7.txt" , names = ["average7"])
ma7 = ma7_['average7'].values

ma8_ = pd.read_csv("/users/satish/Desktop/ma8.txt" , names = ["average8"])
ma8 = ma8_['average8'].values

testdata = data[:7000]
testvix = vix[:7000]
testma3 = ma3[:7000]
testma4 = ma4[:7000]
testma5 = ma5[:7000]
testma6 = ma6[:7000]
testma7 = ma7[:7000]
testma8 = ma8[:7000]





testset = pd.DataFrame({
        'close' : testvix,
        'a3' : testma3,
        'a4' : testma4,
        'a5' : testma5,
        'a6' : testma6,
        'a7' : testma7,
        'a8' : testma8
})

X = testset[['close', 'a3' , 'a4' , 'a5','a6' ,'a7','a8']].values
X_train, X_test, y_train, y_test = train_test_split(X,testdata, random_state =0)

model = MLPClassifier()
model.fit(X_train, y_train)

tp = 0
position = 0
aum = []
for i in range(7000,7671): 
    nextval =[[vix[i], ma3[i], ma4[i], ma5[i], ma6[i], ma7[i], ma8[i]]]
    prediction = model.predict(nextval)
    if(prediction[0] ==0):
        position = -1
    else:
        position =1

    profit = (vix[i+1] - vix[i]) * position
    tp+=profit
    aum.append(tp)

plt.plot(aum)
plt.show()

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

df = pd.read_csv("runtimes.csv")

df = df.groupby(['AlgorithmName', 'P_or_S']).agg(['mean', 'std'])


sns.set(style = 'dark')

df.unstack(level =1).iloc[:, 4:-2].plot(kind = 'barh')
plt.xticks(rotation = 90)
plt.legend(["Partially Sorted Data", "Unsorted Data"])

plt.show()

print(df)
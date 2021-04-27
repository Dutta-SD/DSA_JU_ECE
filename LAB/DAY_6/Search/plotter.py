import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


df = pd.read_csv("SearchRuntimes.csv")

df = df.groupby(['AlgorithmName']).agg(['mean'])


sns.set(style = 'dark')

df.iloc[:, -1].plot(kind = 'barh')
plt.title("Runtime of Search Algorithms")

plt.xticks(rotation = 90)

plt.show()

print(df)
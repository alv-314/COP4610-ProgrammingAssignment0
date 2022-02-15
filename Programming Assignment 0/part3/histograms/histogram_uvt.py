import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv('scenario3.csv',
                   delimiter=',',
                   dtype={'u': int, ' v': float, ' t': float, ' v/t': float, ' 4u - 5v + 2t': float})
plt.hist(data[' 4u - 5v + 2t'],
         bins=100,
         histtype='bar')
plt.title('Sequence 4U - 5V + 2T')
plt.xlabel('Bins')
plt.ylabel('Frequency')

plt.show()

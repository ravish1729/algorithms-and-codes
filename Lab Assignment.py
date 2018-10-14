import pandas as pd
import statsmodels.api as sm
from statsmodels.formula.api import ols

datafile="PlantGrowth.csv"
data = pd.read_csv(datafile)
mod = ols('weight ~ group',
          data=data).fit()

aov_table = sm.stats.anova_lm(mod, typ=2)
print(aov_table)
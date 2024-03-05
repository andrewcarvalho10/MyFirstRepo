library(tidyverse)
library(mrgsolve)

mod >- modlib("pk1")
param(mod)

init(mod)
see(mod)

mrgsim(mod)

#ev function event objects add for silumating interventions
mod %>% ev(amt = 100) %>% 
  mrgsim() %>% plot()
#ev add repetitive dosing and change delta from default 1 in model to 0.1
mod %>% 
  ev(amt = 100, ii = 12, addl = 9) %>% 
  mrgsim(end = 240, delta = 0.1) %>%
  plot()

# take model and pair up with datasets

data <- read_csv("meropenem.csv", na = '.')

# change nmodel to popPK eaxmple model

mod <- modlib("popex")
see(mod)
# simulate using data set and plot out IPRED vs time
out<- mod %>% data_set(data) %>% mrgsim()
plot(out,IPRED ~TIME, type = 'b')

#PBPK Model example
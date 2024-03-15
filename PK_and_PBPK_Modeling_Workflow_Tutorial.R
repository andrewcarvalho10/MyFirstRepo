library(tidyverse)
library(mrgsolve)
library (ggplot2)
library(PKPDsim)

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

mod <-mread_cache("rifampicin_midazolam", delta = 0.1)
param(mod)
init(mod)
mod
# simulate 600mg dose Req = request compartment etc.
rif <- ev (amt = 600)
mod %>% 
  ev(rif) %>% 
  Req(Ccentral) %>% 
  mrgsim(end=240)
## multiple rif(rifampcicin) doses( daily doses for 10 days)
rif <- mutate(rif, ii = 24, addl =9)

rif
out<-
  mod %>% 
  ev(rif) %>% 
  mrgsim(end=240)  
## do a ggplot
p <- plot(out, Ccentral ~ time)
ggplot(as_tibble(out), aes(time/24,Ccentral)) +
  geom_line(lwd = 1) + theme_bw()+
  scale_x_continuous(name = "Time (shutup)", breaks = seq(0,10,2))


## investigate observed decrease in AUCs can t do because PKPDmisc package was removed
library(caTools)
aucs <-
  out %>% 
  mutate(DAY = 1+floor(time/24)) %>% 
  group_by(DAY) %>% 
  summarise(AUC = partial.auc(time,Ccentral)) %>% 
  ungroup %>% 
  mutate(pAUC = 100*AUC/first(AUC)) %>% 
  filter(DAY < 10)
## UGT and CYP induction
simsm <- 
  out %>%
  as_tibble() %>%
  gather(variable, value, c(UGT_ratio_HC5, CYP3A4_ratio_HC5))

simsm %>%
  ggplot(., aes(time/24, value, col = variable)) + 
  geom_line(lwd =2 ) + 
  scale_color_brewer(palette = "Set2",name="",labels=c("CYP3A4", "UGT")) + 
  scale_x_continuous(name="Time (day)", breaks = seq(0,10,2)) + 
  ylab("fold induction") + theme(legend.position  = "bottom")

## See midazolam DDI
mid <- ev(amt =3, cmt ="Mgutlumen")
mid

mod %>% mrgsim_e(mid, outvars = "Cmidazolam", end =240) %>% plot()

## Simulate 75 mg of rif QD for 7 days

rif <- ev(amt = 75, ii = 24, addl = 6, cmt = "Xgutlumen")

## then simulate a sequence do rif then do midazolam after waiting 12 hours
rif_mid <- ev_seq(rif, wait = -12, mid)
mid <- filter(rif_mid, cmt == "Mgutlumen")
both <- as_data_set(mid, rif_mid)
both

sims <-
  mod %>% 
  mrgsim_d(both, Req= "Cmidazolam", end = 166) %>% 
  filter_sims(time>= 156) %>% 
  mutate(ID = factor(ID, labels = c("Midazolam", "Midazolam after Rif")))

## do a ggplot
ggplot(sims, aes(time -156,Cmidazolam,col = factor(ID))) +
  geom_line(lwd = 1) +
  scale_y_continuous(trans = "log10", limits = c(0.1,10)) +
  scale_x_continuous(name = "time (hours)", breaks = seq(0,10,2)) +
  scale_color_brewer(palette = "Set2", name ="")

# make a function ro wrap up workflow for single dose

sim_ddi <- function(rif_dose, mid_dose = 3) {
  mid <- ev(amt = mid_dose, cmt = 2)
  rif <- ev(amt = rif_dose, ii = 24, addl = 6)
  rif_mid <- ev_seq(rif, wait = -12, mid)
  
  mod %>% 
    mrgsim_e(rif_mid, Req="Cmidazolam", end = 166) %>% 
    filter_sims(time >= 156) %>%
    mutate(rif = rif_dose, mid = mid_dose)
}

sim_ddi(600)

out <- map_df(seq(0,600,10), .f = sim_ddi)



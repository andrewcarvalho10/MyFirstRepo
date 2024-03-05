#TESTING Rstudio function and packages
library(tidyverse)
library(mrgsolve)
library(dplyr)
library(magrittr)
library(modmrg)
data()
mod <- mread("pk1cmt", modlib())
view("pk1cmt", modlib())
mod
param(mod)
init (mod)
mod %>% mrgsim()
mod %>% mrgsim() %>% class()
mod %>% mrgsim() %>% plot()
# add dosing event 100mg PO X 1
mod %>% ev(amt= 100) %>% mrgsim() %>% plot
#dose to compartment 2
mod %>% ev(amt=100, cmt=2) %>% mrgsim %>% plot
 #events
e1 <- ev(amt=300, ii= 24, addl = 3)
e2 <- ev(amt=100, ii= 8, addl = 15)
e <- e1 %then% e2
# simuulate events

mod %>%  ev(e) %>% mrgsim() %>% plot(type= 'b')
mod %>% ev(e) %>% mrgsim(end=240,delta=0.1) %>% plot
mod %<>% update(end=240,delta=0.1)
mod %>% Req(EV1,CP) %>% ev(e) %>% mrgsim %>% plot
#Request CP, end –> 96
mod %<>% Req(CP) %>% update(end=96)

# expand data to 100/300/1000 over 10H Q24H x3
data <- expand.ev(amt=c(100,300,1000),
                  ii=24, addl=2, cmt=2)
data %<>% mutate(rate = amt/10)
data
# simulate
mod %>% data_set(data) %>% mrgsim %>% plot

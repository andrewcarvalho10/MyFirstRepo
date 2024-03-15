##tools optimization  demo

#Swiss Fertility and Socioeconomic IndicatorsWe'll get started with the introduciton to optimization with an easy 
#data set and an easy model. Data were collected from 47 French-speaking provences around 1888.

library(tidyverse)
library(broom)
library(ggplot2)
library(mrgsolve)
theme_set(theme_bw())

data(swiss)
glimpse(swiss, width = 60, strict.width = "cut")

ggplot(swiss, aes(Examination,Fertility)) + geom_point() + geom_smooth()

fit <- lm(Fertility ~ Examination, swiss)
tidy(fit)
# Optimization the `R` way

##We'll need

  1. A __model__
      - The model generates the data (dependent variable) based on parameters and 
      predictors
  1. Some __data__
      - Using `swiss` for now
  1. An __objective function__
       - To quantify how consistent a set of parameters are with the 
      observed data
  1. An __optimizer__
      - Search the parameter space for most optimal parameter value


## model for this data make function called linear-model
  ## Model
   #The parameters are 
 # - `intercept`
 # - `slope`
  #And the predictor is `ex` ... in our example `Examination` 
  #This is pretty simple stuff.  But we'll' wrap it up in a function to call like this:

linear_model <- function(intercept, slope, ex) {intercept = slope *ex}
  
## DataHow you want to set this up is a bit dependent on your application.  
 ## I'm going to get vectors called `ex` for the `Examination` value (predictor)
  ##and `fer` for `Fertility` (the dependent variable).
  
ex <- swiss[("Examination")]  
fer <- swiss[("Fertility")]

## Objective function We'll write this function so that 

#  1. The first argument is `par`, the parameters we want to evaluate
      #- Par will be a vector of length 2, the intercept and the slope
  #1. We will also pass in the predictor (`ex`) and the data (`fer`), which 
     #we'll need to calculate the objective function

ofv <- function(par, ex, fer) {fer_hat <- linear_model(par[1], par[2], ex) sum((fer-fer_hat)^2)}
  
  #This is an _O_ rdinary _L_ east _S_ quares objective function.  
  
  #Working backward:
    
    #1. We return the squared difference between the predicted values (`fer_hat`) and the data
 # 1. We generate the predicted values from our linear model function, 
 # the proposed parameters and the data
 # 1. The optimizer will propose a set of parameters for us to evaluate
  
  
 #Let's test the objective function
  theta <- c(70, -2) 
  ofv(theta, ex, fer)
# is that good or bad? when looking back at the data the intercept is more like 80 not 70 so.. let ty that
  theta <- c(80, -1.0)
  ofv(theta, ex, fer)
  theta <- c(86.8, -1.0)
  ofv(theta, ex, fer)
  theta <- c(80, -1.5)
  ofv(theta, ex, fer)
# better but theres a better way to  do it by a parameter search
# Let's do this for a big batch of parameters
#- intercept from 75 to 95
#- slope from -2 to 0
  
  test <-  expand.grid(intercept = seq(75,95,1), slope = seq(-2,0,0.1))
  head(test)
  # now calculate the vlaue of the objective funstio for each parameter set
  test <- mutate(
    test, 
    value = pmap_dbl(test, .f=function(intercept,slope) {
      ofv(c(intercept,slope), ex = ex, fer = fer)
    })
  )
 
arrange (test,value) %>% head
ggplot(test) + geom_contour(aes(intercept,slope,z=value),bins=80)

# Optimize

#We know there is a set of parameters that really gets us the smallest
#value of the objective function and are therefor the "optimal" parameters.

#We invoke an optizer in R to search the parameter space and find that set of 
#parameters.

#Start with an optimizer that comes with R in the `stats` package.  `optim`
#by default does Nelder-Mead optimization algorithm.

#When we call `optim`, we have to give an inital guess (`par`) and 
#the function to minimize (`ofv`).  We also pass in the 
#predictor and the vector of observed data so we can calculate the sum of squares.

fit<- optim(c(100,1)), ofv, ex = ex, fer = fer
fit$par
lm(Fertility ~ Examination, swiss)

# try minqa optimizer
library(minqa)
fit <- newuoa(theta, ofv, ex = ex, fer=fer, control = list(iprint =20))

fit$par
# another optimizer DE ( global optimizer a generic algorithm) used for QSP models
library(DEoptim)

lower <- c(intercept=0, slope = -100)
upper<- c(intercept =150, slope =100)

con <- DEoptim.control(itermax = 80,trace = 2)
set.seed(112233)
fit <- DEoptim(ofv,lower, upper, ex =ex, fer = fer, control = con)

## Maximum likelihood estimation

#Let's write a new (R) function where we optimize based on a normal likelihoodfunction. 

#The arguments are the same as the OLS function.  Now, rather than comparing 
#predictions against data using sum of squares, we compare based on 
#normal likelihood function.

ml <- function(p, ex, fer) {
  
  fer_hat <- linear_model(p[1], p[2], ex)
  
  like <- dnorm(fer, fer_hat, p[3], log = TRUE)
  
  -1*sum(like)
}
```
#Test the function now

```{r}
theta <- c(intercept = 10, slope = 1, sd = 2)

ml(theta, ex, fer)

# And we get the same answer
```{r}
fit <- newuoa(theta, ml, ex = ex, fer = fer)

fit$par

fit$fval

# Extended least squares

```{r}
els <- function(p, ex, fer) {
  
  fer_hat <- linear_model(p[1], p[2], ex)
  
  0.5 * sum((fer - fer_hat)^2/p[3] + log(p[3]))
}
```

```{r}
fit.els <- newuoa(theta, els, ex = ex, fer = fer)

fit.els$par

fit.els$fval


#try NLME package "fdHess

# get standard error estimate

library(numDeriv)

he <- hessian(ml, fit$par, ex = ex, fer = fer)

he
library(nlme)

he <- fdHess(pars  = fit$par, fun = ml, ex = ex, fer = fer)
he$Hessian %>% solve() %>% diag() %>% sqrt()
fit$par

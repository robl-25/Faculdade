rm(list = ls())

c1 = c2 = 2.05
xmin = -10
xmax = 10
vmin = -0.5
vmax = 0.5

n_part = 100
n_var = 2
max_iter = 300

fobj = function(x)
  sum(x^2)/sqrt(abs(max(x)))

#particulas
X =  matrix (runif ( n_part *n_var, xmin, xmax), ncol = n_var)

#memoria
Y = X

#velocidades
V = matrix (runif ( n_part *n_var, vmin, vmax), ncol = n_var)

fx = apply(X,1,fobj)

gBest = X[which.max(fx),]

fi = c1 + c2
k = 2/(abs(2-fi-sqrt((fi*fi) - 4*fi)))
w = 1

for (i in 1:max_iter){
  cat("inIter=", i, "gBest=", gBest," gBestVal=", max(fx),"\n")
  plot(X,xlim = c(xmin,xmax),ylim = c(xmin,xmax))
  points(Y,col = 2)
  points(gBest[1], gBest[2], col=3, pch="X")
  Sys.sleep(0.1)

  r1 = runif(1)
  r2 = runif(1)

  V = k*(w*V + c1 *r1* (Y-X) + c2 *r2* t(gBest - t(X)))
  V [V > vmax] = vmax
  V [V < vmin] = vmin

  w = 1 - (i/max_iter)

  X = X+V
  X [X > xmax] = xmax
  X [X < xmin] = xmin


  fx_novo = apply (X,1,fobj)
  pos = fx_novo > fx

  if(length(pos) > 0){
    Y[pos, ] = X[pos, ]
    fx[pos] = fx_novo[pos]
    gBest = Y[which.max(fx),]
  }
}
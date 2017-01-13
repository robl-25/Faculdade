rm(list = ls())

xmin = -10
xmax = 10
vmin = -0.5
vmax = 0.5

n_part = 100
n_var = 2
max_iter = 300
rodadas = 50

#particulas
X =  matrix (runif ( n_part *n_var, xmin, xmax), ncol = n_var)

#velocidades
V = matrix (runif ( n_part *n_var, vmin, vmax), ncol = n_var)

fobj = function(x){ # Banana
    x1 = x[1]
    x2 = x[2]
    -(100 * (x2 -(x1*x1))^2 + (1 - x1)^2)
}

res = NULL

pso = function(X, Y, V, xmin, xmax, vmin, vmax, n_part, n_var, max_iter, use='n'){
    c1 = c2 = 2.05

    #memoria
    Y = X

    fx = apply(X,1,fobj)

    gBest = X[which.max(fx),]

    if(use == 'k'){
        fi = c1 + c2
        k = 2/(abs(2-fi-sqrt((fi*fi) - 4*fi)))
    }
    else{
        k = 1
    }
    w = 1

    #X11()
    for (i in 1:max_iter){

        r1 = runif(1)
        r2 = runif(1)

        V = k*(w*V + c1 *r1* (Y-X) + c2 *r2* t(gBest - t(X)))
        V [V > vmax] = vmax
        V [V < vmin] = vmin

        if(use == 'w'){
            w = 1 - (i/max_iter)
        }

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
    max(fx)
}

for(j in 1:rodadas){

    cat("\r", (j*100)/rodadas, "%")

    bestK = pso(X, Y, V, xmin, xmax, vmin, vmax, n_part, n_var, max_iter, 'k')
    bestW = pso(X, Y, V, xmin, xmax, vmin, vmax, n_part, n_var, max_iter, 'w')
    bestN = pso(X, Y, V, xmin, xmax, vmin, vmax, n_part, n_var, max_iter)

    res = rbind(res, c(bestN, bestW, bestK))
}


boxplot(res)
boxplot(abs(res - 1e-50), log="y")

tabela_grupos = NULL
for(g in 1:ncol(res)){
    tabela_grupos = rbind(tabela_grupos, cbind(g, res[,g]))
}

print(pairwise.wilcox.test(tabela_grupos[,2], tabela_grupos[,1]))

# banana
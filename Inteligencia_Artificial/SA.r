rm(list = ls())

xmin = -5
xmax = 15

n_part = 100
n_var = 2
max_iter = 300
rodadas = 1000

T0 = 200

banana = function(x){ # Banana
    x1 = x[1]
    x2 = x[2]
    -(100 * (x2 -(x1*x1))^2 + (1 - x1)^2)
}

fobj = function(x, a=1, b=5.1/(4*pi^2), c=5/pi, r=6, s=10, t=1/(8*pi)){ #branin
    x1 = x[1]
    x2 = x[2]

    term1 = a * (x2 - b*x1^2 + c*x1 -r)^2
    term2 = s*(1-t)*cos(x1)

    y = term1 + term2 + s

    y
}

X = runif(2, xmin, xmax)
limitsx = c(xmin, xmax)

SA = function(X, T0, maxiter, alfa, limitsx){
    s = X
    T_t = T0
    iter = 0
    s_estrela = s
    xmin = limitsx[1]
    xmax = limitsx[2]

    # X11()

    while(T_t>0 && iter<maxiter){

        P = runif(2, -1, 1)
        s_linha = s + P

        if(s_linha[1] < xmin){
            s_linha[1] = xmin
        }
        else if(s_linha[1] > xmax){
            s_linha[1] = xmax
        }

        if(s_linha[2] < xmin){
            s_linha[2] = xmin
        }
        else if(s_linha[2] > xmax){
            s_linha[2] = xmax
        }

        delta = fobj(s_linha) - fobj(s)

#         plot(s[1], s[2], xlim=c(xmin, xmax), ylim=c(xmin,xmax), cex=2,
#              main=paste("Temp = ", T_t, " delta = ", delta, " prob = ",
#                         exp(-delta/T_t)))
#
#         points(s_estrela[1], s_estrela[2], xlim=c(xmin, xmax),
#                ylim=c(xmin,xmax), cex=2, pch="X")

        # Sys.sleep(0.1)

        if(delta < 0){
            s = s_linha
            if(fobj(s) < fobj(s_estrela)){
                s_estrela = s
            }
        }
        else if(runif(1) < exp(-delta/T_t)){
            s = s_linha
        }

        T_t = alfa * T_t
        iter = iter + 1

    }
    list(s_estrela, fobj(s_estrela))
}

res = NULL
res_e = NULL

for(j in 1:rodadas){

    cat("\r", (j*100)/rodadas, "%")

    sa_t1 = SA(X, T0, max_iter, 0.9, limitsx)
    sa_t2 = SA(X, T0, max_iter, 0.999, limitsx)
    sa_t3 = SA(X, T0, max_iter, 0.7, limitsx)

    res = rbind(res, c(sa_t1[[2]], sa_t2[[2]], sa_t3[[2]]))
   # res_e = rbind(res, c(sa_t1[[1]], sa_t2[[1]], sa_t3[[1]]))
}


boxplot(res)
boxplot(abs(res - 1e-50), log="y")

tabela_grupos = NULL
for(g in 1:ncol(res)){
    tabela_grupos = rbind(tabela_grupos, cbind(g, res[,g]))
}

print(pairwise.wilcox.test(tabela_grupos[,2], tabela_grupos[,1]))
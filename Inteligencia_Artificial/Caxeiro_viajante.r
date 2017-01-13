rm(list = ls())

xmin = -100
xmax = 100
n_cid = 10

cidades = matrix(runif(n_cid*2, xmin, xmax), ncol = 2)

limitsx = c(xmin, xmax)

fobj = function(cidades, s, n_cid){

    distancia = 0

    for(i in 1:n_cid){
        a = s[i]

        if(i == n_cid){
            b = s[1]
        }
        else{
            b = s[i+1]
        }

        v1 = max(a, b)
        v2 = min(a, b)

        distancia = distancia + sqrt((cidades[v1, 1] + cidades[v2, 1])^2
                    + (cidades[v1, 2] + cidades[v2, 2])^2)
    }

    distancia
}

gera_ciclo = function(cidades, n_cid){
    sample(n_cid, replace=F)
}

gera_filho = function(cidades, n_cid, s){
    aux1 = sample(n_cid, 1)
    aux2 = sample(n_cid, 1)

    aux3 = s[aux1]
    s[aux1] = s[aux2]
    s[aux2] = aux3

    s
}

max_iter = 1000

SA = function(X, T0, maxiter, alfa, limitsx, mat_dist, n_cid){
    s = gera_ciclo(X, n_cid)
    T_t = T0
    iter = 0
    s_estrela = s
    xmin = limitsx[1]
    xmax = limitsx[2]

    while(T_t>0 && iter<maxiter){

        s_linha = gera_filho(X, n_cid, s)

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

        delta = fobj(cidades, s_linha, n_cid) - fobj(cidades, s, n_cid)

        if(delta < 0){
            s = s_linha
            if(fobj(cidades, s, n_cid) < fobj(cidades, s_estrela, n_cid)){
                s_estrela = s
            }
        }
        else if(runif(1) < exp(-delta/T_t)){
            s = s_linha
        }

        T_t = alfa * T_t
        iter = iter + 1

    }
    list(s_estrela, fobj(cidades, s_estrela, n_cid))
}

sa_t1 = SA(cidades, T0, max_iter, 0.999, limitsx, mat_dist, n_cid)

plot(cidades, col="white")
text(cidades[,1], cidades[,2], 1:n_cid)

mat_dist = matrix(dist(cidades))

sol = sa_t1[[1]]

lines(rbind(cidades[sol, ], cidades[sol[1], ]), col=2)

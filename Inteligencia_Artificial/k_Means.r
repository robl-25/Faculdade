rm(list = ls())

#set.seed(24)

n = 300
nc = 2
xmin = 0
xmax = 12

#dados = matrix(runif(n*nc, xmin, xmax), ncol = nc, byrow = TRUE)

#Separa os dados
#grupos = as.numeric(dados[,1] > 0.5)

#plot(dados, col = grupos+1, pch = 19)

#Gera os centroides
#lista = by(dados, grupos, colMeans)

dados = c()

# Estrutura do tipo C
dados = cbind(runif(n,0,10), runif(n,0,2))
dados = rbind(dados, cbind(runif(n, 0, 10), runif(n, 10, 12)))
dados = rbind(dados, cbind(runif(n, 0, 2), runif(n, 0, 12)))

# Circuito Interno
# dados = null
dados = rbind(dados, cbind(rnorm(n, 6, 0.5), rnorm(n, 6, 0.5)))

#Circulo Externo
dados = rbind(dados, cbind(rnorm(n, 12, 0.5), rnorm(n, 6, 0.5)))

distance = function(a, b) sqrt(sum((a-b)^2))

kmeans = function(k, dados, maxiter){

    grupos = rep(0, nrow(dados))
    grupos_aux = rep(0, nrow(dados))
    centroides = matrix(runif(k*nc, xmin, xmax), ncol=nc, byrow=TRUE)
    tam_dados = nrow(dados)
    tam_centroides = nrow(centroides)
    tam_grupos = nrow(dados)

    for(l in 1:maxiter){

        terminar = FALSE

        for(i in 1:tam_dados){

            min_dist = 100000000

            for(j in 1:tam_centroides){
                aux1 = dados[i,]
                aux2 = centroides[j,]

                distancia = distance(aux1, aux2)

                if(min_dist > distancia){

                    min_dist = distancia

                    if(grupos_aux[i] != j){

                      grupos_aux[i] = j
                      terminar = TRUE

                    }

                }
            }
        }

        #aux = sum(grupos == grupos_aux)

        #if(aux != tam_grupos){
          #grupos = grupos_aux
        #}

        var = any((grupos == grupos_aux) == FALSE)

        if(var){
            grupos = grupos_aux
        }

        else{
          terminar = FALSE
        }

        a = round(runif(1, 1, 25))
        plot(dados, col = grupos+1, pch = a)

        Sys.sleep(0.5)

        lista = by(dados, grupos, colMeans)

        centroides = do.call(rbind, lista)

        if(terminar == FALSE){
            cat("Terminou antes de maxiter com l = ", l)
            return(list(centroides = centroides, grupos = grupos))
        }

    }

    list(centroides = centroides, grupos = grupos)
}

ret = kmeans(3, dados, 1000)

grupos = ret[[2]]
plot = round(runif(1, 1, 25))

plot(dados, col = grupos+1, pch = plot)

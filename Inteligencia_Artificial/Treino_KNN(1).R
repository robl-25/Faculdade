rm(list = ls())

# set.seed(1)

nr = 10
nc = 2
minx = -1
maxx = 1

treino = matrix(
  runif(nr * nc, minx, maxx),
  ncol = nc
)

# inidices 1= linha, 2 = coluna
resp_treino = apply(treino, 1, sum)

####################################################################
# teste com o KNN

novo_ex = matrix(runif(1 * nc, 0, 0.5), ncol = nc)
resp_ex = apply(novo_ex, 1, sum)

distance = function(a, b) sqrt(sum((a-b)^2))

distance(c(1,2), c(3,7)) == sqrt( (1-3)^2 + (2-7)^2 )

vet_dist = apply(treino, 1, 
                 function(exemplo)
                   distance(exemplo, novo_ex))
####################################################################
k = 5

# sort ordena um vetor
# retorna o indice do vetor ordenador em relacao ao nao ordenado
knn = order(vet_dist)[1:k]

# mean calcula a media
pred_ex = mean(resp_treino[knn])

####################################################################
# Plots

plot(treino, col="white")
text(treino[,1], treino[,2], round(resp_treino, 2))

text(novo_ex[1,1], novo_ex[1,2], "?", col="blue")

apply(treino[knn,], 1, function(exemplo)
  lines(rbind(novo_ex,exemplo)))

lines(rbind(novo_ex, exemplo))

text(novo_ex[1,1], novo_ex[1,2]+0.1, round(pred_ex,2), col="blue")
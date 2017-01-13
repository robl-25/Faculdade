rm(list = ls())

set.seed(1)

xmin_treino = -100
xmax_treino = 100

xmin_teste = -50
xmax_teste = 50

nr_treino = 100
nr_teste = 500

nc = 100

x_treino = matrix(runif(nr_treino*nc, xmin_treino, xmax_treino), ncol = nc)
# x_teste = matrix(runif(nr_teste*nc, xmin_teste, xmax_teste), ncol = nc)
x_teste = matrix(rnorm(nr_teste*nc, 0, 10), ncol = nc)

y_treino = apply(x_treino, 1, function(x) (sum(x)/max(x)*sd(x)))
y_teste = apply(x_teste, 1, function(x) (sum(x)/max(x)*sd(x)))

print(summary(y_treino))
print(summary(y_teste))

knn = function(k, x_treino, y_treino, x_teste){
  apply(x_teste, 1, function(xteste)
    mean(
        y_treino[
              order(
                  apply(x_treino, 1, function(xtreino)
                      sqrt( sum( (xtreino - xteste)^2) ) 
                  ) 
              )[1:k]
          ] 
    ) 
  ) 
}

max_k = 100
resp_k = sapply(1:max_k, function(k){
  pred_teste = knn(k, x_treino, y_treino, x_teste)
  erro = pred_teste - y_teste
  mae = mean(abs(erro))
  mse = mean(erro^2)
  rmse = sqrt(mse)
  c(mae, mse, rmse)
})

apply(resp_k, 1, min)

apply(resp_k, 1, which.min)

# OU

min_mae = min(resp_k[1,])
min_mse = min(resp_k[2,])
min_rmse = min(resp_k[3,])

k_mae = which.min(resp_k[1,])
k_mse = which.min(resp_k[2,])
k_rmse = which.min(resp_k[3,])

matplot(t(resp_k), type="l", log="y", lwd=4)


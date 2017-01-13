rm(list = ls())

dados = ...


####################################One Row#####################################

contagens = apply(dados, 2, function(valores){
    table(valores, dados[,ncol(dados)])
})

caras = 1

erros = apply(contagens[[caras]], 1, function(cont){
    maior = which.max(cont)
    menor = which.min(cont)
    data.frame(valor=names(cont[maior]), erro=cont[menor])
})

############################ LM ################################################

aux = sample(x_teste)
x_teste = matrix(aux, nc)

### Seleciona de x uma parte
x_teste = x_treino[-(1:5)]

modelo = lm(y_treino ~ ., data.frame(x_teste))

pred_y = predict(modelo, newdata = data.frame(x_teste))

OU

betas = solve(t(x)%*%x) %*% (t(x)%*%y)

previsao = betas[,1] %*% t(x)

Erros
erro = pred_y - y_teste
mae = mean(abs(erro))
mse = mae^2
rmse = sqrt(mse)

#################################KNN############################################

knn = function(dadosx, dadosy, teste, k){
    apply()
}

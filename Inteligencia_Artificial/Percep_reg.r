# Perceptron para aprender portas logicas

rm(list = ls())

set.seed(1)

n = 100
nc = 2

xmin = -1
xmax = 1

Entradas = matrix(runif(n*nc, xmin, xmax), ncol = nc, byrow=TRUE)

Saidas = apply(Entradas, 1, function(x) sum(x))

Entradas = cbind(1, Entradas)

# Erro maximo
limiar = 0.1

max_epocas = 50

melhor_res = c(Inf, runif(3))

for(j in 1:100){
  pesos = runif(3)
  
  alfa = runif(1, 0, 1)
  
  pos = sample(nrow(Entradas))
  Entradas = Entradas[pos,]
  Saidas = Saidas[pos]
  
  for(epoca in 1:max_epocas){
    erro = 0
    
    for(i in 1:nrow(Entradas)){
      saida = sum(pesos * Entradas[i,])
      
      if(saida != Saidas[i]){
        erro = erro + ((Saidas[i] - saida)^2)
        pesos = pesos + alfa * (Saidas[i] - saida) * Entradas[i,]
      }
    }
    
    erro = erro/n
    
    cat("\nEpoca=", epoca, " MSE=", erro, " Pesos=", pesos, "\n")
    
    resultado = c(erro, epoca, j, alfa, pesos)
    
    if(erro < melhor_res[1]){
      melhor_res = resultado
    }
    
    if(erro < limiar){
      break
    }
    
  }
}

cat("\nMelhor Erro = ", melhor_res[1], " Epoca = ", melhor_res[2])
cat(" Alfa = ", melhor_res[4], " j = ", melhor_res[3])
cat(" pesos = ", melhor_res[-(1:4)])


predicao = melhor_res[-(1:4)] %*% t(Entradas)

plot(Saidas, predicao)
plot(sort(Saidas), col=3)
points(sort(predicao), col=2)

modelo = lm(Saidas ~ ., data=data.frame(Entradas[,-1]))
print(summary(modelo))

sum(modelo$residuals)

points(sort(predict(modelo)), col=3)

matplot(cbind(Saidas, predicao[1,], predict(modelo)), type="l", lwd=2)
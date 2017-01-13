# Perceptron para aprender portas logicas

rm(list = ls())

set.seed(1)

# Porta XOR

Entradas = matrix(c(
  0, 0,
  0, 1,
  1, 0,
  1, 1
), ncol = 2, byrow=TRUE)

saidas = c(0, 1, 1, 0)

Entradas = cbind(1, Entradas)

pesos = rep(100, ncol(Entradas))

alfa = 0.5

limiar = 0.5

max_epocas = 10000000

for(epoca in 1:max_epocas){
  erro = 0

  for(i in 1:nrow(Entradas)){
    soma = sum(pesos * Entradas[i,])

    if(soma > limiar)
      saida = 1

    else
      saida = 0

    delta = saidas[i] - saida

    if(abs(delta) != 0){
      pesos = pesos + alfa * delta * Entradas[i,]
      erro = erro + 1
    }
  }

  cat("\nEpoca=", epoca, " Erro=", erro, " Pesos=", pesos, "\n")

  if(erro == 0)
    break;

}

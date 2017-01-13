# Limpar o ambiente

rm(list = ls())

set.seed(123)

#Criar conjunto de dados

n = 10
min = 1
max = -1

x = runif(n, max, min)
y = 7*(x^2) + sqrt(abs(x))

plot(x,y)

### Modelo de previsao Linear sem intercepto (1)
### Modelo de previsao Linear com intercepto (2)

regresor1 = x

regressor2 = cbind(1 ,x)

# (X'X)^(-1) X'y
beta1 = solve(t(regressor1)%*%regressor1) %*% (t(regressor1) %*% y)

# beta = b0*1 * b1*X1
beta2 = solve(t(regressor2)%*%regressor2) %*% (t(regressor2) %*% y)

# Y = b1 X1
previsor1 = betas1 * regressor1

previsor2 = beta2[1]*regressor2[,1] + beta2[2]*regressor2[,2]

points(x, previsor1, pch="1", col=2)
points(x, previsor2, pch="2", col=3)

#Erro absoluto medio = MAE
residuo1 = y - previsor1
mae1 = mean(abs(residuo1))
cat("MAE1=", mae1, "\n")

residuo2 = y - previsor2
mae2 = mean(abs(residuo2))
cat("MAE2=", mae2, "\n")

boxplot(cbind(residuo1, residuo2), col="steelblue")


########################
# Modelo de previsao Linear com intercepto e mais complexo
########################

regressor3 = cbind(1 ,x, x^2, x^2/100, x^2*100, sqrt(abs(x)))
#Correlacao
cor(regressor3)

#Conjunto de nao-colineares
regressor3 = regressor3[, c(1, 2, 3, 6)]

matplot(regressor3)

cor(regressor3)

beta3 = solve(t(regressor3)%*%regressor3) %*% (t(regressor3) %*% y)

previsor3 = beta3[,1] %*% t(regressor3)

points(x, previsor3, pch="3", col=4)

residuo3 = y - previsor3
mae3 = mean(abs(residuo3))
cat("MAE3=", mae3, "\n")

residuo3 = residuo3[1,]
print(summary(residuo3))

boxplot(cbind(residuo1, residuo2, residuo3), col="steelblue")

##################################

regressor4 = cbind(1 ,x, x^2, x^2/100, x^2*100, sqrt(abs(x)))
#Correlacao
cor(regressor4)

#Conjunto de nao-colineares
regressor4 = regressor4[, c(1, 2, 3, 6)]

matplot(regressor4)

cor(regressor4)

beta4 = solve(t(regressor4)%*%regressor4) %*% (t(regressor4) %*% y)

previsor4 = beta4[,1] %*% t(regressor4)

points(x, previsor4, pch="4", col=5)

residuo4 = y - previsor4
mae4 = mean(abs(residuo4))
cat("MAE4=", mae4, "\n")

residuo4 = residuo4[1,]
print(summary(residuo4))

boxplot(cbind(residuo1, residuo2, residuo3, residuo4), col="steelblue")

#Usando comandos do R

#Sem intercepto
modelo1 = lm(y ~ 0 + x)
print(summary(modelo1))

#Com intercepto
modelo2 = lm(y ~ x)
print(summary(modelo2))

modelo3 = lm(y ~ x + I(x^2) + I(x^3*3))
print(summary(modelo3))

modelo4 = lm(y ~ x + I(x^2) + I(sqrt(abs(x))))
print(summary(modelo4))
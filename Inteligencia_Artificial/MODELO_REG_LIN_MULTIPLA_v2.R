# LIMPAR O AMBIENTE
rm (list=ls())

set.seed(123)

# CRIAR O CONJUNTO DE DADOS
n = 20
minx = -1
maxx = 1

x = runif(n, minx, maxx)

y = 7 * x^2 + sqrt(abs(x))

plot(x, y)

#########################
#
# Usando modelo de regressão
# linear para predizer Y
# em funão de X
# Obs.: SEM o intercepto
#
#########################

regressor1 = x

# (X'X)⁻¹X'Y
# %*% (multiplicação matricial)
betas1 = solve(t(regressor1)%*%regressor1) %*% 
  t(regressor1) %*% y

# Y = b1 X1
previsao1 = betas1[1] * regressor1

points(x, previsao1, pch="1", col=2)

# VAMOS MEDIR A QUALIDADE DOS RESÍDUSO
# Erro absoluto medio = MAE (mean absolute error)

residuos1 = y - previsao1
mae1 = mean(abs(residuos1))
cat("MAE1=", mae1, "\n")

print(summary(residuos1))

boxplot(residuos1, col="steelblue")

#########################
#
# Usando modelo de regressão
# linear para predizer Y
# em funão de X
# Obs.: COM o intercepto
#
#########################

regressor2 = cbind(1,x)

# (X'X)⁻¹X'Y
# %*% (multiplicação matricial)
betas2 = solve(t(regressor2)%*%regressor2) %*% 
  t(regressor2) %*% y

# Y = b0 + b1*X1
previsao2 = betas2[1] * regressor2[,1] + betas2[2] * regressor2[,2]

points(x, previsao2, pch="2", col=3)

# VAMOS MEDIR A QUALIDADE DOS RESÍDUSO
# Erro absoluto medio = MAE (mean absolute error)

residuos2 = y - previsao2
mae2 = mean(abs(residuos2))
cat("MAE2=", mae2, "\n")

mean(y)
mean(previsao2)

print(summary(residuos2))

boxplot(cbind(residuos1,residuos2), col="steelblue")

#########################
#
# Usando modelo de regressão
# linear para predizer Y
# em funão de X
# Obs.: COM o intercepto
# e mais complexo
#########################

regressor3 = cbind(1,x,x^2,x^2/100,x^2*100, sqrt(abs(x)))

cor(regressor3)

# Conjunto de nao-colineares
regressor3 = regressor3[, c(1, 2, 3, 6)]

matplot(regressor3, type="l")

cor(regressor3)

# (X'X)⁻¹X'Y
# %*% (multiplicação matricial)
betas3 = solve(t(regressor3)%*%regressor3) %*% 
  t(regressor3) %*% y

# Y = b0 + b1*X1
#previsao3 = betas3[1] * regressor3[,1] + betas3[2] * regressor3[,2]
previsao3 = betas3[,1] %*% t(regressor3)

points(x, previsao3, pch="3", col=4)

# VAMOS MEDIR A QUALIDADE DOS RESÍDUSO
# Erro absoluto medio = MAE (mean absolute error)

residuos3 = y - previsao3
mae3 = mean(abs(residuos3))
cat("MAE3=", mae3, "\n")

residuos3 = residuos3[1,]

print(summary(residuos3))

boxplot(cbind(residuos1,residuos2,residuos3), col="steelblue")


# Usando códigos do R

#Sem o intercepto
modelo1 = lm ( y ~ 0 + x ) #linear model
print(summary(modelo1))

# Com o intercepto
modelo2 = lm ( y ~ x )
print(summary(modelo2))


modelo3 = lm ( y ~ x + I(x^2) + I(x^3*3))
print(summary(modelo3))

modelo4 = lm ( y ~ x + I(x^2) + I(sqrt(abs(x))))
print(summary(modelo4))

# kaizen rogramming
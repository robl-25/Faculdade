# Programa que implementa o PSO

rm()

#particulas
xmin = -10
xmax = 10
vmin = -1
vmax = 1
max_iter = 100

# Numero de particulas
n = 100

# Numero de variaveis de cada particula
qtd_var = 2

# Parametros da componente cognitiva e sociavel
c1 = c2 = 2.05

# Funcao objetivo
fobj = function(x){
  sum(x^2)/sqrt(abs(max(x)))
}

# Particulas
x = matrix(runif(n*qtd_var, xmin, xmax), ncol = qtd_var)

#memoria
y = x

#velocidades
v = matrix(runif(n*qtd_var, vmin, vmax), ncol = qtd_var)

# Calcula o fx
fx = apply(x, 1, fobj)

# Melhor solucao encontrada (linha do melhor cara)
gbest = y[which.max(fx), ]

# Valor da melhor solucao
gbestValor = max(fx)

x11()

for(i in 1:max_iter){
  
  cat("\nGBest = ", gbest, " e GBestVal = ", gbestValor)
  plot(x, xlim = c(xmin, xmax), ylim = c(xmin, xmax), pch="*")
  points(y, col = 2)
  points(gbest[1], gbest[2], col=3, pch="x")
  Sys.sleep(1)
  
  # Numero gerado de uma distribuicao
  r1 = runif(1)
  r2 = runif(1)
  
  # Formula da velocidade
  v =  v + r1*c1*(y-x) + c2*r2*t(gbest-t(x))
  
  # Deixa a particula dentro dos limites
  v[ v > vmax] = vmax
  v[ v > vmin] = vmin
  
  # Anda com a particula
  x = x + v
  
  # Volta aprticula para dentro do intervalo permitido
  x[x<xmin] = xmin
  x[x>xmax] = xmax
  
  fx_novo = apply(x, 1, fobj)
  
  # Procura as pos em que fx melhora (eh um vetor de true ou false)
  pos = fx_novo > fx
  
  # Ve se alguem melhorou
  if(length(pos) > 0){
    
    # Atualiza a memoria e o fx dos que melhoraram
    y[pos, ] = x[pos, ]
    fx[pos] = fx_novo[pos]
    
    # Atualizando o gbest e o maior valor
    gbest = y[which.max(fx), ]
    gbestValor = max(fx)
  }
  
}
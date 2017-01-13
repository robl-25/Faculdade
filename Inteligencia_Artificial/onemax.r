rm(list = ls())

# algoritmo genetico: onemax

# Funcao objetivo
aptidao = function(individuo){
  sum(individuo)
}

# Funcao de mutacao
mutacao = function(individuo, qt_genes){
  tam_ind = length(individuo)
  pos = sample(tam_ind, qt_genes)
    #round(runif(qt_genes, 1, tam_ind))

  #rapply(pos, function(i){
  for (i in pos){
    if(individuo[i] == 1){
      individuo[i] = 0
    }
    else{
      individuo[i] = 1
    }
  }
#)

  individuo
}

mutacao(rep(1, 10), 2)

cruzamento = function(individuo1, individuo2){
  tam_ind = length(individuo1)
  pos = sample(tam_ind-1, 1)
    #round(runif(1, 1, (tam_ind - 1)))
  c(individuo1[1:pos], individuo2[(pos+1):tam_ind])
}

#cruzamento(rep(1, 4), rep(2, 4))

inicia_pop = function(tam_pop, tam_tam_ind){
  matrix(round(runif(tam_pop*tam_ind, 0, 1)), ncol = tam_ind)
}

torneio = function(vet_aptidao, tam_torneio){
  aux = sample(1:length(vet_aptidao), tam_torneio, replace = F)
  aux[which.max(vet_aptidao[aux])]
}

# Laco evolutivo
tam_pop = 100
tam_ind = 100

max_gen = 100
prob_cross = 0.2
prob_mut = 0.01
qtd_mut = 2
tam_torneio = 3
elite = 1

pop = matrix(round(runif(tam_pop*tam_ind, 0, 1)), ncol = tam_ind)
fitness = apply(pop, 1, aptidao)
                #function(i) aptidao(i))
melhor_fit = NULL

for(i in 1:max_gen){

  melhor_fit = c(melhor_fit, max(fitness))

  pop_filhos = NULL
  fit_filhos = NULL

  nova_pop = NULL
  novo_fit= NULL

  pop_ant = NULL
  pop_apt = NULL

  cat("\r", (i*100)/max_gen, "%")

  for (p in 1:(tam_pop * prob_cross)){
    idx_pai1 = torneio(fitness, tam_torneio)

    idx_pai2 = torneio(fitness[-(idx_pai1)], tam_torneio)

    filho = cruzamento(pop[idx_pai1, ], pop[idx_pai2, ])
    filho = mutacao(filho, qtd_mut)
    aptidao_filho = aptidao(filho)

    pop_filhos = rbind(pop_filhos, filho)
    fit_filhos = c(fit_filhos, aptidao_filho)
  }

  pop_ant = rbind(pop_filhos, pop)
  pop_apt = c(fit_filhos, fitness)

  # Elite sempre esta na nova populacao
  aux = order(pop_apt, decreasing=TRUE)[1:elite]
  nova_pop = rbind(nova_pop, pop_ant[aux, ])
  novo_fit = c(novo_fit, pop_apt[aux])

#   for(i in 1:length(aux)){
#     nova_pop = rbind(nova_pop, pop_ant[aux[i], ])
#     novo_fit = c(novo_fit, pop_apt[aux[i]])
#     pop_ant = pop_ant[(-aux[i]), ]
#     pop_apt = pop_apt[(-aux[i])]
#
#   }
#
  #pos = sample(length(pop_apt), tam_pop - elite, replace=F)
#   pos = order(pop_apt, decreasing=TRUE)[elite:tam_pop]
#   nova_pop = rbind(nova_pop, pop_ant[pos, ])
#   novo_fit = c(novo_fit, pop_apt[pos])



  for(j in 1:(tam_pop - elite)){
    boladao = torneio(pop_apt, tam_torneio)
    nova_pop = rbind(nova_pop, pop_ant[boladao, ])
    novo_fit = c(novo_fit, pop_apt[boladao])
    pop_ant = pop_ant[-(boladao), ]
    pop_apt = pop_apt[-boladao]
  }

  pop = nova_pop
  fitness = novo_fit

  cat(" fitness: ", mean(fitness), "\n")
}

melhor = order(fitness, decreasing=TRUE)[1]
cat("Melhor individuo: ", pop[melhor, ], " fitness: ", fitness[melhor], "\n")

pior = order(fitness, decreasing=TRUE)[length(fitness)]
cat("Pior individuo: ", pop[pior, ], " fitness: ", fitness[pior], "\n")

media = mean(fitness)
cat("Fitness media da pop: ", mean(fitness))

plot(melhor_fit)

# imprimir:
# Melhor individuo e seu fitness
# Fitness medio da populacao
# Pior fitness
# Grafico mostrando a evolucao do melhor fitness

# Exercicio 2
# Fazer com senha de caracteres (senha = 'monitoria')
# letters (pega letras minusculas)

# Exercicio 3
# Fazer com numeros assim: "fobj(ind) = sum(ind^2)/(3.2*(sqrt(abs(max(ind)))))"
# tam_ind = 2 e ind[-10., 10.0] (vai de -10.0 até 10.0)

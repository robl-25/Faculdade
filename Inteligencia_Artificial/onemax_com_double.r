rm(list = ls())

# algoritmo genetico: onemax

# Funcao objetivo
aptidao = function(individuo){
  sum(individuo^2)/(3.2*(sqrt(abs(max(individuo)))))
}

# Funcao de mutacao
mutacao = function(individuo, qt_genes){
  tam_ind = length(individuo)
  pos = sample(tam_ind, qt_genes)

  for(i in pos){
    aux = runif(1, -10, 10)

    while(aux == individuo[i]){
      aux = runif(1, -10, 10)
    }

    individuo[i] = aux
  }

  individuo
}

cruzamento = function(individuo1, individuo2){
  tam_ind = length(individuo1)
  pos = sample(tam_ind-1, 1)

  c(individuo1[1:pos], individuo2[(pos+1):tam_ind])
}

torneio = function(vet_aptidao, tam_torneio){
  aux = sample(1:length(vet_aptidao), tam_torneio, replace = F)
  aux[which.max(vet_aptidao[aux])]
}

# Laco evolutivo
tam_pop = 1000
tam_ind = 2

max_gen = 100
prob_cross = 0.5
prob_mut = 0.01
qtd_mut = 2
tam_torneio = 3
elite = 1

pop = matrix(runif(tam_pop*tam_ind, -10.0, 10.0), ncol = tam_ind)
fitness = apply(pop, 1, aptidao)
melhor_fit = NULL

#x11()

for(i in 1:max_gen){

  melhor_fit = c(melhor_fit, max(fitness))

  pop_filhos = NULL
  fit_filhos = NULL


  nova_pop = NULL
  novo_fit= NULL

  pop_ant = NULL
  pop_apt = NULL

  cat("\r", (i*100)/max_gen, "%")

  for(p in 1:(tam_pop * prob_cross)){
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

  for(j in 1:(tam_pop - elite)){
    boladao = torneio(pop_apt, tam_torneio)
    nova_pop = rbind(nova_pop, pop_ant[boladao, ])
    novo_fit = c(novo_fit, pop_apt[boladao])
    pop_ant = pop_ant[-(boladao), ]
    pop_apt = pop_apt[-boladao]
  }


  pop = nova_pop
  fitness = novo_fit

  #plot(pop)
  #Sys.sleep(0.5)
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

# Exercicio 3
# Fazer com numeros assim: "fobj(ind) = sum(ind^2)/(3.2*(sqrt(abs(max(ind)))))"
# tam_ind = 2 e ind[-10., 10.0] (vai de -10.0 até 10.0)

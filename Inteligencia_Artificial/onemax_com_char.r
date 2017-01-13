rm(list = ls())

# algoritmo genetico: onemax

# Funcao objetivo
aptidao = function(individuo, senha){
  sum(individuo==senha)
}

# Funcao de mutacao
mutacao = function(individuo, qt_genes){
  tam_ind = length(individuo)
  pos = round(runif(qt_genes, 1, tam_ind))

  for(i in pos){
    aux = sample(letters, 1)

    while(aux == individuo[i]){
      aux = sample(letters, 1)
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

inicia_pop = function(tam_pop, senha){
  tam_senha = length(senha)

  matrix(sample(letters, tam_senha*tam_pop,replace=T), ncol=tam_senha, nrow=tam_pop)
}

torneio = function(vet_aptidao, tam_torneio){
  aux = sample(1:length(vet_aptidao), tam_torneio, replace = F)
  aux[which.max(vet_aptidao[aux])]
}

# Laco evolutivo
senha = strsplit("nathanvoceehmuitozikado", "")[[1]]
tam_senha = length(senha)

tam_pop = 200
tam_ind = tam_senha

max_gen = 1000
prob_cross = 0.2
prob_mut = 0.01
qtd_mut = 2
tam_torneio = 3
elite = 1

pop = matrix(sample(letters, tam_senha*tam_pop,replace=T), ncol=tam_ind, nrow=tam_pop)
fitness = apply(pop, 1, function(i) aptidao(i, senha))
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
    aptidao_filho = aptidao(filho, senha)

    pop_filhos = rbind(pop_filhos, filho)
    fit_filhos = c(fit_filhos, aptidao_filho)
  }

  pop_ant = rbind(pop_filhos, pop)
  pop_apt = c(fit_filhos, fitness)

  # Elite sempre esta na nova populacao
  aux = order(pop_apt, decreasing=TRUE)[1:elite]
  nova_pop = rbind(nova_pop, pop_ant[aux, ])
  novo_fit = c(novo_fit, pop_apt[aux])

  pos = order(pop_apt, decreasing=TRUE)[elite:tam_pop]
  nova_pop = rbind(nova_pop, pop_ant[pos, ])
  novo_fit = c(novo_fit, pop_apt[pos])

  pop = nova_pop
  fitness = novo_fit
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

# Exercicio 3
# Fazer com numeros assim: "fobj(ind) = sum(ind^2)/(3.2*(sqrt(abs(max(ind)))))"
# tam_ind = 2 e ind[-10., 10.0] (vai de -10.0 até 10.0)

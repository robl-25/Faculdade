rm(list = ls())

# Arquivo csv
tabela = read.csv("~/Downloads/play_tennis.csv", header=T)

# Faz contagens

contagens = apply(tabela[,1:(ncol(tabela)-1)], 2, function(valores)
                  table(valores, tabela,[, ncol(tabela)]))

idx_coluna = 1

erros_valores = apply(contagens[[idx_coluna]], 1, function(cont){
  maior = which.max(cont)
  menor = which.min(cont)
  data.frame(valor=names(cont[maior]), erro=cont[menor])
})


"""
dimensao = dim(tabela)
coluna = length(tabela)-1

sum_parametros = 0

for(i in 1:(length(tabela)-1)){
    dimensao = dim(table(tabela[i]))
    if(sum_parametros < dimensao){
        sum_parametros = dimensao
    }
}

linha = sum_parametros

classes = names(table(tabela[5]))

res = matrix(runif(linha*coluna, Inf, Inf), ncol = coluna, byrow=TRUE)

calculo = function(tabela, classes){

    for(i in 1:(length(tabela)-1)){

        sum_parametros = table(tabela[i])
        name_parametros = names(sum_parametros)

        tam_p = length(name_parametros)
        tam_c = length(classes)

        res_parcial = matrix(runif(tam_p*tam_c, 0, 0), ncol=tam_p, byrow=TRUE)

        for(j in 1:tam_p){

          n = sum_parametros[name_parametros[j]]

          for(z in 1:tam_c){

            at = subset(tabela, Temperature=="Sunny" & Play.Tennis=="No",
                        select=c(Temperature, Play.Tennis))

            num = dim(at)

            res_parcial[1,1] = num[1]/n
          }

        }

        for(k in 1:length(res_parcial[1,])){

            in_max = which.max(res_parcial[k,])
            res[k,i] = classes[in_max]
        }

    }
    res
}

res = calculo(tabela, classes)
"""

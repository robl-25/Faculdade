rm(list =ls())

s = c(rep(0,9), rep(1,5))

entropia = function(vetor){
    tab = table(vetor)
    n = length(vetor)
    x = 0
    
    #sum(-(tab/n)*log2(tab/n))
    for(i in 1:length(tab)){
      p = tab[i]/n
      x = x + (-p*log2(p))
    }
    x
}

entropia(s)
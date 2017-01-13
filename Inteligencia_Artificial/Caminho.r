rm(list = ls())

grafo = list(
  'SC' = c('A', 'J', 'B'),
  'J' = 'B',
  'B' = 'A',
  'RB' = 'A'
)

busca_caminho = function(grafo, origem, destino, caminho = NULL){
  caminho = c(caminho, origem)
  
  if(origem == destino)
    return (caminho)
  
  if( !(origem %in% names(grafo)) )
    return (NULL)
  
  for(no_atual in grafo[[origem]]){
    novo_caminho = busca_caminho(grafo, no_atual, destino, caminho)
    
    if(!is.null(novo_caminho)){
      return (novo_caminho)
    }
    
  }
  
  NULL
  
}

caminho = busca_caminho(grafo, 'SC', 'RB')
print(caminho)
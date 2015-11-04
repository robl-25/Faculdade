#! Define a qualidade da imagem gerada
set terminal jpeg size 800, 600

#! Define o nome da imagem
set out 'grafico.jpg'

#! Define a legenda no eixo x e y
set xlabel 'Tempo'
set ylabel 'Doentes'

#! Define a relação das colunas, por exemplo Suscetiveis por tempo
plot     'doenca.txt' using 6:1 title 'Suscetiveis' with lines, \
    'doenca.txt' using 6:2 title 'Expostos' with lines, \
    'doenca.txt' using 6:3 title 'Infectados' with lines, \
    'doenca.txt' using 6:4 title 'Recuperados' with lines, \
    'doenca.txt' using 6:5 title 'Vacinados' with lines

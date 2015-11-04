# Script para gerar graficos SIMPLES para o trabalho de
# modelagem computacional da minha namorada linda, ;)

set terminal jpeg size 1080, 600
set out 'Velocidade.jpeg'

set ylabel 'm/s'


plot './velocidade.txt' using 1:2 title 'Velocidade' with lines



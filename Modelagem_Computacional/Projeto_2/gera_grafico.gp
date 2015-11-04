# Script para gerar graficos SIMPLES para o trabalho de
# modelagem computacional da minha namorada linda, ;)

set terminal jpeg size 1080, 600
set out 'Cadeia.jpeg'

set ylabel 'Populacao'
set xlabel 'Tempo'


plot './mato.txt' using 1:2 title 'Mato' with lines,'./vaca.txt' using 1:2 title 'Vaca' with lines,'./cavalo.txt' using 1:2 title 'Cavalo' with lines,'./humano.txt' using 1:2 title 'Humano' with lines,'./leao.txt' using 1:2 title 'Leao' with lines,'./fungo.txt' using 1:2 title 'Fungo' with lines



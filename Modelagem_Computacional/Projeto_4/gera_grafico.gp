set terminal jpeg size 800, 600
set out 'grafico.jpg'
set nokey
set xlabel 'Tempo'
set ylabel 'Doentes'
plot 'doenca.txt' using 2:1 with lines

set terminal jpeg size 1800, 720
set out 'Cadeia.jpeg'

set ylabel 'Pessoas'
set xlabel 'Tempo'


plot './A.txt' using 1:2 title 'Zumbi dos Palmares' with lines,'./B.txt' using 1:2 title 'Frei Caneca' with lines,'./C.txt' using 1:2 title 'Miguel Joaquim' with lines,'./Nulo.txt' using 1:2 title 'Nulo' with lines

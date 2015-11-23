# Funciona com python3 apenas

# Assummo que o arquivo de dados esta organizado da seguinte forma:
# X1  Y1  Y2 ... Yn
# X2  ...
# ... ...
# Xn  ...

import random

XLABEL = 'Threads'
YLABEL = 'Tempo (s)'

ARQ_ENTRADA = 'Plot.txt'
ARQ_SAIDA = 'gera_grafico.gp'


def get_headers():
    with open(ARQ_ENTRADA, 'r') as arq:
        head = arq.readline()
    return head.split()[2:]


def gera_arq_entrada(quantidade_linhas=50, quantidade_ys=10,
                     valor_max=10, valor_min=0):

    # Funcao auxiliar
    def imprime_linha(arq, quantidade_y, x):
        for i in range(quantidade_y):
            a = random.randint(valor_min, valor_max)
            print(a, end='\t', file=arq)
        print(x, file=arq)

    with open(ARQ_ENTRADA, 'w') as arq:
        for i in range(quantidade_linhas):
            imprime_linha(arq, quantidade_ys, i)


def conta_quantidade_y(arq):
    arq.readline()
    entrada = arq.readline().split()
    return 1, len(entrada)
    # return len(entrada) - 1, len(entrada)

if __name__ == '__main__':

    # Gera um arquivo de entrada para testar
    # gera_arq_entrada()

    with open(ARQ_SAIDA, 'w') as out, open(ARQ_ENTRADA) as inp:

        # Define a dimensao e o formato da imagem de saida
        print('set terminal jpeg size 800, 600', file=out)

        # Define a saida do programa para um arquivo
        print('set out \'grafico.jpg\'', file=out)

        # Remove as descricoes das linhas
        # print('set nokey', file=out)

        # Define os labels
        print('set xlabel \'{}\''.format(XLABEL), file=out)
        print('set ylabel \'{}\''.format(YLABEL), file=out)

        # Configuracoes para titulos bonitinhos
        print('set encoding utf8', file=out)
        print('set termoption enhanced', file=out)

        # Imprime as linhas de plot
        print('plot', end=' ', file=out)
        indice_x, max_y = conta_quantidade_y(inp)

        for i, j in zip(range(2, max_y + 1), get_headers()):
            print(' \'{}\' using {}:{} title \'{}\' with linespoints, \\'.
                  format(ARQ_ENTRADA, indice_x, i, j), file=out)

import random

escolha = ["amarelo","marrom", "verde", "azul", "rosa", "vermelho"]
opcoes = escolha[:]
saida = []
senha = []
ganhou = ['1', '1', '1', '1']

for i in range(4):
    escolhido = random.choice(escolha)
    senha.append(escolhido)
    escolha.remove(escolhido)

print("\t****Bem-vindo ao jogo senha****\n")
print("Segue abaixo as opcoes de cores\n")
print(opcoes)
print("\ndica: a senha possui 4 cores\n")

for i in range(10):
    for j in range(4):
        sequencia = raw_input()
        try:
            local = senha.index(sequencia)
        except ValueError:
            local = -1
        if local == j:
            saida = saida + ['1']
        elif local != -1:
            saida = saida + ['0']
    
    if saida == ganhou:
        print("\nVoce acertou!!! :D\n")
        raise StopIteration
    else:
        print(saida)
        print("\nVoce errou :(\nTente novamente\n")
        saida = []

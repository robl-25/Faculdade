#!/usr/bin/env python3

import time
import datetime

def addSecs(tm, secs):
    fulldate = datetime.datetime(100, 1, 1, tm.hour, tm.minute, tm.second)
    fulldate = fulldate + datetime.timedelta(seconds=secs)
    fulldate = fulldate.time()
    return "{}:{}:{}".format(fulldate.hour, fulldate.minute, fulldate.second)

def convert_str_int(connection_time):
    try:
        return datetime.datetime.strptime(connection_time, '%H:%M:%S.%f').timestamp()
    except:
        return datetime.datetime.strptime(connection_time, '%H:%M:%S').timestamp()


def belongs(interface, connection):
    if interface['ip'] == connection['ip_begin']:
        interface['throughput'] += connection['throughput']
        interface['latency'] += connection['latency']
        interface['error'] += connection['error']
        return True

    return False


def timeout(interface, connection):
    if interface['timeout'] < connection['timeout']:
        return connection['timeout']

    return interface['timeout']


def renew(interface, connection):
    if interface['timeout'] <= connection['start_time']:
        return True

    return False


def insert_connection(interfaces, connection):
    for interface in interfaces:
        if belongs(interface, connection):
            interface['timeout'] = timeout(interface, connection)
            interface['connections']+= 1
            return interfaces.index(interface)
        elif renew(interface, connection):
            interface['timeout'] = connection['timeout']
            interface['ip'] = connection['ip_begin']
            interface['throughput'] = connection['throughput']
            interface['latency'] = connection['latency']
            interface['error'] = connection['error']
            interface['connections'] = 1
            return interfaces.index(interface)

    interfaces.append({'ip': connection['ip_begin'],
                       'timeout': connection['timeout'],
                       'throughput': connection['throughput'],
                       'latency': connection['latency'],
                       'error': connection['error'],
                       'connections': 1
                      })
    return len(interfaces) - 1




def write_output_interface(output_file, interface, interface_number, time):
    length = len(interface)
    output_file.write('{}\t'.format(interface_number))
    output_file.write('{}\t'.format(interface['throughput']))
    output_file.write('{}\t'.format(interface['latency']))
    output_file.write('{}\t'.format(interface['error']/length))
    output_file.write('{}\t'.format(length))
    output_file.write('{}\n'.format(time))


def get_lines(filename):
    aux = ("{}.txt").format(filename)
    fo = open(aux, "r")
    output = [k.split() for k in fo]
    fo.close()

    return output


def read_input(number):
    saida = get_lines(("mptcpdump/saida_{}").format(number))
    medida = get_lines(("mptcpdump/medidas_{}").format(number))

    ip_begin = saida[0][3]
    ip_end = saida[0][5]
    start_time = '{}'.format(saida[0][2])
    timeout = '{}'.format(saida[-1][2])

    for j in medida[16:]:
        if j[0] == '|':
            if j[7] != '|':
                throughput = float(j[7])
                latency = float(j[9])
                error = float(j[13])
            else:
                throughput = float(j[6])
                latency = float(j[8])
                error = float(j[12])

    return {
        'ip_begin': ip_begin,
        'ip_end': ip_end,
        'start_time': start_time,
        'timeout': timeout,
        'throughput': throughput,
        'latency': latency,
        'error': error
    }


def write_conections(output_file, connections, interface_number, time):
    for i in range(0, connections):
        output_file.write('{}.{}\t'.format(interface_number, i))


def write_graph(arq):
    maximium = 0
    for line in arq.readlines():
        if len(line) > maximium:
            maximium = len(line.split('\t')[1:-1])

    graph = open("gera_grafico_com_FIN.gp", "a")
    for i in range(0, maximium):
        if i == 0:
            graph.write("\nplot 'final.txt' using 1:{} notitle with points,".format(i+2))
        elif i >= maximium-1:
            graph.write("\t 'final.txt' using 1:{} notitle with points".format(i+2))
        else:
            graph.write("\t 'final.txt' using 1:{} notitle with points, ".format(i+2))


def get_connections():
    # arq = open('final.txt', "w")

    output_interface = open('interface_numbers.txt', "w")
    output_interface.write('numero' + '\t')
    output_interface.write('vazao' + '\t')
    output_interface.write('latencia' + '\t')
    output_interface.write('error' + '\t')
    output_interface.write('conexoes' + '\t')
    output_interface.write('time' + '\n')

    interfaces = []
    max_time = 0

    for i in range(0, 2541):
        response = read_input(i)
        time = response['start_time'].split('.')[0]
        interface_number = insert_connection(interfaces, response)
        if max_time == 0:
            max_time = time

        if time > max_time:
            break

        if i == 0:
            write_arq = addSecs(datetime.datetime.strptime(time, "%H:%M:%S"), 1)
            # arq.write('{}\t'.format(time))
            max_time = addSecs(datetime.datetime.strptime(time, "%H:%M:%S"), 300)
            for interface in interfaces:
                # write_conections(arq,
                #                  interface['connections'],
                #                  interfaces.index(interface),
                #                  time)
                write_output_interface(output_interface,
                                        interface,
                                        interfaces.index(interface),
                                        response['start_time'])
                # arq.write('\n')

        if time >= write_arq:
            print(time)
            write_arq = addSecs(datetime.datetime.strptime(time, "%H:%M:%S"), 1)
            # arq.write('{}\t'.format(time))
            for interface in interfaces:
                # write_conections(arq,
                #                  interface['connections'],
                #                  interfaces.index(interface),
                #                  time)
                write_output_interface(output_interface,
                                        interface,
                                        interfaces.index(interface),
                                        response['start_time'])
                # arq.write('\n')
    # arq.close()
    # arq = open('final.txt', "r")
    # write_graph(arq)


get_connections()


################################################################################
# Oq o codigo faz:
# result eh a variavel que tem todas as conexoes, sendo q pra cada uma tem:
# - ip de origem
# - ip de destino
# - latencia
# - vazao
# - erro

# A variavel 'final' contem uma lista no qual cada posicao contem uma lista de
# conexoes pertencentes a mesma interface, ou seja, uma lista de conexoes cujo
# ip de origem e destino eh o mesmo.

# O arquivo resultando eh formada da seguinte maneira:
# Para cada lista da variavel 'final' faca:
#   Para cada conexoes salve os ip's, latencia, erro e vazao
#   de um numero (correspondente a posicao da lista em 'final'), esse numero
#   representa a interface daquele conjunto de conexoes.

# Como eu sei que acabou uma conexao?
# - Pelo tempo final de cada conexao

# Como eu reaproveito uma interface?
# - Verifica se o tempo de encerramento eh menor que o tempo da ultima conexao.
#   Se for menor, entao usa essa interface pra uma conexao nao classificada.

# Ideia:
# vai contando o tempo e classificando as interfaces que comecam dentro do tempo
# ja contado.
#
# Se o tempo final de uma conexao ja classificada for igual ou menor que o tempo
# contado, verifica se naquela interface ainda tem alguma conexao cujo tempo
# final eh maior que o tempo contado.
#   Se nao existir, classifica a proxima conexao que nao se encaixar em outra
#   interface, como pertencente a essa.

# Ordena um dicionario pelo valor sorted(x.items(), key=operator.itemgetter(1))
# precisa do import operator, sendo x o dicionario

# Ordena, pelo valor de uma chave, uma lista de dicionarios:
# from operator import itemgetter
# list_to_be_sorted = [{'name':'Homer', 'age':39}, {'name':'Bart', 'age':10}]
# sorted(list_to_be_sorted, key=itemgetter('name'))
# output: [{'age': 10, 'name': 'Bart'}, {'age': 39, 'name': 'Homer'}]

# Posso salvar em outro vetor o maior tempo final de cada interface ja
# classificada. Ex.: vetor[0] = maior_tempo_final_da_interface_0

# Posso fazer:
# Para cada conexao:
#   Verifica se ela pertence a uma interface, com pelo menos uma conexao
#   Se pertence:
#       Verifica se o tempo final dela maior que o final guardado como maior:
#           Se sim, salva como maior tempo final
#   Senao pertencer:
#       Verifica se o tempo final de alguma interface eh menor que o inicial dessa:
#       Se for:
#           Guarda essa conexao pertencente a essa nova interface e a interface
#            ganha um novo ip de origem e destino
#       Senao:
#           Salva em um nova interface
# Problema resolvido

# O que preciso fazer agora?
#   - Salvar os parametros de QoS por interface (1)
#   - Plotar o grafico (2)

# (2) envolve plotar por tempo as conexoes, por exemplo, no tempo x as conexoes ativas (colocar como pontinhos) e
# dividir por interface (juntar os pontinhos da mesma conexoes depois), assim fica melhor de visualizar o comportamento
# delas

# Tentar salvar em outro local os parametros para cada interface

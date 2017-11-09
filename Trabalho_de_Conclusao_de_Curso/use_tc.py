#!/usr/bin/env python3

import subprocess
import time

def get_lines(filename):
    aux = ("{}.txt").format(filename)
    fo = open(aux, "r")
    output = [k.split() for k in fo]
    fo.close()

    return output

def get_command(number, connection):
    throughput = number[1]
    latency = number[2]
    error = number[3]
    throughput = '{}kbit'.format(throughput)
    latency = '{}ms'.format(latency)
    error = '{}%'.format(error)

    response = ['sudo', 'tc', 'qdisc', 'change', 'dev']
    response.extend([connection, 'root', 'handle', '1:', 'tbf', 'rate'])
    response.extend([throughput, 'latency', latency, 'burst', '1540'])

    response_error = ['sudo', 'tc', 'qdisc', 'change', 'dev']
    response_error.extend([connection, 'parent', '1:1', 'handle', '10:'])
    response_error.extend(['netem', 'loss', error])

    return [response, response_error]

def get_interface_numbers():
    numbers = get_lines('interface_numbers')
    connections = ['eno2', 'ens3f3', 'ens3f2', 'ens3f1', 'ens3f0']

    command = ['sudo', 'tc', 'qdisc', 'add', 'dev', connections[0]]
    command.extend(['parent', '1:1', 'handle', '10:', 'netem', 'loss', '0%'])
    subprocess.run(command)

    for number in numbers:
        command = get_command(number, connections[int(number[0])])
        subprocess.run(command[0])
        subprocess.run(command[1])
        time.sleep(1)

    command = ['sudo', 'tc', 'qdisc', 'del', 'dev', connections[0]]
    command.extend(['parent', '1:1', 'handle', '10:', 'netem', 'loss', '0%'])
    subprocess.run(command)

get_interface_numbers()

# controla latencia + vazao
# tc qdisc add dev <eth> root handle 1: tbf rate <x>mbit mtu <x> peakrate \
#  <x>mbit buffer <x>kb latency <x>ms

# controla erro
# tc qdisc add dev <eth> parent 1:1 handle 10: netem loss 0%
# tc qdisc change dev <eth> parent 1:1 handle 10: netem loss <y>%

#### IP machine 1 ####
# 172.21.210.218

##### Command
# subprocess.call("command-name-here")

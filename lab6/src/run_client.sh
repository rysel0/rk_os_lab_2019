#!/bin/bash

# Параметры клиента
K=4
MOD=5
SERVERS_FILE="servers.txt"

# Запуск клиента
./client --k $K --mod $MOD --servers $SERVERS_FILE
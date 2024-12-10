#!/bin/bash

# Параметры клиента
K=9
MOD=11
SERVERS_FILE="servers.txt"

# Запуск клиента
./client --k $K --mod $MOD --servers $SERVERS_FILE
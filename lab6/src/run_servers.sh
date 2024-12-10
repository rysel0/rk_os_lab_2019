#!/bin/bash

# Убедитесь, что сервера запущены на разных портах
./server --port 20001 --tnum 2 &
./server --port 20002 --tnum 2 &

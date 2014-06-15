#!/bin/bash
echo -e "\nRunning test with approximate option set"
if [ $# -eq 0 ]; then
  echo -e "Running as server, (to run as client include ip_address of server as first argument)"
  gcc -Wall --std=gnu99 -o network_server network_server.c
  echo -e "Ready to receive"
  ./network_server
  echo -e "Received message"
else
  echo -e "Running as client"
  gcc -Wall --std=gnu99 -o network_client network_client.c
  echo -e "Sending message"
  ./network_client $1
  echo -e "Sent message"
fi



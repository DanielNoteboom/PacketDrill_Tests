#!/bin/bash
echo "Running $1 ..."
ip tcp_metrics flush all > /dev/null 2>&1
if [ $# -eq 1 ]; then
  ../../packetdrill $1
else
  ../../packetdrill --wire_client --wire_server_ip=$2 $1
fi


#!/bin/bash
for f in `find approximate_tests -name "*.pkt" | sort`; do
  echo "Running $f ..."
  ip tcp_metrics flush all > /dev/null 2>&1
if [ $# -eq 1 ]; then
  ../../packetdrill --wire_client --wire_server_ip=$1 $f
else
  ../../packetdrill $f
fi
done

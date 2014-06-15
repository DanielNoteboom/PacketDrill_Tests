#!/bin/bash
echo -e "\nRunning packetdrill tests with approximate option set\n"
for f in `find approximate_tests -name "*.pkt" | sort`; do
  echo "Running $f ..."
  ip tcp_metrics flush all > /dev/null 2>&1
if [ $# -eq 1 ]; then
  packetdrill/gtests/net/packetdrill/packetdrill --wire_client --wire_server_ip=$1 $f
else
  packetdrill/gtests/net/packetdrill/packetdrill $f
fi
done



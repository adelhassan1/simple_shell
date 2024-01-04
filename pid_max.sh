#!/bin/bash

pid_max=$(cat /proc/sys/kernel/pid_max 2>/dev/null)

if [ -z "$pid_max" ]; then
    echo "Unable to retrieve the maximum PID value."
else
    echo "The maximum value a process ID can be is: $pid_max"
fi

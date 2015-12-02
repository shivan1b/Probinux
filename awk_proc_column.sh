#!/bin/bash

# Created by Shivani Bhardwaj <shivanib134@gmail.com>

# Description
# ------------
# This script will take the top output of current processes in the system
# and write only the process names to the file cur_proc which will be
# checked against dictionary

# Scope
# -----
# This script is fully functional and leaves no scope of change

while IFS='' read -r line || [[ -n "$line" ]]; do
	echo $line | awk '{print $NF}' | cut -f1 -d":" | cut -f1 -d"/" | cut -f1 -d"+" | sed -e 's/-$//' >> cur_proc
done < top-out 

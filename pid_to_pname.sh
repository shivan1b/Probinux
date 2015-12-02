# !/usr/bin
# Created by Shivani Bhardwaj

# Description
# ------------
# This script will generate a dictionary that is going to
# contain the names of processes that are native to Linux
# at present.

# Scope
# -----
# Working on a better way to find out all native processes

for i in `seq 1 32768`
do
	ps -p $i -o comm= >> <write absolute path to the dictionary here>
done

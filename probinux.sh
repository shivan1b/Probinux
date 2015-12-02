#!/usr/bin/probinux

#Created by Shivani Bhardwaj <shivanib134@gmail.com>

# Description
# ------------
# This script runs the complete utility

# Scope
# -----
# This script is fully functional and leaves no scope of change

(touch top-out &&
top -n 1 -b > top-out &&
touch cur_proc &&
> cur_proc &&
sh awk_proc_column.sh &&
sed -e '1,7d' < cur_proc > .tmp &&
rm cur_proc &&
mv .tmp cur_proc &&
gcc AESDec.c -o AES -lmcrypt &&
./AES && cat temp > dictionary &&
python odd_one_finder.py &&
gcc AESEnc.c -o AES -lmcrypt &&
./AES &&
sh unr_proc.sh)

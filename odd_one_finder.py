# !/usr/bin/env/python
# This is created by Tirth Bal
# Description
# -----------
#This script will compare th our native process file with current process file 
# and give us the odd one out.

# Scope
#------
# You can do this with some different and more efficient algorithm and ca use functional programming. 

with open("temp1",'r') as fi :
      list_proc = fi.read()
new_proc=list_proc.split('\n')
process_dict={}

for proc in new_proc:
      process_dict[proc]=1

with open('temp2','r') as fi2 :
     cur_proc=fi2.read()
new_cur_proc=cur_proc.split('\n')

for  w in new_cur_proc:
     if w not in process_dict:
           print w

    

# !/usr/bin/env/python
# This is created by Tirth Bal
# Description
# -----------
#This script will compare  our native process file with current process file 
# and give us the odd one out.

# Scope
#------
# You can do this with some different and more efficient algorithm and can use functional programming. 

with open("dictionary",'r') as fi :
      list_proc = (line.rstrip() for line in fi)
      list_proc = list(line for line in list_proc if line) 

print list_proc
'''new_proc=list_proc.split('\n')

final_proc_list=[]

for i in new_proc:
    final_proc_list.append(i.strip())
print final_proc_list
'''
'''process_dict={}

for proc in final_proc_list:
      process_dict[proc]=1
'''
with open('cur_proc','r') as fi2 :
     cur_proc=fi2.read()

new_cur_proc=cur_proc.split('\n')

new_cur_proc=list(set(new_cur_proc))
log=open('log.txt','w')

for  w in new_cur_proc:
     if w not in list_proc:
           print >> log,w


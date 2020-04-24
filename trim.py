import os
import re
import sys

def mostreUSO():
    print ("Uso : python3 ./trim.py <nome_arquivo_dos_arquivos>")

if len(sys.argv) < 2:
    mostreUSO()
    exit()
    
f = open(sys.argv[1], "r")
text = f.read()

acentos = u'áÁâÂàÀäÄãÃ' + u'éÉêÊèÈëË' + u'íÍîÎìÌïÏ' + u'óÓôÔòÒöÖõÕ' + u'úÚûÛùÙüÜ'

new = re.sub(u'[^A-Za-z\s’' + acentos + ']', '' ,text)
new = new.lower()
print (new)
f.close()
new_nome = sys.argv[1].replace('.txt','') + "_trimmed.txt"
print (new_nome)
os.remove(new_nome)
trimmed = open(new_nome, "w")
trimmed.write(new)
trimmed.close()

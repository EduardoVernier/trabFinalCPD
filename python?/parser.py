#!/usr/bin/env python
# -*- coding: utf-8 -*-
class Professor ():
   def __init__(self, nome, instituicao):
        self.nome = nome
        self.instituicao = instituicao
        self.field3 = field3


import xml.etree.ElementTree as ET
tree = ET.parse('3867942762661182.xml')
root = tree.getroot()
root.tag
root.attrib
for child in root:
    #print child.tag, child.attrib
    if child.tag == 'DADOS-GERAIS':
    	print child.attrib.get('NOME-COMPLETO')
    	print child.attrib 


#for trabs in root.iter('DADOS-BASICOS-DO-ARTIGO'):
#	print trabs.tag, trabs.attrib

#for trabs in root.iter('DADOS-BASICOS-DO-TRABALHO'):
#	name = trabs.get('TITULO-DO-TRABALHO')
#    print name

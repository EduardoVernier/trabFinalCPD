#!/usr/bin/env python
# -*- coding: utf-8 -*-

import xml.etree.ElementTree as ET
tree = ET.parse('3867942762661182.xml')
root = tree.getroot()
root.tag
root.attrib
for child in root:
    print child.tag, child.attrib

for trabs in root.iter('ARTIGO-PUBLICADO'):
	print trabs.tag, trabs.attrib


for trabs in root.iter('DADOS-BASICOS-DO-ARTIGO'):
	print trabs.tag, trabs.attrib

for trabs in root.iter('DADOS-BASICOS-DO-TRABALHO'):
	name = trabs.get('TITULO-DO-TRABALHO')
    print name

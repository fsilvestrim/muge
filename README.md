Copyright 2009 Filipe Silvestrim
http://www.filipesilvestrim.com
filipe@silvestrim.com


This file is part of MuGE (Multi-genre Game Engine).

OGRE is proprietary software; you can NOT redistribute it and/or 
modify it under MY terms: that in resume are do not use it for any 
propose that exceed the read and understand expectative. All of the 
content that is in theses files (of this directory that the readme 
are in) are under NDA!

MuGE is distributed in the hope that it will be useful just for
studies proposes, but WITHOUT ANY WARRANTY; 
without even the implied warranty of MERCHANTABILITY or 
FITNESS FOR A PARTICULAR PURPOSE.

---------------------------------------------------------------------

Visualizando as informações contidas nesse documento você está ciente
dos termos descritos (em inglês) nos paragrafos anteriores, isso, pois
todo esse software é um código proprietário e não poderá ser 
compartilhado com nimguém.

Todos os créditos e toda a implementação foi feita pelo desenvolvedor 
Filipe Silvestrim.

---------------------------------------------------------------------

Sobre
-- 
O projeto do MuGE define-se como sendo uma
engine de jogos proprietária. O objetivo do
mesmo é de atuar como um interpretador da DIGEO
Language (transcrição em XML da linguagem 
proposta na tese de monografia do autor Filipe
Silvestrim).




Arquitetura
--
A engine é composta de uma arquitetura de nodos.
Cada nodo equivale a um elemento da ontologia DIGEO.
Cada elemento é computado através de um ciclo de 
ativações/desativações.

Cada nodo possue 3 etapas principais: build - sendo
a fase de inicialização do elemento (parse e outras
operações mais inciais são feitas aqui); linkage - uma 
etapa que é acinada cada vez que ocorrer uma troca de 
estado do nodo (de ativo para inativo, por exemplo); 
step - etapa que ocorre a cada ciclo do update do game
loop que é inicializado no Kernel da engine.





Como fazer build do projeto
--
Faz-se necessária a instalação no sistema (adicioná-las no 
diretório - em um Mac - /Library/Frameworks ) as bibliotecas
do MuGE (MuGE/build/Release/MuGE.framework) e do plugin
(MuGEPluginIrrlicht/build/Release/MuGEPluginIrrlicht.framework), que
no caso o plugin default do motor é o PLuginIrrlicht. Por final, 
ainda é necessário incluir a framework do tinyXML, pois esse framework
é a única biblioteca externa da qual o MuGE depende para fazer parser
de XML (tinyXML/build/Release/tinyXML.framework)





Workflow
--
Para desenvlver um produto final (vulgo jogo) com a MuGE
é necessário a utilização de pelo menos um plugin de 
visualização e um projeto do jogo - que serve para inicializar
a engine, carregar o XML do jogo e fazer algumas alterações
mais no baixo nível.

O projeto do jogo irá incluir as bibliotecas MuGE.framework e
também plugin.framework

Atualmente o código está todo escrito em cima da IDE XCode, então
os projetos já estão presentos dentro das pastas dos projetos, basta
(após as frameworks instaladas) abrir o projeto de demostração 
(MuGEDemo) e compilar com o XCode.





Estrutura de Diretórios
--
Todo e qualquer diretório (framework) possuirá um arquivo .xcodeproj
representando o projeto em XCode, uma pasta chamada "build" contendo 
a framework em modo release e debug e ainda o código fonte (muitas vezes
dividido em diretórios "header" e "source"), dentre outros arquivos como
diagrama UML e etc...





Arquivos contidos na raíz do atual diretório
--
./readme.txt			---> Este arquivo com termos e informações do projeto
./MuGE_presentation.pdf	---> Apresentação do projeto em sí
./MuGE 					---> Diretório com o projeto do motor em sí
./MuGEDemo 				---> Diretório com o exemplo do jogo pong
./MuGEPluginIrrlicht 	---> Diretório com o projeto do plugin default do MuGE
./tinyXML 				---> Diretório com o projeto do compilado da tinyXML


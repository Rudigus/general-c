# Interpolação - Método Newton Gregory

TRABALHO APRESENTADO NA DISCIPLINA SISTEMAS EMBARCADOS DO CURSO DE ENG DA COMPUTAÇÃO DO IFCE - INSTITUTO FEDERAL DE CIÊNCIA E EDUCAÇÃO DO CEARÁ, 
SEMESTRE 2023.2

### Professor
Elias Teodoro da Silva Junior

### Alunos
Edmilson Bernardino Souza e Rodrigo de Matos Aguiar

### Descrição
O presente código em linguagem C, adaptado para a plataforma STM32F030, Arm Cortex-M), 48MHz, 64 Kb de Memória Flash
8 Kb de SRAM, rodando na IDE Mbed Studio 1.4.5, trata-se de uma implementação do algorítimo para cálculo polinomial por interpolação,
utilizando o método Newton-Gregory, que trata de um caso particular do polinômio de Newton, isto é, os valores das abcissas dos pontos
são crescentes e com espaçamento constante entre os valores sucessivos, isto é, h=X1-Xo é constante. 
Essa implementação utilizou como ponto de partida o código em C++ disponível no GitHub https://github.com/BryanDamasceno/Analise-Numerica, 
repositório público, sendo adaptado para a linguagem C.

### Arquivos
- newton_gregory.cpp

    Contém a implementação do método de Newton Gregory.

- newton_gregory.h

    Header que disponibiliza funções e defines do newton_gregory.cpp.

- main.cpp

    Inicia o fluxo do programa por meio da função main, em que vai ler as entradas por serial, aplicar o método de Newton Gregory e mandar o resultado pela serial.

### Licença

O código-fonte está sujeito a [licença MIT](LICENSE.txt).
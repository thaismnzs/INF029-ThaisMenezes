// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Thais Ribeiro Menezes
//  email: thaismenezes3108@gmail.com
//  Matrícula: 20242160013
//  Semestre: 2025.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "ThaisMenezes20242160013.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>

DataQuebrada quebraData(char data[]) {
    DataQuebrada dq;
    char sDia[3];
    char sMes[3];
    char sAno[5];
    int i, j;
    
    for(i = 0; data[i] != '/' && data[i] != '\0'; i++) {
        sDia[i] = data[i];
    }
    if(i == 1 || i == 2) {
        sDia[i] = '\0';
    } else {
        dq.valido = 0;
        return dq;
    }
    
    j = i + 1; 
    
    for(i = 0; data[j] != '/' && data[j] != '\0'; j++, i++) {
        sMes[i] = data[j];
    }
    if(i == 1 || i == 2) {
        sMes[i] = '\0';
    } else {
        dq.valido = 0;
        return dq;
    }
    
    j = j + 1; 
    
    for(i = 0; data[j] != '\0'; j++, i++) {
        sAno[i] = data[j];
    }
    if(i == 2 || i == 4) {
        sAno[i] = '\0';
    } else {
        dq.valido = 0;
        return dq;
    }
    
    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno);
    
    dq.valido = 1;
    return dq;
}
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int validarFormatoEDigitos(const char *data) {
    int i = 0, etapa = 0;
    int digDia = 0, digMes = 0, digAno = 0;

    while (data[i] != '\0' && data[i] != '\n') {
        if (etapa == 0) {
            if (data[i] >= '0' && data[i] <= '9') digDia++;
            else if (data[i] == '/') etapa++;
            else return 0;
        }
        else if (etapa == 1) {
            if (data[i] >= '0' && data[i] <= '9') digMes++;
            else if (data[i] == '/') etapa++;
            else return 0;
        }
        else if (etapa == 2) {
            if (data[i] >= '0' && data[i] <= '9') digAno++;
            else return 0;
        }
        i++;
    }

    return (digDia >= 1 && digDia <= 2) &&
           (digMes >= 1 && digMes <= 2) &&
           (digAno == 2 || digAno == 4);
}


int validarData(int dia, int mes, int ano) {
    if(dia < 1 || dia > 31 || mes < 1 || mes > 12){
        return 0;
    }
    if(mes == 2) {
       int bissexto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
        if (bissexto && dia <= 29) return 1;
        else if (!bissexto && dia <= 28) return 1;
        else return 0;
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return dia <= 30;
    }
    return dia <= 31;
}

int q1(char data[]) {
    int datavalida = 1;
    if(!validarFormatoEDigitos(data)) {
        return 0;
    }
    DataQuebrada dq = quebraData(data);
    if(!dq.valido) {
        return 0;
}

if(!validarData(dq.iDia, dq.iMes, dq.iAno)) {
return 0;
}

return 1;
}


/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[]){
    DiasMesesAnos dma;
    
    if(q1(datainicial) == 0) {
        dma.retorno = 2;
        return dma;
    }
    if(q1(datafinal) == 0) {
        dma.retorno = 3;
        return dma;
    }
    
    DataQuebrada ini = quebraData(datainicial);
    DataQuebrada fim = quebraData(datafinal);
    
     if ((ini.iAno > fim.iAno) ||
        (ini.iAno == fim.iAno && ini.iMes > fim.iMes) ||
        (ini.iAno == fim.iAno && ini.iMes == fim.iMes && ini.iDia > fim.iDia)) {
        dma.retorno = 4;
        return dma;
    }
    int difDia = fim.iDia - ini.iDia;
    int difMes = fim.iMes - ini.iMes;
    int difAno = fim.iAno - ini.iAno;
    
    if(difDia < 0) {
        difDia += 30;
        difMes--;
    }
    
    if(difMes < 0) {
        difMes += 12;
        difAno--;
    }
    
    dma.qtdDias = difDia;
    dma.qtdMeses = difMes;
    dma.qtdAnos = difAno;
    dma.retorno = 1;
    
    return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    char caractereTexto;
    char busca;
    int i;
    int qtdOcorrencias = 0;
    
    for(i = 0; texto[i] != '\0'; i++){
        caractereTexto = texto[i];
        busca = c;
        
        if(!isCaseSensitive) {
            if (caractereTexto >= 'A' && caractereTexto <= 'Z')
                caractereTexto += 32;
            if (busca >= 'A' && busca <= 'Z')
                busca += 32;
        }

        if(caractereTexto == busca) {
            qtdOcorrencias++;
        }
    }
    
    return qtdOcorrencias; 
}


/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(const char *strTexto, const char *strBusca, int posicoes[]) {
    int ocorrencias = 0;
    int tamTexto = strlen(strTexto);
    int tamBusca = strlen(strBusca);
    
    if (tamBusca == 0 || tamBusca > tamTexto) {
        return 0;
    }
    
    for (int i = 0; i <= tamTexto - tamBusca; i++) {
        int encontrou = 1;
        
        for (int j = 0; j < tamBusca; j++) {
            if (strTexto[i + j] != strBusca[j]) {
                encontrou = 0;
                break;
            }
        }
        
        if (encontrou) {
            posicoes[ocorrencias * 2] = i + 1;        
            posicoes[ocorrencias * 2 + 1] = i + tamBusca; 
            ocorrencias++;
        }
    }
    
    return ocorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num) {
    int num_invertido = 0;
    
    while(num > 0) {
        num_invertido = num_invertido * 10 + (num%10);
        num /= 10;
    }
    return num_invertido;
}

int main() {
    int num = 190;
    
    q5(num);
    printf("%d", q5(num));
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca) {
    int qtdOcorrencias = 0;
    int i;
    
    char base[50];
    char busca[50];
    
    sprintf(base, "%d", numerobase);
    sprintf(busca, "%d", numerobusca);
    
    int tamBase = strlen(base);
    int tamBusca = strlen(busca);
    
    for(i=0; i <= tamBase - tamBusca; i++) {
        if(strncmp(&base[i], busca, tamBusca) == 0) {
            qtdOcorrencias++;
        }
    }
    
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

int q7(char matriz[8][10], char palavra[5]) {
    int tam = strlen(palavra);
    if(tam == 0) return 0;
    int i, j, k, l;
    int linhas = 8;
    int colunas = 10;
    
    int direcoes[8][2] = {
        {-1, 0}, {1, 0},
        {0, -1}, {0, 1},  
        {-1, -1}, {-1, 1},
        {1, -1}, {1, 1}
    };
    
    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
            if(matriz[i][j] == palavra[0]) {
                for(k = 0; k < 8; k++) {
                    int ni = i, nj = j;
                    
                    for(l = 1; l < tam; l++) {
                        ni += direcoes[k][0];
                        nj += direcoes[k][i];
                        
                        if(ni < 0 || ni >= linhas || nj < 0 || nj >= colunas)
                        break;
                        
                        if(matriz[ni][nj] != palavra[l]) 
                        break;
                    }
                    
                    if (l == tam) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}




	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

//Desenvolver um projeto para vender ingressos para um cinema.

//O tamanho do cinema (quantidade de lugares) é de 20 Fileiras com 30 assentos por fileiras.
//Usar uma matriz de inteiros para gerenciar a venda de ingressos.
//Ao iniciar a aplicação todos os assentos estão disponíveis. Esse controle é feito armazenado 0 em todas as posições da matriz.
//O usuário deverá informar o valor do ingresso na tarifa cheia ao iniciar a aplicação.

//Executar a venda de ingressos até quando o usuário desejar ou enquanto existirem ingressos disponíveis para venda.
//Ao vender um ingresso, perguntar:
//assento o cliente deseja sentar (linha e coluna).
//tipo de ingresso (1=normal, 2=meia e 3 = cortesia)
//Atenção, não vender um assento inexistente ou já vendido!
//Ao finalizar a aplicação mostrar:
//total de ingressos normais vendidos.
//total de ingressos meia entrada vendidos.
//total de ingressos cortesia fornecidos.
//Total arrecadado

#include <stdio.h>

#define FIL 20
#define COL 30

int main(){
	int mat[FIL][COL];
	int opcao = 0, tipIngresso, fileira, totalOcupadas = 0, cadeira, totalNormais = 0, totalMeia = 0, totalCortesia = 0, i, j;
	float preco, totalArrecadado;
	
	for(i = 0; i < FIL; i++){
		for(j = 0; j < COL; j++){
			mat[i][j] = 0;
		}
	}
		
	printf(" -> Bem vindo ao sistema de Venda de Ingressos!\n");
	printf("\n -> Qual sera o preco do ingresso? ");
	scanf("%f", &preco);
	
	while(opcao != 2 || totalOcupadas >= FIL * COL){
		do{
			do{
				printf("\n -> Insira a fileira escolhida: ");
				scanf("%i", &fileira);
			}while(fileira < 1 || fileira > FIL);
			
			do{
				printf("\n -> Insira a cadeira escolhida: ");
				scanf("%i", &cadeira);
			}while(cadeira < 1 || cadeira > COL);
	
			do{
				printf("\n -> Selecione o tipo de ingresso: \n");
				printf("\n1 - Normal");
				printf("\n2 - Meia");
				printf("\n3 - Cortesia\n\n");
				
				scanf("%i", &tipIngresso);
			}while(tipIngresso < 1 || tipIngresso > 3);
			
			if(mat[fileira - 1][cadeira - 1] != 0){
				printf("\n--------------------CADEIRA OCUPADA!--------------------\n");
			}else{
				if(tipIngresso == 1){
					totalNormais++;
					totalArrecadado += preco;
				}else if(tipIngresso == 2){
					totalMeia++;
					totalArrecadado += preco / 2;
				}else{
					totalCortesia++;
				}
				mat[fileira - 1][cadeira - 1] = tipIngresso;
				totalOcupadas++;
			}
			
		}while(mat[fileira][cadeira] != 0);
		
		printf("\nA -> Assentos disponiveis: \n\n");
		
		for(i = 0; i < FIL; i++){
			printf("\t");
			for(j = 0; j < COL; j++){
				printf("%i ", mat[i][j]);
			}
			printf("\n");
		}
		
		do{
			printf("\n -> Deseja executar mais uma venda? ");
			printf("\n1 - Sim");
			printf("\n2 - Nao\n");
			
			scanf("%i", &opcao);
		} while(opcao < 1 || opcao > 2);
	}
	
	printf("\n -> Relatorio final: \n");
	
	printf("\n -> Total de ingressos normais vendidos: %i", totalNormais);
	printf("\n -> Total de ingressos meia vendidos: %i", totalMeia);
	printf("\n -> Total de ingressos cortesia vendidos: %i\n", totalCortesia);
	
	printf("\n\t -> Total Arrecadado: R$%.2f", totalArrecadado);
	
	return 0;
}
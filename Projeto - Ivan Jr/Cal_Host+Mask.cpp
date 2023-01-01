//==================================================================================================================================================================
// Descrição: Lê um número decimal seguido de 4 octetos e imprime o ID,GATEWAY,NETMASK,BROADCAST,IP INICIAL E FINAL,QUANTIDADE DE HOSTS E CLASSE !
// Projeto desenvolvido por Ivan Jr, Discente do IFBA Santo Amaro, Componente de Algoritmos do Curso de Licenciatura de Computação !
//==================================================================================================================================================================
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<locale.h>
#include<windows.h>
#define ANSI_COLOR_RED      "\x1b[31m" //cores em ANSI utilizadas \33[0m
#define ANSI_COLOR_NONE      "\33[1;37m" //cores em ANSI utilizadas 

//---------------------------------------------------------------------------------------------------------------------------------------------------------------						
 void aClasse(int host1){ /*declaração de uma função, onde vai ser feita condições e apresentada no codigo na hora do resultado*/
 	if(host1>=1 && host1<=126)printf("\t\t\t\t| 		Classe A 	    		    |\n"); /*Condicao ira verificar o host1 e comparar se encaixa na condicao solicitada*/
 	if(host1>=128 && host1<=191)printf("\t\t\t\t| 		Classe B 	    		    |\n"); /*Condicao ira verificar o host1 e comparar se encaixa na condicao solicitada*/
 	if(host1>=192 && host1<=223)printf("\t\t\t\t| 		Classe C 	    		    |\n"); /*Condicao ira verificar o host1 e comparar se encaixa na condicao solicitada*/
 	if(host1>=224 && host1<=239)printf("\t\t\t\t| 		Classe D 	    		    |\n"); /*Condicao ira verificar o host1 e comparar se encaixa na condicao solicitada*/
 	if(host1>=240 && host1<=255)printf("\t\t\t\t| 		Classe E 	    		    |\n"); /*Condicao ira verificar o host1 e comparar se encaixa na condicao solicitada*/
 }
//---------------------------------------------------------------------------------------------------------------------------------------------------------------						
int main(void){
fflush(stdin);	/*Limpar dados capturado pelo usuario e definir com default (valor padrao)*/
system ("cls"); /*Limpar tela*/
setlocale(LC_ALL, "Portuguese_Brazil"); /*usado junto com a biblioteca locale, para usar Linguagem-idiomas, EX.: Portuguese_Brazil para usar acentuação. */
system("title [3ª Avaliação] ::: 1º SEM/LC ::: CONVERSOR DE HOSTS IP  :::  Ivan Jr."); /*Titulo do programa, identificar na barra do prompt o que está sendo executado.*/

	int i,opcao, mask1[8], mask2[8], mask3[8], mask4[8], bit[32], barra, soma1=0,soma2=0,soma3=0,soma4=0,soma5=0;
	int host1,host2,host3,host4,quant_ip_dispo=0, decimal = 0;
	system("cls"); system("color 17"); /*Limpar tela*/ /*usado junto com a conio para colorir o fundo do prompt e a letra*/
//---------------------------------------------------------------------------------------------------------------------------------------------------------------						
printf("	_________________________________________________________________________________________________________\n");
printf("	|													|\n");
printf(ANSI_COLOR_RED"	|						-->>MENU<<--						|\n"ANSI_COLOR_NONE); /*Menu*/
printf("	|_______________________________________________________________________________________________________|\n");
printf("	|				SEJA BEM VINDO AO CONVERSOR DE MASCARA IP !				|\n"); /*texto informando qual dado está sendo solicitado*/
printf("	|													|\n");
printf("	|				1. DIGITE PARA INSERIR O IP E O CIDR.					|\n"); /*texto informando qual dado está sendo solicitado*/
printf("	|				2. DIGITE PARA CALCULAR SO A MASCARA.					|\n"); /*texto informando qual dado está sendo solicitado*/
printf("	|				3. SAIR.								|\n");
printf("	|													|\n");
printf("	|													|\n");
printf(ANSI_COLOR_RED"	|				* Usuario, por favor, digite a sua opcao !				|\n"ANSI_COLOR_NONE); /*texto informando qual dado está sendo solicitado*/
printf("	|_______________________________________________________________________________________________________|\n");
printf("\n========================================================>><<========================================================\n");
printf("-->>",opcao); /*recebe dado*/
	scanf("%d", &opcao); /*Ler dado que foi lido do MENU digitado e armazena na variavel opcao para dar continuidade ao que foi solicitado*/	
system("cls"); /*Limpar tela*/
	switch(opcao) /*verifica o dado que foi armazenado na variavel opcao e apresenta a condicao representado pelo valor recebido da opcao*/
//---------------------------------------------------------------------------------------------------------------------------------------------------------------						
	        {
//		-------------------------------------------------------------------------------------------------------------------------------------------------------					
	        case 1:
	        	
	        	{
					IP: /*Inicio da condição goto*/
					system("cls"); /*Limpar tela*/
		            printf("_________________________________________________________________________________________________________\n");
					printf("| DIGITE O ENDEREÇO IP.											|\n"); /*texto informando qual dado está sendo solicitado*/
					printf("|													|\n");
					printf("| * obedeçendo as regras do seguinte formato seguido do ponto (XXX.XXX.XXX.XXX).			|\n"); /*texto informando qual dado está sendo solicitado*/
					printf("|_______________________________________________________________________________________________________|\n");
					printf("\nIP ==> "); /*impresso na tela para auxiliar ao usuario qual dado inserir*/
					Beep(600,200); /*representado para emitir um som*/					
		            scanf("%d.%d.%d.%d",&host1, &host2, &host3, &host4); /*Ler dado inserido pelo usuario e armazena em cada variavel seguida do ponto*/		            
		            if((host4 ==0)||(host4 >254)){ /*host é igual a zero ou host maior que 255 verifica condição e passa adiante*/
						printf("\nIP inválido !\n"); /*impressão de codigo errado, devido valor recebido nao ser igual a condição*/
						goto IP; /*serve para demarcar um estado de inicio depois da condição*/
					}
					MASK: /*Inicio da condição goto*/
					system("cls"); /*Limpar tela*/          
					printf("_________________________________________________\n");
					printf("| DIGITE O TAMANHO DA SUA MASCARA DE REDE	 |\n"); /*texto informando qual dado está sendo solicitado*/
					printf(ANSI_COLOR_RED"| * (Ex.: 24)					 |\n"ANSI_COLOR_NONE); /*Exemplo de valor a ser digitado*/
					printf("|________________________________________________|\n");
					printf("\nNetmask ==> "); /*impresso na tela para auxiliar ao usuario qual dado inserir*/
					Beep(600,200); /*representado para emitir um som*/	
		            scanf("%d",&barra); /*Ler valor recebido e armazena na variavel barra*/
		            decimal = 32-barra; /*decimal é igual a 32 menos barra*/
		            if((barra ==0)||(barra >32)){ /*barra é igual a zero ou host4 for maior que 32*/
						printf("\nCIDR Invalido !\n"); /*impressão de codigo errado, devido valor recebido nao ser igual a condição*/
						goto MASK; /*serve para demarcar um estado de inicio depois da condição*/
					}
		            printf("\n");
	            break;
	        	}
//		-------------------------------------------------------------------------------------------------------------------------------------------------------										        
	        case 2:
//		-------------------------------------------------------------------------------------------------------------------------------------------------------						
				{
					MASK1: /*Inicio da condição*/
					printf("_________________________________________________\n");
					printf("| DIGITE O TAMANHO DA SUA MASCARA DE REDE	 |\n"); /*texto informando qual dado está sendo solicitado*/
					printf(ANSI_COLOR_RED"| * (Ex.: 24)					 |\n"ANSI_COLOR_NONE); /*Exemplo de valor a ser digitado*/
					printf("|________________________________________________|\n");
					printf("\nNetmask ==> "); /*impresso na tela para auxiliar ao usuario qual dado inserir*/
					Beep(600,200); /*representado para emitir um som*/				
	            	scanf("%d",&barra); /*Ler valor recebido e armazena na variavel barra*/
	            	decimal = 32-barra; /*decimal é igual a 32 menos barra*/
					if((barra ==0)||(host4 >32)){ /*barra é igual a zero ou host4 for maior que 32*/
						printf("\nCIDR Invalido !\n"); /*impressão de codigo errado, devido valor recebido nao ser igual a condição*/
						goto MASK1; /*serve para demarcar um estado de inicio depois da condição*/
					}
				break;	
				}
//		-------------------------------------------------------------------------------------------------------------------------------------------------------					
			case 3:
				{
					exit(0); /*caso seja recebido valor igual a 3, programa é encerado*/
				break;
				}
			
			default: system("cls");
			printf("\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
			    printf("\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
			    printf(ANSI_COLOR_RED"\t\t\t- -  =================== * CONVERSOR DE HOSTS IP * ================       - - \n"ANSI_COLOR_NONE);
			    printf("\t\t\t- -                                                                       - - \n");
			    printf("\t\t\t- -                                                                       - - \n");
			    printf("\t\t\t- -                                                                       - - \n");
			    printf("\t\t\t- -                                                                       - - \n");
			    printf("\t\t\t- -                                                                       - - \n");
			    printf("\t\t\t- -                                                                       - - \n");
			    printf("\t\t\t- -                                                                       - - \n");
                printf("\t\t\t- -                    #OPÇÃO INVÁLIDA, TENTE NOVAMENTE!!                 - - \n");
			    printf("\t\t\t- -                                                                       - - \n");
			    printf("\t\t\t- -                                                                       - - \n");
			    printf("\t\t\t- -                                                                       - - \n");
			    printf("\t\t\t- -                                                                       - - \n");
			    printf("\t\t\t- -                                                                       - - \n");
			    printf("\t\t\t- -                                                                       - - \n");
			    printf("\t\t\t- -                                                                       - - \n");
			    printf("\t\t\t- -                                                                       - - \n");
			    printf("\t\t\t- -                                                                       - - \n");
			    printf("\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
			    printf("\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n");
			    		printf(ANSI_COLOR_RED"\t\t\t\t PRESSIONE QUALQUER \"TECLA\" PARA RETORNAR AO \"MENU\" ! ");	
			    Beep(3951,1000);
			getch(); 
			return main ();
	}	
//--------------------------------------------------------------------------------------------------------------------------------------------------------------				
			for(i=0; i<32; i++){ /*i é igual a zero, i menor que 32 "i" incrementa*/	
				bit[i] =0; /*bit recebe i igual a zero*/
			}
			for(i=0; i<barra; i++){ /*i é igual a zero, i menor que barra(valor recebido para cal da mascara, "i" incrementa)*/
				bit[i]=1;
			}
			for(i=0; i<32; i++){ /*i é igual a zero, i menor que 32 "i" incrementa*/	
			}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------			
			{				
			mask1[0]=bit[0]; /*octeto recebe e é armazenado na mask1 de posicao zero onde é guardado no bit zero */
			mask1[1]=bit[1]; /*octeto recebe e é armazenado na mask1 de posicao um onde é guardado no bit um */
			mask1[2]=bit[2]; /*octeto recebe e é armazenado na mask1 de posicao dois onde é guardado no bit dois */
			mask1[3]=bit[3]; /*octeto recebe e é armazenado na mask1 de posicao três onde é guardado no bit três */
			mask1[4]=bit[4]; /*octeto recebe e é armazenado na mask1 de posicao quatro onde é guardado no bit quatro */
			mask1[5]=bit[5]; /*octeto recebe e é armazenado na mask1 de posicao cinco onde é guardado no bit cinco */
			mask1[6]=bit[6]; /*octeto recebe e é armazenado na mask1 de posicao seis onde é guardado no bit seis */
			mask1[7]=bit[7]; /*octeto recebe e é armazenado na mask1 de posicao sete onde é guardado no bit sete */
//--------------------------------------------------------------------------------------------------------------------------------------------------------------			
			mask2[0]=bit[8]; /*octeto recebe e é armazenado na mask2 de posicao zero onde é guardado no bit oito */
			mask2[1]=bit[9]; /*octeto recebe e é armazenado na mask2 de posicao um onde é guardado no bit nove */
			mask2[2]=bit[10]; /*octeto recebe e é armazenado na mask2 de posicao dois onde é guardado no bit dez */
			mask2[3]=bit[11]; /*octeto recebe e é armazenado na mask2 de posicao três onde é guardado no bit onze */
			mask2[4]=bit[12]; /*octeto recebe e é armazenado na mask2 de posicao quatro onde é guardado no bit doze */
			mask2[5]=bit[13]; /*octeto recebe e é armazenado na mask2 de posicao cinco onde é guardado no bit treze */
			mask2[6]=bit[14]; /*octeto recebe e é armazenado na mask2 de posicao seis onde é guardado no bit quatorze */
			mask2[7]=bit[15]; /*octeto recebe e é armazenado na mask2 de posicao sete onde é guardado no bit quinze */
//--------------------------------------------------------------------------------------------------------------------------------------------------------------			
			mask3[0]=bit[16]; /*octeto recebe e é armazenado na mask3 de posicao zero onde é guardado no bit dezeseis */
			mask3[1]=bit[17]; /*octeto recebe e é armazenado na mask3 de posicao um onde é guardado no bit dezesete */
			mask3[2]=bit[18]; /*octeto recebe e é armazenado na mask3 de posicao dois onde é guardado no bit dezoito */
			mask3[3]=bit[19]; /*octeto recebe e é armazenado na mask3 de posicao três onde é guardado no bit dezenove */
			mask3[4]=bit[20]; /*octeto recebe e é armazenado na mask3 de posicao quatro onde é guardado no bit vinte */
			mask3[5]=bit[21]; /*octeto recebe e é armazenado na mask3 de posicao cinco onde é guardado no bit vinte e um */
			mask3[6]=bit[22]; /*octeto recebe e é armazenado na mask3 de posicao seis onde é guardado no bit vinte e dois */
			mask3[7]=bit[23]; /*octeto recebe e é armazenado na mask3 de posicao sete onde é guardado no bit vinte e três */
//--------------------------------------------------------------------------------------------------------------------------------------------------------------			
			mask4[0]=bit[24]; /*octeto recebe e é armazenado na mask4 de posicao zero onde é guardado no bit vinte e quatro */
			mask4[1]=bit[25]; /*octeto recebe e é armazenado na mask4 de posicao um onde é guardado no bit vinte e cinco */
			mask4[2]=bit[26]; /*octeto recebe e é armazenado na mask4 de posicao dois onde é guardado no bit vinte e seis */
			mask4[3]=bit[27]; /*octeto recebe e é armazenado na mask4 de posicao três onde é guardado no bit vinte e sete */
			mask4[4]=bit[28]; /*octeto recebe e é armazenado na mask4 de posicao quatro onde é guardado no bit vinte e oito */
			mask4[5]=bit[29]; /*octeto recebe e é armazenado na mask4 de posicao cinco onde é guardado no bit vinte e nove */
			mask4[6]=bit[30]; /*octeto recebe e é armazenado na mask4 de posicao seis onde é guardado no bit trinta */
			mask4[7]=bit[31]; /*octeto recebe e é armazenado na mask4 de posicao sete onde é guardado no bit trinta e um */
//--------------------------------------------------------------------------------------------------------------------------------------------------------------			
			if(mask1[0] ==1) soma1=soma1+128; /*condicao "SE", onde os dados de mask1 na posicao zero é igual a 1 e soma é igual a soma+128*/
			if(mask1[1] ==1) soma1=soma1+64; /*condicao "SE", onde os dados de mask1 na posicao um é igual a 1 e soma é igual a soma+64*/
			if(mask1[2] ==1) soma1=soma1+32; /*condicao "SE", onde os dados de mask1 na posicao dois é igual a 1 e soma é igual a soma+32*/
			if(mask1[3] ==1) soma1=soma1+16; /*condicao "SE", onde os dados de mask1 na posicao três é igual a 1 e soma é igual a soma+16*/
			if(mask1[4] ==1) soma1=soma1+8; /*condicao "SE", onde os dados de mask1 na posicao quatro é igual a 1 e soma é igual a soma+8*/
			if(mask1[5] ==1) soma1=soma1+4; /*condicao "SE", onde os dados de mask1 na posicao cinco é igual a 1 e soma é igual a soma+4*/
			if(mask1[6] ==1) soma1=soma1+2; /*condicao "SE", onde os dados de mask1 na posicao seis é igual a 1 e soma é igual a soma+2*/
			if(mask1[7] ==1) soma1=soma1+1; /*condicao "SE", onde os dados de mask1 na posicao ste é igual a 1 e soma é igual a soma+1*/
//--------------------------------------------------------------------------------------------------------------------------------------------------------------			
			if(mask2[0] ==1) soma2=soma2+128; /*condicao "SE", onde os dados de mask2 na posicao zero é igual a 1 e soma é igual a soma+128*/
			if(mask2[1] ==1) soma2=soma2+64; /*condicao "SE", onde os dados de mask2 na posicao um é igual a 1 e soma é igual a soma+64*/
			if(mask2[2] ==1) soma2=soma2+32; /*condicao "SE", onde os dados de mask2 na posicao dois é igual a 1 e soma é igual a soma+32*/
			if(mask2[3] ==1) soma2=soma2+16; /*condicao "SE", onde os dados de mask2 na posicao três é igual a 1 e soma é igual a soma+16*/
			if(mask2[4] ==1) soma2=soma2+8; /*condicao "SE", onde os dados de mask2 na posicao quatro é igual a 1 e soma é igual a soma+8*/
			if(mask2[5] ==1) soma2=soma2+4; /*condicao "SE", onde os dados de mask2 na posicao cinco é igual a 1 e soma é igual a soma+4*/
			if(mask2[6] ==1) soma2=soma2+2; /*condicao "SE", onde os dados de mask2 na posicao seis é igual a 1 e soma é igual a soma+2*/
			if(mask2[7] ==1) soma2=soma2+1; /*condicao "SE", onde os dados de mask2 na posicao sete é igual a 1 e soma é igual a soma+1*/
//--------------------------------------------------------------------------------------------------------------------------------------------------------------			
			if(mask3[0] ==1) soma3=soma3+128; /*condicao "SE", onde os dados de mask3 na posicao zero é igual a 1 e soma é igual a soma+128*/
			if(mask3[1] ==1) soma3=soma3+64; /*condicao "SE", onde os dados de mask3 na posicao um é igual a 1 e soma é igual a soma+64*/
			if(mask3[2] ==1) soma3=soma3+32; /*condicao "SE", onde os dados de mask3 na posicao dois é igual a 1 e soma é igual a soma+32*/
			if(mask3[3] ==1) soma3=soma3+16; /*condicao "SE", onde os dados de mask3 na posicao três é igual a 1 e soma é igual a soma+16*/
			if(mask3[4] ==1) soma3=soma3+8; /*condicao "SE", onde os dados de mask3 na posicao quatro é igual a 1 e soma é igual a soma+8*/
			if(mask3[5] ==1) soma3=soma3+4; /*condicao "SE", onde os dados de mask3 na posicao cinco é igual a 1 e soma é igual a soma+4*/
			if(mask3[6] ==1) soma3=soma3+2; /*condicao "SE", onde os dados de mask3 na posicao seis é igual a 1 e soma é igual a soma+2*/
			if(mask3[7] ==1) soma3=soma3+1; /*condicao "SE", onde os dados de mask3 na posicao sete é igual a 1 e soma é igual a soma+1*/
//--------------------------------------------------------------------------------------------------------------------------------------------------------------			
			if(mask4[0] ==1) soma4=soma4+128; /*condicao "SE", onde os dados de mask4 na posicao zero é igual a 1 e soma é igual a soma+128*/
			if(mask4[1] ==1) soma4=soma4+64; /*condicao "SE", onde os dados de mask4 na posicao um é igual a 1 e soma é igual a soma+64*/
			if(mask4[2] ==1) soma4=soma4+32; /*condicao "SE", onde os dados de mask4 na posicao dois é igual a 1 e soma é igual a soma+32*/
			if(mask4[3] ==1) soma4=soma4+16; /*condicao "SE", onde os dados de mask4 na posicao três é igual a 1 e soma é igual a soma+16*/
			if(mask4[4] ==1) soma4=soma4+8; /*condicao "SE", onde os dados de mask4 na posicao quatro é igual a 1 e soma é igual a soma+8*/
			if(mask4[5] ==1) soma4=soma4+4; /*condicao "SE", onde os dados de mask4 na posicao cinco é igual a 1 e soma é igual a soma+4*/
			if(mask4[6] ==1) soma4=soma4+2; /*condicao "SE", onde os dados de mask4 na posicao seis é igual a 1 e soma é igual a soma+2*/
			if(mask4[7] ==1) soma4=soma4+1; /*condicao "SE", onde os dados de mask4 na posicao sete é igual a 1 e soma é igual a soma+1*/
			
			if(mask4[0] ==0) soma5=soma5+128; /*condicao "SE", onde os dados de mask4 na posicao zero é igual a 0 e soma é igual a soma+128*/
			if(mask4[1] ==0) soma5=soma5+64; /*condicao "SE", onde os dados de mask4 na posicao um é igual a  e soma é igual a soma+64*/
			if(mask4[2] ==0) soma5=soma5+32; /*condicao "SE", onde os dados de mask4 na posicao dois é igual a 0 e soma é igual a soma+32*/
			if(mask4[3] ==0) soma5=soma5+16; /*condicao "SE", onde os dados de mask4 na posicao três é igual a 0 e soma é igual a soma+16*/
			if(mask4[4] ==0) soma5=soma5+8; /*condicao "SE", onde os dados de mask4 na posicao quatro é igual a 0 e soma é igual a soma+8*/
			if(mask4[5] ==0) soma5=soma5+4; /*condicao "SE", onde os dados de mask4 na posicao cinco é igual a 0 e soma é igual a soma+4*/
			if(mask4[6] ==0) soma5=soma5+2; /*condicao "SE", onde os dados de mask4 na posicao seis é igual a 0 e soma é igual a soma+2*/
			if(mask4[7] ==0) soma5=soma5+1; /*condicao "SE", onde os dados de mask4 na posicao sete é igual a 0 e soma é igual a soma+1*/			
			}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------			
		quant_ip_dispo = (pow(2, decimal)-2); /*quant_ip_dispo é igual a 2 elevado a decimal=0 -2, chegando ao resultado desejado.*/
			if(opcao==1){
			printf("				_____________________________________________________\n");
			printf(ANSI_COLOR_RED"				| 		CONVERSÃO EFETUADA !  	     	    |\n"ANSI_COLOR_NONE); /*Menu de resultados*/
			printf("				|___________________________________________________|\n");
			aClasse(host1); /*funcao declarada sendo chamada*/
			printf("				|\t\tID da rede:%d.%d.%d.%d  	    |\n", host1, host2, host3, (host4-1)); /*recebe IP digitado - 1*/
			printf("				|\t\tIP Inicial: %d.%d.%d.%d  	    |\n", host1, host2, host3, (host4+1)); /*recebe IP digitado + 1*/
			printf("				|\t\tGateway:%d.%d.%d.%d  	    	    |\n", host1, host2, host3, host4); /*recebe IP que foi digitado*/
			printf("				|\t\tMascara:%d.%d.%d.%d  	    	    |\n", soma1,soma2,soma3,soma4); /*cada octeto(soma) é calc de um vetor (bit de 32 posic que é dividido por 8 octeto (mask) igualado a 1 e armazenado na variavel soma*/
			printf("				|\t\tIP Final: %d.%d.%d.%d  	    |\n", host1, host2, quant_ip_dispo/254, (soma5-1));/*represemtado por um cal de potencia e dividivo por 254*/
			printf("				|\t\tBroadcast: %d.%d.%d.%d\t    |\n", host1, host2, quant_ip_dispo/254, (soma5));
			printf("				|\t\tHosts Disponiveis: %d\t\t    |\n", quant_ip_dispo); /*represemtado por um cal de potencia e dividivo por 254*/
			printf("				|___________________________________________________|\n");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n										Desenvolvido por-->>Ivan Jr.<<--\n\n"); /*assinatura do autor do codigo*/
			Beep(1864,200); /*representado para emitir um som*/
			Beep(1396,180); Beep(1760,180); Beep(1864,180); /*representado para emitir um som*/
			//printf("%d \n",num/254);
			}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------										
				else{
				system("cls");	/*Limpar tela*/
				printf("				_____________________________________________________\n");
				printf(ANSI_COLOR_RED"				| 		CONVERSÃO EFETUADA !  	     	    |\n"ANSI_COLOR_NONE); /*Menu de resultados*/
				printf("				|___________________________________________________|\n");
				printf("				| 		Mascara:%d.%d.%d.%d  	    |\n", soma1,soma2,soma3,soma4); /*cada octeto(soma) é calc de um vetor (bit de 32 posic que é dividido por 8 octeto (mask) igualado a 1 e armazenado na variavel soma*/
				printf("				|___________________________________________________|\n");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n										Desenvolvido por-->>Ivan Jr.<<--\n\n\n\n"); /*assinatura do autor do codigo*/
				Beep(1864,200); /*representado para emitir um som*/
				Beep(1396,180); Beep(1760,180); Beep(1864,180);	/*representado para emitir um som*/
				}
		printf(ANSI_COLOR_RED"\t\t\t\tPRESSIONE QUALQUER \"TECLA\" PARA RETORNAR AO \"MENU\" ! ");		
//---------------------------------------------------------------------------------------------------------------------------------------------------------------										
getch(); /*pausar*/ system("cls"); /*Limpar tela*/
return main (); /*retornar ao inicio do codigo*/

}

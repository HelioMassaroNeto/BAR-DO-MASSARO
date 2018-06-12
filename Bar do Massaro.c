#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void menu() {
	
system("cls");
printf("\n");
printf("\n                               .::::.                                   ::::::.     ::    ::::::.                                    .::::.                            ");
printf("\n                             .:::::::.                                  ::    ::   ::::   ::    ::                                 .::::::::.                          ");
printf("\n                            :::::::::::                                 :::::::   ::  ::  ::::::'                                 :::::::::::                          ");
printf("\n                            ':::::::::::..                              ::    :: :::::::: ::':.                                ..:::::::::::'                          ");
printf("\n                            ':::::::::::..                              ::::::'  ::    :: ::  '::.                             ..:::::::::::'                          ");
printf("\n                            ':::::::::::.                                                                                       .:::::::::::'                          ");
printf("\n                             .::::::::::::::'                                ::::::.   .::::.                               '::::::::::::::.                           ");
printf("\n                            .:::::::::::..                                   ::    :: ::    ::                                 ..:::::::::::.                          ");
printf("\n                           :::::::::::::::                                   ::    :: ::    ::                                 :::::::::::::::                         ");
printf("\n                .::.       '::::::::''::::                                   ::    :: ::    ::                                 ::::''::::::::'       .::.              ");
printf("\n              .:::::::.      ':::::'  '::::                                  ::::::'   '::::'                                 ::::'  ':::::'      .:::::::.            ");
printf("\n            .::::':::::::.    :::::   '::::.                                                                                 .::::'   :::::    .:::::::'::::.          ");
printf("\n          .:::::' '::::::::.  :::::     ':::.         :::  :::    ::    .::::::: .:::::::    ::    ::::::.   .::::.         .:::'     :::::  .::::::::' ':::::.        ");
printf("\n        .:::::'     ':::::::::.:::::      '::.        :: :: ::   ::::   :::      :::        ::::   ::    :: ::    ::       .::'      :::::.:::::::::'     ':::::.      ");
printf("\n      .::::''         ':::::::::::::       '::.       :: :: ::  ::  ::   '::::.   '::::.   ::  ::  ::::::'  ::    ::      .::'       :::::::::::::'         ''::::.    ");
printf("\n     .::''              '::::::::::         :::...    ::    :: ::::::::      :::      ::: :::::::: ::':.    ::    ::   ...:::         ::::::::::'              ''::.   ");
printf("\n  .:::'                   '::::::'          ::::::    ::    :: ::    :: :::::::' :::::::' ::    :: ::  '::.  '::::'    ::::::          '::::::'                   ':::.");
printf("\n\n\n");
printf("              1 - Inserir Produto             2 - Alterar Produto             3 - Excluir Produto             4 - Consultar Produto             5 - Sair");
printf("                              '''''''''''''''''''             '''''''''''''''''''             '''''''''''''''''''             '''''''''''''''''''''             ''''''''\n");
printf ("\n\n    Digite a opcao desejada: ");
	
}

int main(){
	
system ("color F4");
	
struct bar{
	
char produto[150];
float preco;
int ativo, quantidade, total, conta;
	
};

FILE *pont_arq;
char texto_str[250];
char* token;
	
struct bar vetor[100];
int i=0, m;
int x=0, y,vod;

pont_arq = fopen ("registro.txt", "t");

while (fgets(texto_str, 350, pont_arq) != NULL ){

token = strtok (texto_str, "_");

while (token != NULL){
	
if (x == 0){

strcpy (vetor[i].produto, token);
x++;
	
}else if (x == 1){

sscanf (token, "%f", &vetor[i].preco);
x++;
	
}else if (x == 2){

strcpy (vetor[i].quantidade, token);
x++;
		
}else if (x == 3){

sscanf (token, "%d", &vetor[i].total);
x++;
		
}else if (x == 4){
	
vetor[i].ativo = atoi(token);
x++;

}	
token = strtok (NULL, "_");
	
}

x=0;
i++;
    
}

fclose (pont_arq);
    
menu();
scanf ("%d", &m);

while (m != 5){

switch (m){

case 1:
printf ("\n\n\nProduto: ");
scanf  ("%s", vetor[i].produto);

printf ("\nPreco: ");
scanf  ("%f", &vetor[i].preco);
  			
printf ("\nQuantidade: ");
scanf  ("%d", &vetor[i].quantidade);

vetor[i].conta=vetor[i].preco*vetor[i].quantidade;

printf ("\nTotal: %d",vetor[i].conta);

printf("\n\n\n");

vetor[i].ativo = 1;
i++;

system("pause");

break;

case 2:
printf ("\nRegistro: ");
scanf  ("%d", &vod);

printf ("\nProduto: %s", vetor[vod].produto);
printf ("\nValor: %f", vetor[vod].preco);
printf ("\nQuantidade: %d", vetor[vod].quantidade);
printf ("\nTotal: %d", vetor[vod].conta);

printf ("\n\nProduto ");
scanf  ("%s", vetor[vod].produto);

printf ("\nPreco: ");
scanf  ("%f", &vetor[vod].preco);

printf ("\nQuantidade: ");
scanf  ("%d", &vetor[vod].quantidade);

printf ("\nTotal: ");
scanf  ("%d", &vetor[vod].conta);

break;

case 3:
printf("\nCodigo: ");
scanf("%d",&vod);

vetor[vod].ativo=0;

printf("\nExcluido!\n\n");
system("pause");
  			
break;

case 4:
printf("\nRegistro: ");
scanf("%d",&vod);
printf("\nProduto: %s", vetor[vod].produto);
printf("\nPreco: %.2f", vetor[vod].preco);
printf("\nQuantidade: %d", vetor[vod].quantidade);
printf("\nTotal: %d", vetor[vod].conta);
printf("\nAtivo: %d", vetor[vod].ativo);
printf("\n\n");
system("pause");

break;

default:

printf("Invalido!\n");

break;  
  	     
}
   
menu();
scanf("%d",&m);
  
}

pont_arq = fopen ("registro.txt", "w");
    
for (y=0; y<i; y++){
        	
if (vetor[y].ativo == 1){
        		
fprintf (pont_arq, "%s_%.2f_%s_%.f_%d\n", vetor[y].produto, vetor[y].preco, vetor[y].quantidade, vetor[y].conta, vetor[y].ativo);

}
}

fclose (pont_arq);
    
}

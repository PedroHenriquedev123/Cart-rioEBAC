#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string
int registro()//fun��o responsavel por cadastrar os usu�rios
{	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de variaveis/string
	printf("digite o cpf a ser cadastrado:  ");//coletando informa��o do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo,  "w"); // cria o arquivo
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL,"portuguese"); //Definindo a linguagem

	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");

	if(file == NULL)
{
	printf("n�o foi possivel abrir o arquivo, n�o localizado:\n");
}

	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}	
system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("digite o cpf do usu�rio a ser deletado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("\n o usu�rio n�o se encontra no sistema. \n");
		system("pause");
	}
	
	else
	{
		
	if(remove(cpf) == 0) //tenta remover o arquivo correspondente ao cpf
	{
		printf("\n usu�rio deletado com sucesso!\n\n");
		system("pause");
	}
	
	}
		
}

int main()
{
    int opcao=0; //definindo var�aveis
    int laco=1;
    
	for(laco=1;laco=1;)
	{
	
	system("cls");
	
		setlocale(LC_ALL,"portuguese"); //Definindo a linguagem
	
		printf("### cart�rio da EBAC ###\n\n");//inicio do menu
		printf("escolha a op��o desejada no menu: \n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n\n");
		printf("\t4 - sair do sistema\n\n");
		printf("op��o:");//fim do menu
	
		scanf("%d", &opcao);// armazenamento a escolha do usu�rio
	
		system("cls");//responsavel por limpar a tela
	
		switch(opcao)
		{
		
			case 1:
			registro();//chamada das fun��es
			break;
			
			case 2:
			consulta();
    		break;
    	
    		case 3:
			deletar();
    		break;
    		
    		case 4:
    		printf("obrigado por utilizar o sistema");
    		return 0;
    		break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
	
		}
	
	
		
}
}


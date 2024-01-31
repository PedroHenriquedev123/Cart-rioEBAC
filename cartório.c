#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
int registro()//função responsavel por cadastrar os usuários
{	//inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variaveis/string
	printf("digite o cpf a ser cadastrado:  ");//coletando informação do usuário
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
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
	printf("não foi possivel abrir o arquivo, não localizado:\n");
}

	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\n Essas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}	
system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("digite o cpf do usuário a ser deletado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("\n o usuário não se encontra no sistema. \n");
		system("pause");
	}
	
	else
	{
		
	if(remove(cpf) == 0) //tenta remover o arquivo correspondente ao cpf
	{
		printf("\n usuário deletado com sucesso!\n\n");
		system("pause");
	}
	
	}
		
}

int main()
{
    int opcao=0; //definindo varíaveis
    int laco=1;
    
	for(laco=1;laco=1;)
	{
	
	system("cls");
	
		setlocale(LC_ALL,"portuguese"); //Definindo a linguagem
	
		printf("### cartório da EBAC ###\n\n");//inicio do menu
		printf("escolha a opção desejada no menu: \n\n");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n\n");
		printf("\t4 - sair do sistema\n\n");
		printf("opção:");//fim do menu
	
		scanf("%d", &opcao);// armazenamento a escolha do usuário
	
		system("cls");//responsavel por limpar a tela
	
		switch(opcao)
		{
		
			case 1:
			registro();//chamada das funções
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
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
	
		}
	
	
		
}
}


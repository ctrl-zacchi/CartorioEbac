#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastras os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char NOME[40];
	char SOBRENOME[40];
	char CARGO[40];
	//final da cria��o de vari�veis/strings
	
	printf("Voc� est� no registro de alunos!\n\n");
	printf("Digite seu CPF para criar seu usu�rio: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se as strings
	
	strcpy(arquivo, cpf); //strcpy responsavel por copiar o valor das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //salva o ID
	fclose(file); //fecha o comando
	
	file = fopen(arquivo, "a");
	fprintf(file," Nome: ");
	fclose(file);
	
	printf("Digite seu nome: ");
	scanf("%s",NOME);
	
	file = fopen(arquivo, "a");
	fprintf(file,NOME);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file," Sobrenome: ");
	fclose(file);
	
	printf("Digite seu sobrenome: ");
	scanf("%s",SOBRENOME);
	
	file = fopen(arquivo, "a");
	fprintf(file,SOBRENOME);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," Cargo: ");
	fclose(file);
	
	printf("Digite seu cargo atual na EBAC: ");
	scanf("%s",CARGO);
	
	file = fopen(arquivo, "a");
	fprintf(file,CARGO);
	fclose(file);
	
	system("pause");
	
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Voc� est� na aba de Consultar Alunos!");
	printf("\n\nDigite o CPF que deseja consultar:");
	scanf("%s",cpf);
	
	FILE *file;
	file =fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("\nAluno n�o encontrado, n�o foi possivel abrir o arquivo.\n");
	}
	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nEstas s�o as informa��es encontradas.\n\n");
	printf("%s", conteudo);
	}
	
	system("pause");
}


int deletar()
{
	char cpf[40];
	
	printf("Voc� escolheu a op��o de Deletar Alunos!");
	printf("\n\nDigite o CPF para deletar o usu�rio:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nEste CPF n�o foi registrado no sistema.\n\n");
		system("pause");
	}
}


int main()
{
	int opcao=0; //definindo var�avel
	int repeticao=1;
	
	for(repeticao=1;repeticao=1;)
{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
		printf("Cart�rio digital da EBAC\n\n"); //as # servem como espa�amentos dentro das mensagens
		printf("Escolha a op��o desejada:\n\n");
		printf("\t1 - Registrar Nomes\n"); // \t responsavel por dar espa�o no come�o da frase
		printf("\t2 - Consultar Alunos\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\t4 - Sair\n\n");
		printf("Qual op��o deseja para continuarmos?:");

		scanf("%d", &opcao); //scan serve para escanear as informa��es digitadas pelo usu�rio
	
		system("cls"); //cls limpa a tela
	
		
		switch(opcao)
		{
			
		case 1:
		registro(); //chamada de fun��o
		break;
		
		case 2:
		consulta(); //chamada de fun��o
		break;
		
		case 3:
		deletar(); //chamada de fun��o
		break;
		
		case 4:
		printf("Obrigado por utilizar meu sistema, volte sempre! :D\n\n");
		return 0;
		break;
		
		default:
		printf("\nOp��o escolhida n�o est� dispon�vel, volte ao menu para ver as op��es dispon�veis!\n\n\n");
		system("pause");
		break;
		}
	
    
}    

}

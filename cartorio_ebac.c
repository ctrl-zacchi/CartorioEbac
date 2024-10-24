#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastras os usuários no sistema
{
	//início criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char NOME[40];
	char SOBRENOME[40];
	char CARGO[40];
	//final da criação de variáveis/strings
	
	printf("Você está no registro de alunos!\n\n");
	printf("Digite seu CPF para criar seu usuário: "); //coletando informações do usuário
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
	
	printf("Você está na aba de Consultar Alunos!");
	printf("\n\nDigite o CPF que deseja consultar:");
	scanf("%s",cpf);
	
	FILE *file;
	file =fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("\nAluno não encontrado, não foi possivel abrir o arquivo.\n");
	}
	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nEstas são as informações encontradas.\n\n");
	printf("%s", conteudo);
	}
	
	system("pause");
}


int deletar()
{
	char cpf[40];
	
	printf("Você escolheu a opção de Deletar Alunos!");
	printf("\n\nDigite o CPF para deletar o usuário:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nEste CPF não foi registrado no sistema.\n\n");
		system("pause");
	}
}


int main()
{
	int opcao=0; //definindo varíavel
	int repeticao=1;
	
	for(repeticao=1;repeticao=1;)
{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
		printf("Cartório digital da EBAC\n\n"); //as # servem como espaçamentos dentro das mensagens
		printf("Escolha a opção desejada:\n\n");
		printf("\t1 - Registrar Nomes\n"); // \t responsavel por dar espaço no começo da frase
		printf("\t2 - Consultar Alunos\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\t4 - Sair\n\n");
		printf("Qual opção deseja para continuarmos?:");

		scanf("%d", &opcao); //scan serve para escanear as informações digitadas pelo usuário
	
		system("cls"); //cls limpa a tela
	
		
		switch(opcao)
		{
			
		case 1:
		registro(); //chamada de função
		break;
		
		case 2:
		consulta(); //chamada de função
		break;
		
		case 3:
		deletar(); //chamada de função
		break;
		
		case 4:
		printf("Obrigado por utilizar meu sistema, volte sempre! :D\n\n");
		return 0;
		break;
		
		default:
		printf("\nOpção escolhida não está disponível, volte ao menu para ver as opções disponíveis!\n\n\n");
		system("pause");
		break;
		}
	
    
}    

}

#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das string
	
	FILE *file; // Cria o arquivo do Banco de Dados
	file = fopen(arquivo, "w"); // Cria o arquivo do Banco de Dados, o "w" significa escrever
	fprintf(file,cpf); // Salva o valor da vari�vel
	fclose(file); // |Fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);	
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta() // // Fun��o respons�vel por consultar o CPF dos usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); // Coletando informa��o do usu�rio
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, arquivo n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n\n");
		system("pause");
	}
	
	else
	{
		printf("O usu�rio foi deletado com sucesso!.\n\n");
		system("pause");	
	}
	
}

int main()
{
	int opcao=0; //Definindo vari�vel
	int laco=1;	
	char senhadigitada[]="a";
	int comparacao;

	printf("#### Cart�rio da EBAC ####\n");
	printf("Login de Administrador!\n");
	printf("Digite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
 	
	if(comparacao == 0)
	{
		
		for(laco=1;laco=1;)
		{
	
			system("cls");
		
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
			printf("#### Cart�rio da EBAC ####\n"); //In�cio do Menu
			printf("\nEscolha a op��o desejada do menu: \n\n");
			printf("\t1- Registrar nomes\n");
			printf("\t2- Consultar nomes\n");
			printf("\t3- Deletar nomes\n"); 
			printf("\t4- Sair do Sistema\n\n"); 
			printf("Op��o: "); //Fim do Menu
	
			scanf("%d", &opcao); //Armanzeando a escolha do Usu�rio
		
			system("cls"); // Respons�vel por limpar a tela
		
			switch(opcao) // Chamada de fun��es
			{
				case 1:
				registro();
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
								
				default:
				printf("Essa Op��o n�o est� dispon�vel\n\n");
				system("pause");
				break;
			} //Fim da sele��o
		}
	}
	
	else
		printf("Senha Incorreta!");
		
		
}

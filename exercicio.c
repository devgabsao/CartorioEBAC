#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastrar os usuários no sistema
{
	// Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das string
	
	FILE *file; // Cria o arquivo do Banco de Dados
	file = fopen(arquivo, "w"); // Cria o arquivo do Banco de Dados, o "w" significa escrever
	fprintf(file,cpf); // Salva o valor da variável
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

int consulta() // // Função responsável por consultar o CPF dos usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); // Coletando informação do usuário
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, arquivo não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
		printf("O usuário não se encontra no sistema!.\n\n");
		system("pause");
	}
	
	else
	{
		printf("O usuário foi deletado com sucesso!.\n\n");
		system("pause");	
	}
	
}

int main()
{
	int opcao=0; //Definindo variável
	int laco=1;	
	char senhadigitada[]="a";
	int comparacao;

	printf("#### Cartório da EBAC ####\n");
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
	
			printf("#### Cartório da EBAC ####\n"); //Início do Menu
			printf("\nEscolha a opção desejada do menu: \n\n");
			printf("\t1- Registrar nomes\n");
			printf("\t2- Consultar nomes\n");
			printf("\t3- Deletar nomes\n"); 
			printf("\t4- Sair do Sistema\n\n"); 
			printf("Opção: "); //Fim do Menu
	
			scanf("%d", &opcao); //Armanzeando a escolha do Usuário
		
			system("cls"); // Responsável por limpar a tela
		
			switch(opcao) // Chamada de funções
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
				printf("Essa Opção não está disponível\n\n");
				system("pause");
				break;
			} //Fim da seleção
		}
	}
	
	else
		printf("Senha Incorreta!");
		
		
}

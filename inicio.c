//Matheus Soppa Geremias
//André de Campos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct endereco 
{
	int numero;
	char complemento[100];
	int cep;
	char rua[100];
	char bairro[100];
	char cidade[100];
	char estado[100];
	char pais[100];
};

struct telefone 
{
	int cod_inter;
	int cod_area;
	int numero;
};

struct nascimento 
{
	int dia;
	int mes;
	int ano;
};

struct pessoa 
{
	char nome[100];
	char email[100];
	char comentario[256];
	struct endereco ender;
	struct telefone tel;
	struct nascimento data;
};

int inserir_pessoas(struct pessoa *agenda, int pessoas_existentes, int qtd_pessoas);

int imprime_tudo(struct pessoa *agenda, int pessoas_existentes);

int imprime_um_pouco(struct pessoa *agenda, int pessoas_existentes);

int acha_pessoa(struct pessoa *agenda, int pessoas_existentes);

int acha_niver(struct pessoa *agenda, int pessoas_existentes);

int acha_niverdia(struct pessoa *agenda, int pessoas_existentes);

int remover_pessoas(struct pessoa *agenda, int *pessoas_existentes);

int ler_arquivo(struct pessoa *agenda, int *pessoas_existentes, FILE *arquivo);


int main() 
{
	int qtd_pessoas, i, variavel_menu = 1, pessoas_existentes = 0;
	struct pessoa *agenda;

	FILE *arquivo;

	if ((arquivo = fopen("agenda.txt", "r")) == NULL) {

		agenda = (struct pessoa*) malloc (MAX * sizeof(struct pessoa));

		while (variavel_menu > 0)
		{
			printf("\nOlá, sou sua agenda telefônica. O que gostaria de fazer? Digite a opção desejada\n[1] - Inserir pessoas por ordem alfábetica\n[2] - Retirar uma pessoa\n[3] - Mostrar todos os nomes, telefones e emails\n[4] - Mostrar todos os dados disponíveis\n[5] - Buscar com o primeiro nome\n[6] - Buscar por mês de aniversário\n[7] - Buscar por dia e mês de aniversário\n[0] - Fechar a agenda\n");
			scanf("%d", &variavel_menu);

			if (variavel_menu == 1) 
			{
				printf("Quantas pessoas gostaria de adicionar?\n");
				scanf("%d", &qtd_pessoas);
				inserir_pessoas(agenda, pessoas_existentes, qtd_pessoas);
				pessoas_existentes += qtd_pessoas;
				
			}
			else if (variavel_menu == 2) 
			{
				remover_pessoas(agenda, &pessoas_existentes);
			}
			else if (variavel_menu == 3) 
			{
				imprime_um_pouco(agenda, pessoas_existentes);
			}
			else if (variavel_menu == 4) 
			{
				imprime_tudo(agenda, pessoas_existentes);
			}
			else if (variavel_menu == 5) 
			{
				acha_pessoa(agenda, pessoas_existentes);
			}
			else if (variavel_menu == 6) 
			{
				acha_niver(agenda, pessoas_existentes);
			}
			else if (variavel_menu == 7) 
			{
				acha_niverdia(agenda, pessoas_existentes);
			}
		}
		
		printf("\n\nObrigado por usar nossa agenda, volte sempre.\n\n");
		return 0;
	}
	else {

		agenda = (struct pessoa*) malloc (MAX * sizeof(struct pessoa));
		ler_arquivo(agenda, &pessoas_existentes, arquivo);

    while (variavel_menu > 0)
		{
			printf("\nOlá, sou sua agenda telefônica. O que gostaria de fazer? Digite a opção desejada\n[1] - Inserir pessoas por ordem alfábetica\n[2] - Retirar uma pessoa\n[3] - Mostrar todos os nomes, telefones e emails\n[4] - Mostrar todos os dados disponíveis\n[5] - Buscar com o primeiro nome\n[6] - Buscar por mês de aniversário\n[7] - Buscar por dia e mês de aniversário\n[0] - Fechar a agenda\n");
			scanf("%d", &variavel_menu);

			if (variavel_menu == 1) 
			{
				printf("Quantas pessoas gostaria de adicionar?\n");
				scanf("%d", &qtd_pessoas);
				inserir_pessoas(agenda, pessoas_existentes, qtd_pessoas);
				pessoas_existentes += qtd_pessoas;
				
			}
			else if (variavel_menu == 2) 
			{
				remover_pessoas(agenda, &pessoas_existentes);
			}
			else if (variavel_menu == 3) 
			{
				imprime_um_pouco(agenda, pessoas_existentes);
			}
			else if (variavel_menu == 4) 
			{
				imprime_tudo(agenda, pessoas_existentes);
			}
			else if (variavel_menu == 5) 
			{
				acha_pessoa(agenda, pessoas_existentes);
			}
			else if (variavel_menu == 6) 
			{
				acha_niver(agenda, pessoas_existentes);
			}
			else if (variavel_menu == 7) 
			{
				acha_niverdia(agenda, pessoas_existentes);
			}
		}
		
		printf("\n\nObrigado por usar nossa agenda, volte sempre.\n\n");
		return 0;
	}
}

int inserir_pessoas(struct pessoa *agenda, int pessoas_existentes, int qtd_pessoas) 
{
	int i, aux;
	char auxc[100];

	for (i = pessoas_existentes, aux = 0; aux < qtd_pessoas; i++, aux++) 
	{

		printf("Por favor, insira os dados requisitados.\n");

		//Melhorar o visual dos inputs, para deixar mais amigável

		printf("Digite seu nome: ");
		scanf("\n%[A-Z a-z]s",agenda[i].nome);
		fflush(stdin);

		printf("Digite seu email: ");
		scanf("\n%[A-Z a-z @ .]s", agenda[i].email);
		fflush(stdin);

		printf("Digite seu endereco na seguinte ordem: Rua, número, bairro, cidade, CEP, estado, país e complemento, como no exemplo a seguir:\n Rua Xablau \n691 \nVila Sesámo \nGothan \n12345678 \nTatooine \nNova Zelândia \nCasa:\n");
		scanf("\n%[A-Z a-z]s", agenda[i].ender.rua);
		fflush(stdin);
		scanf("\n%d", &agenda[i].ender.numero);
		fflush(stdin);
		scanf("\n%[A-Z a-z]s", agenda[i].ender.bairro);
		fflush(stdin);
		scanf("\n%[A-Z a-z]s", agenda[i].ender.cidade);
		fflush(stdin);
		scanf("\n%d", &agenda[i].ender.cep);
		fflush(stdin);
		scanf("\n%[A-Z a-z]s", agenda[i].ender.estado);
		fflush(stdin);
		scanf("\n%[A-Z a-z]s", agenda[i].ender.pais);
		fflush(stdin);
		scanf("\n%[A-Z a-z]s", agenda[i].ender.complemento);
		fflush(stdin);

		printf("Digite seu numero telefônico como no exemplo a seguir: 55 47 999999999\n ");
		scanf("\n%d", &agenda[i].tel.cod_inter);
		fflush(stdin);
		scanf("\n%d", &agenda[i].tel.cod_area);
		fflush(stdin);
		scanf("\n%d", &agenda[i].tel.numero);
		fflush(stdin);

		printf("Digite sua data de nascimento na seguinte ordem: dia, mês e ano, como o no exemplo a seguir: 20 11 1999\n");
		scanf("\n%d", &agenda[i].data.dia);
		fflush(stdin);
		scanf("\n%d", &agenda[i].data.mes);
		fflush(stdin);
		scanf("\n%d", &agenda[i].data.ano);
		fflush(stdin);

		printf("Tem alguma observação? Pode escrever alguma coisa: ");
		scanf("\n%[A-Z a-z]s", agenda[i].comentario);
		fflush(stdin);
  }

  return 0;
}

int imprime_tudo(struct pessoa *agenda, int pessoas_existentes) 
{
	int i;

	for (i = 0; i < pessoas_existentes; i++) 
	{
		printf("Nome: %s\n",agenda[i].nome);

		printf("Email: %s\n", agenda[i].email);

		printf("Endereço: %s, %d, %s, %s, %d - %s, %s - %s\n", agenda[i].ender.rua, agenda[i].ender.numero, agenda[i].ender.bairro, agenda[i].ender.cidade, agenda[i].ender.cep, agenda[i].ender.estado, agenda[i].ender.pais, agenda[i].ender.complemento);

		printf("Numero telefônico: +%d%d%d\n", agenda[i].tel.cod_inter, agenda[i].tel.cod_area, agenda[i].tel.numero);

		printf("Data de nascimento: %d/%d/%d\n", agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);

		printf("Observação: %s\n\n\n", agenda[i].comentario);
  }
  
  return 0;
}

int imprime_um_pouco(struct pessoa *agenda, int pessoas_existentes) 
{
	int i;

	for (i = 0; i < pessoas_existentes; i++) 
	{
		printf("Nome: %s\n",agenda[i].nome);

		printf("Email: %s\n", agenda[i].email);

		printf("Numero telefônico: +%d%d%d\n", agenda[i].tel.cod_inter, agenda[i].tel.cod_area, agenda[i].tel.numero);
  }
  
  return 0;
}

int acha_pessoa(struct pessoa *agenda, int pessoas_existentes)
{

	int i, tamanho;
	char nome[100];

	printf("Quem você gostaria de encontrar?");
	scanf("\n%[A-Z a-z]s", nome);
	tamanho = strlen(nome);

	for (i = 0; i < pessoas_existentes; i++) 
	{

		if (strncmp(nome,agenda[i].nome, tamanho) == 0) 
		{
			printf("\nOs dados encontrados dessa pessoa são:\n");
			printf("Email: %s\n", agenda[i].email);
			printf("Endereço: %s, %d, %s, %s, %d - %s, %s - %s\n", agenda[i].ender.rua, agenda[i].ender.numero, agenda[i].ender.bairro, agenda[i].ender.cidade, agenda[i].ender.cep, agenda[i].ender.estado, agenda[i].ender.pais, agenda[i].ender.complemento);
			printf("Numero telefônico: +%d%d%d\n", agenda[i].tel.cod_inter, agenda[i].tel.cod_area, agenda[i].tel.numero);

		}
	}
  return 0;
}

int acha_niver(struct pessoa *agenda, int pessoas_existentes)
{
	int mes, i;

	printf("Qual mes de aniversario de quem quer encontrar?");
	scanf("\n%d", &mes);

	for (i = 0; i < pessoas_existentes; i++) 
    {
		if (agenda[i].data.mes==mes) 
		{
			printf("\nOs dados encontrados dessa pessoa são:\n");
			printf("Nome: %s\n", agenda[i].nome);
			printf("Email: %s\n", agenda[i].email);
			printf("Endereço: %s, %d, %s, %s, %d - %s, %s - %s\n", agenda[i].ender.rua, agenda[i].ender.numero, agenda[i].ender.bairro, agenda[i].ender.cidade, agenda[i].ender.cep, agenda[i].ender.estado, agenda[i].ender.pais, agenda[i].ender.complemento);
			printf("Numero telefônico: +%d%d%d\n", agenda[i].tel.cod_inter, agenda[i].tel.cod_area, agenda[i].tel.numero);
		}
	}
    return 0;
}


int acha_niverdia(struct pessoa *agenda, int pessoas_existentes)
{
	int mes, dia, i;

	printf("Qual o dia e o mes de aniversario de quem quer encontrar?\nDigite no padrao dia mes(00 00)");
	scanf("\n%d%d",&dia, &mes);

	for (i = 0; i < pessoas_existentes; i++) 
    {
		if (agenda[i].data.mes==mes) 
		{
			if (agenda[i].data.dia==dia)
			{
				printf("\nOs dados encontrados dessa pessoa são:\n");
				printf("Nome: %s\n", agenda[i].nome);
				printf("Email: %s\n", agenda[i].email);
				printf("Endereço: %s, %d, %s, %s, %d - %s, %s - %s\n", agenda[i].ender.rua, agenda[i].ender.numero, agenda[i].ender.bairro, agenda[i].ender.cidade, agenda[i].ender.cep, agenda[i].ender.estado, agenda[i].ender.pais, agenda[i].ender.complemento);
				printf("Numero telefônico: +%d%d%d\n", agenda[i].tel.cod_inter, agenda[i].tel.cod_area, agenda[i].tel.numero);
			}
		}
			
	}
    return 0;
}


int remover_pessoas(struct pessoa *agenda, int *pessoas_existentes) 
{
	int i, j, aux= 0;
	char nome[40];

	printf("Quem você gostaria de remover?");
	scanf("\n%[A-Z a-z]s", nome);

	for (j = 0; j < *pessoas_existentes; j++) 
	{
		if (strcmp(nome,agenda[j].nome) == 0) 
		{
			for(i=j;i<*pessoas_existentes;i++)
			{
				strcpy(agenda[i].nome, agenda[i+1].nome);
				strcpy(agenda[i].email, agenda[i+1].email);
				strcpy(agenda[i].ender.rua, agenda[i+1].ender.rua);
				strcpy(agenda[i].ender.complemento, agenda[i+1].ender.complemento);
				strcpy(agenda[i].ender.bairro, agenda[i+1].ender.bairro);
				strcpy(agenda[i].ender.cidade, agenda[i+1].ender.cidade);
				strcpy(agenda[i].ender.estado, agenda[i+1].ender.estado);
				strcpy(agenda[i].ender.pais, agenda[i+1].ender.pais);
				strcpy(agenda[i].comentario, agenda[i+1].comentario);
				agenda[i].ender.numero = agenda[i+1].ender.numero;
				agenda[i].ender.cep = agenda[i+1].ender.cep;
				agenda[i].tel.cod_inter = agenda[i+1].tel.cod_inter;
				agenda[i].tel.cod_area = agenda[i+1].tel.cod_area;
				agenda[i].tel.numero = agenda[i+1].tel.numero;
				agenda[i].data.dia = agenda[i+1].data.dia;
				agenda[i].data.mes = agenda[i+1].data.mes;
				agenda[i].data.ano = agenda[i+1].data.ano;
			}
			aux++;
		}
	}
	if(aux==0)
	{
		printf("\nNenhuma pessoa deletada da agenda.\n");
	}else
	{
		*pessoas_existentes = *pessoas_existentes-1;

	}

	return 0;
}

int ler_arquivo(struct pessoa *agenda, int *pessoas_existentes, FILE *arquivo) {
	
	int i = 0;
	while (!feof(arquivo)) {

		fscanf(arquivo, "\n%[A-Z a-z]s",agenda[i].nome);

		fscanf(arquivo,"\n%[A-Z a-z @ .]s", agenda[i].email);


		fscanf(arquivo,"\n%[A-Z a-z]s", agenda[i].ender.rua);
		fscanf(arquivo,"\n%d", &agenda[i].ender.numero);
		fscanf(arquivo,"\n%[A-Z a-z]s", agenda[i].ender.bairro);
		fscanf(arquivo,"\n%[A-Z a-z]s", agenda[i].ender.cidade);
		fscanf(arquivo,"\n%d", &agenda[i].ender.cep);
		fscanf(arquivo,"\n%[A-Z a-z]s", agenda[i].ender.estado);
		fscanf(arquivo,"\n%[A-Z a-z]s", agenda[i].ender.pais);
		fscanf(arquivo,"\n%[A-Z a-z]s", agenda[i].ender.complemento);


		fscanf(arquivo,"\n%d", &agenda[i].tel.cod_inter);
		fscanf(arquivo,"\n%d", &agenda[i].tel.cod_area);
		fscanf(arquivo,"\n%d", &agenda[i].tel.numero);

		fscanf(arquivo,"\n%d", &agenda[i].data.dia);
		fscanf(arquivo,"\n%d", &agenda[i].data.mes);
		fscanf(arquivo,"\n%d", &agenda[i].data.ano);

		fscanf(arquivo,"\n%[A-Z a-z]s", agenda[i].comentario);
		
		i++;
    *pessoas_existentes = *pessoas_existentes + 1;
    }
    return 0;
}
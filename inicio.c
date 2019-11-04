//Matheus Soppa Geremias
//André de Campos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct endereco 
{
	int numero;
	char complemento[40];
	int cep;
	char rua[40];
	char bairro[40];
	char cidade[40];
	char estado[40];
	char pais[40];
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
	char nome[40];
	char email[40];
	char comentario[40];
	struct endereco ender;
	struct telefone tel;
	struct nascimento data;
};

int inserir_pessoas(struct pessoa *agenda, int qtd_pessoas);

int imprime_tudo(struct pessoa *agenda, int pessoas_existentes);

int imprime_um_pouco(struct pessoa *agenda, int pessoas_existentes);

int acha_pessoa(struct pessoa *agenda, int pessoas_existentes);

int acha_niver(struct pessoa *agenda, int pessoas_existentes);

int acha_niverdia(struct pessoa *agenda, int pessoas_existentes);


int main() 
{
	int qtd_pessoas, i, variavel_menu = 1, pessoas_existentes = 0;
	struct pessoa agenda[6];


	while (variavel_menu > 0)
	{
		printf("\nOlá, sou sua agenda telefônica. O que gostaria de fazer? Digite a opção desejada\n[1] - Inserir pessoas por ordem alfábetica\n[2] - Retirar uma pessoa\n[3] - Mostrar todos os nomes, telefones e emails\n[4] - Mostrar todos os dados disponíveis\n[5] - Buscar com o primeiro nome\n[6] - Buscar por mês de aniversário\n[7] - Buscar por dia e mês de aniversário\n[0] - Fechar a agenda\n");
		scanf("%d", &variavel_menu);

		if (variavel_menu == 1) 
		{
			printf("Quantas pessoas gostaria de adicionar?\n");
			scanf("%d", &qtd_pessoas);
			pessoas_existentes += qtd_pessoas;
			inserir_pessoas(&agenda[6], qtd_pessoas);
		}
		else if (variavel_menu == 2) 
		{
			printf("\nCalma, ainda estamos implementando essa função :D\n");
		}
		else if (variavel_menu == 3) 
		{
			imprime_um_pouco(&agenda[6], pessoas_existentes);
		}
		else if (variavel_menu == 4) 
		{
			imprime_tudo(&agenda[6], pessoas_existentes);
		}
		else if (variavel_menu == 5) 
		{
			acha_pessoa(&agenda[6], pessoas_existentes);
		}
		else if (variavel_menu == 6) 
		{
			acha_niver(struct pessoa *agenda, int pessoas_existentes);
		}
		else if (variavel_menu == 7) 
		{
			acha_niverdia(struct pessoa *agenda, int pessoas_existentes);
		}
	}
	
	printf("\n\nObrigado por usar nossa agenda, volte sempre.\n\n");
	return 0;
}

int inserir_pessoas(struct pessoa *agenda, int qtd_pessoas) 
{
	int i, aux;
	char auxc[40];

	for (i = 0; i < qtd_pessoas; i++) 
	{

		printf("Por favor, insira os dados requisitados.\n");

		//Melhorar o visual dos inputs, para deixar mais amigável

		printf("Digite seu nome: ");
		scanf("\n%[A-Z a-z]s",agenda[i].nome);
		fflush(stdin);

		printf("Digite seu email: ");
		scanf("\n%[A-Z a-z]s", agenda[i].email);
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

	int i;
	char nome[40];

	printf("Quem você gostaria de encontrar?");
	scanf("\n%[A-Z a-z]s", nome);

	for (i = 0; i < pessoas_existentes; i++) 
	{

		if (strcmp(nome,agenda[i].nome) == 0) 
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

//Matheus Soppa Geremias
//Andrézinho

#include <stdio.h>
#include <stdlib.h>

struct endereco {
	int numero;
	char complemento[40];
	int cep;
	char rua[40];
	char bairro[40];
	char cidade[40];
	char estado[40];
	char pais[40];
};

struct telefone {
	int cod_inter;
	int cod_area;
	int numero;
};

struct nascimento {
	int dia;
	int mes;
	int ano;
};

struct pessoa {
	char nome[40];
	char email[40];
	char comentario[40];
	struct endereco ender;
	struct telefone tel;
	struct nascimento data;
};

int main() {
	int qtd_pessoas = 6, i, variavel_menu;
	struct pessoa agenda[6];

	//criar as opcoes de menu de acordo com a variavel_menu
	printf("Olá, sou sua agenda telefônica. O que gostaria de fazer? Digite a opção desejada\n[1] - Inserir pessoas por ordem alfábetica\n[2] - Retirar uma pessoa\n[3] - Mostrar todos os nomes, telefones e emails\n[4] - Mostrar todos os dados dispóniveis\n[5] - Buscar com o primeiro nome\n[6] - Buscar por mês de aniversário\n[7] - Buscar por dia e mês de aniversário\n");
	scanf("%d", &variavel_menu);

	//insere pessoas, criar funcao para cada opcao do menu?
	for (i = 0; i < qtd_pessoas; i++) {

		printf("Por favor, insira os dados requisitados.\n");

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
	printf("Hello there, my name is Supper Soppa");
	return 0;
}
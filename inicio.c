//Matheus Soppa Geremias
//Andrézinho

#include <stdio.h>
#include <stdlib.h>

struct endereco {
	int numero;
	int complemento;
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
	struct pessoa humanos[6];
	printf("Hello there, my name is Supper Soppa");
	return 0;
}
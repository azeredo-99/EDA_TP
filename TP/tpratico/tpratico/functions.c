#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Inserção de um novo registo
Meio* adicionarMeio(Meio* inicio, int cod, char tipo[], float bat, float aut)
{
	if (!existeMeio(inicio, cod))
	{
		Meio* novo = malloc(sizeof(struct registo));
		if (novo != NULL)
		{
			novo->codigo = cod;
			strcpy(novo->tipo, tipo);
			novo->bateria = bat;
			novo->autonomia = aut;
			novo->seguinte = inicio;
			return(novo);
		}
	}
	else return(inicio);
}

// listar na consola o conteúdo da lista ligada
void listarMeios(Meio* inicio)
{
	while (inicio != NULL)
	{
		printf("%d %s %.2f %.2f\n", inicio->codigo, inicio->tipo,
			inicio->bateria, inicio->autonomia);
		inicio = inicio->seguinte;
	}
}

Meio* removerMeio(Meio* inicio, int cod)
{
	Meio* anterior = inicio, * atual = inicio, * aux;

	if (atual == NULL) return(NULL);
	else if (atual->codigo == cod) // remoção do 1º registo
	{
		aux = atual->seguinte;
		free(atual);
		return(aux);
	}
	else
	{
		while ((atual != NULL) && (atual->codigo != cod))
		{
			anterior = atual;
			atual = atual->seguinte;
		}
		if (atual == NULL) return(inicio);
		else
		{
			anterior->seguinte = atual->seguinte;
			free(atual);
			return(inicio);
		}
	}
}


Meio* guardarMeios(Meio* inicio)
{
	FILE* fp;
	fp = fopen("meios.txt", "w");
	if (fp != NULL)
	{
		Meio* aux = inicio;
		while (aux != NULL)
		{
			fprintf(fp, "%d;%f;%f;%s\n", aux->codigo, aux->bateria,
				aux->autonomia, aux->tipo);
			aux = aux->seguinte;
		}
		fclose(fp);
		return(1);
	}
	else return(0);
}

Meio* lerMeios()
{
	FILE* fp;
	int cod;
	float bat, aut;
	char tipo[50];
	Meio* aux = NULL;
	fp = fopen("meios.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%f;%f;%[^\n]\n", &cod, &bat, &aut, tipo);
			aux = adicionarMeio(aux, cod, tipo, bat, aut);
		}
		fclose(fp);
	}
	return(aux);
}

// Determinar existência do 'codigo' na lista ligada 'inicio'
// devolve 1 se existir ou 0 caso contrário
int existeMeio(Meio* inicio, int cod)
{
	while (inicio != NULL)
	{
		if (inicio->codigo == cod) return(1);
		inicio = inicio->seguinte;
	}
	return(0);
}


User* adicionarUser(User* inicio, int id, int NIF, float saldo, char nome[], char morada[])
{
	if (!existeUser(inicio, id))
	{
		User* novo = malloc(sizeof(struct utilizador));
		if (novo != NULL)
		{
			strcpy(novo -> nome, nome);
			novo->id = id;
			novo->NIF = NIF;
			novo->saldo = saldo;
			strcpy(novo -> nome, nome);
			strcpy(novo -> morada, morada);
			novo->seguinte = inicio;
			return(novo);
		}
	}
	else return(inicio);
}


void listarUser(User* inicio)
{
	while (inicio != NULL)
	{
		printf("%d %s %s %d %.2f\n", inicio->id, inicio->nome, inicio->morada, inicio->NIF,
			inicio->saldo);
		inicio = inicio->seguinte;
	}
}


User* removerUser(User* inicio, int id)
{
	User* anterior = inicio, * atual = inicio, * aux;

	if (atual == NULL) return(NULL);
	else if (atual->id == id) // remoção do 1º registo
	{
		aux = atual->seguinte;
		free(atual);
		return(aux);
	}
	else
	{
		while ((atual != NULL) && (atual->id != id))
		{
			anterior = atual;
			atual = atual->seguinte;
		}
		if (atual == NULL) return(inicio);
		else
		{
			anterior->seguinte = atual->seguinte;
			free(atual);
			return(inicio);
		}
	}
}

User* guardarUser(User* inicio)
{
	FILE* fp;
	fp = fopen("user.txt", "w");
	if (fp != NULL)
	{
		User* aux = inicio->seguinte;
		while (aux != NULL)
		{
			fprintf(fp, "%d;%d;%f;%s;%s\n", aux->id, aux->NIF,
				aux->saldo, aux->nome, aux->morada);
			aux = aux->seguinte;
		}
		fclose(fp);
		return(1);
	}
	else return(0);
}


User* lerUser()
{
	FILE* fp;
	int id, nif;
	char nome[50], morada[50];
	float sa;
	User* aux = NULL;
	fp = fopen("user.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d;%f;%f;%[^\n]s\n", &id, &nif, &sa, &nome);
			aux = adicionarUser(aux, id, nif, sa, nome, morada);
		}
		fclose(fp);
	}
	return(aux);
}

int existeUser(User* inicio, int id)
{
	while (inicio != NULL)
	{
		if (inicio->id == id) return(1);
		inicio = inicio->seguinte;
	}
	return(0);
}


Gestor* adicionarGestor(Gestor* inicio, int idGestor, char nomeGestor[50], char moradaGestor[50])
{
	if (!existeGestor(inicio, idGestor))
	{
		Gestor* novo = malloc(sizeof(struct gestor));
		if (novo != NULL)
		{
			novo->idGestor = idGestor;
			strcpy(novo->nomeGestor, nomeGestor);
			strcpy(novo->moradaGestor, moradaGestor);
			return(novo);
		}
	}
	else return(inicio);
}


Gestor* listarGestor(Gestor* inicio)
{
	while (inicio != NULL)
	{
		printf("%d %s %.2f %.2f\n", inicio->idGestor, inicio->nomeGestor,
			inicio->moradaGestor);
		inicio = inicio->seguinte;
	}
}


Gestor* removerGestor(Gestor* inicio, int idGestor)
{
	Gestor* anterior = inicio, * atual = inicio, * aux;

	if (atual == NULL) return(NULL);
	else if (atual->idGestor == idGestor) // remoção do 1º registo
	{
		aux = atual->seguinte;
		free(atual);
		return(aux);
	}
	else
	{
		while ((atual != NULL) && (atual->idGestor != idGestor))
		{
			anterior = atual;
			atual = atual->seguinte;
		}
		if (atual == NULL) return(inicio);
		else
		{
			anterior->seguinte = atual->seguinte;
			free(atual);
			return(inicio);
		}
	}
}


int existeGestor(Gestor* inicio, int idGestor)
{
	while (inicio != NULL)
	{
		if (inicio->idGestor == idGestor) return(1);
		inicio = inicio->seguinte;
	}
	return(0);
}


// Editar um atributo do usuário com o id especificado
User* editarUser(User* inicio, int id, char atributo[], char novoValor[]) {
	User* atual = inicio;
	while (atual != NULL) {
		if (atual->id == id) {
			if (strcmp(atributo, "id") == 0) {
				printf("O id não pode ser editado\n");
			}
			else if (strcmp(atributo, "nome") == 0) {
				strcpy(atual->nome, novoValor);
			}
			else if (strcmp(atributo, "morada") == 0) {
				strcpy(atual->morada, novoValor);
			}
			else if (strcmp(atributo, "nif") == 0) {
				atual->NIF = atoi(novoValor);
			}
			else if (strcmp(atributo, "saldo") == 0) {
				atual->saldo = atof(novoValor);
			}
			else {
				printf("Atributo inválido\n");
			}
			break;
		}
		atual = atual->seguinte;
	}
	if (atual == NULL) {
		printf("Usuário não encontrado\n");
	}
	return inicio;
}

Gestor* guardarGestor(Meio* inicio)
{
	FILE* fp;
	fp = fopen("gestor.txt", "w");
	if (fp != NULL)
	{
		Gestor* aux = inicio;
		while (aux != NULL)
		{
			fprintf(fp, "%d;%f;%f\n", aux->idGestor, aux->nomeGestor,
				aux->moradaGestor);
			aux = aux->seguinte;
		}
		fclose(fp);
		return(1);
	}
	else return(0);
}

void guardarDadosTexto(No* listaNos, const char* nomeFicheiro) {
	FILE* arquivo = fopen(nomeFicheiro, "w");
	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo de texto.\n");
		return;
	}

	No* noAtual = listaNos;
	while (noAtual != NULL) {
		fprintf(arquivo, "%d %.6f %.6f\n", noAtual->id, noAtual->latitude, noAtual->longitude);
		noAtual = noAtual->proximo;
	}

	fclose(arquivo);
}

No* lerDadosTexto(const char* nomeFicheiro) {
	FILE* arquivo = fopen(nomeFicheiro, "r");
	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo de texto.\n");
		return NULL;
	}

	No* listaNos = NULL;
	int id;
	float latitude, longitude;
	while (fscanf(arquivo, "%d %f %f\n", &id, &latitude, &longitude) == 3) {
		No* novoNo = (No*)malloc(sizeof(No));
		novoNo->id = id;
		novoNo->latitude = latitude;
		novoNo->longitude = longitude;
		novoNo->proximo = NULL;
		novoNo->ligacoes = NULL;

		if (listaNos == NULL) {
			listaNos = novoNo;
		}
		else {
			No* ultimo = listaNos;
			while (ultimo->proximo != NULL) {
				ultimo = ultimo->proximo;
			}
			ultimo->proximo = novoNo;
		}
	}

	fclose(arquivo);
	return listaNos;
}

void guardarDadosBinarios(No* listaNos, const char* nomeFicheiro) {
	FILE* arquivo = fopen(nomeFicheiro, "wb");
	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo binário.\n");
		return;
	}

	No* noAtual = listaNos;
	while (noAtual != NULL) {
		fwrite(noAtual, sizeof(No), 1, arquivo);
		noAtual = noAtual->proximo;
	}

	fclose(arquivo);
}

void listarMeiosNoRaio(No* inicio, User* user , char tipo, float raio) {
	Ligacao* ligacaoAtual = inicio->ligacoes;
	while (ligacaoAtual != NULL) {
		No* meio = ligacaoAtual->destino;
		if (strcmp(meio->tipo, tipo) == 0) {
			float distancia = calcularDistancia(user, meio);
			if (distancia <= raio) {
				printf("Meio de mobilidade elétrica: Código %d, Tipo %s, Distância %.2f\n", meio->codigo, meio->tipo, distancia);
			}
		}
		ligacaoAtual = ligacaoAtual->proxima;
	}
}

float calcularDistancia(No* no1, No* no2) {
	// Implemente o cálculo da distância entre dois nós aqui
	// Retorna a distância calculada como um valor de ponto flutuante
	return 0.0;
}

void calcularTrajetoRecarga(No* pontoPartida, float capacidadeCaminhao) {
	// Implemente o algoritmo para calcular o trajeto com a menor distância
	// percorrer para recolher os meios de mobilidade elétrica com carga abaixo de 50%.
}
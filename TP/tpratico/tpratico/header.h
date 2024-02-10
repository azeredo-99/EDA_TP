#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registo
{
    int codigo; // código do meio de mobilidade elétrica
    char tipo[50];
    float bateria;
    float autonomia;
    char morada[50];
    struct registo* seguinte; // endereço de memória para uma struct registo
}Meio;


typedef struct utilizador {
    int id;
    int NIF;
    float saldo;
    char nome[50];
    char morada[50];
    struct utilizador* seguinte;
}User;

typedef struct gestor {
    int idGestor;
    char nomeGestor[50];
    char moradaGestor[50];
    struct gestor* seguinte;
}Gestor;

typedef struct ligacao Ligacao;
typedef struct no No;

struct ligacao {
    No* destino;
    float distancia;
    Ligacao* proxima;
};

struct no {
    int id;
    int codigo;
    char tipo[50];
    float latitude;
    float longitude;
    float raio;
    No* proximo;
    Ligacao* ligacoes;
};

// Inserção de um novo registo
Meio* adicionarMeio(Meio* inicio, int cod, char tipo[], float bat, float aut);

// listar na consola o conteúdo da lista ligada
void listarMeios(Meio* inicio);

// Determinar existência do 'codigo' na lista ligada 'inicio'
int existeMeio(Meio* inicio, int codigo);

// Remover um meio a partir do seu código
Meio* removerMeio(Meio* inicio, int cod);

Meio* guardarMeios(Meio* inicio);

Meio* lerMeios();


User* adicionarUser(User* inicio, int id, int nif, float saldo, char nome[], char morada[]);

void listarUser(User* inicio);

User* removerUser(User* inicio, int id);

User* guardarUser(User* inicio);

User* lerUser();

User* editarUser(User* inicio, int id, char atributo[], char novoValor[]);


Gestor* adicionarGestor(Gestor* inicio, int idGestor, char nomeGestor[], char moradaGestor[]);

Gestor* listarGestor(Gestor* inicio);

Gestor* removerGestor(Gestor* inicio, int idGestor);

Gestor* guardarGestor(Gestor* inicio);

Gestor* lerGestor();

void listarMeiosNoRaio(No* inicio, User* user, char tipo, float raio);
float calcularDistancia(No* no1, No* no2);



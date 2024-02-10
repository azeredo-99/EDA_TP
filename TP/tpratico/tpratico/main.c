#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int menu()
{
    int op;
    printf("M E N U\n");
    printf("1 Entrar como User\n");
    printf("2 Entrar como Gestor\n");
    printf("3 Ler meios\n");
    printf("4 Listar meios\n");
    printf("0 Sair\n");
    printf("Opcao:\n");
    scanf_s("%d", &op);
    return(op);
}

int menuUsers() {
    int opU;
    printf("M E N U\n");
    printf("1 Adicionar Utilizador\n");
    printf("2 Alugar um meio\n");
    printf("0 Sair\n");
    printf("Opcao:\n");
    scanf("%d", &opU);
    return(opU);
}

int menuGestor() {
    int opG;
    printf("M E N U\n");
    printf("1. Adicionar User\n");
    printf("2. Adicionar Meio\n");
    printf("3. Adicionar Gestor\n");
    printf("4. Remover User\n");
    printf("5. Remover Meio\n");
    printf("6. Remover Gestor\n");
    printf("7. Guardar Meios\n");
    printf("8. Guardar Gestor\n");
    printf("9. Ler Meios\n");
    printf("10. Listar Meios\n");
    printf("11. Listar Users\n");
    printf("12. Listar Gestores\n");
    printf("13. Editar User\n");
    printf("14. Listar Meios no Raio\n");
    printf("15. Guardar Dados de Texto\n");
    printf("Opcao:\n");
    scanf("%d", &opG);
    return opG;
}

int main() {
    Meio* meios = NULL; // Lista ligada vazia
    int op, opU, opG, cod;
    float bat, aut;
    char tipo[50];

    Meio* listaMeios = NULL;
    User* listaUsers = NULL;

    User* users = NULL;
    int id, nif;
    float saldo;
    char nome[50], morada[50];

    Gestor* gestor = NULL;
    int idGestor;
    char nomeGestor[50], moradaGestor[50];
/*
    No* no = NULL;
    No* cliente = NULL;
    float raio;
    */
    No* inicio = NULL;
    float raio;

    meios = lerMeios();; // Lê a lista de meios de um ficheiro
    users = lerUser(); // Lê a lista de utilizadores de um ficheiro

    do {
        op = menu();
        switch (op) {
        case 1:
            do {
                opU = menuUsers();
                switch (opU) {
                case 1:
                    printf("Id?\n");
                    scanf("%d", &id);
                    printf("Nome\n");
                    scanf(" %[^\n]s", nome);
                    printf("Morada\n");
                    scanf(" %[^\n]s", morada);
                    printf("NIF?\n");
                    scanf("%d", &nif);
                    printf("Saldo?\n");
                    scanf("%f", &saldo);
                    users = adicionarUser(users, id, nif, saldo, nome, morada);
                    break;
                case 2:
                    listarMeios(meios);
                    printf("Qual o meio que quer alugar\n");
                    scanf("%d", &cod);
                    meios = removerMeio(meios, cod);
                    break;
                }
            } while (opU != 0);
            break;
        case 2:
            do {
                opG = menuGestor();
                switch (opG) {
                case 1:
                    printf("Id?\n");
                    scanf("%d", &id);
                    printf("Nome\n");
                    scanf(" %[^\n]s", nome);
                    printf("Morada\n");
                    scanf(" %[^\n]s", morada);
                    printf("NIF?\n");
                    scanf("%d", &nif);
                    printf("Saldo?\n");
                    scanf("%f", &saldo);
                    users = adicionarUser(users, id, nif, saldo, nome, morada);
                    break;
                case 2:
                    printf("Codigo?\n");
                    scanf("%d", &cod);
                    scanf("%*c");
                    printf("Tipo\n");
                    scanf("%[^\n]", tipo);
                    printf("Nivel da bateria?\n");
                    scanf("%f", &bat);
                    printf("Autonomia\n");
                    scanf("%f", &aut);
                    meios = adicionarMeio(meios, cod, tipo, bat, aut);
                    break;
                case 3:
                    printf("Id?\n");
                    scanf("%d", &idGestor);
                    printf("Nome\n");
                    scanf(" %[^\n]s", &nomeGestor);
                    printf("Morada\n");
                    scanf(" %[^\n]s", &moradaGestor);
                    gestor = adicionarGestor(gestor, idGestor, nomeGestor, moradaGestor);
                    break;
                case 4:
                    printf("Id do utilizador que quer remover\n");
                    scanf("%d", &id);
                    users = removerUser(users, id);
                    break;
                case 5:
                    printf("Codigo do meio de mobilidade a remover?\n");
                    scanf("%d", &cod);
                    meios = removerMeio(meios, cod);
                    break;
                case 6:
                    printf("Id do gestor que quer remover\n");
                    scanf("%d", &idGestor);
                    gestor = removerGestor(gestor, idGestor);
                    break;
                case 7:
                    guardarMeios(meios);
                    break;
                case 8:
                    guardarGestor(gestor);
                    break;
                case 9:
                    meios = lerMeios();
                    break;
                case 10:
                    listarMeios(meios);
                    break;
                case 11:
                    listarUser(users);
                    break;
                case 12:
                    listarGestor(gestor, idGestor, nomeGestor, moradaGestor);
                    break;
                case 13:
                    printf("Qual o id do usuario que deseja editar?\n");
                    scanf("%d", &id);
                    printf("Qual atributo deseja editar?\n");
                    char atributo[50], novoValor[50];
                    scanf("%s", atributo);
                    printf("Digite o novo valor para o atributo:\n");
                    scanf("%s", novoValor);
                    users = editarUser(users, id, atributo, novoValor);
                    break;
                case 14:
                   
                    printf("Tipo de meio de mobilidade elétrica: ");
                    scanf("%s", tipo);
                    printf("Raio de busca: ");
                    scanf("%f", &raio);
                    listarMeiosNoRaio(inicio, users, tipo, raio); 
                    break;
                    break;
                case 15:
                    // Implemente a funcionalidade de guardar dados de texto
                    break;
                }
            } while (opG != 0);
        case 3:meios = lerMeios(); break;
        case 4:listarMeios(meios); break;
        }
    } while (op != 0);
}


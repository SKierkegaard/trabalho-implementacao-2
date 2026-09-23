#include "gcofo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int numSongs;
    float numPlays;
} Album;

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int queryAlbumName(void *a, void *b) {
    Album *nameA = (Album *) a;
    Album *nameB = (Album *) b;

    // strcmp() retorna 0 se as strings forem iguais
    if (!strcmp(nameA->name, nameB->name)) {
        return TRUE;
    }

    return FALSE;
}

int queryAlbumNumSongs(void *a, void *b) {
    Album *numSongsA = (Album *) a;
    Album *numSongsB = (Album *) b;

    if (numSongsA->numSongs == numSongsB->numSongs) {
        return TRUE;
    }

    return FALSE;
}

int queryAlbumNumPlays(void *a, void *b) {
    Album *numPlaysA = (Album *) a;
    Album *numPlaysB = (Album *) b;

    if (numPlaysA->numPlays == numPlaysB->numPlays) {
        return TRUE;
    }

    return FALSE;
}

Album *albumCreate() {
    Album *album = malloc(sizeof(Album));
    if (album != NULL) {
        printf("Digite o nome do álbum: ");
        fgets(album->name, 30, stdin);

        printf("Digite a quantidade de músicas do álbum: ");
        scanf("%d", &album->numSongs);
        cleanBuffer();

        printf("Digite a quantidade de visualizações(em milhões) do álbum: ");
        scanf("%f", &album->numPlays);
        cleanBuffer();

        return album;
    }

    return NULL;
}

int albumRemove(GCofo *gCofo) {
    int option;
    int running = TRUE;
    Album key;
    void *removed;

    while (running) {
        key = (Album){0};
        printf("#--------- Remover Álbum ---------#\n");
        printf("| 1 - Por nome                    |\n");
        printf("| 2 - Por número de músicas       |\n");
        printf("| 3 - Por número de visualizações |\n");
        printf("#---------------------------------#\n");
        printf("> ");

        if (scanf("%d", &option) != 1) {
            printf("Entrada inválida.\n");
            cleanBuffer();
            continue;
        }
        cleanBuffer();


        printf("\n");
        switch(option) {
            case 1:
                printf("Digite o nome do álbum: ");
                fgets(key.name, 30, stdin);
                removed = gCofoRemove(gCofo, (void *) &key, queryAlbumName);

                break;

            case 2:
                printf("Digite o número de músicas: ");
                scanf("%d", &key.numSongs);
                cleanBuffer();
                removed = gCofoRemove(gCofo, &key, queryAlbumNumSongs);
 
                break;

            case 3:
                printf("Digite o número de visualizações: ");
                scanf("%f", &key.numPlays);
                cleanBuffer();
                removed = gCofoRemove(gCofo, &key, queryAlbumNumPlays);

                break;

            default:
                printf("Opcão inválida.\n");
                continue;
        }

        if (removed != NULL) {
            free(removed);
            return TRUE;
        }

        running = FALSE;
    }

    return FALSE;
}

int albumQuery(GCofo *gCofo) {
    int option;
    int running = TRUE;
    Album key;
    void *find;

    while (running) {
        key = (Album){0};
        printf("#-------- Consultar Álbum --------#\n");
        printf("| 1 - Por nome                    |\n");
        printf("| 2 - Por número de músicas       |\n");
        printf("| 3 - Por número de visualizações |\n");
        printf("#---------------------------------#\n");
        printf("> ");

        if (scanf("%d", &option) != 1) {
            printf("Entrada inválida.\n");
            cleanBuffer();
            continue;
        }
        cleanBuffer();


        printf("\n");
        switch(option) {
            case 1:
                printf("Digite o nome do álbum: ");
                fgets(key.name, 30, stdin);
                find = gCofoQuery(gCofo, (void *) &key, queryAlbumName);

                break;

            case 2:
                printf("Digite o número de músicas: ");
                scanf("%d", &key.numSongs);
                cleanBuffer();
                find = gCofoQuery(gCofo, &key, queryAlbumNumSongs);
 
                break;

            case 3:
                printf("Digite o número de visualizações: ");
                scanf("%f", &key.numPlays);
                cleanBuffer();
                find = gCofoQuery(gCofo, &key, queryAlbumNumPlays);

                break;

            default:
                printf("Opcão inválida.\n");
                continue;
        }

        if (find != NULL) {
            return TRUE;
        }

        running = FALSE;
    }

    return FALSE;
}

int main() {
    int maxItems;
    printf("Digite a capacidade do gCofo: ");
    scanf("%d", &maxItems);
    cleanBuffer();

    GCofo *gCofo = gCofoCreate(maxItems);
    if (gCofo == NULL) {
        printf("Não foi possível criar o gCofo!\n");

        return 1;
    }

    int option;
    int running = TRUE;

    while(running) {
        printf("\n#----- Lista de Álbums -----#\n");
        printf("| 1 - Inserir álbum         |\n");
        printf("| 2 - Remover álbum         |\n");
        printf("| 3 - Consultar álbum       |\n");
        printf("| 4 - Mostar primeiro álbum |\n");
        printf("| 5 - Mostrar próximo álbum |\n");
        printf("| 6 - Esvaziar lista        |\n");
        printf("| 7 - Destruir lista(sair)  |\n");
        printf("#---------------------------#\n");
        printf("> ");

        if (scanf("%d", &option) != 1) {
            printf("Entrada inválida.\n");
            cleanBuffer();
            continue;
        }
        cleanBuffer();
        printf("\n");

        switch (option) {
            case 1:
                Album *album = albumCreate();
                if (album != NULL) {
                    if(gCofoInsert(gCofo, (void *) album)) {
                        printf("Álbum adicionado com sucesso!\n");
                    } else {
                        printf("Não foi possível adicionar o álbum à lista!\n");
                        free(album);
                    }
                } else {
                    printf("Não foi possível adicionar o álbum, a lista está cheia!\n");
                }
                break;

            case 2:
                if (albumRemove(gCofo)) {
                    printf("Álbum removido com sucesso!\n");
                } else {
                    printf("Álbum não encontrado!\n");
                }
                break;

            case 3:
                if (albumQuery(gCofo)) {
                    printf("Álbum encontrado!\n");
                } else {
                    printf("Álbum não encontrado\n");
                }

                break;

            case 4:
                Album *first = (Album *) gCofoGetFirst(gCofo);
                if (first != NULL) {
                    printf("Nome: %sNúmero de músicas: %d\nNúmero de visualizações: %.1f\n", first->name, first->numSongs, first->numPlays);
                } else {
                    printf("Não há álbuns na lista!\n");
                }
                break;

            case 5:
                Album *next = (Album *) gCofoGetNext(gCofo);
                if (next != NULL) {
                    printf("Nome: %sNúmero de músicas: %d\nNúmero de visualizações: %.1f\n", next->name, next->numPlays, next->numSongs);
                } else {
                    printf("Não foi possível encontrar o próximo!\n");
                }

                break;

            case 6:
                if (gCofoClear(gCofo)) {
                    printf("Lista de álbums esvaziada!\n");
                } else {
                    printf("A lista já está vazia!\n");
                }

                break;

            case 7:
                if (gCofoDestroy(gCofo)) {
                    printf("Lista destuída com sucesso!\nAdeus...\n");
                    gCofo == NULL;
                    running = FALSE;
                } else {
                    printf("Não foi possível destruir a lista, a lista não está vazia!\n");
                }
 
                break;

            default:
                printf("Opcão inválida!");
                continue;
        }
    }

    return 0;
}

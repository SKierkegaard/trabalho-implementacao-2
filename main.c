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
        scanf("%s", &album->numSongs);
        cleanBuffer();

        printf("Digite a quantidade de visualizações(em milhões) do álbum: ");
        scanf("%f", &album->numPlays);
        cleanBuffer();

        return album;
    }

    return NULL;
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
                    if(gCofoInsert(gCofo, album)) {
                        printf("Álbum adicionado com sucesso!\n");
                    } else {
                        printf("Não foi possível adicionar o álbum à lista!\n");
                    }
                } else {
                    printf("Não foi possível adicionar o álbum à lista!\n");
                    free(album);
                }
                break;

            case 7:
                if (gCofoDestroy(gCofo)) {
                    printf("Lista destuída com sucesso!\nAdeus...\n");
                    gCofo == NULL;
                    running = FALSE;
                } else {
                    printf("Não foi possível destruir a lista!\n");
                }
        }
    }

    return 0;
}

#include "gcofo.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[30];
    int numSongs;
    float numPlays;
} Album;

int queryAlbumName(void *a, void *b) {
    Album *nameA = (Album *) a;
    Album *nameB = (Album *) b;

    // strcmp() retorna 0 se as strings forem iguais
    if (!strcmp(nameA->name, nameB->name)) {
        return TRUE;
    }

    return FALSE;
}

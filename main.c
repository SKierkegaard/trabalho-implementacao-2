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

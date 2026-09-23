#include "gcofo.h"
#include <stdlib.h>

struct GCofo {
    void **list;
    int numItems;
    int maxItems;
    int current;
};

GCofo *gCofoCreate(int maxItems) {
    if (maxItems > 0) {
        GCofo *gc = (GCofo *) malloc(sizeof(GCofo));
        if (gc != NULL) {
            gc->list = (void **) malloc(sizeof(void *) * maxItems);
            if (gc->list != NULL) {
                gc->numItems = 0;
                gc->maxItems = maxItems;
                gc->current = 0;

                return gc;
            }

            free(gc);
        }
    }

    return NULL;
}

int gCofoInsert(GCofo *gCofo, void *item) {
    if (gCofo != NULL) {
        if (gCofo->numItems < gCofo->maxItems) {
            gCofo->list[gCofo->numItems] = item;
            gCofo->numItems++;

            return TRUE;
        }
    }

    return FALSE;
}

void *gCofoRemove(GCofo *gCofo, void *key, int (*cmp)(void *, void *)) {
    if (gCofo != NULL) {
        if (gCofo->numItems > 0) {
            for (int i = 0; i < gCofo->numItems; i++) {
                if (cmp(key, gCofo->list[i])) {
                    void *removed = gCofo->list[i];
                    for (int j = i; j < gCofo->numItems -1; j++) {
                        gCofo->list[j] = gCofo->list[j + 1];
                    }

                    gCofo->numItems--;

                    return removed;
                }
            }
        }
    }

    return NULL;
}

void *gCofoQuery(GCofo *gCofo, void *key, int (*cmp)(void *, void *)) {
    if (gCofo != NULL) {
        if (gCofo->numItems > 0) {
            for (int i = 0; i < gCofo->numItems; i++) {
                if (cmp(key, gCofo->list[i])) {
                    return gCofo->list[i];
                }
            }
        }
    }

    return NULL;
}

void *gCofoGetNext(GCofo *gCofo) {
    if (gCofo != NULL) {
        if (gCofo->numItems > 0 && gCofo->current < gCofo->numItems - 1) {
            gCofo->current++;

            return gCofo->list[gCofo->current];
        }
    }

    return NULL;
}

void *gCofoGetFirst(GCofo *gCofo) {
    if (gCofo != NULL) {
        if (gCofo->numItems > 0) {
            gCofo->current = 0;

            return gCofo->list[gCofo->current];
        }
    }

    return NULL;
}

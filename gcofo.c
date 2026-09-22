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
                gc->current = -1;

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

int gCofoRemove(GCofo *gCofo, void *key, int (*cmp)(void *, void *)) {
    if (gCofo != NULL) {
        if (gCofo->numItems > 0) {
            int i = 0;
            int isEqual = cmp(key, gCofo->list[i]);

            while (i < gCofo->numItems && !isEqual) {
                i++;
                isEqual = cmp(key, gCofo->list[i]);
            }

            if (isEqual) {
                for (int j = i; j < gCofo->numItems - 1; j++) {
                    gCofo->list[j] = gCofo->list[j + 1];
                }

                gCofo->numItems--;

                return TRUE;
            }
        }
    }

    return FALSE;
}

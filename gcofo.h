#ifndef GCOFO_H
#define GCOFO_H
#define TRUE 1
#define FALSE 0

typedef struct GCofo GCofo;

GCofo *gCofoCreate(int maxItens);
int gCofoInsert(GCofo *gCofo, void *item);
int gCofoRemove(GCofo *gCofo, void *key, int (*cmp)(void *, void *));
int gCofoQuery(GCofo *gCofo, void *key, int (*cmp)(void *, void *));


#endif

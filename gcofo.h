#ifndef GCOFO_H
#define GCOFO_H
#define TRUE 1
#define FALSE 0

typedef struct GCofo GCofo;

GCofo *gCofoCreate(int maxItens);
int gCofoInsert(GCofo *gCofo, void *item);
void *gCofoRemove(GCofo *gCofo, void *key, int (*cmp)(void *, void *));
void *gCofoQuery(GCofo *gCofo, void *key, int (*cmp)(void *, void *));
void *gCofoGetNext(GCofo *gCofo);
void *gCofoGetFirst(GCofo *gCofo);

#endif

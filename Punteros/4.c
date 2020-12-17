int *ip, **ipp, (*ip16)[16], i, j;
int matriz[5][16];

ip16 = matriz;

ip = (int *)matriz;

ipp = (int **) matriz;

*(*(ip16 + i) + j)

*(*(matriz + i ) + j)
#include "raycaster.h"

void ft_error(t_game *g, char *msg)
{
    printf("%s", msg);
    free (g->buffer);
    exit(1);
}
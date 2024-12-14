
#include "so_long.h"

void map_check(char *argv, t_map *game)
{
    int fd;
    int len;
    
    fd = open(argv, O_RDWR);
    if(fd <= 0)
    {
        close(fd);
        ft_error("Error: File can not open.", game);
    }
    close(fd);
    len = ft_strlen(argv);
    if(argv[len - 1] == 'r' && argv[len - 2] == 'e' 
        && argv[len - 3] == 'b' && argv[len - 4] == '.')
        return ;
    else
    {
        ft_error("Error: The map is not '.ber' extension.", game);
    }
}

void map_check_2(char *argv, t_map *game)
{
    char *line;
    int fd;

    fd = open(argv, O_RDONLY);
    game->row = 0;
    
}
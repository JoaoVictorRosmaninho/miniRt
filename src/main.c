#include "../includes/minit_rt.h"

e_errors cmd_line_parse(t_context *ctx, int argc, char *argv[])
{
    if (argc != 3)
        return CMD_ERROR;


    ctx->height = ft_atoi(argv[1]);
    ctx->width  = ft_atoi(argv[2]);
    ctx->file   = open("image.ppm", O_WRONLY | O_CREAT);
    memory = ft_lstnew();

    return NO_ERROR;
}


int main(int argc, char *argv[])
{
    t_context context;
    
    if (cmd_line_parse(&context, argc, argv) != NO_ERROR) {
        
    } else {
        ft_lstclear(memory, vector_free);
        close(context.file);
    }

    return 0;
}
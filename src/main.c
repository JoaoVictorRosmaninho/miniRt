#include "../includes/minit_rt.h"

e_errors cmd_line_parse(t_context *ctx, int argc, char *argv[])
{
    if (argc != 3)
        return CMD_ERROR;


    ctx->height = ft_atoi(argv[1]);
    ctx->width  = ft_atoi(argv[2]);
    ctx->file   = open("image.ppm", O_WRONLY | O_CREAT);

    return NO_ERROR;
}


int main(int argc, char *argv[])
{
    t_context context;
    
    if (cmd_line_parse(&context, argc, argv) == NO_ERROR) {
        ft_fprintf(context.file, "P3\n%d %d\n255\n", context.width, context.height);
        for (int i = 0; i < context.height; i++) {
            for (int j = 0; j < context.width; j++) {
                t_vector *v = vector_new((float) i / (context.width -  1), (float) j / (context.height - 1), 0);
                vector_write_color(v, context.file);
            }
        }
        close(context.file);
        memory_flush();
    } else {
        ft_fprintf(2, "command_line error");
        return 1;
    }
    return (0);
}
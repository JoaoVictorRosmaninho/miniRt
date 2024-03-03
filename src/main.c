#include "../includes/minit_rt.h"

extern t_memory g_memory;

static e_errors parse_and_init(t_context *ctx, int argc, char *argv[])
{
    if (argc < 2 || argc > 3 )
        return CMD_ERROR;
    ctx->height = ft_atoi(argv[1]);
    ctx->width  = ft_atoi(argv[2]);
    ctx->file   = open("image.ppm", O_WRONLY | O_CREAT, 0666);
    ctx->ratio  = 16.0 / 9.0;
    ctx->projected_height = (int) (ctx->width / ctx->ratio);
    ctx->projected_height =  (ctx->projected_height < 0) ? 1 : ctx->projected_height;
    ctx->focal_center   = 1.0;
    // memory
    g_memory.memory[SHORT].door   = NULL;
    g_memory.memory[SHORT].region = NULL;
    g_memory.memory[SHORT].size   = ARENA_512B;

    g_memory.memory[LONG].door   = NULL;
    g_memory.memory[LONG].region = NULL;
    g_memory.memory[LONG].size   = ARENA_8M;

    g_memory.coliseu          = LONG;
    return NO_ERROR;
}


int main(int argc, char *argv[])
{
    t_context context;
    
    if (parse_and_init(&context, argc, argv) == NO_ERROR) {
        
        memory_destroy();
        close(context.file);
    } else {
        ft_fprintf(2, "command_line error");
        return 1;
    }
    return (0);
}
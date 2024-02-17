#include "../includes/minit_rt.h"

extern t_memory* memory;

static e_errors cmd_line_parse(t_context *ctx, int argc, char *argv[])
{
    if (argc < 2 || argc > 3 )
        return CMD_ERROR;
    ctx->height = ft_atoi(argv[1]);
    ctx->width  = ft_atoi(argv[2]);
    ctx->file   = open("image.ppm", O_WRONLY | O_CREAT);
    ctx->ratio  = 16.0 / 9.0;
    ctx->projected_height = (int) (ctx->width / ctx->ratio);
    ctx->projected_height =  (ctx->projected_height < 0) ? 1 : ctx->projected_height;
    ctx->viewport_width = VIEWPORT * ctx->width / ctx->projected_height;
    ctx->focal_center   = 1.0;
    return NO_ERROR;
}


int main(int argc, char *argv[])
{
    t_context context;
    
    if (cmd_line_parse(&context, argc, argv) == NO_ERROR) {
        t_vector* viewport_u = vector_new(context.viewport_width, 0, 0);

        t_vector* viewport_v = vector_new(0, -VIEWPORT, 0);

        t_vector* pixel_delta_u = vdivf(viewport_u, context.width);
        t_vector* pixel_delta_v = vdivf(viewport_u, context.height);

        t_position* camera_position = vector_new(0,0,0);

        t_position* viewport_upper_left = vsub(camera_position, vector_new(0, 0, context.focal_center));
        viewport_upper_left = vsub(viewport_upper_left, vdivf(viewport_u, 2));
        viewport_upper_left = vsub(viewport_upper_left, vdivf(viewport_v, 2));

        t_position* pixel   = vsub(camera_position, vmultf(vsum(pixel_delta_u, pixel_delta_v), 0.5));

        ft_fprintf(context.file, "P3\n%d %d\n255\n", context.width, context.projected_height);

        memory->write_in_short();
        for (int i = 0; i < context.projected_height; ++i) {
            for (int j = 0; j < context.width; ++j) {
                t_vector* v =  vsum(pixel_delta_v, vsum(pixel, vmultf(pixel_delta_u, i)));

                t_vector* ray_direction = vsub(v, camera_position);

                t_ray*    ray = ray_new(camera_position, ray_direction);                
                
                t_vector* result = ray_color(ray);
                vector_write_color(result, context.file);
            }
            memory->memory_flush(SHORT);
        }
        memory->write_in_long();
        memory->memory_flush(ALL);
        close(context.file);
    } else {
        ft_fprintf(2, "command_line error");
        return 1;
    }
    return (0);
}
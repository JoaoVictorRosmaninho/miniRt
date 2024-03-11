#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "canvas.h"
#include "vectors.h"

struct Canvas_s
{
    size_t width;
    size_t height;
    Vec3 pixelCanvas[];
};

Canvas *canvasCreate(const size_t width, const size_t height)
{
    Canvas *canvas = malloc(sizeof(Canvas) + sizeof(Vec3[width * height]));
    if (canvas == NULL)
    {
        return canvas;
    }
    *canvas = (Canvas){width, height};
    for (size_t i = 0; i < width; i++)
    {
        for (size_t j = 0; j < height; j++)
        {
            canvas->pixelCanvas[i + j * canvas->width] = (Vec3){{0, 0, 0}}; // TODO: Use memset
        }
    }
    return canvas;
}

Canvas *canvasCopy(const Canvas *canvas)
{
    Canvas *copyCanvas = malloc(sizeof(Canvas) + sizeof(Vec3[canvas->width * canvas->height]));
    if (copyCanvas == NULL)
    {
        return copyCanvas;
    }
    memcpy(copyCanvas, canvas, sizeof(Canvas) + sizeof(Vec3[canvas->width * canvas->height]));
    return copyCanvas;
}

Vec3 canvasPixel(const Canvas *canvas, const size_t x, const size_t y)
{
    return canvas->pixelCanvas[x + y * canvas->width];
}

void canvasPixelWrite(Canvas *canvas, const size_t x, const size_t y, const Vec3 pixel)
{
    canvas->pixelCanvas[x + y * canvas->width] = pixel;
}

size_t canvasWidth(const Canvas *canvas)
{
    return canvas->width;
}

size_t canvasHeight(const Canvas *canvas)
{
    return canvas->height;
}

char *canvasPPM(const Canvas *canvas)
{
    Canvas *PPMCanvas = canvasCopy(canvas);
    for (size_t i = 0; i < canvasWidth(PPMCanvas) * canvasHeight(PPMCanvas); i++)
    {
        PPMCanvas->pixelCanvas[i] = vec3PPM(PPMCanvas->pixelCanvas[i]);
    }
    size_t bufferSize = sizeof(char) * snprintf(NULL, 0, "P3\n%lu %lu\n255\n", canvasWidth(PPMCanvas), canvasHeight(PPMCanvas));
    bufferSize += sizeof(char) * 4 * 3 * canvasWidth(PPMCanvas) * canvasHeight(PPMCanvas);
    char *buffer = malloc(bufferSize);
    if (buffer == NULL)
    {
        abort();
    }
    char *bufferPtr = buffer + sprintf(buffer, "P3\n%lu %lu\n255\n", canvasWidth(PPMCanvas), canvasHeight(PPMCanvas));
    for (size_t j = 0; j < canvasHeight(PPMCanvas); j++)
    {
        for (size_t i = 0; i < canvasWidth(PPMCanvas); i++)
        {
            if (i == (canvasWidth(PPMCanvas) - 1))
            {
                bufferPtr += 1 + sprintf(bufferPtr, "%3.0f %3.0f %3.0f", PPMCanvas->pixelCanvas[i + j * PPMCanvas->width].x,
                                         PPMCanvas->pixelCanvas[i + j * PPMCanvas->width].y,
                                         PPMCanvas->pixelCanvas[i + j * PPMCanvas->width].z);
                *(bufferPtr - 1) = '\n';
            }
            else
            {
                bufferPtr += sprintf(bufferPtr, "%3.0f %3.0f %3.0f ", PPMCanvas->pixelCanvas[i + j * PPMCanvas->width].x,
                                     PPMCanvas->pixelCanvas[i + j * PPMCanvas->width].y,
                                     PPMCanvas->pixelCanvas[i + j * PPMCanvas->width].z);
            }
        }
    }
    *(bufferPtr - 1) = '\0';
    free(PPMCanvas);
    PPMCanvas = NULL;
    return buffer;
}

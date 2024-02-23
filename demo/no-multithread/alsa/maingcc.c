#define TDAW_BACKEND_ALSA
#define TDAW_IMPLEMENTATION
#include "../../../include/TDAW.h"
#include <math.h>


TDAW_CHANNEL test(float time, float samp)
{
        TDAW_CHANNEL out;
        out.left = out.right = sin(6.2831*440.0*time)*exp(-3.0*time) * 0.5; // sine pluck
        return out;
}

void _start()
{
        asm volatile("push %rax\n");
        TDAW_PIP tdaw;
        TDAW_initTDAW(&tdaw, 1024);
        while(1) {
                TDAW_render(&tdaw, &test);
        }
        TDAW_terminate(&tdaw);
        //termination commands are not needed in this case as the program will never reach
}
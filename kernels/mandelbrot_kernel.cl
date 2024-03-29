__kernel void mandelbrot(__global char *image_data, __global t_transform *transform)
{
    int y = get_global_id(0) / WIDTH;
    int x = get_global_id(0) % WIDTH;

    double newRe, newIm, oldRe, oldIm;
    double pr, pi;

    pr = 1 * (x - WIDTH / 2) / (0.5 * 1 * WIDTH * transform->zoom) + -0.5 + transform->delta_x;
    pi = (y - WIDTH / 2) / (0.5 * 1 * WIDTH * transform->zoom) + 0 + transform->delta_y;
    newRe = newIm = oldRe = oldIm = 0;
    int i = 0;
    while (i++ < transform->max_iterations)
    {
        oldRe = newRe;
        oldIm = newIm;
        newRe = oldRe * oldRe - oldIm * oldIm + pr;
        newIm = 2 * oldRe * oldIm + pi;
        if ((newRe * newRe + newIm * newIm) > 4)
            break;
    }
    HsvColor hsv;
    hsv.h = i % 256 + transform->color;
    hsv.s = 255;
    hsv.v = 255 * (i < transform->max_iterations);
    kernel_put_point_to_image(image_data, x, y, rgb_to_int(HsvToRgb(hsv)));
}

#include <libipd.h>

struct circle
{
    double x, y, radius;
};

// Scales the radius of circle `*p` by factor `f`.
void scale_circle(struct circle* p, double f)
{
    double old_radius = p->radius;
    double new_radius = f * old_radius;

    if (p != NULL && old_radius != new_radius) {
        p->radius = new_radius;
    }
}

int main(void)
{
    struct circle my_circle = {
            .x      = 10,
            .y      = 20,
            .radius = 7,
    };

    scale_circle(&my_circle, 2);
    scale_circle(NULL,       3);
    scale_circle(&my_circle, 4);

    CHECK_DOUBLE( my_circle.radius, 56 );
}
#include <stdio.h>
#include <math.h>

enum coordinate_type {RECTANGULAR, POLAR};
struct complex_struct {
    enum coordinate_type t;
    double a,b;
};

double real_part(struct complex_struct x){
    switch (x.t) {
        case 0:
            return x.a; 
            break;
        case 1:
            return x.a * cos(x.b);
            break;
    }
}

double img_part(struct complex_struct x){
    switch (x.t) {
        case 0:
            return x.b; 
            break;
        case 1:
            return x.a * sin(x.b);
            break;
    }
}

double magnitude(struct complex_struct x){
    switch (x.t) {
        case 0:
            return sqrt(x.a * x.a + x.b * x.b); 
            break;
        case 1:
            return x.a; 
            break;
    }
}

double angle(struct complex_struct x){
    switch (x.t) {
        case 0:
            return atan2(x.b, x.a); 
            break;
        case 1:
            return x.b; 
            break;
    }

}

struct complex_struct make_real_img(double x, double y)
{
    struct complex_struct z;
    z.t = 0;
    z.a = x;
    z.b = y;
    return z;
}

struct complex_struct make_mag_ang(double x, double y)
{
    struct complex_struct z;
    z.t = 1;
    z.a = x;
    z.b = y;
    return z;
    
}

struct complex_struct add_complex(struct complex_struct x, struct complex_struct y)
{
    return make_real_img(real_part(x) + real_part(y), img_part(x) + img_part(y));    
}

struct complex_struct sub_complex(struct complex_struct x, struct complex_struct y)
{
    return make_real_img(real_part(x) - real_part(y), img_part(x) - img_part(y));        
}

struct complex_struct mul_complex(struct complex_struct x, struct complex_struct y)
{
    return make_mag_ang(magnitude(x) * magnitude(y), angle(x) + angle(y));    
}

struct complex_struct div_complex(struct complex_struct x, struct complex_struct y)
{
    return make_mag_ang(magnitude(x) / magnitude(y), angle(x) - angle(y));        
}

int printf_complex_real_img(struct complex_struct x)
{
    if(x.a == 0) printf("%+fi\n", img_part(x));
    else if (x.b == 0) printf("%+f\n", real_part(x));
    else printf("%+f%+fi\n", real_part(x), img_part(x));

    return 0;
}

int main(void){
    struct complex_struct cp_01 = {0, 1, 2};
    struct complex_struct cp_02 = {1, 1, 2};
    struct complex_struct cp_03 = {0, 2, 5};

    printf_complex_real_img(cp_01);
    printf_complex_real_img(cp_03);
    printf("cp_01 + cp_03 = ");
    printf_complex_real_img(add_complex(cp_01, cp_03));
    printf("cp_01 - cp_03 = ");
    printf_complex_real_img(sub_complex(cp_01, cp_03));
    
    return 0;
}

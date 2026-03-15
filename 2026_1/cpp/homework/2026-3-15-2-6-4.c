#include <stdio.h>
#include <math.h>
float get_area(const float a, const float b, const float c) {
    const float s = (a + b + c) / 2;
    const float area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

int main() {
    float a, b, c, s, area;
    printf("Please input 3 sides of one triangle:\n");
    scanf(" %f, %f, %f", &a, &b, &c);
    area = get_area(a, b , c);
    printf("a = %7.2f, b = %7.2f, c = %7.2f\n", a, b, c);
    printf("area of triangle is %10.5f\n", area);
    return 0;
}
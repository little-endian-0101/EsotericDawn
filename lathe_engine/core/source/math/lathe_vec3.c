#include "math/lathe_vec3.h"
#include <math.h>

lathe_vec3 vec3_scalar_mult(const lathe_vec3 *v, float scalar) {
  return (lathe_vec3){v->x * scalar, v->y * scalar, v->z * scalar};
}

lathe_vec3 vec3_scalar_div(const lathe_vec3 *v, float scalar) {
  lathe_vec3 res;
  float recipcal = 1.0f / scalar;
  return (lathe_vec3){v->x * recipcal, v->y * recipcal, v->z * recipcal};
}

lathe_vec3 vec3_negate(const lathe_vec3 *v) {
  return (lathe_vec3){-v->x, -v->y, -v->z};
}

lathe_vec3 vec3_normalize(const lathe_vec3 *v) {
  float magnitude = vec3_magnitude(v);
  float recipcal = 1.0f / magnitude;
  return (lathe_vec3){v->x * recipcal, v->y * recipcal, v->z * recipcal};
}

lathe_vec3 vec3_sub(const lathe_vec3 *a, lathe_vec3 *b) {
  return (lathe_vec3){a->x - b->x, a->y - b->y, a->z - b->z};
}

lathe_vec3 vec3_add(const lathe_vec3 *a, lathe_vec3 *b) {
  return (lathe_vec3){a->x + b->x, a->y + b->y, a->z + b->z};
}

float vec3_magnitude(const lathe_vec3 *v) {
  return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

void vec3_print(const lathe_vec3 *v, FILE *out) {
  out = (out == nullptr) ? stderr : out;
  fprintf(out, "vec3: [%.3f %.3f %.3f]\n", v->x, v->y, v->z);
}

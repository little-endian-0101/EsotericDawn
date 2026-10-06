#include "math/lathe_vec3.h"
#include "system/lathe_logger.h"
#include <assert.h>
#include <math.h>

const lathe_vec3 zero_vec3 = {{0.0f,0.0f,0.0f}};

lathe_vec3 vec3_scalar_mult(const lathe_vec3 *v, float scalar) {
  return (lathe_vec3){{v->x * scalar, v->y * scalar, v->z * scalar}};
}

lathe_vec3 vec3_scalar_div(const lathe_vec3 *v, float scalar) {
  assert(scalar != 0.0f);
  if (scalar == 0.0f) {
    LATHE_ERROR("Attempted to divide by 0, returning 0 vec3 instead", nullptr);
    return (lathe_vec3){{0.0f, 0.0f, 0.0f}};
  }
  float recipcal = 1.0f / scalar;
  return (lathe_vec3){{v->x * recipcal, v->y * recipcal, v->z * recipcal}};
}

lathe_vec3 vec3_negate(const lathe_vec3 *v) {
  return (lathe_vec3){{-v->x, -v->y, -v->z}};
}

lathe_vec3 vec3_normalize(const lathe_vec3 *v) {
  float magnitude = vec3_magnitude(v);
  assert(magnitude != 0.0f);
  if (magnitude == 0.0f) {
    LATHE_ERROR("Attempted to divide by 0, returning 0 vec3 instead", nullptr);
    return (lathe_vec3){{0.0f, 0.0f, 0.0f}};
  }
  float recipcal = 1.0f / magnitude;
  return (lathe_vec3){{v->x * recipcal, v->y * recipcal, v->z * recipcal}};
}

lathe_vec3 vec3_sub(const lathe_vec3 *a, lathe_vec3 *b) {
  return (lathe_vec3){{a->x - b->x, a->y - b->y, a->z - b->z}};
}

lathe_vec3 vec3_add(const lathe_vec3 *a, lathe_vec3 *b) {
  return (lathe_vec3){{a->x + b->x, a->y + b->y, a->z + b->z}};
}

float vec3_magnitude(const lathe_vec3 *v) {
  return (float)sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

float vec3_dot_product(const lathe_vec3 *a, const lathe_vec3 *b) {
    float scalar = (a->x * b->x + a->y * b->y + a->z * b->z);
    #ifdef LOG_DEBUG_ENABLED
    if(scalar == 0.0f){
        LATHE_INFO("These vectors are orthogonal to one another!",stderr);
    }
    #endif
  return scalar;
}


//simplification of the wedge product on 3d vectors
lathe_vec3 vec3_cross_product(const lathe_vec3 *a, const lathe_vec3 *b) {
  lathe_vec3 v = {};
  v.x = (a->y * b->z - a->z * b->y);
  v.y = (a->z * b->x - a->x * b->z);
  v.z = (a->x * b->y - a->y * b->x);
  return v;
}

//TODO: Validate this with test, and look inton the proofs
lathe_vec3 vec3_projection(const lathe_vec3 *a, const lathe_vec3 *b){
    //lathe_vec3 v = {};
    //  (dot product of a b and dot product of b and b (hence b^2 but thats fine)) <- makes a scalar, multiply said scalar by b to project
    lathe_vec3 v = vec3_scalar_mult(b,(vec3_dot_product(a,b) / vec3_dot_product(b,b)));
    return v;
    
}
lathe_vec3 vec3_rejection([[maybe_unused]] const lathe_vec3 *a, [[maybe_unused]] const lathe_vec3 *b){
    //temp
    lathe_vec3 v = {};
    return v;
}

bool vec3_eq(const lathe_vec3 *a, const lathe_vec3 *b){
    return (a->x == b->x && a->y == b->y && a->z == b->z);
}

float vec3_angle(const lathe_vec3 *a,const lathe_vec3 *b)
{
	float a_dot_b = vec3_dot_product(a,b);
	
    float a_len = vec3_magnitude(a);
    float b_len = vec3_magnitude(b);
    
	float cos_theta = (a_dot_b)/(a_len * b_len);
	return acosf(cos_theta); //Radians
}

void vec3_print(const lathe_vec3 *v, FILE *out) {
    out = (out == nullptr) ? stderr : out;
    fprintf(out, "vec3: [%.3f %.3f %.3f]\n", v->x, v->y, v->z);
}

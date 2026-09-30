//
//  lathe_vec3.h
//  lathe_core
//
//  Created by Christopher Scott on 9/22/26.
//  Inspired the following sites:
//  https://github.com/FrictionalGames/HPL1Engine/blob/master/include/math/Vector3.h
//  https://foundationsofgameenginedev.com
//

#pragma once
#include <stdio.h>
typedef union {
  float idx[3];
  struct {
    float x;
    float y;
    float z;
  };
} lathe_vec3;

lathe_vec3 vec3_scalar_mult(const lathe_vec3 *v, float scalar);
lathe_vec3 vec3_scalar_div(const lathe_vec3 *v, float scalar);
lathe_vec3 vec3_negate(const lathe_vec3 *v);
lathe_vec3 vec3_normalize(const lathe_vec3 *v);
lathe_vec3 vec3_sub(const lathe_vec3 *a, lathe_vec3 *b);
lathe_vec3 vec3_add(const lathe_vec3 *a, lathe_vec3 *b);
float vec3_magnitude(const lathe_vec3 *v);
float vec3_dot_product(const lathe_vec3 *a, const lathe_vec3 *b);
lathe_vec3 vec3_cross_product(const lathe_vec3 *a, const lathe_vec3 *b);
bool vec3_eq(const lathe_vec3 *a, const lathe_vec3 *b);
void vec3_print(const lathe_vec3 *v, FILE *out);

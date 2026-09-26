//
//  lathe_mat3_3.h
//  lathe_core
//
//  Created by Christopher Scott on 9/20/26.
//  Inspired the following sites:
//  https://github.com/FrictionalGames/HPL1Engine/blob/master/include/math/Matrix.h
//  https://foundationsofgameenginedev.com
//

#pragma once

#include "lathe_vec3.h"
#include <stdio.h>

typedef struct {
  float m[3][3];
} lathe_mat_3x3;

extern const lathe_mat_3x3 zero_3x3;
extern const lathe_mat_3x3 identity_3x3;

lathe_mat_3x3 create_3x3_matrix_vec3(const lathe_vec3 *a, const lathe_vec3 *b,
                                     const lathe_vec3 *c);

lathe_mat_3x3 create_3x3_matrix_float(float n00, float n01, float n02,
                                      float n10, float n11, float n12,
                                      float n20, float n21, float n22);

// using row-major order,dont care im in C so acting like it
lathe_vec3 get_mat_3x3_row(const lathe_mat_3x3 *mat, int row);

lathe_mat_3x3 mat_3x3_mul_mat_3x3(const lathe_mat_3x3 *A,
                                  const lathe_mat_3x3 *B);
lathe_vec3 mat_3x3_mul_vec3(const lathe_mat_3x3 *M, const lathe_vec3 *v);
void mat_3x3_print(const lathe_mat_3x3 *mat, FILE *out);

//
//  lathe_mat3.c
//  lathe_core
//
//  Created by Christopher Scott on 9/20/26.
//  Inspired the following sites:
//  https://github.com/FrictionalGames/HPL1Engine/blob/master/include/math/Matrix.h
//  https://foundationsofgameenginedev.com
//

// typedef struct {
//   float m[3][3];
// } lathe_mat_3x3;
#include "math/lathe_mat3.h"
const lathe_mat_3x3 zero_3x3 = {};
const lathe_mat_3x3 identity_3x3 = {
    {{1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}}};

lathe_mat_3x3 create_3x3_matrix_vec3(const lathe_vec3 *a, const lathe_vec3 *b,
                                     const lathe_vec3 *c) {
  lathe_mat_3x3 mat = {};
  mat.m[0][0] = a->x;
  mat.m[0][1] = a->y;
  mat.m[0][2] = a->z;

  mat.m[1][0] = b->x;
  mat.m[1][1] = b->y;
  mat.m[1][2] = b->z;

  mat.m[2][0] = c->x;
  mat.m[2][1] = c->y;
  mat.m[2][2] = c->z;

  return mat;
}

lathe_mat_3x3 create_3x3_matrix_float(float n00, float n01, float n02,
                                      float n10, float n11, float n12,
                                      float n20, float n21, float n22) {
  lathe_mat_3x3 mat = {};
  mat.m[0][0] = n00;
  mat.m[0][1] = n01;
  mat.m[0][2] = n02;

  mat.m[1][0] = n10;
  mat.m[1][1] = n11;
  mat.m[1][2] = n12;

  mat.m[2][0] = n20;
  mat.m[2][1] = n21;
  mat.m[2][2] = n22;

  return mat;
}

// using row-major order,dont care im in C so acting like it
lathe_vec3 get_mat_3x3_row(const lathe_mat_3x3 *mat, int row) {
  return (lathe_vec3){mat->m[row][0], mat->m[row][1], mat->m[row][2]};
}

lathe_mat_3x3 mat_3x3_mul_mat_3x3(const lathe_mat_3x3 *A,
                                  const lathe_mat_3x3 *B) {
  lathe_mat_3x3 mat;

  mat.m[0][0] = A->m[0][0] * B->m[0][0] + A->m[0][1] * B->m[1][0] +
                A->m[0][2] * B->m[2][0];

  mat.m[0][1] = A->m[0][0] * B->m[0][1] + A->m[0][1] * B->m[1][1] +
                A->m[0][2] * B->m[2][1];

  mat.m[0][2] = A->m[0][0] * B->m[0][2] + A->m[0][1] * B->m[1][2] +
                A->m[0][2] * B->m[2][2];

  mat.m[1][0] = A->m[1][0] * B->m[0][0] + A->m[1][1] * B->m[1][0] +
                A->m[1][2] * B->m[2][0];

  mat.m[1][1] = A->m[1][0] * B->m[0][1] + A->m[1][1] * B->m[1][1] +
                A->m[1][2] * B->m[2][1];

  mat.m[1][2] = A->m[1][0] * B->m[0][2] + A->m[1][1] * B->m[1][2] +
                A->m[1][2] * B->m[2][2];

  mat.m[2][0] = A->m[2][0] * B->m[0][0] + A->m[2][1] * B->m[1][0] +
                A->m[2][2] * B->m[2][0];

  mat.m[2][1] = A->m[2][0] * B->m[0][1] + A->m[2][1] * B->m[1][1] +
                A->m[2][2] * B->m[2][1];

  mat.m[2][2] = A->m[2][0] * B->m[0][2] + A->m[2][1] * B->m[1][2] +
                A->m[2][2] * B->m[2][2];

  return mat;
}
lathe_vec3 mat_3x3_mul_vec3(const lathe_mat_3x3 *M, const lathe_vec3 *v) {
  return (lathe_vec3){
      .x = M->m[0][0] * v->x + M->m[0][1] * v->y + M->m[0][2] * v->z,

      .y = M->m[1][0] * v->x + M->m[1][1] * v->y + M->m[1][2] * v->z,

      .z = M->m[2][0] * v->x + M->m[2][1] * v->y + M->m[2][2] * v->z};
}
void mat_3x3_print(const lathe_mat_3x3 *mat, FILE *out) {
  out = (out == nullptr) ? stderr : out;
  fprintf(out, "mat3x3:\n");
  fprintf(out, "[ %8.3f %8.3f %8.3f ]\n", mat->m[0][0], mat->m[0][1],
          mat->m[0][2]);
  fprintf(out, "[ %8.3f %8.3f %8.3f ]\n", mat->m[1][0], mat->m[1][1],
          mat->m[1][2]);
  fprintf(out, "[ %8.3f %8.3f %8.3f ]\n", mat->m[2][0], mat->m[2][1],
          mat->m[2][2]);
}

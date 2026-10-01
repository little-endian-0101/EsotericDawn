//
//  lathe_mat3.h
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

/**
 * @brief Represents a 3 x 3 matrix.
 *
 * An element in the matrix can be accessed via its internal array m 
 */
typedef struct {
  float m[3][3]; /**< Components as a 2D array of floats. */
} lathe_mat_3x3;

/**@brief A 3x3 mat with 0 for each component*/
extern const lathe_mat_3x3 zero_3x3;

/**@brief A 3x3 mat with 1's along its diagonal*/
extern const lathe_mat_3x3 identity_3x3;

/**
 * @defgroup mat3x3_operators
 * @brief A collection operators to use on vec3 objects
 * @details All functions within this grouping do not change the args,rather return new vec3 instance
 */

/**
 * @ingroup mat3x3_operators
 * @brief Creates a 3x3 matrix with 3 lathe_vec3's in a row, by row manner. Row major
 * @param a Pointer to the vec3 in the first row
 * @param b Pointer to the vec3 in the second row
 * @param c Pointer to the vec3 in the third row
 * @return The resulting mat3x3
 */
lathe_mat_3x3 create_3x3_matrix_vec3(const lathe_vec3 *a, const lathe_vec3 *b,
                                     const lathe_vec3 *c);

/**
 * @ingroup mat3x3_operators
 * @brief Creates a 3x3 matrix with 9 floats. Row major
 * @return The resulting mat3x3
 */
lathe_mat_3x3 create_3x3_matrix_float(float n00, float n01, float n02,
                                      float n10, float n11, float n12,
                                      float n20, float n21, float n22);

/**
 * @ingroup mat3x3_operators
 * @brief Creates a vec3 from a row in the matrix.
 * @param mat Pointer to the mat3x3
 * @param row The row in the mat3x3 to get the vec3 from
 * @return The resulting vec3. Will assert if row is >= 3 in debug mode. 
 * in release mode will just return row zero vector.
 */
lathe_vec3 get_mat_3x3_row(const lathe_mat_3x3 *mat, int row);

/**
 * @ingroup mat3x3_operators
 * @brief Multiplies two mat3x3's by another
 * @param A Pointer to a mat3x3
 * @param B Pointer to a mat3x3 (could be another or the same)
 * @return The resulting mat3x3.
 */
lathe_mat_3x3 mat_3x3_mul_mat_3x3(const lathe_mat_3x3 *A,
                                  const lathe_mat_3x3 *B);
/**
 * @ingroup mat3x3_operators
 * @brief Multiplies a mat3x3 by a vec3
 * @param M Pointer to a mat3x3
 * @param v Pointer to a vec3
 * @return The resulting mat3x3.
 */
lathe_vec3 mat_3x3_mul_vec3(const lathe_mat_3x3 *M, const lathe_vec3 *v);

/**
 * @ingroup mat3x3_operators
 * @brief Prints the mat3 to the provided output file
 * @param mat Pointer to a mat3x3
 * @param out Output file to write to
 */
void mat_3x3_print(const lathe_mat_3x3 *mat, FILE *out);

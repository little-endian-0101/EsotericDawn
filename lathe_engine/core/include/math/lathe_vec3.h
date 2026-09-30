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

/**
 * @brief Represents a 3D vector.
 *
 * A vector can be accessed either by its individual components
 * (`x`, `y`, `z`) or as a three-element array (`idx`).
 */
typedef union lathe_vec3 {
    float idx[3]; /**< Components as an array of floats size 3. */

    struct {
        float x; /**< X component. */
        float y; /**< Y component. */
        float z; /**< Z component. */
    };
} lathe_vec3;

/**
 * @defgroup vec3_operators
 * @brief A collection operators to use on vec3 objects
 * @details All functions within this grouping do not change the args,rather return new vec3 instance
 */

/**
 * @ingroup vec3_operators
 * @brief Multiplies the vec3 by a scalar
 * @param v Pointer to the vec3 to multiply
 * @param scalar Scalar value to multiply each component of vec3 @p v by.
 * @return The resulting vec3.
 */
lathe_vec3 vec3_scalar_mult(const lathe_vec3 *v, float scalar);

/**
 * @ingroup vec3_operators
 * @brief Divides the vec3 by a scalar
 * @param v Pointer to the vec3 to divide
 * @param scalar Scalar value to divide each component of vec3 @p v by.
 * @return The resulting vec3. If @p scalar is zero, the function will assert in debug mode
 * and return the zero vector in release mode.    
 */
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

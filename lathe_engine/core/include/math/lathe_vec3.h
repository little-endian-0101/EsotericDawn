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

/**@brief A vec3 with 0 for each component*/
extern const lathe_vec3 zero_vec3;

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

/**
 * @ingroup vec3_operators
 * @brief Negates the vec3
 * @param v Pointer to the vec3 to negate
 * @return The resulting vec3.  
 */
lathe_vec3 vec3_negate(const lathe_vec3 *v);

/**
 * @ingroup vec3_operators
 * @brief Normalizes the vector, so magnitude becomes 1, while pointing in same direction
 * @param v Pointer to the vec3 to divide
 * @return The resulting vec3. If @p v has a magnitude of 0 will assert in debug mode
 * and return the zero vector in release mode
 */
lathe_vec3 vec3_normalize(const lathe_vec3 *v);

/**
 * @ingroup vec3_operators
 * @brief Subtracts two vectors
 * @param a Pointer to a vec3
 * @param b Pointer to another vec3 (or the same) dont care about using restrict 
 * @return The resulting vec3.
 */
lathe_vec3 vec3_sub(const lathe_vec3 *a, lathe_vec3 *b);

/**
 * @ingroup vec3_operators
 * @brief Adds two vectors
 * @param a Pointer to a vec3
 * @param b Pointer to another vec3 (or the same) dont care about using restrict 
 * @return The resulting vec3.
 */
lathe_vec3 vec3_add(const lathe_vec3 *a, lathe_vec3 *b);

/**
 * @ingroup vec3_operators
 * @brief Calculates the magnitude (length) of the provided vector
 * @param v Pointer to a vec3
 * @return The resulting magnitude of vector @p v.
 */
float vec3_magnitude(const lathe_vec3 *v);

/**
 * @ingroup vec3_operators
 * @brief Calculates the dot product of two vectors
 * @param a Pointer to a vec3
 * @param b Pointer to another vec3 (or the same) dont care about using restrict 
 * @return The resulting dot product of the two vectors @p a and @p b.
 */
float vec3_dot_product(const lathe_vec3 *a, const lathe_vec3 *b);

/**
 * @ingroup vec3_operators
 * @brief Calculates the cross product of two vectors
 * @param a Pointer to a vec3
 * @param b Pointer to another vec3 (or the same) dont care about using restrict 
 * @return The resulting vec3.
 */
lathe_vec3 vec3_cross_product(const lathe_vec3 *a, const lathe_vec3 *b);

/**
 * @ingroup vec3_operators
 * @brief Compares two vec3's equality
 * @param a Pointer to a vec3
 * @param b Pointer to another vec3 (or the same) dont care about using restrict 
 * @return true if @p a and @p b have the same components (x,y,z) and false otherwise
 */
bool vec3_eq(const lathe_vec3 *a, const lathe_vec3 *b);

/**
 * @ingroup vec3_operators
 * @brief Gives the angle between two vectors
 * @param a Pointer to a vec3
 * @param b Pointer to another vec3 (or the same) dont care about using restrict 
 * @return The angle between both vectors in radians
 */
float vec3_angle(const lathe_vec3 *a,const lathe_vec3 *b);

/**
 * @ingroup vec3_operators
 * @brief Prints the vec3 to the provided output file
 * @param v Pointer to a vec3
 * @param out Output file to write to
 */
void vec3_print(const lathe_vec3 *v, FILE *out);

#ifndef CU_VECTOR_H
#define CU_VECTOR_H

#include "Vector.h"

// //////////////////////
// Inplace math functions
// //////////////////////

/* Replaces contents of u with *u + v.
 */
__device__
void
cu_v_add_inplace (Vector *u, Vector v);

/* Replaces contents of u with *u - v.
 */
__device__
void
cu_v_sub_inplace (Vector *u, Vector v);

/* Replaces contents of u with -*u.
 */
__device__
void
cu_v_neg_inplace (Vector *u);

/* Replaces contents of u with s*(*u).
 */
__device__
void
cu_v_scl_inplace (Coord s, Vector *u);

/* Replaces contents of u with Vector in the same direction normalized
 *     to given length.
 */
__device__
void
cu_v_norm_inplace (Coord length, Vector *v);

// ////////////////////////////////
// Math functions returning Vectors
// ////////////////////////////////

/* Returns u + v.
 */
__device__
Vector
cu_v_add (Vector u, Vector v);

/* Returns u - v.
 */
__device__
Vector
cu_v_sub (Vector u, Vector v);

/* Returns -u.
 */
__device__
Vector
cu_v_neg (Vector u);

/* Returns s*u.
 */
__device__
Vector
cu_v_scl (Coord s, Vector u);

/* Returns Vector in the same direction as u normalized to given
 *     length.
 */
__device__
Vector
cu_v_norm (Coord length, Vector v);

/* Returns vector product of u and v.
 */
__device__
Vector
cu_v_cross (Vector u, Vector v);

// ////////////////////////////////
// Math functions returning scalars
// ////////////////////////////////

/* Returns scalar product of u and v.
 */
__device__
Coord
cu_v_dot (Vector u, Vector v);

/* Returns magnitude of u.
 */
__device__
Coord
cu_v_mag (Vector u);

#endif

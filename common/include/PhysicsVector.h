#ifndef PHYSICS_VECTOR_H
#define PHYSICS_VECTOR_H

struct PhysicsVector
{
    double x, y, z;
};
typedef struct PhysicsVector PhysicsVector;

/* Print PhysicsVector in format "<v.x,v.y,v.z>\n"
 */
void
v_print (PhysicsVector v);

// //////////////////////
// Inplace math functions
// //////////////////////

/* Replaces contents of u with *u + v.
 */
void
v_add_inplace (PhysicsVector *u, PhysicsVector v);

/* Replaces contents of u with *u - v.
 */
void
v_sub_inplace (PhysicsVector *u, PhysicsVector v);

/* Replaces contents of u with -*u.
 */
void
v_neg_inplace (PhysicsVector *u);

/* Replaces contents of u with s*(*u).
 */
void
v_scl_inplace (double s, PhysicsVector *u);

/* Replaces contents of u with PhysicsVector in the same direction normalized
 *     to given length.
 */
void
v_norm_inplace (double length, PhysicsVector *v);

// ////////////////////////////////
// Math functions returning PhysicsVectors
// ////////////////////////////////

/* Returns u + v.
 */
PhysicsVector
v_add (PhysicsVector u, PhysicsVector v);

/* Returns u - v.
 */
PhysicsVector
v_sub (PhysicsVector u, PhysicsVector v);

/* Returns -u.
 */
PhysicsVector
v_neg (PhysicsVector u);

/* Returns s*u.
 */
PhysicsVector
v_scl (double s, PhysicsVector u);

/* Returns PhysicsVector in the same direction as u normalized to given
 *     length.
 */
PhysicsVector
v_norm (double length, PhysicsVector v);

/* Returns vector product of u and v.
 */
PhysicsVector
v_cross (PhysicsVector u, PhysicsVector v);

// ////////////////////////////////
// Math functions returning scalars
// ////////////////////////////////

/* Returns scalar product of u and v.
 */
double
v_dot (PhysicsVector u, PhysicsVector v);

/* Returns magnitude of u.
 */
double
v_mag (PhysicsVector u);

#endif

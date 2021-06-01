#include <stdio.h>
#include <math.h>
#include "PhysicsVector.h"

/* Print PhysicsVector in format "<v.x,v.y,v.z>\n"
 */
void
v_print (PhysicsVector v)
{
    printf ("<%f,%f,%f>\n", v.x, v.y, v.z);
}

// //////////////////////
// Inplace math functions
// //////////////////////

/* Replaces contents of u with *u + v.
 */
void
v_add_inplace (PhysicsVector *u, PhysicsVector v)
{
    u->x += v.x;
    u->y += v.y;
    u->z += v.z;
}

/* Replaces contents of u with *u - v.
 */
void
v_sub_inplace (PhysicsVector *u, PhysicsVector v)
{
    u->x -= v.x;
    u->y -= v.y;
    u->z -= v.z;
}

/* Replaces contents of u with -*u.
 */
void
v_neg_inplace (PhysicsVector *u)
{
    u->x = -u->x;
    u->y = -u->y;
    u->z = -u->z;
}

/* Replaces contents of u with s*(*u).
 */
void
v_scl_inplace (double s, PhysicsVector *u)
{
    u->x *= s;
    u->y *= s;
    u->z *= s;
}

/* Replaces contents of u with PhysicsVector in the same direction normalized
 *     to given length.
 */
void
v_norm_inplace (double length, PhysicsVector *v)
{
    double _mag = v_mag (*v);
    if (_mag) // do not rescale if magnitude is zero.
        v_scl_inplace (length / _mag, v);
}

// ////////////////////////////////
// Math functions returning PhysicsVectors
// ////////////////////////////////

/* Returns u + v.
 */
PhysicsVector
v_add (PhysicsVector u, PhysicsVector v)
{
    v_add_inplace (&u, v);
    return u;
}

/* Returns u - v.
 */
PhysicsVector
v_sub (PhysicsVector u, PhysicsVector v)
{
    v_sub_inplace (&u, v);
    return u;
}

/* Returns -u.
 */
PhysicsVector
v_neg (PhysicsVector u)
{
    v_neg_inplace (&u);
    return u;
}

/* Returns s*u.
 */
PhysicsVector
v_scl (double s, PhysicsVector u)
{
    v_scl_inplace (s, &u);
    return u;
}

/* Returns PhysicsVector in the same direction as u normalized to given
 *     length.
 */
PhysicsVector
v_norm (double length, PhysicsVector v)
{
    v_norm_inplace (length, &v);
    return v;
}

/* Returns vector product of u and v.
 */
PhysicsVector
v_cross (PhysicsVector u, PhysicsVector v)
{
    double w_x = u.y*v.z - u.z*v.y;
    double w_y = u.z*v.x - u.x*v.z;
    double w_z = u.x*v.y - u.y*v.x;
    PhysicsVector w = { w_x, w_y, w_z };
    return w;
}

// ////////////////////////////////
// Math functions returning scalars
// ////////////////////////////////

/* Returns scalar product of u and v.
 */
double
v_dot (PhysicsVector u, PhysicsVector v)
{
    double product = 0.;
    product += u.x*v.x;
    product += u.y*v.y;
    product += u.z*v.z;
    return product;
}

/* Returns magnitude of u.
 */
double
v_mag (PhysicsVector u)
{
    return sqrt (v_dot (u, u));
}

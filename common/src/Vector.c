#include <stdio.h>
#include <math.h>
#include "Vector.h"

/* Print Vector in format "<v.x,v.y,v.z>\n"
 */
void
v_print (Vector v)
{
    printf ("<%f,%f,%f>\n", v.x, v.y, v.z);
}

// //////////////////////
// Inplace math functions
// //////////////////////

/* Replaces contents of u with *u + v.
 */
void
v_add_inplace (Vector *u, Vector v)
{
    u->x += v.x;
    u->y += v.y;
    u->z += v.z;
}

/* Replaces contents of u with *u - v.
 */
void
v_sub_inplace (Vector *u, Vector v)
{
    u->x -= v.x;
    u->y -= v.y;
    u->z -= v.z;
}

/* Replaces contents of u with -*u.
 */
void
v_neg_inplace (Vector *u)
{
    u->x = -u->x;
    u->y = -u->y;
    u->z = -u->z;
}

/* Replaces contents of u with s*(*u).
 */
void
v_scl_inplace (double s, Vector *u)
{
    u->x *= s;
    u->y *= s;
    u->z *= s;
}

/* Replaces contents of u with Vector in the same direction normalized
 *     to given length.
 */
void
v_norm_inplace (double length, Vector *v)
{
    double _mag = v_mag (*v);
    if (_mag) // do not rescale if magnitude is zero.
        v_scl_inplace (length / _mag, v);
}

// ////////////////////////////////
// Math functions returning Vectors
// ////////////////////////////////

/* Returns u + v.
 */
Vector
v_add (Vector u, Vector v)
{
    v_add_inplace (&u, v);
    return u;
}

/* Returns u - v.
 */
Vector
v_sub (Vector u, Vector v)
{
    v_sub_inplace (&u, v);
    return u;
}

/* Returns -u.
 */
Vector
v_neg (Vector u)
{
    v_neg_inplace (&u);
    return u;
}

/* Returns s*u.
 */
Vector
v_scl (double s, Vector u)
{
    v_scl_inplace (s, &u);
    return u;
}

/* Returns Vector in the same direction as u normalized to given
 *     length.
 */
Vector
v_norm (double length, Vector v)
{
    v_norm_inplace (length, &v);
    return v;
}

/* Returns vector product of u and v.
 */
Vector
v_cross (Vector u, Vector v)
{
    double w_x = u.y*v.z - u.z*v.y;
    double w_y = u.z*v.x - u.x*v.z;
    double w_z = u.x*v.y - u.y*v.x;
    Vector w = { w_x, w_y, w_z };
    return w;
}

// ////////////////////////////////
// Math functions returning scalars
// ////////////////////////////////

/* Returns scalar product of u and v.
 */
double
v_dot (Vector u, Vector v)
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
v_mag (Vector u)
{
    return sqrt (v_dot (u, u));
}

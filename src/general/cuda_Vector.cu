#include "cuda_Vector.h"

// //////////////////////
// Inplace math functions
// //////////////////////

/* Replaces contents of u with *u + v.
 */
__device__
void
cu_v_add_inplace (Vector *u, Vector v)
{
    u->x += v.x;
    u->y += v.y;
    u->z += v.z;
}

/* Replaces contents of u with *u - v.
 */
__device__
void
cu_v_sub_inplace (Vector *u, Vector v)
{
    u->x -= v.x;
    u->y -= v.y;
    u->z -= v.z;
}

/* Replaces contents of u with -*u.
 */
__device__
void
cu_v_neg_inplace (Vector *u)
{
    u->x = -u->x;
    u->y = -u->y;
    u->z = -u->z;
}

/* Replaces contents of u with s*(*u).
 */
__device__
void
cu_v_scl_inplace (Coord s, Vector *u)
{
    u->x *= s;
    u->y *= s;
    u->z *= s;
}

/* Replaces contents of u with Vector in the same direction normalized
 *     to given length.
 */
__device__
void
cu_v_norm_inplace (Coord length, Vector *v)
{
    Coord _mag = cu_v_mag (*v);
    if (_mag) // do not rescale if magnitude is zero.
        cu_v_scl_inplace (length / _mag, v);
}

// ////////////////////////////////
// Math functions returning Vectors
// ////////////////////////////////

/* Returns u + v.
 */
__device__
Vector
cu_v_add (Vector u, Vector v)
{
    cu_v_add_inplace (&u, v);
    return u;
}

/* Returns u - v.
 */
__device__
Vector
cu_v_sub (Vector u, Vector v)
{
    cu_v_sub_inplace (&u, v);
    return u;
}

/* Returns -u.
 */
__device__
Vector
cu_v_neg (Vector u)
{
    cu_v_neg_inplace (&u);
    return u;
}

/* Returns s*u.
 */
__device__
Vector
cu_v_scl (Coord s, Vector u)
{
    cu_v_scl_inplace (s, &u);
    return u;
}

/* Returns Vector in the same direction as u normalized to given
 *     length.
 */
__device__
Vector
cu_v_norm (Coord length, Vector v)
{
    cu_v_norm_inplace (length, &v);
    return v;
}

/* Returns vector product of u and v.
 */
__device__
Vector
cu_v_cross (Vector u, Vector v)
{
    Coord w_x = u.y*v.z - u.z*v.y;
    Coord w_y = u.z*v.x - u.x*v.z;
    Coord w_z = u.x*v.y - u.y*v.x;
    Vector w = { w_x, w_y, w_z };
    return w;
}

// ////////////////////////////////
// Math functions returning scalars
// ////////////////////////////////

/* Returns scalar product of u and v.
 */
__device__
Coord
cu_v_dot (Vector u, Vector v)
{
    Coord product = 0.;
    product += u.x*v.x;
    product += u.y*v.y;
    product += u.z*v.z;
    return product;
}

/* Returns magnitude of u.
 */
__device__
Coord
cu_v_mag (Vector u)
{
    return sqrt (cu_v_dot (u, u));
}

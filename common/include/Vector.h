#ifndef VECTOR_H
#define VECTOR_H

typedef double Coord; // for declaring coordinates

struct Vector
{
    Coord x, y, z;
};
typedef struct Vector Vector;

/* Print Vector in format "<v.x,v.y,v.z>\n"
 */
void
v_print (Vector v);

// //////////////////////
// Inplace math functions
// //////////////////////

/* Replaces contents of u with *u + v.
 */
void
v_add_inplace (Vector *u, Vector v);

/* Replaces contents of u with *u - v.
 */
void
v_sub_inplace (Vector *u, Vector v);

/* Replaces contents of u with -*u.
 */
void
v_neg_inplace (Vector *u);

/* Replaces contents of u with s*(*u).
 */
void
v_scl_inplace (Coord s, Vector *u);

/* Replaces contents of u with Vector in the same direction normalized
 *     to given length.
 */
void
v_norm_inplace (Coord length, Vector *v);

// ////////////////////////////////
// Math functions returning Vectors
// ////////////////////////////////

/* Returns u + v.
 */
Vector
v_add (Vector u, Vector v);

/* Returns u - v.
 */
Vector
v_sub (Vector u, Vector v);

/* Returns -u.
 */
Vector
v_neg (Vector u);

/* Returns s*u.
 */
Vector
v_scl (Coord s, Vector u);

/* Returns Vector in the same direction as u normalized to given
 *     length.
 */
Vector
v_norm (Coord length, Vector v);

/* Returns vector product of u and v.
 */
Vector
v_cross (Vector u, Vector v);

// ////////////////////////////////
// Math functions returning scalars
// ////////////////////////////////

/* Returns scalar product of u and v.
 */
Coord
v_dot (Vector u, Vector v);

/* Returns magnitude of u.
 */
Coord
v_mag (Vector u);

#endif

/* j/4/by_jab.c
**
*/
#include "all.h"


/* functions
*/
  u3_noun
  u3qdb__stage_jab(u3_noun a,
            u3_noun key,
            u3_noun fun)
  {
    if ( u3_nul == a ) {
      return u3m_bail(c3__exit);
    }
    else {
      u3_noun l_a, n_a, r_a;
      u3_noun pn_a, qn_a;

      if ( (c3n == u3r_trel(a, &n_a, &l_a, &r_a)) ||
           (c3n == u3r_cell(n_a, &pn_a, &qn_a) ) )
      {
        return u3m_bail(c3__exit);
      }
      else {
        if ( (c3y == u3r_sing(key, pn_a)) ) {
          u3_noun value = u3n_slam_on(u3k(fun), u3k(qn_a));
          return u3nc(u3nc(u3k(pn_a), value), u3k(u3t(a)));
        }
        else {
          if ( c3y == u3qc__stage_gor(key, pn_a) ) {
            return u3nt(u3k(n_a), u3qdb__stage_jab(l_a, key, fun), u3k(r_a));
          }
          else {
            return u3nt(u3k(n_a), u3k(l_a), u3qdb__stage_jab(r_a, key, fun));
          }
        }
      }
    }
  }

  u3_noun
  u3wdb__stage_jab(u3_noun cor)
  {
    u3_noun a, key, fun;

    if ( c3n == u3r_mean(cor, u3x_sam_2,   &key,
                              u3x_sam_3,   &fun,
                              u3x_con_sam, &a, 0) ) {
      return u3m_bail(c3__exit);
    } else {
      u3_noun n = u3qdb__stage_jab(a, key, fun);
      return n;
    }
  }

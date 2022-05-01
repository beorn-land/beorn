/* Beorn Lang - 2022
 * Jean Carlos (jeantux)
 */

#ifndef __BVM
#define __BVM

#include "btypes.h"

typedef struct beorn_env {
  beorn_state** bval;
} beorn_env;

beorn_state* process(beorn_env* benv, beorn_state* curr);

#endif
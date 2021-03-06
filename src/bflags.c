/* Beorn Lang - 2022
 * Jean Carlos (jeantux)
 */

#include "bflags.h"

void initial_info() {
  printf("Beorn (%s) (%s)\n", BEORN_VM_VERSION, BEORN_LIB_VERSION);
}

void version_app() {
  printf("Beorn Land (%s) (%s)\n", BEORN_VM_VERSION, BEORN_LIB_VERSION);
}

int non_flag(char * name) {
  if (name[0] != '-') return 1;

  return 0;
}

int argcmp(char sname, const char * name, char * arg) {
  if (arg[0] == '-')
  {
    if (arg[1] == '-')
    {
      return strcmp(name, arg);
    }

    if (arg[1] == sname) return 0;
  }

  return 1;
}

bimode get_bimode(int argc, char** argv) {
  if (argc <= 1) return BI_INTERACTIVE_DEFAULT;

  for (int i = 1; i < argc; i++)
  {
    if (non_flag(argv[i])) return BI_PROCESS_DEFAULT;

    if (argcmp('v', "--version", argv[i]) == 0)
    {
      version_app();
    }
  }

  return BI_NONE;
}

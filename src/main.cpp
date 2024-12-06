#include <cstdio>
#include <cstdlib>
#include <cstring>
/*
 * constants:
 * HEULPAD_PLUGINS
 * HEULPAD_PLUGINS_REGISTRY
 * HEULPAD_CONFIG
 *
 * */

// All available commands
#define NCOMMANDS 5
const char *commands[NCOMMANDS] = {"new", "enable", "help", "preview", "list"};

int main(int argc, char *argv[]) {
  if (argc > 1) {
    for (int i = 0; i < NCOMMANDS; ++i) {
      if (strcmp(argv[1], commands[i]) == 0) {
        printf("Will call 'heulpad %s'\n", argv[1]);
        printf("Looking through %s/heulpad-%s\n",
               std::getenv("HEULPAD_LIBEXEC"), argv[1]);
        return 0;
      }
    }
    fprintf(
        stderr,
        "'heulpad %s' is not a command\t\tSee heulpad --help for reference\n",
        argv[1]);
    return 1;
  }
  printf("Calling 'heulpad help'\n");
  printf("Looking through %s/heulpad-help\n", std::getenv("HEULPAD_LIBEXEC"));
  return 0;
}

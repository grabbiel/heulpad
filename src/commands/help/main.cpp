#include <cstdio>
#include <string.h>

#define NCOMMANDS 5
#define NMAINFLAGS 5
const char *commands[NCOMMANDS] = {"new", "enable", "help", "preview", "list"};
const char *flags[NMAINFLAGS] = {"--version", "--help", "--config", "--logs",
                                 "--env"};

int main(int argc, char *argv[]) {
  if (argc > 1) {
    for (int i = 0; i < NCOMMANDS; ++i) {
      if (strcmp(argv[1], commands[i]) == 0) {
        printf("[help]: Invoking man page 'heulpad-%s'\n", commands[i]);
        return 0;
      }
    }
    fprintf(stderr,
            "'heulpad help %s' is not a command\t\tSee heulpad --help for "
            "reference\n",
            argv[1]);
    return 1;
  }

  const char *prefix = "usage: heulpad ";
  const int prefix_len = strlen(prefix);
  printf("%s[%s] [%s]\n", prefix, flags[0], flags[1]);
  printf("%*s[%s] [%s]\n", prefix_len, "", flags[2], flags[3]);
  printf("%*s[%s]\n\n\n", prefix_len, "", flags[4]);

  return 0;
}

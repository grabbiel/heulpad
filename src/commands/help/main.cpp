#include <cstdio>
#include <cstdlib>
#include <string.h>

#define NCOMMANDS 5
#define NMAINFLAGS 5
const char *commands[NCOMMANDS] = {"new", "enable", "help", "preview", "list"};
const char *flags[NMAINFLAGS] = {"--version", "--help", "--config", "--logs",
                                 "--env"};

int main(int argc, char *argv[]) {
  if (argc > 0) {
    for (int i = 0; i < NCOMMANDS; ++i) {
      printf("argv[0] = %s\n", argv[0]);
      printf("argv[1] = %s\n", argv[1]);
      if (strcmp(argv[1], commands[i]) == 0) {
        /* ============================
         * System call to man-page can be at most:
         * ============================
         * 'man '                     4
         * 'heulpad-'                 8
         * max(<command>)            16
         * ----------------------------
         *                           28
         *                          ~30
         * */
        char man_command[31];
        if (strcmp(argv[1], "heulpad") == 0) {
          snprintf(man_command, sizeof(man_command), "man heulpad");
        } else {
          snprintf(man_command, sizeof(man_command), "man heulpad-%s", argv[1]);
        }
        return std::system(man_command);
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

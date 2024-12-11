#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
/*
 * constants:
 * HEULPAD_MAN
 * HEULPAD_CONFIG: "#{etc}/heulpad/config",
 * HEULPAD_PLUGINS: "#{var}/heulpad/plugins",
 * HEULPAD_PLUGINS_REGISTRY: "#{share}/heulpad/plugins.list",
 * HEULPAD_LIBEXEC: libexec,
 * HEULPAD_SHARE: "#{share}"
 * */

// All available commands
#define NCOMMANDS 5
const char *commands[NCOMMANDS] = {"new", "enable", "help", "preview", "list"};

int main(int argc, char *argv[]) {
  const char *libexecpath = std::getenv("HEULPAD_LIBEXEC");
  if (libexecpath == nullptr) {
    fprintf(stderr, "Cannot determine environment variable HEULPAD_LIBEXEC");
    return 1;
  }
  const char *minimal_env[] = {"TERM=xterm-256color", NULL, NULL};
  char exec_path[165] = "";
  if (argc > 1) {
    for (int i = 0; i < NCOMMANDS; ++i) {
      if (strcmp(argv[1], commands[i]) == 0) {
        /* ============================
         * The path to executable would be:
         * ============================
         * BASE HOMEBREW PATH     (<100)
         * [Cellar] directory        (7)
         * [heulpad] directory       (8)
         * [version] directory     (<10)
         * [libexec] directory       (8)
         * <executable>            (<30)
         * ----------------------------
         *                          163
         *                         ~165
         * */
        if (strcmp(argv[1], "help") == 0) {
          FILE *fp;
          char manpath[1024];
          fp = popen("manpath", "r");
          if (!fp) {
            fprintf(stderr, "[heulpad]: Could not execute 'manpath' command\n");
            return 1;
          }
          while (fgets(manpath, 1024, fp) != NULL) {
            printf("%s\n", manpath);
            printf("-----\n");
          }
          if (pclose(fp) == -1) {
            fprintf(stderr, "[heulpad]: Could not close buffer\n");
            return 1;
          }
          // char manpath[256];
          // snprintf(manpath, sizeof(manpath), "MANPATH=%s/man",
          //          std::getenv("HEULPAD_SHARE"));
          return 0;
        }
        snprintf(exec_path, sizeof(exec_path), "%s/heulpad-%s", libexecpath,
                 argv[1]);
        return execve(exec_path, argv + 2, (char *const *)minimal_env);
      }
    }

    fprintf(
        stderr,
        "'heulpad %s' is not a command\t\tSee heulpad --help for reference\n",
        argv[1]);
    return 1;
  }
  snprintf(exec_path, sizeof(exec_path), "%s/heulpad-help", libexecpath);
  return execve(exec_path, NULL, (char *const *)minimal_env);
}

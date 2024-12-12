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
#define NCOMMANDS 4
const char *commands[NCOMMANDS] = {"new", "enable", "preview", "list"};

int main(int argc, char *argv[]) {
  // ensure executables are reachable
  const char *libexecpath = std::getenv("HEULPAD_LIBEXEC");
  if (libexecpath == nullptr) {
    fprintf(stderr, "Cannot determine environment variable HEULPAD_LIBEXEC\n");
    return 1;
  }

  /* ============================
   * The path to executable (in char) is:
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
  char exec_path[165];
  const char *minimal_env[] = {"TERM=xterm-256color", NULL};

  /* ====== heulpad help ======
   * extra ENV variable is needed
   * ==========================*/
  if (argc == 1 || strcmp(argv[1], "help") == 0) {
    const char *sharepath = std::getenv("HEULPAD_SHARE");
    if (sharepath == nullptr) {
      fprintf(stderr, "[heulpad]: Cannot determine environment variable "
                      "HEULPAD_SHARE\n");
      return 1;
    }
    FILE *fp;
    char manpath[1024];
    fp = popen("manpath", "r");
    if (!fp) {
      fprintf(stderr, "[heulpad]: Could not execute 'manpath' command\n");
      return 1;
    }
    while (fgets(manpath, 1024, fp) != NULL) {
      char *result = manpath;
      result = strchr(result, '\n');
      if (result)
        *result = '\0';
    }
    if (pclose(fp) == -1) {
      fprintf(stderr, "[heulpad]: Could not close buffer\n");
      return 1;
    }
    char env_manpath[1024];
    snprintf(env_manpath, sizeof(env_manpath),
             "MANPATH=%s:%s/man:usr/local/share/man:/usr/share/man", manpath,
             sharepath);
    minimal_env[1] = env_manpath;
    snprintf(exec_path, sizeof(exec_path), "%s/heulpad-help", libexecpath);
    return execve(exec_path, argv + 2, (char *const *)minimal_env);
  }
  /*====== heulpad <command> ======= */
  for (int i = 0; i < NCOMMANDS; ++i) {
    if (strcmp(argv[1], commands[i]) == 0) {
      snprintf(exec_path, sizeof(exec_path), "%s/heulpad-%s", libexecpath,
               argv[1]);
      return execve(exec_path, argv + 2, (char *const *)minimal_env);
    }
  }

  /*===== unknown command =======*/
  fprintf(stderr,
          "'heulpad %s' is not a command\t\tSee heulpad --help for reference\n",
          argv[1]);
  return 1;
}

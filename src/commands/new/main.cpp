#include <cstdio>
#include <cstdlib>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc > 0) {
    for (int i = 0; i < argc; ++i) {
      printf("heulpad new %s\n", argv[i]);
    }
    return 1;
  }
  const char *libexecpath = std::getenv("HEULPAD_LIBEXEC");
  char exec_path[165];
  snprintf(exec_path, sizeof(exec_path), "%s/heulpad-help", libexecpath);
  const char *minimal_env[] = {"TERM=xterm-256color", NULL};
  return execve(exec_path, NULL, (char *const *)minimal_env);
}

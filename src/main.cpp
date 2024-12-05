#include <cstdio>
#include <cstdlib>
/*
 * constants:
 * HEULPAD_PLUGINS
 * HEULPAD_PLUGINS_REGISTRY
 * HEULPAD_CONFIG
 *
 * */
int main(int argc, char *argv[]) {
  if (argc > 1) {
    printf("Will call 'heulpad %s'\n", argv[1]);
    printf("Looking through %s\n", std::getenv("HEULPAD_LIBEXEC"));
  } else
    printf("Calling 'heulpad'\n");
  return 0;
}

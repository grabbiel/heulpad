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

  printf("Argument count is %d\n", argc);
  for (int i = 0; i < argc; ++i) {
    printf("ar%d: %s\n", i + 1, argv[i]);
  }

  return 0;
}

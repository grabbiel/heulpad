#include <cstdio>
int main(int argc, char *argv[]) {
  if (argc > 1) {
    for (int i = 1; i < argc; ++i) {
      printf("heulpad new %s\n", argv[i]);
    }
    return 1;
  }

  const char *prefix = "usage: heulpad new\n";
  return 0;
}

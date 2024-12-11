#include <cstdio>
int main(int argc, char *argv[]) {
  if (argc > 0) {
    for (int i = 0; i < argc; ++i) {
      printf("heulpad enable %s\n", argv[i]);
    }
    return 1;
  }
  const char *prefix = "usage: heulpad enable\n";
  return 0;
}

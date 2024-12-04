#include <cstdio>
#include <cstdlib>

int main(int argc, char *argv[]) {
  const char *config_path = std::getenv("HEULPAD_CONFIG");
  if (!config_path) {
    printf("Could not find config path\n");
  } else {
    printf("%s\n", config_path);
  }
  return 0;
}

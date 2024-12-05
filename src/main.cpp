#include <cstdio>
#include <cstdlib>

int main(int argc, char *argv[]) {
  const char *config_path = std::getenv("HEULPAD_CONFIG");
  if (!config_path) {
    printf("Could not find config path, I am serious\n");
  } else {
    printf("[SUCCESS] %s\n", config_path);
  }
  return 0;
}

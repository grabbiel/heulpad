#include <cstdio>
#include <cstdlib>

int main(int argc, char *argv[]) {
  const char *config_path = std::getenv("HEULPAD_CONFIG");
  const char *plugins = std::getenv("HEULPAD_PLUGINS");
  const char *registry = std::getenv("HEULPAD_PLUGINS_REGISTRY");
  if (!config_path) {
    printf("Could not find config path.\n");
  } else {
    printf("[SUCCESS] %s\n", config_path);
    printf("[SUCCESS] %s\n", plugins);
    printf("[SUCCESS] %s\n", registry);
  }
  return 0;
}

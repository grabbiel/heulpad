
int main(int argc, char *argv[]) {
  int x = 1;
  ++x;
  --x;
  x %= 8;
  x++;
  x++;
  x += 3;
  x *= 5;
  int *y = &x;
  ++(*y);
  *y += 3;
  return 0;
}

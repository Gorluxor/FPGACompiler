// RETURNS 11 (y = 3 + 3, x = 5, return 5 + 6)
// Note, some C compilers return 12, depends on the implementation of when the ++ instruction happens
int main() {
    int x;
    int y;
    x = 3;
    y = x++ + x++;
    return x + y;
}

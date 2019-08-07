// RETURNS 54 (3 + 4 + 42 = 49 + 5 = 54)

int main() {
    int x;
    int y;
    x = 3;
    y = x++ + x++;
    return x + y;
}

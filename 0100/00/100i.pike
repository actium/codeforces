int main()
{
    int k = (int)Stdio.stdin->gets();

    int x, y;
    sscanf(Stdio.stdin->gets(), "%d %d", x, y);

    float a = k * acos(-1.0) / 180;
    float nx = x * cos(a) - y * sin(a);
    float ny = x * sin(a) + y * cos(a);
    write(nx + " " + ny);

    return 0;
}

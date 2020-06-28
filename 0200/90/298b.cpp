#include <iostream>
#include <string>

#include <climits>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(int sx, int sy, int ex, int ey, const std::string& wind_dirs)
{
    size_t t = 0;
    do {
        switch (wind_dirs[t++]) {
            case 'E':
                if (sx < ex)
                    ++sx;
                break;

            case 'S':
                if (sy > ey)
                    --sy;
                break;

            case 'W':
                if (sx > ex)
                    --sx;
                break;

            case'N':
                if (sy < ey)
                    ++sy;
                break;
        }

        if (sx == ex && sy == ey)
            return answer(t);

    } while (t < wind_dirs.length());

    answer(-1);
}

int main()
{
    int t, sx, sy, ex, ey;
    std::cin >> t >> sx >> sy >> ex >> ey;

    std::string wind_dirs;
    std::cin >> wind_dirs;

    solve(sx, sy, ex, ey, wind_dirs);

    return 0;
}


#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x, int y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<std::string>& a, const std::vector<std::string>& b)
{
    const size_t na = a.size(), nb = b.size(), n = std::max(na, nb);
    const size_t ma = a[0].length(), mb = b[0].length(), m = std::max(ma, mb);

    std::vector<int> c = { -1, 0, 0 };
    for (size_t x = 0; x < n; ++x) {
        for (size_t y = 0; y < m; ++y) {
            unsigned qlu = 0, qld = 0, qru = 0, qrd = 0;
            for (size_t i = 0; i < n; ++i) {
                for (size_t j = 0; j < m; ++j) {
                    if (i < nb && i + x < na && j < mb && j + y < ma)
                        qlu += (a[i+x][j+y] & b[i][j]) - '0';

                    if (i < nb && i + x < na && j < ma && j + y < mb)
                        qru += (a[i+x][j] & b[i][j+y]) - '0';

                    if (i < na && i + x < nb && j < mb && j + y < ma)
                        qld += (a[i][j+y] & b[i+x][j]) - '0';

                    if (i < na && i + x < nb && j < ma && j + y < mb)
                        qrd += (a[i][j] & b[i+x][j+y]) - '0';
                }
            }

            c = std::max(c, { qlu, -x, -y });
            c = std::max(c, { qld,  x, -y });
            c = std::max(c, { qru, -x,  y });
            c = std::max(c, { qrd,  x,  y });
        }
    }

    answer(c[1], c[2]);
}

int main()
{
    size_t na, ma;
    std::cin >> na >> ma;

    std::vector<std::string> a(na);
    std::cin >> a;

    size_t nb, mb;
    std::cin >> nb >> mb;

    std::vector<std::string> b(nb);
    std::cin >> b;

    solve(a, b);

    return 0;
}

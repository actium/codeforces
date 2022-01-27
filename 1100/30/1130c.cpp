#include <iostream>
#include <vector>

using point_t = std::pair<unsigned, unsigned>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<std::string>& b, const point_t& s, const point_t& d)
{
    const size_t n = b.size();

    const auto space = [&](const point_t& x) {
        std::vector<point_t> q = { x };

        const auto enqueue = [&](unsigned r, unsigned c) {
            if (r > 0 && r <= n && c > 0 && c <= n && b[r-1][c-1] == '0') {
                q.emplace_back(r, c);
                b[r-1][c-1] = '1';
            }
        };

        enqueue(x.first, x.second);

        for (size_t i = 0; i < q.size(); ++i) {
            const point_t p = q[i];

            enqueue(p.first - 1, p.second);
            enqueue(p.first + 1, p.second);
            enqueue(p.first, p.second - 1);
            enqueue(p.first, p.second + 1);
        }

        return q;
    };

    const auto s1 = space(s), s2 = space(d);

    unsigned c = ~0u;
    for (const point_t s : s1) {
        for (const point_t d : s2) {
            const int dr = d.first - s.first, dc = d.second - s.second;
            c = std::min<unsigned>(c, dr * dr + dc * dc);
        }
    }

    answer(c);
}

int main()
{
    size_t n;
    std::cin >> n;

    point_t s, d;
    std::cin >> s >> d;

    std::vector<std::string> b(n);
    std::cin >> b;

    solve(b, s, d);

    return 0;
}

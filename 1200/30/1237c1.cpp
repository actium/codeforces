#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

struct Point {
    int x;
    int y;
    int z;
};

std::istream& operator >>(std::istream& input, Point& p)
{
    return input >> p.x >> p.y >> p.z;
}

unsigned distance(const Point& s, const Point& t)
{
    return abs(s.x - t.x) + abs(s.y - t.y) + abs(s.z - t.z);
}

void solve(const std::vector<Point>& p)
{
    const size_t n = p.size();

    std::vector<size_t> q(n);
    for (size_t i = 0; i < n; ++i)
        q[i] = i;

    std::vector<std::pair<unsigned, unsigned>> s;
    while (!q.empty()) {
        const size_t u = q.back();
        q.pop_back();

        std::pair<unsigned, size_t> x = { ~0u, u };
        for (size_t i = 0; i < q.size(); ++i)
            x = std::min(x, std::make_pair(distance(p[q[i]], p[u]), i));

        s.emplace_back(1+u, 1+q[x.second]);

        q[x.second] = q.back();
        q.pop_back();
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<Point> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}

#include <iostream>
#include <string>
#include <vector>

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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, const std::vector<std::pair<unsigned, unsigned>>& q)
{
    const size_t n = s.length();

    struct Segment {
        int x = 0;
        int lb;
        int ub;
    };

    std::vector<Segment> ps(1+n);
    for (size_t i = 0; i < n; ++i) {
        ps[i+1].x = ps[i].x + (s[i] == '+' ? 1 : -1);
        ps[i+1].lb = std::min(ps[i].lb, ps[i+1].x);
        ps[i+1].ub = std::max(ps[i].ub, ps[i+1].x);
    }

    std::vector<Segment> ss(1+n);
    for (size_t i = n; i-- > 0; ) {
        ss[i].x = ss[i+1].x + (s[i] == '+' ? 1 : -1);
        ss[i].lb = std::min(ss[i+1].lb, ss[i].x);
        ss[i].ub = std::max(ss[i+1].ub, ss[i].x);
    }

    for (const auto& r : q) {
        const auto& p = ps[r.first - 1];
        const auto& s = ss[r.second];

        const int lb = std::min(p.lb, p.x + s.x - s.ub);
        const int ub = std::max(p.ub, p.x + s.x - s.lb);

        answer(ub - lb + 1);
    }
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<std::pair<unsigned, unsigned>> q(m);
    std::cin >> q;

    solve(s, q);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}


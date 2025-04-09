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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

struct Range {
    unsigned lb = ~0u;
    unsigned ub = 0;
};

void solve(const std::string& s, const std::string& t, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = s.size();

    std::vector<Range> b(n);
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '1') {
            b[i].lb = i + 1;
            b[i].ub = i + 1;
        } else {
            if (i > 1 && s[i-2] == '0')
                b[i].lb = i - 1;

            if (i > 0 && t[i-1] == '1')
                b[i].lb = i;

            if (i + 2 < n && s[i+2] == '0')
                b[i].ub = i + 3;

            if (i + 1 < n && t[i+1] == '1')
                b[i].ub = i + 2;
        }
    }

    std::vector<unsigned> c(1+n);
    for (size_t i = 0; i < n; ++i)
        c[i+1] = c[i] + (b[i].lb <= b[i].ub);

    std::vector<bool> v(n);
    for (const std::pair<unsigned, unsigned>& q : r) {
        unsigned k = c[q.second] - c[q.first-1];
        for (const size_t x : { q.first-1, q.first, q.second-2, q.second-1 }) {
            if (x < q.first-1 || x >= q.second || v[x])
                continue;

            if (b[x].lb < q.first || q.second < b[x].ub)
                k -= (b[x].lb <= b[x].ub);

            v[x] = true;
        }

        answer(k);

        for (const size_t x : { q.first-1, q.first, q.second-2, q.second-1 }) {
            if (x < n)
                v[x] = false;
        }
    }
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    size_t q;
    std::cin >> q;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(s, t, r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

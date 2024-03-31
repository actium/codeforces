#include <iostream>
#include <set>
#include <string>
#include <vector>

using integer = long long;

constexpr integer M = 2147483647;

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

class HashedString {
public:
    HashedString(const std::string& s)
        : s_(s)
    {
        const size_t n = s_.length();

        h_[0].resize(1 + n);
        h_[1].resize(1 + n);

        integer p = 1, q = 1;
        for (size_t i = 0; i < n; ++i) {
            const unsigned d = s_[i] - '0' + 1;

            h_[0][i+1] = (h_[0][i] + d * p) % M;
            h_[1][i+1] = (h_[1][i] + d * q) % M;

            p = p * 13 % M;
            q = q * 1597 % M;
        }
    }

    std::pair<integer, integer> select(size_t i, size_t k) const
    {
        return std::make_pair((h_[0][i+k] - h_[0][i] + M) % M, (h_[1][i+k] - h_[1][i] + M) % M);
    }

private:
    const std::string s_;

    std::vector<integer> h_[2];

}; // class HashedString

const HashedString h0(std::string(200000, '0'));
const HashedString h1(std::string(200000, '1'));

void solve(const std::string& s, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = s.length();

    const HashedString hs(s);

    std::vector<unsigned> p(1 + n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + (s[i] - '0');

    std::set<std::pair<integer, integer>> v;
    for (const std::pair<unsigned, unsigned>& q : r) {
        const unsigned k = q.second - q.first + 1, c1 = p[q.second] - p[q.first-1], c0 = k - c1;

        const std::pair<integer, integer> ph = hs.select(0, q.first - 1);
        const std::pair<integer, integer> d0 = h0.select(q.first - 1, c0);
        const std::pair<integer, integer> d1 = h1.select(q.first - 1 + c0, c1);
        const std::pair<integer, integer> sh = hs.select(q.second, n - q.second);

        v.emplace((ph.first + d0.first + d1.first + sh.first) % M, (ph.second + d0.second + d1.second + sh.second) % M);
    }

    answer(v.size());
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<std::pair<unsigned, unsigned>> r(m);
    std::cin >> r;

    solve(s, r);
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

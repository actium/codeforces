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

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

struct Segment {
    std::string s;
    unsigned f[26];
};

void solve(size_t k, const std::string& s, const std::vector<std::pair<unsigned, char>>& x)
{
    Segment p = { s };
    for (const char c : s)
        ++p.f[c-'a'];

    std::vector<Segment> d(k, p);
    for (std::pair<unsigned, char> q : x) {
        const size_t c = q.second - 'a';

        auto it = d.begin();
        while (it->f[c] < q.first) {
            q.first -= it->f[c];
            ++it;
        }

        size_t i = 0;
        while (q.first != 0)
            q.first -= (it->s[i++] == q.second);

        it->s.erase(it->s.begin() + i - 1);
        --it->f[c];
    }

    std::string t;
    for (const Segment& e : d)
        t += e.s;

    answer(t);
}

int main()
{
    size_t k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, char>> x(n);
    std::cin >> x;

    solve(k, s, x);

    return 0;
}

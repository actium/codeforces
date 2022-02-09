#include <iostream>
#include <string>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& p, const std::string& s)
{
    const size_t n = p.size();

    std::vector<integer> pa(1 + n), pb(1 + n);
    for (size_t i = 0; i < n; ++i) {
        pa[i+1] = pa[i] + (s[i] == 'A' ? p[i] : 0);
        pb[i+1] = pb[i] + (s[i] == 'B' ? p[i] : 0);
    }

    integer x = 0;
    for (size_t i = 0; i < n; ++i) {
        x = std::max(x, pa[i] + pb.back() - pb[i]);
        x = std::max(x, pb[i] + pa.back() - pa[i]);
    }

    answer(x);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    std::string s;
    std::cin >> s;

    solve(p, s);

    return 0;
}

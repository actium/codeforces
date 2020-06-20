#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<size_t>& p, const std::vector<size_t>& t, size_t c)
{
    const size_t n = p.size();

    size_t z[2] = {}, s[2] = {};
    for (size_t i = 0, j = n-1; i < n; ++i, --j) {
        z[0] += t[i];
        z[1] += t[j];

        if (z[0] * c < p[i])
            s[0] += p[i] - z[0] * c;

        if (z[1] * c < p[j])
            s[1] += p[j] - z[1] * c;
    }

    if (s[0] == s[1])
        return answer("Tie");

    answer(s[0] < s[1] ? "Radewoosh" : "Limak");
}

int main()
{
    size_t n, c;
    std::cin >> n >> c;

    std::vector<size_t> p(n);
    std::cin >> p;

    std::vector<size_t> t(n);
    std::cin >> t;

    solve(p, t, c);

    return 0;
}


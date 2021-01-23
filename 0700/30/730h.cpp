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

void no_answer()
{
    std::cout << "No" << '\n';
}

void answer(const std::string& v)
{
    std::cout << "Yes" << '\n';
    std::cout << v << '\n';
}

void solve(std::vector<std::string>& s, const std::vector<unsigned>& x)
{
    const size_t m = x.size();

    std::vector<std::string> t;
    for (const unsigned i : x)
        t.push_back(std::move(s[i-1]));

    const size_t k = t[0].length();
    for (size_t i = 1; i < m; ++i) {
        if (t[i].length() != k)
            return no_answer();

        for (size_t j = 0; j < k; ++j) {
            if (t[i][j] != t[0][j])
                t[0][j] = '?';
        }
    }

    const auto match = [&](const std::string& q) {
        if (q.length() != k)
            return false;

        for (size_t i = 0; i < k; ++i) {
            if (q[i] != t[0][i] && t[0][i] != '?')
                return false;
        }
        return true;
    };

    for (const std::string& q : s) {
        if (match(q))
            return no_answer();
    }

    answer(t[0]);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    std::cin >> s;

    std::vector<unsigned> x(m);
    std::cin >> x;

    solve(s, x);

    return 0;
}


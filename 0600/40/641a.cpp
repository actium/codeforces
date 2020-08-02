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

void answer(bool v)
{
    constexpr const char* s[2] = { "INFINITE", "FINITE" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, std::vector<unsigned>& d)
{
    const int n = s.length();

    for (int i = 0, k; i >= 0 && i < n; i += k) {
        k = (s[i] == '>' ? d[i] : -d[i]);
        if (k == 0)
            return answer(false);

        d[i] = 0;
    }

    answer(true);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<unsigned> d(n);
    std::cin >> d;

    solve(s, d);

    return 0;
}


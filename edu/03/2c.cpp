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

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << '!' << '\n';
}

void solve(const std::vector<unsigned>& z)
{
    const size_t n = z.size();

    if (z[0] != 0)
        return no_answer();

    std::string s(n, ' ');
    for (size_t i = 0, c = 'a'; i < n; ++i) {
        if (i + z[i] > n)
            return no_answer();

        for (size_t j = 0; j < z[i]; ++j) {
            if (s[i+j] != ' ' && s[i+j] != s[j])
                return no_answer();

            s[i+j] = s[j];
        }

        if (s[i] == ' ') {
            s[i] = c;
            c = (c != 'z' ? c + 1 : 'A');
        }
    }

    for (size_t i = 1; i < n; ++i) {
        if (i + z[i] < n && s[i + z[i]] == s[z[i]])
            return no_answer();
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> z(n);
    std::cin >> z;

    solve(z);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

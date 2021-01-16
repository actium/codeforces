#include <algorithm>
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

void answer(const std::vector<size_t>& v)
{
    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& w, const std::string& s)
{
    const size_t n = w.size();

    std::vector<size_t> x(n);
    for (size_t i = 0; i < n; ++i)
        x[i] = i;

    std::sort(x.begin(), x.end(), [&w](size_t a, size_t b) { return w[a] < w[b]; });

    std::vector<size_t> p(2 * n), r;
    for (size_t i = 0, j = 0; i < 2 * n; ++i) {
        if (s[i] == '0') {
            p[i] = x[j];
            r.push_back(x[j++]);
        } else {
            p[i] = r.back();
            r.pop_back();
        }
    }

    answer(p);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> w(n);
    std::cin >> w;

    std::string s;
    std::cin >> s;

    solve(w, s);

    return 0;
}


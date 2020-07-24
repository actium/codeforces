#include <iostream>
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

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& s)
{
    std::vector<bool> h(n), v(n);

    const char* separator = "";
    for (size_t i = 0; i < s.size(); ++i) {
        const auto [r, c] = s[i];
        if (h[r-1] || v[c-1])
            continue;

        h[r-1] = true;
        v[c-1] = true;

        std::cout << separator << 1+i;
        separator = " ";
    }
    std::cout << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> s(n * n);
    std::cin >> s;

    solve(n, s);

    return 0;
}


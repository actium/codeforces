#include <algorithm>
#include <iostream>
#include <string>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(std::string& s, size_t k)
{
    const size_t n = s.length();

    std::sort(s.begin(), s.end());

    unsigned w = 0;
    for (size_t i = 0, j = 0; i < n && k != 0; ++i) {
        if (i == 0 || s[i] - s[j] > 1) {
            w += 1 + (s[i] - 'a');
            j = i;
            --k;
        }
    }

    answer(k == 0 ? w : -1);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);

    return 0;
}


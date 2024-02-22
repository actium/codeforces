#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    std::string t, b;

    const auto consume = [&] {
        const size_t m = b.length();

        for (size_t i = 0, j = 0; i < m; ++i) {
            if (i - j > 1 && (b[i] != b[j] || b[i] != b[i-1])) {
                t.push_back(' ');
                j = i;
            }
            t.push_back(b[i]);
        }

        b.clear();
    };

    for (const char c : s) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            b.push_back(c);
        } else {
            consume();
            t.push_back(c);
        }
    }
    consume();

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

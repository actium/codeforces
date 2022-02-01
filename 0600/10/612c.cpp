#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "Impossible" << '\n';
}

void solve(const std::string& s)
{
    unsigned k = 0;

    std::string b;
    for (const char c : s) {
        if (c == '<' || c == '{' || c == '[' || c == '(') {
            b.push_back(c);
            continue;
        }

        if (b.empty())
            return no_answer();

        k += (c == '>' && b.back() != '<');
        k += (c == '}' && b.back() != '{');
        k += (c == ']' && b.back() != '[');
        k += (c == ')' && b.back() != '(');

        b.pop_back();
    }

    if (b.empty())
        return answer(k);

    no_answer();
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

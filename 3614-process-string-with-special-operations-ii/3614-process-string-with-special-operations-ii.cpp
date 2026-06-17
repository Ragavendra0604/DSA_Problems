class Solution {
public:
    char processStr(string s, long long k) {
        const unsigned long long INF = (unsigned long long)2e18;
        int m = s.size();

        vector<char> ops;
        vector<char> letters;
        ops.reserve(m);
        letters.reserve(m);

        vector<unsigned long long> len;
        len.reserve(m + 1);
        len.push_back(0);

        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                ops.push_back('L');
                letters.push_back(c);
                unsigned long long newLen = len.back() + 1;
                if (newLen > INF) newLen = INF;
                len.push_back(newLen);
            } else if (c == '*') {
                ops.push_back('*');
                letters.push_back(0);
                unsigned long long prev = len.back();
                unsigned long long newLen = (prev == 0 ? 0 : prev - 1);
                len.push_back(newLen);
            } else if (c == '#') {
                ops.push_back('#');
                letters.push_back(0);
                unsigned long long prev = len.back();
                unsigned long long newLen;
                if (prev == 0) newLen = 0;
                else if (prev <= INF / 2) newLen = prev * 2;
                else newLen = INF;
                len.push_back(newLen);
            } else if (c == '%') {
                ops.push_back('%');
                letters.push_back(0);
                len.push_back(len.back());
            }
        }

        unsigned long long finalLen = len.back();
        if (k < 0 || (unsigned long long)k >= finalLen) return '.';

        unsigned long long K = (unsigned long long)k;
        int opCount = ops.size();

        for (int i = opCount - 1; i >= 0; --i) {
            unsigned long long prev = len[i];
            unsigned long long curr = len[i + 1];
            char op = ops[i];

            if (op == 'L') {
                if (K == curr - 1) return letters[i];
            } else if (op == '*') {
                if (prev > curr) {
                    if (K == curr) {
                        K = prev - 1;
                    }
                }
            } else if (op == '#') {
                if (prev > 0 && K >= prev) {
                    K -= prev;
                }
            } else if (op == '%') {
                if (prev > 0) K = (prev - 1) - K;
            }
        }

        return '.';
    }
};

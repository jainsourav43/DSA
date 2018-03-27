class Solution {
public:
    string minWindow(string S, string T) {
        if (S.length() < T.length()) return "";
        unordered_map<char, int> counts;
        for (int i = 0; i < T.length(); i++) {
            if (counts.find(T[i]) == counts.end()) {
                counts[T[i]] = 1;
            } else {
                counts[T[i]]++;
            }
        }
        int start = 0;
        int length = 0;
        int total = 0;
        for (int head = 0, tail = 0; tail < S.length(); tail++) {
            auto itTail = counts.find(S[tail]);
            if (counts.find(S[tail]) == counts.end()) {
                // If this character is not present in T at all, 
                // we don't care about this character. 
                continue;
            }
            counts[S[tail]]--;
            // We check if the current character represented by tail caused
            // a character to be included which is relevant to T and is still
            // in deficit. 
            // For example, if T has 3 As, then the first 3 A are relevant to us
            // but the 4th one is not. 
            if (counts[S[tail]] >= 0) {
                total++;
            }
            // check if we have all characters in T covered. 
            if (total == T.size()) {
                // Now move the head pointer till popping out those characters 
                // still makes sure that all characters in T are covered. 
                while (counts.find(S[head]) == counts.end() || counts[S[head]] < 0) {
                    if (counts.find(S[head]) != counts.end()) counts[S[head]]++;
                    head++;
                }
                // Now [head - 1, tail] is a valid substring. Update the answer. 
                if (length == 0 || tail - head + 1 < length) {
                    length = tail - head + 1;
                    start = head;
                }
            }
        }
        return S.substr(start, length);
    }
};

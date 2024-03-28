#include <ios>

#include "../common-header.hpp"

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param S string字符串 
     * @param T string字符串 
     * @return string字符串
     */
    string minWindow(string S, string T)
    {
        // write code here
        const int length = static_cast<int>(S.length());
        int left_index = 0;
        int right_index = 0;

        unordered_map<char, int> window_contains_letters;
        unordered_map<char, int> target_letters;
        for (const char c : T) {
            target_letters[c]++;
        }
        const int target_match_letters = static_cast<int>(target_letters.size());
        int match_letters = 0;

        int min_result_length = length + 1;
        int result_start_index = 0;
        while (right_index < length) {
            if (const char r = S[right_index]; target_letters.contains(r)) {
                window_contains_letters[r]++;
                if (window_contains_letters[r] == target_letters[r]) {
                    match_letters++;
                }
            }
            right_index++;

            if (match_letters == target_match_letters) {
                if (right_index - left_index < min_result_length) {
                    min_result_length = right_index - left_index;
                    result_start_index = left_index;
                }

                while (match_letters == target_match_letters) {
                    if (right_index - left_index < min_result_length) {
                        min_result_length = right_index - left_index;
                        result_start_index = left_index;
                    }
                    if (const char l = S[left_index]; target_letters.contains(l)) {
                        window_contains_letters[l]--;
                        if (window_contains_letters[l] < target_letters[l]) {
                            match_letters--;
                        }
                    }
                    left_index++;
                }
            }

            while (match_letters == target_match_letters) {
                if (right_index - left_index < min_result_length) {
                    min_result_length = right_index - left_index;
                    result_start_index = left_index;
                }
                if (const char l = S[left_index]; target_letters.contains(l)) {
                    window_contains_letters[l]--;
                    if (window_contains_letters[l] < target_letters[l]) {
                        match_letters--;
                    }
                }
                left_index++;
            }
        }

        return min_result_length == length + 1 ? "" : S.substr(result_start_index, min_result_length);
    }
};

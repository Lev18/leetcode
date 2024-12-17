#include <unordered_map>
#include <queue>

std::string repeatLimitedString(std::string s, int repeatLimit) {
        // counting characters occurance
        std::unordered_map<char, int> freq_map;
        for (const auto& it : s) {
            ++freq_map[it];
        }

        // keeping unique of string letters into pq
        std::priority_queue<char> max_heap;
        for (const auto& it : freq_map) {
            max_heap.push(it.first);
        }

        // main solution
        std::string res {};
        while (!max_heap.empty()) {
            // taking the top of the heap as it is the lexicographically largest 
            // and then erase it from the heap
            char ch = max_heap.top();
            max_heap.pop();

            // taking the count of the largest element
            // find the minimum amout of appending
            int count = freq_map[ch];
            int use = std::min(count, repeatLimit);

            // then append it to result
            int i = 0;
            while (i < use) {
                res += ch;
                ++i;
            }

            // subtract used element count from character frequency map
            freq_map[ch] -= use; 

            // checking that we can use the character in future 
            if (freq_map[ch] > 0 && !max_heap.empty()) {
                // if number of appended character is greather than repeatLimit
                //  and heap is not empty
                // but we have that character for future use we interupt the char sequence
                //  with second lexicographically larger value
                char next_ch = max_heap.top();
                max_heap.pop();
                
                res += next_ch;
                if (--freq_map[next_ch]) {
                    max_heap.push(next_ch);
                }
                // after appending that  character to the result we are pushing it back to the heap
                max_heap.push(ch);
            }
        }
        return res;
    }

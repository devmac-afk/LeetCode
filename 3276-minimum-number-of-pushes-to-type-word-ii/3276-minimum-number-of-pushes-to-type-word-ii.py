class Solution:
    def minimumPushes(self, word: str) -> int:
        freq = sorted(Counter(word).values() , reverse = True)
        res = 0
        for i in range(len(freq)):
            res += ceil((i+1)/8) * freq[i]
        return res
        return sum(ceil(i+1)/8 * freq[i] for i in range(len(freq)))
        
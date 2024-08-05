class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        output = []
        for char in arr:
            if(arr.count(char) == 1):
                output.append(char)
        
        if (k > len(output)):
            return ""
        else:
            return output[k-1]

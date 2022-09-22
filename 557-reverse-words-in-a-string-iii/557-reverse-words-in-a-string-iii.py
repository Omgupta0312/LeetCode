class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        a=[];
        t=s.split(" ")
        for i in t:
            a.append(i[::-1])
            
        ans=" ".join(a)
        print(ans)
        return ans
        
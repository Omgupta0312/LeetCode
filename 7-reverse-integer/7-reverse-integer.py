class Solution(object):
    def reverse(self, x):
		if x==0:
			return 0
		s=str(x).rstrip("0")
		s=s[::-1]
		if x<0:
			s="-"+s.rstrip("-")
		s=int(s)
		if (-2)**31>s or s>((2)**31)-1:
				return 0
		return s
        
class Solution:
    def reverseEqn(self, s):
        # code here
        s=list(s)
        se=['0','1','2','3','4','5','6','7','8','9']
        se=set(se)
        k1=[]
        for i in range(len(s)):
            if(s[i] not in se):
                k1.append(s[i])
                s[i]="."
        new=""
        for i in s:
            new+=i
        a1=new.split(".")
        new_ans=""
        new_ans+=a1[-1]
        a1.pop()
        a1=a1[:]
        for i in range(len(k1)):
            new_ans+=k1.pop()
            new_ans+=a1.pop()
        return new_ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        ob = Solution()
        ans = ob.reverseEqn(s)
        print(ans)
# } Driver Code Ends
class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        st=[]
        tt=[]

        for el in s:
            if el == '#':
                if st:
                    st.pop()
            else:
                st.append(el)
        for i in t:
            if i == '#':
                if tt:
                   tt.pop()
            else:
                tt.append(i)                
        
        return st==tt
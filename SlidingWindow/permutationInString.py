def permutationInString( s1: str, s2: str) -> bool:
    c1={}
    c2={}

    for c in s1:
        c1[c]=c1.get(c,0)+1
    l=0
    for r in range(len(s2)):
        c2[s2[r]]=c2.get(s2[r],0)+1
        
        if r-l+1 > len(s1):
            c2[s2[l]] -=1
            if c2[s2[l]] ==0:
                del c2[s2[l]]
            l+=1
            
        if c1==c2:
            return True
    return False
if __name__ == "__main__":
    s1 = "abc"
    s2 = "lecabee"
    print("Is permutation present:", permutationInString(s1, s2))
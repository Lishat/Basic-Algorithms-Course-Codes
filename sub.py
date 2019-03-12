def sub(a, b):
    c = len(a)
    d = len(b)
    if(c < d):
        return sub(b, a)
    else:
        e = min(c, d)
        borrow = 0
        i = -1
        j = 0
        while j < e:
            f = ord(a[i]) - borrow - ord(b[i])
            if(f < 0):
                f = ord(a[i])+10 - borrow - ord(b[i])
                borrow = 1
            else:
                borrow = 0
            a[i] = chr(48+f)
            j += 1
            i -= 1
        while borrow == 1:
            f = ord(a[i]) - borrow
            if(f < 48):
                f = ord(a[i])+10 - borrow
                borrow = 1
            else:
                borrow = 0
            a[i] = chr(f)
            i -= 1
        try:
            while(a[0] == '0'):
                a = a[1:]
        except:
            return ['0']
        return a
for _ in range(int(input())):
    a = list(input())
    b = list(input())
    c = sub(a, b)
    #print(c)
    print(*sub(['9']*len(c), c), sep = "")
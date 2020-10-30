def solution(relation):
    answer = 0
    m1 = []
    for i in range(1,1<<len(relation[0])) :
        s1 = []
        for m in range(len(relation)):
            li=[]
            for k in range(len(relation[0])) :
                if ((1<<k)  & i ) != 0 :
                    li.append(relation[m][len(relation[0])-k-1])
            if li  in s1 :
                break
            # else:
            s1.append(li)
        if len(s1) == len(relation) :
            flag = 0
            for s in  m1 :
                if (i & s) == s : 
                    flag=1
                    break
            if flag == 0:
                m1.append(i)
    
    answer= len(m1)

    return answer
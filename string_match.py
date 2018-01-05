"""
    字符串匹配，Sunday算法
    资料：
        http://blog.csdn.net/gerl123456/article/details/51189678
        http://blog.csdn.net/l953972252/article/details/51331001
"""


def sunday(text, pattern):
    
    len_text = len(text)
    len_pattern = len(pattern)
    badchars = {}

    if len_text < len_pattern:
        return -1

    # 预处理，
    for i in range(len_pattern):
        badchars[pattern[i]] = len_pattern-i
    
    # matching
    i = 0
    while i <= len_text-len_pattern:
        if text[i:i+len_pattern] == pattern:
            return i
        else:
            a = text[i+len_pattern] 
            if a in badchars.keys():
                move = badchars[a]
            else:
                move = len_pattern
            i += move
    
    return -1
            

def strmatch(text, pattern):
    """
        在s1中匹配s2
        若匹配成功，返回s2在s1的index值；否则，返回-1
    """
    return sunday(text, pattern)

if __name__ == "__main__":
    print(strmatch("here is a simple example", "example"))

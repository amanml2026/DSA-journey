'''
You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

Every open bracket is closed by the same type of close bracket.
Open brackets are closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Return true if s is a valid string, and false otherwise.

'''

def isValid( s: str) -> bool:
    stack = [] # stack 
    closeOpen = {')': '(', '}':'{', ']':'['} # dictionary for the opening and closing brackets
    for char in s:
        if char in closeOpen: # if char is a closing bracket
            if stack and closeOpen[char] == stack[-1]: # if len(stack) != 0 and closing bracket = opening bracket
                stack.pop() 
            else:
                return False # len(stack) == 0
        else:
            stack.append(char) # if char is opening bracket

    return True if not stack else False # if stack is empty -> every opening bracket got popped -> valid parantheses

def isValid2( s: str) -> bool: 
    closeOpen = {')': '(', '}':'{', ']':'['} # dictionary for the opening and closing brackets
    i = 0
    j = len(s) - 1
    while(i<j):
        if s[i] != closeOpen[s[j]]: # could give error if the ending elements are not the closing brackets
            return False
        i += 1
        j -= 1

    return True

# this approach could also fail if the brackets are non-symmetric ex. "{}[]()"

string1 = "([{}])"
print(isValid(string1)) # return True

string2 = "[(])"
print(isValid(string2)) # return False

#Testing approach 2:
print(isValid2(string1))
print(isValid2(string2))
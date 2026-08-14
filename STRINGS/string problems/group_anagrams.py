'''Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.'''

# Approach : 1. Making a dictionary where the key would be the frequency array and values would be the strings.
#            2. for each string in the given list of strings finding the frequency array and storing them in dictionary with
#               as the frequency table.
#            3. returning the list of dictionary values.

from collections import defaultdict

def groupAnagrams(strs: list[str]) -> list[list[str]]:
    res = defaultdict(list)
    for st in strs:
        count = [0]*26

        for char in st:
            count[ord(char)-ord('a')] += 1
        
        res[tuple(count)].append(st)

    return list(res.values())

strs = ["act","pots","tops","cat","stop","hat"]
print(groupAnagrams(strs))
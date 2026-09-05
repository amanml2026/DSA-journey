'''
You are given a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:

Each row must contain the digits 1-9 without duplicates.
Each column must contain the digits 1-9 without duplicates.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
Return true if the Sudoku board is valid, otherwise return false

'''

def isValidSudoku(board: list[list[str]]) -> bool:
    # Handling rows
    for row in board:
        row = [x for x in row if x != '.']
        if len(set(row)) != len(row):
            return False # duplicate found in row
            break
            
    # Handling the columns
    for i in range(9):
        col = [row[i] for row in board]
        col = [x for x in col if x != '.']
        if len(set(col)) != len(col):
            return False # duplicate found in column
            break

    # Handling 3x3 boxes
    for r in range(0,9,3): 
        for c in range(0,9,3):
            box = [] # accessing 3x3 boxes
            for i in range(r,r+3): # accessing each row in a box
                for j in range(c,c+3): # accessing each column in a box
                    if board[i][j] != '.':
                        box.append(board[i][j]) # appending the elements

            if len(set(box)) != len(box):
                return False # duplicate found in 3x3 box
                break

    return True # everything is fine :)

# TEST CASES
board1 = [["1","2",".",".","3",".",".",".","."],
["4",".",".","5",".",".",".",".","."],
[".","9","8",".",".",".",".",".","3"],
["5",".",".",".","6",".",".",".","4"],
[".",".",".","8",".","3",".",".","5"],
["7",".",".",".","2",".",".",".","6"],
[".",".",".",".",".",".","2",".","."],
[".",".",".","4","1","9",".",".","8"],
[".",".",".",".","8",".",".","7","9"]]

board2 = [["1","2",".",".","3",".",".",".","."],
["4",".",".","5",".",".",".",".","."],
[".","9","1",".",".",".",".",".","3"],
["5",".",".",".","6",".",".",".","4"],
[".",".",".","8",".","3",".",".","5"],
["7",".",".",".","2",".",".",".","6"],
[".",".",".",".",".",".","2",".","."],
[".",".",".","4","1","9",".",".","8"],
[".",".",".",".","8",".",".","7","9"]]

# test output
print(isValidSudoku(board1)) # returns true
print(isValidSudoku(board2)) # returns false
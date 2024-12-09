""" 
a) Write a pythonprogram to store roll numbers of student in array who attended training program in random order. 
Write function for searching whether particular student attended training program or not, 
using Linear search and Sentinel search.
"""
def linear_search(rollno, key):
    # Perform linear search
    for i in range(len(rollno)):
        if rollno[i] == key:
            print("Element found at index", i)
            return
    print("Element not found")

def sentinel_search(rollno, key):
    # Perform sentinel search
    n = len(rollno)
    if n == 0:
        print("Element not found")
        return
    
    last = rollno[-1]
    rollno[-1] = key

    i = 0
    while rollno[i] != key:
        i += 1
    
    rollno[-1] = last

    if i < n or rollno[i] == key:
        print("Element found at index", i)
    else:
        print("Element not found")

rollno = []
n = int(input("Enter the number of students: "))
for i in range(n):
    ele = int(input("Enter the roll number of the student: "))
    rollno.append(ele)

flag = 1
while flag == 1:
    print("1. Linear search")
    print("2. Sentinel search")
    print("3. Exit")
    ch = int(input("Enter the choice: "))
    if ch == 1:
        key = int(input("Enter the roll number to be searched: "))
        linear_search(rollno, key)
    elif ch == 2:
        key = int(input("Enter the roll number to be searched: "))
        sentinel_search(rollno, key)
    elif ch == 3:
        flag = 0

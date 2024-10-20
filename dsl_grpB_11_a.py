""" 
a) Write a pythonprogram to store roll numbers of student in array who attended training program in random order. 
Write function for searching whether particular student attended training program or not, 
using Linear search and Sentinel search.
"""
def linear_search(rollno,key):
    #key=int(input("Enter the element to be searched: "))
    for i in range(len(rollno)):
        if rollno[i] == key:
            print("Element found at index")
        else:
            print("Element not found")

def sentinel_search(rollno,key):
    #key=int(input("Enter the element to be searched: "))
    n=len(rollno)
    if n == 0:
        return False
    
    last=rollno[-1]
    rollno[-1]=key

    i=0
    while rollno[i]!= key:
        i+=1
    rollno[-1]=last

    if i<n-1 or rollno[i]==key:
        print("Element found at index",i)
    else:
        print("Element not found")

rollno=[]
n=int(input("Enter the number of students :"))
for i in range(0,n):
    ele=int(input("Enter the roll number of the students: "))
    rollno.append(ele)

flag=1
while flag==1:
    print("1.Linear search")
    print("2.Sentinel search")
    print("3.Exit")
    ch=int(input("Enter the choice: "))
    if ch==1:
        key=int(input("Enter the element to be searched: "))
        linear_search(rollno,key)
    if ch==2:
        key=int(input("Enter the element to be searched: "))
        sentinel_search(rollno,key)
    if ch==3:
        flag=0


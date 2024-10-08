'''
Experiment Number 14: Write a python program to store first year percentage of students in an array.
                      Write function for sorting array of floating point numbers in ascending order using:
                      a) Selection Sort
                      b) Bubble Sort and display top five scores
'''
def Selection_Sort(marks):
    for i in range(len(marks)):

        min_idx = i
        for j in range(i + 1, len(marks)):
            if marks[min_idx] > marks[j]:
                min_idx = j

        marks[i], marks[min_idx] = marks[min_idx], marks[i]

    print("Marks of students after performing Selection Sort on the list : ")
    for i in range(len(marks)):
        print(marks[i])

def Bubble_Sort(marks):
    n = len(marks)
    
    for i in range(n - 1):
       
        for j in range(0, n - i - 1):
            if marks[j] > marks[j + 1]:
                marks[j], marks[j + 1] = marks[j + 1], marks[j]

    print("Marks of students after performing Bubble Sort on the list :")
    for i in range(len(marks)):
        print(marks[i])

def top_five_marks(marks):
    print("Top",len(marks),"Marks are : ")
    print(*marks[::-1], sep="\n")


marks=[]
n = int(input("Enter number of students : "))

for i in range(0, n):
    ele = int(input("Enter marks of students "+str(i+1) + " : "))
    marks.append(ele)  

print("The marks of",n,"students are : ")
print(marks)

flag=1;
while flag==1:
    print("\n---------------MENU---------------")
    print("1. Selection Sort of the marks")
    print("2. Bubble Sort of the marks")
    print("3. Exit")
    ch=int(input("Enter your choice (from 1 to 3) : "))

    if ch==1:
        Selection_Sort(marks)
        a=input("Do you want to display top marks from the list (yes/no) : ")
        if a=='yes':
            top_five_marks(marks)
        else:
            print("\nThanks for using this program!")
            flag=0

    elif ch==2:
        Bubble_Sort(marks)
        a = input("Do you want to display top five marks from the list (yes/no) : ")
        if a == 'yes':
            top_five_marks(marks)
            flag=0
        else:
            print("Thanks for using this program!")
            flag = 0

    elif ch==3:
        print("Thanks for using this program!!")
        flag=0

    else:
        print("Enter a valid choice!!")
        print("Thanks for using this program!!")
        flag=0



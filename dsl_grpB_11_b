"""
b) Write a python program to store roll numbers of student array who attended training program in sorted order. 
Write function for searching whether particular student attended training program or not, 
using Binary search and Fibonacci search
"""
def menu():
    print("Enter 1 for Iterative Binary search\nEnter 2 for left-to-right Fibonacci search\n")
menu()
list_of_roll = []
strength = int(input("Enter the strength of the class - "))

def getroll(size):
    array = []
    assign = 0
    while assign < size:
        roll_no = int(input("Enter roll numbers of students - "))
        if roll_no in array:
            print("Roll no already in list\n------------------------------------------")
            size += 1
        else:
            array.append(roll_no)
        assign += 1
    return array


def bubble_sort(sorted_array):
    for compare in range(0,len(sorted_array),1):
        for iter in range(compare+1,len(sorted_array),1):
            if sorted_array[compare] > sorted_array[iter]:
                sorted_array[compare],sorted_array[iter] = sorted_array[iter],sorted_array[compare]
    return sorted_array



def fibonacchi_search(fib_array, records, target):
    fib_n2 = 0
    fib_n1 = 1
    fib_n = fib_n1 + fib_n2

    while fib_n < records:
        fib_n2 = fib_n1
        fib_n1 = fib_n
        fib_n = fib_n1 + fib_n2

    offset = -1
    index = min(fib_n2 + offset, records - 1)
    if fib_n == 1:
        return records - 1
    while fib_n != 1:
        if fib_array[index] < target:
            offset = index
            fib_n = fib_n1
            fib_n1 = fib_n2
            fib_n2 = fib_n - fib_n1
            index = min(fib_n2 + offset, records - 1)


        elif fib_array[index] > target:
            fib_n = fib_n2
            fib_n1 = fib_n1 - fib_n2
            fib_n2 = fib_n - fib_n1
            index = min(fib_n2 + offset, records - 1)
        if index<(records-1) and fib_array[records-1]:
            return records - 1

        else:
            return index


    else:
        return -1


def binary_search(bin_array,start_pos,end_pos,target):

    while start_pos<=end_pos:
        index = start_pos + (end_pos - start_pos) // 2

        if bin_array[index] == target:
            return index
        elif bin_array[index] < target:
            start_pos = index + 1
        else:
            end_pos = index - 1
    return -1

list_of_roll = getroll(strength)
sorted_list = bubble_sort(list_of_roll)
print(sorted_list)
key = int(input("Enter the roll no. to be searched -  "))

menu()
choice = int(input("Enter choice - "))
while choice not in (1, 2, 3, 4):
    print("Pls enter appropriate choice - \n")
    choice = int(input("Enter choice - "))
check = True
while check:
    if choice == 1:
        search_result = binary_search(sorted_list,0,strength - 1, key)
        if search_result == -1:
            print("Key isn't present.")
        else:
            print("Key present at", search_result+1, "location of the list of roll numbers.")

    

    elif choice == 2:
        search_result =fibonacchi_search(sorted_list,strength, key)
        if search_result == -1:
            print("Key isn't present.")
        else:
            print("Key present at", search_result+1,"location of the list of roll numbers.")

    

    to_continue = input("Want to continue?\nyes or no - ")
    while (to_continue.lower() not in ("yes", "no")):
        print("ENTER ONLY YES OR NO\n")
        to_continue = input("Want to continue?\nyes or no - ")

    if to_continue.lower() == "no":
        print("\nThnx for using our program.")
        check = False
    else:
        choice = int(input("Enter choice - "))
        while choice not in (1, 2, 3, 4):
            print("Pls enter appropriate choice - \n")
            choice = int(input("Enter choice - "))

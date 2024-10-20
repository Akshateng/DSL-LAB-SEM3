'''
Experiment No. 16 : Write a python program to store first year percentage of students in array.
                    Write function for sorting array of floating point numbers in ascending order using
                    quick sort and display top five scores.
'''

def per_partition(perc, start, end):
    pivot = perc[start]
    lower_bound = start + 1
    upper_bound = end
    
    while True:
        while lower_bound <= upper_bound and perc[lower_bound] <= pivot:
            lower_bound += 1
        while lower_bound <= upper_bound and perc[upper_bound] >= pivot:
            upper_bound -= 1
        if lower_bound <= upper_bound:
            perc[lower_bound], perc[upper_bound] = perc[upper_bound], perc[lower_bound]
        else:
            break
            
    perc[start], perc[upper_bound] = perc[upper_bound], perc[start]
    return upper_bound

def quick_sort(perc, start, end):
    if start < end:  # Fix condition to prevent infinite recursion
        partition = per_partition(perc, start, end)
        quick_sort(perc, start, partition - 1)
        quick_sort(perc, partition + 1, end)

def display_top(perc):
    print("Top five percentages are: ")
    top_percentages = sorted(perc, reverse=True)[:5]  # Get top 5 percentages
    for percentage in top_percentages:
        print(percentage)

# Main Program
percen = []
x = int(input("Enter the number of students: "))
for i in range(x):
    ele = int(input(f"Enter the percentage of student {i + 1}: "))
    percen.append(ele)

print(percen)

flag = True
while flag:
    print("\n----MENU----")
    print("1. Perform Quick Sort of the Data")
    print("2. Display Top 5 Percentages of the students")
    print("3. Exit")
    
    ch = int(input("Enter the choice from 1 to 3: "))
    
    if ch == 1:
        quick_sort(percen, 0, len(percen) - 1)
        print("Sorted Percentages: ", percen)
        
    elif ch == 2:
        display_top(percen)
        
    elif ch == 3:
        print("Thank you for using the program.")
        flag = False
    
    else:
        print("Invalid choice. Please try again.")

'''
Experiment No. 16 : Write a python program to store first year percentage of students in array.
                    Write function for sorting array of floating point numbers in ascending order using
                    quick sort and display top five scores.
'''

def per_partition(perc,start,end):
	pivot = perc[start]
	lower_bound = start +1
	upper_bound = end
	
	while True:
		while lower_bound <= upper_bound and perc[lower_bound] <= pivot:
			lower_bound +=1
			
		while lower_bound <= upper_bound and perc[lower_bound] >= pivot:
			upper_bound -= 1
		
		if lower_bound <= upper_bound:
			perc[lower_bound],perc[upper_bound] = perc[upper_bound],perc[lower_bound]
		else:
			break
	perc[start],perc[upper_bound] = perc[upper_bound],perc[start]
	return upper_bound
	
def quick_sort(perc,start,end):
	while start <= end:
		partition = per_partition(perc,start,end)
		quick_sort(perc,start,partition-1)
		quick_sort(perc,partition+1,end)
		return perc

def display_top_five(perc):
	print("Top five percentages are : ")
	if len(perc) < 5:
		start,stop = len(perc) -1,-1
	else:
		start,stop = len(perc) -1,len(perc)-6
	for i in range(start,stop,-1):
		print(perc[i],sep = "\n")

perc = []
x = int(input("Enter the number of students: "))
for i in range(0,x):
	ele = int(input("Enter the Percentages of the students " +str(i+1) + " : "))
	perc.append(ele)

print(perc)

flag = 1
while flag == 1:
	print("\n----MENU----")
	print("1.Perform Quick Sort of the Data")
	print("2.Display Top 5 Percentages of the students")
	print("3.Exit")
	
	ch = int(input("Enter the choice from 1 to 3 : "))
	
	if ch == 1:
		quick_sort(perc,0,len(perc)-1)
		print("Sorted Percentage of the students after Selection Sort are: ",perc)
		
		b=input("Do you want to continue(yes/no): ")
		if b == "yes":
			flag=1
		else:
			print("Thank you for using the program ")
			flag = 0
	if ch == 2:
		display_top_five(perc)
		b=input("Do you want to continue(yes/no): ")
		if b == "yes":
			flag=1
		else:
			print("Thank you for using the program ")
			flag = 0
	if ch == 3:
		print("Thank you for using the program")
		flag = 0
	

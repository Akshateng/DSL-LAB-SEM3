'''Write a Python program to store marks scored in subject “Fundamental of Data 
Structure” by N students in the class. Write functions to compute following:
a) The average score of class 
b) Highest score and lowest score of class 
c) Count of students who were absent for the test
d) Display mark with highest frequency
'''

def menu():
	n = int(input("Enter number of students in the class: "))
	marks = []
	for i in range(n):
		a = int(input("Enter the marks of student" + str(i+1) + "(Enter -999 if absent):"))
		marks.append(a)
	flag = 1
	while flag == 1:
		print("\n\n---MENU---\n")
		print("1.Total and Average Marks of the class")
		print("2.Highest and Lowest Marks in the class")
		print("3.Number of student absent for the test")
		print("4.Marks with highest frequency")
		print("5.Exit\n")
		
		ch = int(input("Enter the choice from 1 to 5"))
		if ch == 1:
			average(marks)
			b = input("Do you want to continue(Yes/No):")
			if b == "Yes":
				flag = 1
			else:
				flag = 0
				print("Thanks for using the program")
		elif ch == 2:
			maximum(marks)
			minimum(marks)
			b = input("Do you want to continue(Yes/No):")
			if b == "Yes":
				flag = 1
			else:
				flag = 0
				print("Thanks for using the program")
		elif ch == 3:
			absentcount(marks)
			b = input("Do you want to continue(Yes/No):")
			if b == "Yes":
				flag = 1
			else:
				flag = 0
				print("Thanks for using the program")
		elif ch == 4:
			highestfreq(marks)
			b = input("Do you want to continue(Yes/No):")
			if b == "Yes":
				flag = 1
			else:
				flag = 0
				print("Thanks for using the program")
		else:
			Exit

def average(marks):
	Sum = 0 
	count = 0
	for i in range(len(marks)):
		if marks[i] != -999:
			Sum += marks[i]
			count +=1
	avg = Sum/count
	print("Average of the score is: ", avg)

def maximum(marks):
	for i in range(len(marks)):
		if marks[i] != -999:
			Max = marks[0]
			break
	for i in range(1,len(marks)):
		if marks[i]>Max:
			Max = marks[i]
	print("Maximum marks: ", Max)

def minimum(marks):
	for i in range(len(marks)):
		if marks[i] != -999:
			Min = marks[0]
			break
	for i in range(1,len(marks)):
		if marks[i]<Min:
			Min = marks[i]
	print("Minimum marks: ", Min)

def absentcount(marks):
	count = 0 
	for i in range(len(marks)):
		if marks[i] == -999:
			count += 1
	print("Number of student absent for the test: ", count)

def highestfreq(marks):
	Max = 0
	h = 0
	count = 1
	for i in range(0, len(marks), 1):
		for j in range(i+1, len(marks),1):
			if marks[i] == marks[j]:
				count = count + 1
			if count > Max:
				Max = count
				h = marks[i]
		count = 1
	print("Highest frequency marks: ", h, "Frequency: ", Max)


menu()


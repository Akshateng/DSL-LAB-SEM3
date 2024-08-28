'''Write a Python program to compute following operations on String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in the string
c) To check whether given string is palindrome or not 
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string'''
def menu():
    senten= str(input("Enter the string : "))
    flag = 1
    while flag ==1 :
        print("\n\n---MENU---\n")
        print("1. To display word with longest length.")
        print("2. To determines the frequency of occurrence of particular character in the string.")
        print("3. To check whether given string is palindrome or not.")
        print("4. To display index of first appearance of the substring.")
        print("5. To count the occurrences of each word in a given string.")
        print("6. Exit ")
        
        ch = int(input("Enter the choice from 1 to 6  "))
        if ch == 1:
            longest(senten)
            b = input("Do you want to continue(Yes/No):  ")
            if b == "Yes":
                flag = 1
            else:
                flag = 0
                print("Thank you for using the program")
        
        elif ch == 2:
            character(senten)
            b = input("Do you want to continue(Yes/No): ")
            if b == "Yes":
                flag = 1
            else:
                flag = 0
                print("Thank you for using the program")
         
        elif ch == 3:
            palindrome(senten)
            b = input("Do you want to continue(Yes/No): ")
            if b == "Yes":
                flag = 1
            else:
                flag = 0
                print("Thank you for using the program")
         
        elif ch == 4:
            firstindex(senten)
            b = input("Do you want to continue(Yes/No): ")
            if b == "Yes":
                flag = 1
            else:
                flag = 0
                print("Thank you for using the program")
        
        elif ch == 5:
            countwords(senten)
            b = input("Do you want to continue(Yes/No): ")
            if b == "Yes":
                flag = 1
            else:
                flag = 0
                print("Thank you for using the program")
         
        elif ch == 6:
            flag = 0
            print("Thank you for using the program")
        
        else:
            print("Enter valid number....")       

def longest(senten):
	words = senten.split()
	longest_word = ""
	
	for s in words:
		if len(s) > len(longest_word):
			longest_word = s
	
	print("Longest word in the string is : ", longest_word)

def character(senten):
	count = 0
	u = input("Occurance of the character : ")
	for x in senten:
		if x == u:
			count +=1
	print("Occurance of the character ", u, "is: ", count)

def firstindex(senten):
	substring = input("Enter the substring : ")
	n=len(senten)
	m=len(substring)
	
	for i in range (n-m+1):
		match = True
		for j in range(m):
			if senten[i+j] != substring[j]:
				match = False
				break
		if match:
			print("Index of the substring is :",i)
			return i
	return -1



def palindrome(senten):
	c = senten[::-1]
	if senten == c :
		print("Yes, This is a palindrome")
	else:
		print("No, This is not a palindrome")
		

def countwords(senten):
	word_count ={}
	current_word = ""
	
	for char in senten + ' ' :
		if char != ' ' :
			current_word += char.lower()
		else:
			if current_word in word_count:
				word_count[current_word] += 1
			else:
				word_count[current_word] = 1
			current_word = ""
	
	print("Occurances of the words are : ", word_count)
		
menu() 

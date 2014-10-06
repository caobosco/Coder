from random import randint

def shuffle(num):
	print(num)
	print(len(num))
	for i in range(0, len(num)):
		ind = randint(0, i)
		tmp = num[i]
		num[ind], num[i] = tmp, num[ind]

if __name__ == "__main__":
	num = [i for i in range(0, 52)]
	shuffle(num)
	print(num)

	

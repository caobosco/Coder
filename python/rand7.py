import random

def rand5():
	return random.randint(0,4)

def rand7():
	while 1:
		tmp = rand5()*5 + rand5()
		if tmp < 22:
			return tmp%7

if __name__=="__main__":
	print(rand7())

	

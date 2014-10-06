def add(curSum, carry):
	tmp = curSum^carry
	carry = curSum&carry
	if carry == 0:
		return tmp
	else:
		return add(tmp, carry)
if __name__ == "__main__":
	x = int(input("x: "))
	y = int(input("y: "))
	print(add(x, y))


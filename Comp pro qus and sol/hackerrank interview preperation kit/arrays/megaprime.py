# Python program to print all primes smaller than or equal to 
# n using Sieve of Eratosthenes 

def SieveOfEratosthenes(a, n): 
	
	# Create a boolean array "prime[0..n]" and initialize 
	# all entries it as true. A value in prime[i] will 
	# finally be false if i is Not a prime, else true. 
	prime = [True for i in range(n+1)] 
	pRange = []
	p = 2
	while (p * p <= n): 
		
		# If prime[p] is not changed, then it is a prime 
		if (prime[p] == True): 
			
			# Update all multiples of p 
			for i in range(p * p, n+1, p): 
				prime[i] = False
		p += 1
	
	# Print all prime numbers 
	for p in range(a, n+1): 
		if prime[p]: 
			pRange.append(str(p))
	return pRange


# def approach2(start, end):
# 	base = [2, 3, 5, 7]


def chkPrime(digit):
	base = [ '2', '3', '5', '7' ]
	if(digit in base):
		return True
	return False

if __name__=='__main__': 
	start = int(input())
	endi = int(input())
	pRange = SieveOfEratosthenes(start, endi) 
	count = 0
	# base = [2, 3, 5, 7]
	# print(pRange)
	for i in pRange:
		flag = False
		for j in i:
			isPrime = chkPrime(j)
			if(isPrime == False):
				flag = True
				break
		if(flag == False):
			count += 1
	print(count)


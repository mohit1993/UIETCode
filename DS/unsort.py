import random
import sys

def main():
	f = open("input.txt","w")
	l = [i for i in range(1,int(sys.argv[1])+1)]
	random.shuffle(l)
	for x in l:
		f.write("%d\n" % x)
	f.close()

if __name__ == "__main__":
	main()

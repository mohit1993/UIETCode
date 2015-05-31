import os
import sys
import random
import math

def main():
	len = int(sys.argv[1])
	l = [i for i in range(1,len+1)]
	iter = 0

	while iter != 20000:
		try:
			f = open("input","w")
			random.shuffle(l)
			f.writelines(["%d\n" % i for i in l])
			f.close()
			os.system("gcc heapsort.c;./a.out < input > h.txt")
			os.system("gcc quicksort.c;./a.out < input > q.txt")
			os.system("gcc mergesort.c;./a.out < input > m.txt")

			f = open("h.txt","r")
			data = f.read()
			data = float(data)	
			f.close()
			f = open("heap.txt","a")
			f.writelines("%f\n" % data)
			f.close()

			f = open("q.txt","r")
			data = f.read()
			data = float(data)
			f.close()
			f = open("quick.txt","a")
			f.writelines("%f\n" % data)
			f.close()

			f = open("m.txt","r")
			data = f.read()
			data = float(data)
			f.close()
			f = open("merge.txt","a")
			f.writelines("%f\n" % data)
			f.close()
			os.system("rm -f h.txt q.txt m.txt")
			iter = iter + 1
			ans = iter/ls200
			print "Completed  %d" % ans + '%....\033[1A'

		except StopIteration:
			break

if __name__ == "__main__":
	main()
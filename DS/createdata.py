def main():
	file = open("SortResult.txt","a")
	res = ['quick.txt','merge.txt','heap.txt']
	for t in res:
		f = open(t,"r")
		text = f.read()
		l = text.split('\n')
		l.remove('')
		l = [int(float(i)) for i in l]
		ans = sum(l)/20000
		data = t.replace('.txt',' Sort')
		data = data.title()
		file.writelines("%s = %fms\n" %(str(data),ans))
		f.close()
	file.close()

if __name__ == "__main__":
	main()
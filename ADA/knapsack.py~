from __future__ import division

def ratioSelection(data = [],n=0,M=0):
	for i in range(n):
		if M < data[i][1]:
			data[i][2] = M/data[i][1]
			break
		else:
			data[i][2] = 1
			M = M - data[i][1]
	return data

def calculateProfit(data,n):
	profit = 0.0
	for i in range(n):
		profit = profit + data[i][0]*data[i][2]

	return profit

def display(data = [],n=0):	
	print "\nItem:   ",
	for i in range(n):
		print '{:6d}'.format(data[i][3]),

	print "\nProfit: ",
	for i in range(n):
		print '{:6d}'.format(data[i][0]),

	print "\nWeight: ",
	for i in range(n):
		print '{:6d}'.format(data[i][1]),


	print "\nFraction:  ",
	for i in range(n):
		print '{:6s}'.format('{:1.2f}'.format(data[i][2])),

	print "\n"

def main():
	print "Enter weight of knapsack"
	M = int(raw_input())
	
	print "No. of terms: "
	n = int(raw_input())

	profits = {'byProfitWeightRatio' : 0.0,'byWeight': 0.0,'byProfit': 0.0}

	print "Enter profits "
	profit = [int(raw_input()) for i in range(n)]

	print "Enter weights "
	weight = [int(raw_input()) for i in range(n)]

	data = [[p,w,0,i] for p,w,i in zip(profit,weight,range(n))]
	""" sorting data by profit weight ratio"""
	data = sorted(data,key = lambda x: x[0]/x[1],reverse =True)
	
	datapw = ratioSelection(data,n,M)
	profits['byProfitWeightRatio'] = calculateProfit(datapw,n)

	data = [[x[0],x[1],0,x[3]] for x in data]
	""" sorting data by profit"""
	data = sorted(data,key = lambda x: x[0],reverse = True)

	datap = ratioSelection(data,n,M)
	profits['byProfit'] = calculateProfit(datap,n)

	data = [[x[0],x[1],0,x[3]] for x in data]
	""" sorting data by weight"""
	data = sorted(data,key = lambda x: x[1],reverse = True)
	
	dataw = ratioSelection(data,n,M)
	profits['byWeight'] = calculateProfit(dataw,n)

	display(dataw,n)
	print "\nTotal profit by weight: %2.2f" %(profits['byWeight'])
	display(datap,n)
	print "\nTotal profit by profit: %2.2f" %(profits['byProfit'])
	display(datapw,n)
	print "\nTotal profit by profit:weight ratio: %2.2f" %(profits['byProfitWeightRatio'])

if __name__ == "__main__":
	main()

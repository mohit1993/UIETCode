#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void sortList(int *weight,int *profit,int n,int type){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(type == 0 && weight[j] < weight[j+1]){
				weight[j] = weight[j] + weight[j+1] - (weight[j+1] = weight[j]);
				profit[j] = profit[j] + profit[j+1] - (profit[j+1] = profit[j]);
			}

			else if(type ==1 && profit[j] < profit[j+1]){
				weight[j] = weight[j] + weight[j+1] - (weight[j+1] = weight[j]);
				profit[j] = profit[j] + profit[j+1] - (profit[j+1] = profit[j]);
			}
	
			else if(type == 2 && (float(profit[j])/weight[j]) < (float(profit[j+1])/weight[j+1])){
				weight[j] = weight[j] + weight[j+1] - (weight[j+1] = weight[j]);
				profit[j] = profit[j] + profit[j+1] - (profit[j+1] = profit[j]);
			}

			else continue;
		}
	}
}

void knapsack(float *res,int *weight,int *profit,int n,int max){
	int count=0;
	while(max > 0 && count < n){
		if((max - weight[count]) > 0){
			res[count] = 1.0;
			max = max - weight[count];
			count++;
		}
		else break;
	}
	if(max > 0 && count < n){
		res[count] = float(max)/weight[count];
	}
	for(int x = count+1;x<n;x++){
		res[x] = 0;
	}
}

void showresult(float *res,int *weight,int *profit,int n,int type){
	//cout<<setw(5)<<setprecision(2);
	cout<<left;
	cout<<setw(20)<<"\nITEM";
	for(int i=0;i<n;i++){
		cout<<setw(8)<<i+1;
	}
	cout<<"\n"<<setw(70)<<right<<setfill('-')<<" ";
	cout<<setfill(' ')<<left;
	cout<<setw(20)<<"\nWeight";
	for(int i=0;i<n;i++){
		cout<<setw(8)<<weight[i];
	}
	cout<<setw(20)<<"\nProfit";
	for(int i=0;i<n;i++){
		cout<<setw(8)<<profit[i];
	}
	if(type == 2){
		cout<<setw(20)<<"\nProfit/Weight";
		for(int i=0;i<n;i++){
			cout<<setw(8)<<setprecision(2)<<float(profit[i])/weight[i];
		}
	}
	float totalprofit = 0;
	cout<<setw(20)<<"\nRatio";
	for(int i=0;i<n;i++){
		cout<<setw(8)<<setprecision(2)<<res[i];
		totalprofit = totalprofit + res[i]*profit[i];
	}
	cout<<"\n\nTotal Profit is "<<totalprofit;
}

int main(){
	int *weight,*profit,n=0,max;
	float **result;
	result = new float* [3];		
	
	cout<<"\nEnter No. of items: ";
	cin>>n;
	for(int i=0;i<3;i++){
		result[i] = new float[n];
	}
	weight = new int[n];
	profit = new int[n];
	
	for(int i=0;i<n;i++){
		cout<<"\nEnter weight of the item "<<i+1<<": ";
		cin>>weight[i];
		cout<<"\nEnter profit of the item "<<i+1<<": ";
		cin>>profit[i];
	}
	cout<<"\nEnter the maximum weight of the sack: ";
	cin>>max;

	string data[3];
	data[0] = "Knapsack Solution sorted by Weight";
	data[1] = "Knapsack Solution sorted by Profit";
	data[2] = "Knapsack Solution sorted by Profit/Weight";

	for(int i=0;i<3;i++){
		sortList(weight,profit,n,i);
		knapsack(result[i],weight,profit,n,max);
		cout<<"\n\n\n"<<data[i]<<"\n";
		showresult(result[i],weight,profit,n,i);
	}

	cout<<endl<<endl;
	return 0;
}
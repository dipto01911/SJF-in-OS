#include<iostream>
using namespace std;
int At[20],Bt[20],Ct[20],Tat[20],Wt[20],order[20];
int main(){
	int i,j,n,id;
	float avwt=0,avtt=0;
	cout<<"enter the number of process"<<endl;
	cin>>n;
	for(i=1;i<=n;i++){
		printf("Enter the process p%d burst time and\n",i);
		cin>>Bt[i];
		order[i]=i;
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(Bt[order[i]]>Bt[order[j]]){
				swap(order[i],order[j]);
			}
		}
	}
	for(i=1;i<=n;i++){
		Ct[order[i]]=Ct[order[i-1]]+Bt[order[i]];
	}
	
	for(i=1;i<=n;i++){
		 id=order[i];
		Tat[id]=Ct[id];
		Wt[id]=Tat[id]-Bt[id];
		avtt=avtt+Tat[id];
		avwt=avwt+Wt[id];
	}
	printf("p_id.....Burst......Turnaround.....waiting\n");
	for(i=1;i<=n;i++){
		id=order[i];
		printf("P%d\t\t%d\t\t%d\t\t%d\t\t\n",id,Bt[id],Tat[id],Wt[id]);
	}
	cout<<"avrage turnaround time"<<avtt/n<<endl;
	cout<<"average waiting time"<<avwt/n<<endl;
	return 0;
}




















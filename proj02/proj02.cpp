/*
Zehua Li
lizehua3@bulldog
section:003
2016-09-13
project 02
proj02.cpp

Your Comments
caculate how many time in each series need to run in order to get the epsilon that user provide
out put the result of each series and the times each series ran in the process
to check the input epsilon
if the epsilon is 0 then just stop and program and out put 0 for each series
*/

#include <iostream>
using std::cout; using std::endl;using std::cin; using std::fixed;
#include <iomanip>
using std::setprecision;
#include <cmath>
using std::abs;

int main(){
	double epsilon,new_gl=10,new_n=10,old_gl=0,old_n=0,series_gl,series_n;
	long first_time_gl=0,first_time_n=0,n_gl=0,count_gl=0,count_n=0,n_n=0;
	cin>>epsilon;
//check if the epsilon is 0, then the result of each series is 0 and program end
	if (epsilon==0){
		new_gl-=10;
		new_n-=10;
		cout<<fixed<<setprecision(12)<<new_gl<<" "<<count_gl<<endl;
		cout<<fixed<<setprecision(12)<<new_n<<" "<<count_n<<endl;
	}
	//if the epsilon is not 0, then caculate how many times does each series have to run in order to with in epsilon
	else{
		//caculate Gregory-Leibniz series
		while(abs(new_gl-old_gl)>epsilon){
			//after get the first number of the series and then continue the rest of the caculation until find the epsilon
			if (first_time_gl>0){
				old_gl=new_gl;
				series_gl=(new_gl/4)+((pow(-1,n_gl))/(2*n_gl+1));
				new_gl=4*series_gl;
				count_gl++;
				n_gl++;
			}
			//caculate the first number of the series, and then go back to the top of the while loop and keep continue to caculate the rest of the caculation
			else{
				series_gl=((pow(-1,n_gl))/(2*n_gl+1));
				n_gl++;
				new_gl=4*series_gl;
				count_gl++;
				first_time_gl++;
			}
		}
		cout<<fixed<<setprecision(12)<<new_gl<<" "<<count_gl<<endl;
		//caculate Nilakantha series
		while(abs(new_n-old_n)>epsilon){
			//after get the first number of the series and then continue the rest of the caculation until find the epsilon
			if (first_time_n>0){
				old_n=new_n;
				series_n=((new_n-3)/4)+(pow(-1,n_n))/((2*n_n+2)*(2*n_n+3)*(2*n_n+4));
				new_n=3+4*series_n;
				count_n++;
				n_n++;
			}
			//caculate the first number of the series, and then go back to the top of the while loop and keep continue to caculate the rest of the caculation
			else{
				series_n=(pow(-1,n_n))/((2*n_n+2)*(2*n_n+3)*(2*n_n+4));
				n_n++;
				new_n=3+4*series_n;
				count_n++;
				first_time_n++;
			}
		}
		cout<<fixed<<setprecision(12)<<new_n<<" "<<count_n<<endl;
	}
	return 0;
}

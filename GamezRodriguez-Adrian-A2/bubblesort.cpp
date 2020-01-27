#include <iostream>

int main(){
	
	vector <int> vec = {4,5,8,6,7,2,0,5,9,4};
	for (int i=0;i<vec.size()-1:++i)
	{
		for(int j =0;j<vec.size()-i;++j)
		{
			if(vec[j]>vec[j+1]
			{
				temp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = vec[i];
			}
		}
		
	}
}
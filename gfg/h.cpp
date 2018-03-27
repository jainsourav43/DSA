			sum1=sum1+a[i];
			min1=min(min1,a[i]);		
			if(sum1>msum)
			{
		//		min1=min(min1,a[i]);
				count++;
				if(msum<sum1)
				msum=sum1;
				if(msum-min1>msum&&count>1)
				{
					count--;
					msum=msum-min1;
				}
			
			}
			else if(sum1-min1>msum)
			{
				count--;
				msum=sum1-min1;
			}
			if(sum1<0)
			{
				sum1=0;
				min1=INT_MAX;
				count=0;
			}

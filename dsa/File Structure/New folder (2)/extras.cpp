i=0;
		if(c%2==0)
		{
		while(a[0]!=-1&&b[0]!=-1)
		{
		count1=0;	
		fout1>>a[0];
		if(a[0]!=-1)
		{
			count1++;
		}
		for(i=1;i<3&&a[i-1]!=-1;i++)
		{
			fout1>>a[i];
			count1++;
		}
		count2=0;
		fout2>>b[0];
		if(b[0]!=-1)
		count2++;
		for(i=1;i<3&&b[i-1]!=-1;i++)
		{
			fout2>>b[i];
			count2++;
		}
		i=0;j=0;
		count3=count1;
		count4=count2;
		while(i<count1&&j<count2)
		{
			if(a[i]<b[j])
			{
				fout3<<a[i]<<" ";
				i++;
				count3--;	
			}
			else 
			{
				fout3<<b[j]<<" ";
				j++;
				count4--;
			}
		}
		if(count3==0)
		{
			fout1>>a[0];
			if(a[0]!=-1)
			{
				for(i=1;i<3;i++)
				{
					fout1>>a[i];
				}
			}
		}
		else  if(count4==0)
		{
			fout2>>b[0];
			if(b[0]!=-1)
			{
				for(i=1;i<3;i++)
				{
					fout1>>b[i];
				}
			}
		}
		else
		{
		while(i<count1)
		{
			fout3<<a[i]<<" ";
			i++;
		}
		while(j<count2)
		{
			fout3<<b[i]<<" ";
			j++;
		}
	    }
		}
		}
		else
		{
				while(1)
		{
		count1=0;	
		fout1>>a[0];
		if(a[0]!=-1)
		{
			count1++;
		}
		for(i=1;i<3&&a[i-1]!=-1;i++)
		{
			fout1>>a[i];
			count1++;
		}
		count2=0;
		fout2>>b[0];
		if(b[0]!=-1)
		count2++;
		for(i=1;i<3&&b[i-1]!=-1;i++)
		{
			fout2>>b[i];
			count2++;
		}
		i=0;j=0;
		count3=count1;
		count4=count2;
		while(i<count1&&j<count2)
		{
			if(a[i]<b[j])
			{
				fout4<<a[i]<<" ";
				i++;
				count3--;	
			}
			else 
			{
				fout4<<b[j]<<" ";
				j++;
				count4--;
			}
		}
		if(count3==0)
		{
			fout1>>a[0];
			if(a[0]!=-1)
			{
				for(i=1;i<3;i++)
				{
					fout1>>a[i];
				}
			}
		}
		else  if(count4==0)
		{
			fout2>>b[0];
			if(b[0]!=-1)
			{
				for(i=1;i<3;i++)
				{
					fout2>>b[i];
				}
			}
		}
		else
		{
		while(i<count1)
		{
			fout4<<a[i]<<" ";
			i++;
		}
		while(j<count2)
		{
			fout4<<b[i]<<" ";
			j++;
		}
	    }
		}
		}

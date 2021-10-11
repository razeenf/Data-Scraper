#include <stdio.h>

int main()
{
	
	
	double sup[365], mich[365], hur[365], erie[365], ont[365], stclr[365]; 
	double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0, avg[6];
	int i, year, day[365]; 
	
	FILE*fp = fopen("lakes.txt", "r");
	
	for(i = 0; i < 365; i++){
		fscanf(fp, "%d %d %lf %lf %lf %lf %lf %lf", &year, &day[i], &sup[i], &mich[i], &hur[i], &erie[i], &ont[i], &stclr[i]);
		
		sum1 += sup[i];  
		sum2 += mich[i]; 
		sum3 += hur[i]; 
		sum4 += erie[i]; 
		sum5 += ont[i]; 
		sum6 += stclr[i];
			
	}
	
	fclose(fp);
	
	avg[0] = sum1/365;
	avg[1] = sum2/365; 
	avg[2] = sum3/365; 
	avg[3] = sum4/365; 
	avg[4] = sum5/365; 
	avg[5] = sum6/365; 
	
	printf("\t\tAverage Lake Temps\n");
	printf("Sup \t Mich \t Hur \t Erie \t Ont \t Stclr \n"); 
	printf("%.2lf \t %.2lf \t %.2lf \t %.2lf \t %.2lf \t %.2lf \n", avg[0], avg[1], avg[2], avg[3], avg[4], avg[5]);
	
	double ovr_avg; 

	ovr_avg = (avg[0] + avg[1] + avg[2] + avg[3] + avg[4] + avg[5])/6; 
	
	
	printf("\nYearly average of all 6 Lakes: %.2lf \n", ovr_avg);
	
	//2
	
	int n, wt = 0, ct = 0;
	double ht = 6, lt = 6; 
	char *lake[6] = {"Superior", "Michigan", "Huron", "Erie", "Ontario", "St. Clair"};

	
	
	for(n = 0; n < 6; n++){
	
		if(avg[n]<lt){
			lt = avg[n];
			ct++;
		}
		if(avg[n]>ht){
			ht = avg[n];
			wt++;
		} 	
		
		if(avg[n]<ovr_avg){
			printf("Below Overall Lake Avg: %s \n", lake[n]); 
		}
		if(avg[n]>ovr_avg){
			printf("Above Overall Lake Avg: %s \n", lake[n]); 
		
		}	
	
	}
	
	printf("\nCoolest Lake: %s \n", lake[ct]);
	printf("Warmest Lake: %s \n", lake[wt]);
	
	
	//3. 
	
	int j, coolest_day_sup, coolest_day_mich, coolest_day_hur, coolest_day_erie, coolest_day_ont, coolest_day_stclr;
	int warmest_day_sup, warmest_day_mich, warmest_day_hur, warmest_day_erie, warmest_day_ont, warmest_day_stclr; 
	float  coolest_temp_sup = 25.0, coolest_temp_mich = 25.0, coolest_temp_hur = 25.0, coolest_temp_erie = 25.0, coolest_temp_ont = 25.0, coolest_temp_stclr = 25.0; 
	float  warmest_temp_sup = 0.0,  warmest_temp_mich = 0.0,  warmest_temp_hur = 0.0,  warmest_temp_erie= 0.0,  warmest_temp_ont = 0.0,  warmest_temp_stclr = 0.0;
	
	for(j=1; j<365; j++){	
		if(sup[j]<coolest_temp_sup){
			coolest_temp_sup = sup[j];
			coolest_day_sup = day[j];
		}
		if(sup[j]>warmest_temp_sup){
			warmest_temp_sup = sup[j];
			warmest_day_sup = day[j];	
		}
	//
		if(mich[j]<coolest_temp_mich){
			coolest_temp_mich = mich[j];
			coolest_day_mich = day[j];
		}
		if(mich[j]>warmest_temp_mich){
			warmest_temp_mich = mich[j];
			warmest_day_mich = day[j];	
		}
	//	
		if(hur[j]<coolest_temp_hur){
			coolest_temp_hur = hur[j];
			coolest_day_hur = day[j];
		}
		if(hur[j]>warmest_temp_hur){
			warmest_temp_hur = hur[j];
			warmest_day_hur = day[j];	
		}
	//	
		if(erie[j]<coolest_temp_erie){
			coolest_temp_erie = erie[j];
			coolest_day_erie = day[j];
		}
		if(erie[j]>warmest_temp_erie){
			warmest_temp_erie = erie[j];
			warmest_day_erie = day[j];	
		}
	//
		if(ont[j]<coolest_temp_ont){
			coolest_temp_ont = ont[j];
			coolest_day_ont = day[j];
		}
		if(ont[j]>warmest_temp_ont){
			warmest_temp_ont = ont[j];
			warmest_day_ont = day[j];	
		}
	//
		if(stclr[j]<coolest_temp_stclr){
			coolest_temp_stclr = stclr[j];
			coolest_day_stclr = day[j];
		}
		if(stclr[j]>warmest_temp_stclr){
			warmest_temp_stclr = stclr[j];
			warmest_day_stclr = day[j];	
		}
	}
	
	int daymonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	int sup1 = 0, sup2 = 0, mich1 = 0, mich2 = 0, hur1 = 0, hur2 = 0, erie1 = 0, erie2 = 0, ont1 = 0, ont2 = 0, stclr1 = 0, stclr2 = 0;
	
	while(coolest_day_sup>0){
		coolest_day_sup -= daymonth[sup1];
		sup1++;
		}	
	coolest_day_sup += daymonth[sup1-1];
	
	while(warmest_day_sup>0){
		warmest_day_sup -= daymonth[sup2];
		sup2++;
		}	
	warmest_day_sup += daymonth[sup2-1];
	
	while(coolest_day_mich>0){
		coolest_day_mich -= daymonth[sup1];
		mich1++;
		}	
	coolest_day_mich += daymonth[mich1-1];
	
	while(warmest_day_mich>0){
		warmest_day_mich -= daymonth[mich2];
		mich2++;
		}	
	warmest_day_mich += daymonth[mich2-1];
	
	while(coolest_day_hur>0){
		coolest_day_hur -= daymonth[hur1];
		hur1++;
		}	
	coolest_day_hur += daymonth[hur1-1];
	
	while(warmest_day_hur>0){
		warmest_day_hur -= daymonth[hur2];
		hur2++;
		}	
	warmest_day_hur += daymonth[hur2-1];
	
	while(coolest_day_erie>0){
		coolest_day_erie -= daymonth[erie1];
		erie1++;
		}	
	coolest_day_erie += daymonth[erie1-1];
	
	while(warmest_day_erie>0){
		warmest_day_erie -= daymonth[erie2];
		erie2++;
		}	
	warmest_day_erie += daymonth[erie2-1];
	
	while(coolest_day_ont>0){
		coolest_day_ont -= daymonth[ont1];
		ont1++;
		}	
	coolest_day_ont += daymonth[ont1-1];
	
	while(warmest_day_ont>0){
		warmest_day_ont -= daymonth[ont2];
		ont2++;
		}	
	warmest_day_ont += daymonth[ont2-1];
	
	while(coolest_day_stclr>0){
		coolest_day_stclr -= daymonth[stclr1];
		stclr1++;
		}	
	coolest_day_stclr += daymonth[stclr1-1];
	
	while(warmest_day_stclr>0){
		warmest_day_stclr -= daymonth[stclr2];
		stclr2++;
		}	
	warmest_day_stclr += daymonth[stclr2-1];

	
	printf("\nLake Superior was the coldest on %d/%d with a temperature of %.2f degrees.\n", coolest_day_sup, sup1, coolest_temp_sup); 
	printf("Lake Superior was the warmest on %d/%d with a temperature of %.2f degrees.\n", warmest_day_sup, sup2, warmest_temp_sup);
	
	printf("\nLake Michigan was the coldest on %d/%d with a temperature of %.2f degrees.\n", coolest_day_mich, mich1, coolest_temp_mich); 
	printf("Lake Michigan was the warmest on %d/%d with a temperature of %.2f degrees.\n", warmest_day_mich, mich2, warmest_temp_mich);
	
	printf("\nLake Huron was the coldest on %d/%d with a temperature of %.2f degrees.\n", coolest_day_hur, hur1, coolest_temp_hur); 
	printf("Lake Huron was the warmest on %d/%d with a temperature of %.2f degrees.\n", warmest_day_hur, hur2, warmest_temp_hur);
	
	printf("\nLake Erie was the coldest on %d/%d with a temperature of %.2f degrees.\n", coolest_day_erie, erie1, coolest_temp_erie); 
	printf("Lake Erie was the warmest on %d/%d with a temperature of %.2f degrees.\n", warmest_day_erie, erie2, warmest_temp_erie);
	
	printf("\nLake Ontario was the coldest on %d/%d with a temperature of %.2f degrees.\n", coolest_day_ont, ont1, coolest_temp_ont); 
	printf("Lake Ontario was the warmest on %d/%d with a temperature of %.2f degrees.\n", warmest_day_ont, ont2, warmest_temp_ont);
	
	printf("\nLake St.Clair was the coldest on %d/%d with a temperature of %.2f degrees.\n", coolest_day_stclr, stclr1, coolest_temp_stclr); 
	printf("Lake St.Clair was the warmest on %d/%d with a temperature of %.2f degrees.\n", warmest_day_stclr, stclr2, warmest_temp_stclr);
	
	//4.
	
	double coolest_lake_temp [6], warmest_lake_temp[6]; 
	int o=0, p=0, m, mu = 10, mu2 = 0;
	int coolest_day[6], warmest_day[6], cmonth[6], wmonth[6];
	
	coolest_lake_temp[0] = coolest_temp_sup;
	coolest_lake_temp[1] = coolest_temp_mich;
	coolest_lake_temp[2] = coolest_temp_hur;
	coolest_lake_temp[3] = coolest_temp_erie;
	coolest_lake_temp[4] = coolest_temp_ont;
	coolest_lake_temp[5] = coolest_temp_stclr;
	
	warmest_lake_temp[0] = warmest_temp_sup;
	warmest_lake_temp[1] = warmest_temp_mich;
	warmest_lake_temp[2] = warmest_temp_hur;
	warmest_lake_temp[3] = warmest_temp_erie;
	warmest_lake_temp[4] = warmest_temp_ont;
	warmest_lake_temp[5] = warmest_temp_stclr;
	
	coolest_day[0] = coolest_day_sup;
	coolest_day[1] = coolest_day_mich;
	coolest_day[2] = coolest_day_hur;
	coolest_day[3] = coolest_day_erie;
	coolest_day[4] = coolest_day_ont;
	coolest_day[5] = coolest_day_stclr;
	
	warmest_day[0] = warmest_day_sup;
	warmest_day[1] = warmest_day_mich;
	warmest_day[2] = warmest_day_hur;
	warmest_day[3] = warmest_day_erie;
	warmest_day[4] = warmest_day_ont;
	warmest_day[5] = warmest_day_stclr;
	
	cmonth[0] = sup1; 
	cmonth[1] = mich1; 
	cmonth[2] = hur1; 
	cmonth[3] = erie1; 
	cmonth[4] = ont1; 
	cmonth[5] = stclr1;
	
	wmonth[0] = sup2;  
	wmonth[1] = mich2;  
	wmonth[2] = hur2;  
	wmonth[3] = erie2;  
	wmonth[4] = ont2;  
	wmonth[5] = stclr2;  

	
	for(m=0; m<6; m++){
		if(coolest_lake_temp[m]<mu){
			mu = coolest_lake_temp[m]; 
			o = m; 
		}
		if(warmest_lake_temp[m]>mu2){
			mu2 = warmest_lake_temp[m];
			p = m;
		}
	}
		
	printf("\nLake %s had the lowest temp of all the lakes at %.2lf degrees on %d/%d ", lake[o], coolest_lake_temp[o], coolest_day[o], cmonth[o]);	
	printf("\nLake %s had the warmest temp of all the lakes at %.2lf degrees on %d/%d \n\n", lake[p], warmest_lake_temp[p], warmest_day[p], wmonth[p]);
		
		
	//5. 
	
	
	int d, swpd;
	double sum_sup=0, sum_mich=0, sum_hur=0, sum_erie=0, sum_ont=0, sum_stclr=0, avg_sum[6], temp; 
	char *tempc; 
	
	for(d=172; d<265; d++){
		sum_sup += sup[d];
		sum_mich += mich[d];
		sum_hur += hur[d];
		sum_erie += erie[d];
		sum_ont += ont[d];
		sum_stclr += stclr[d];	 
	}
	
	avg_sum[0] = sum_sup/93; 
	avg_sum[1] = sum_mich/93; 
	avg_sum[2] = sum_hur/93; 
	avg_sum[3] = sum_erie/93; 
	avg_sum[4] = sum_ont/93; 
	avg_sum[5] = sum_stclr/93; 

	
	while(1){
	
		swpd = 0; 
		
		for(d=0; d<5; d++){
			
			if(avg_sum[d]<avg_sum[d+1]){
				
				temp = avg_sum[d];
				avg_sum[d] = avg_sum[d+1];
				avg_sum[d+1] = temp; 
				
				tempc = lake[d];
				lake[d] = lake[d+1];
				lake[d+1] = tempc; 
			
				swpd = 1; 
				
			}	
		}
		
		if(swpd==0){
			break;
		}	
	}
	
	
	for(d=0; d<6; d++){
		printf("Lake %s Summer Avg: %.2lf \n", lake[d], avg_sum[d]);
	}
	printf("Yes, the order of warmest to coldest temps displayed here do match the yearly average calculated in step #2 \n");
	
	//6. 
	
	double win_sup=0, win_mich=0, win_hur=0, win_erie=0, win_ont=0, win_stclr=0, avg_sumw[6];
	
	for(d=1; d<79; d++){
		win_sup += sup[d];
		win_mich += mich[d];
		win_hur += hur[d];
		win_erie += erie[d];
		win_ont += ont[d];
		win_stclr += stclr[d];	 
	}
	
	for(d=355; d<365; d++){
		win_sup += sup[d];
		win_mich += mich[d];
		win_hur += hur[d];
		win_erie += erie[d];
		win_ont += ont[d];
		win_stclr += stclr[d];
	}
	
	avg_sumw[0] = win_sup/88; 
	avg_sumw[1] = win_mich/88; 
	avg_sumw[2] = win_hur/88; 
	avg_sumw[3] = win_erie/88; 
	avg_sumw[4] = win_ont/88; 
	avg_sumw[5] = win_stclr/88; 
	
	while(1){
	
		swpd = 0; 
		
		for(d=0; d<5; d++){
			
			if(avg_sumw[d]<avg_sumw[d+1]){
				
				temp = avg_sumw[d];
				avg_sumw[d] = avg_sumw[d+1];
				avg_sumw[d+1] = temp; 
				
				tempc = lake[d];
				lake[d] = lake[d+1];
				lake[d+1] = tempc; 
			
				swpd = 1; 
				
			}	
		}
		
		if(swpd==0){
			break;
		}	
	}
	
	printf("\n");
	
	for(d=0; d<6; d++){
		printf("Lake %s Winter Avg: %.2lf \n", lake[d], avg_sumw[d]);
	}
	
	printf("No, the order of warmest to coldest temps displayed here don't match the yearly average calculated in step #2 \n");

			
	//7.
	
	int x, st[6], ft[6]; 
	int st_sup = 0, st_mich = 0, st_hur = 0, st_erie = 0, st_ont = 0, st_stclr = 0;
	int ft_sup = 0, ft_mich = 0, ft_hur = 0, ft_erie = 0, ft_ont = 0, ft_stclr = 0;
	
	 
	for(x=0; x<366; x++){
		if(sup[x]>=20){
			st_sup++;
		}
		if(mich[x]>=20){
			st_mich++;
		}
		if(hur[x]>=20){
			st_hur++;
		}
		if(erie[x]>=20){
			st_erie++;
		}
		if(ont[x]>=20){
			st_ont++;
		}
		if(stclr[x]>=20){
			st_stclr++;
		}
	}
	
	st[0] = st_sup;
	st[1] = st_mich;
	st[2] = st_hur;
	st[3] = st_erie;
	st[4] = st_ont; 
	st[5] = st_stclr; 
	
	for(x=0; x<6; x++){
		printf("\nAmount of days you can swim in lake %s comfortably in a year is %d days", lake[x], st[x]);
	}
	
	
	//8.
	
	for(x=0; x<365; x++){
		if(sup[x]<0){
			ft_sup++;
		}
		if(mich[x]<0){
			ft_mich++;
		}
		if(hur[x]<0){
			ft_hur++;
		}
		if(erie[x]<0){
			ft_erie++;
		}
		if(ont[x]<0){
			ft_ont++;
		}
		if(stclr[x]<0){
			ft_stclr++;
		}
	}
	
	ft[0] = ft_sup;
	ft[1] = ft_mich;
	ft[2] = ft_hur;
	ft[3] = ft_erie;
	ft[4] = ft_ont; 
	ft[5] = ft_stclr;
	
	printf("\n");
	
	for(x=0; x<6; x++){
		printf("\nLake %s is frozen for %d days out of the year", lake[x], ft[x]);
	}
	
	//9. 
	
	double superior[365], michigan[365], huron[365], eriee[365], ontario[365], stclair[365]; //Making the arrays for the lakes
	double summ1 = 0, summ2 = 0, summ3 = 0, summ4 = 0, summ5 = 0, summ6 = 0, avg2[6];
	int y, year2, day2[365]; 
	
	
	FILE*fp2 = fopen("lakes18.txt", "r");
	
	for(y = 1; y < 365; y++){
		
		fscanf(fp2, "%d %d %lf %lf %lf %lf %lf %lf", &year2, &day2[y], &superior[y], &michigan[y], &huron[y], &eriee[y], &ontario[y], &stclair[y]);
		
		summ1 += superior[y];  
		summ2 += michigan[y]; 
		summ3 += huron[y]; 
		summ4 += eriee[y]; 
		summ5 += ontario[y]; 
		summ6 += stclair[y];
			
	}
	
	fclose(fp2);
	
	avg2[0] = summ1/365;
	avg2[1] = summ2/365; 
	avg2[2] = summ3/365; 
	avg2[3] = summ4/365; 
	avg2[4] = summ5/365; 
	avg2[5] = summ6/365; 
	 
	double lake6; 

	lake6 = (avg2[0] + avg2[1] + avg2[2] + avg2[3] + avg2[4] + avg2[5])/6; 
	
	printf("\n\n\t\t\tAverage Lake Temps\n");
	
	printf("Year\tSup\tMich\tHur\tErie\tOnt\tSt.Clr\tYearly Average");
	printf("\n2019\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t    %.2lf", avg[0], avg[1], avg[2], avg[3], avg[4], avg[5], ovr_avg);
	printf("\n2018\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t    %.2lf", avg2[0], avg2[1], avg2[2], avg2[3], avg2[4], avg2[5], lake6);
	
	
	return 0;
}


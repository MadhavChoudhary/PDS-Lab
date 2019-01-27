#include<stdio.h>
#include<math.h>


//In whatever directory it may be in go to it
//compile gcc Mech.c -lm
//run ./a.out
//keep the ouput terminal window to full screen for good results

int main(){

	int map_lenght=190,map_width=160,i,j;
	double temp=0,sum=0,area,k,scale;
	char flag = '*';

	typedef struct component{

		int x;
		int y;
	}component;

	struct component moment,centroid;
    
    //website for longitudes and lattitudes
    //http://www.latlong.net/c/?lat=-35.844535&long=-56.250000

	int coord[70][2];
	int map[500][500]={0};

	//longitudes and lattitudes along the boundary from above website
	//These are 70 gps coordinates on outline of india taken manually

	double outline[70][2]={           

		{8.153629, 77.543876},
		{12.215027, 79.865501},
		{15.284052, 80.058970},
		{16.709833, 82.122636},
		{18.431220, 83.992834},
		{19.832512, 85.798543},
		{21.701694, 87.346293},
		{22.716663, 88.894043},
		{24.899542, 88.184657},
		{26.353135, 88.313636},
		{26.002569, 88.116398},
		{25.191670, 91.731584},
		{23.310230, 91.602605},
		{23.013773, 92.376480},
		{22.239946, 93.085866},
		{25.067238, 94.540478},
		{25.067238, 94.540478},
		{27.941662, 97.226347},
		{29.328292, 95.857081},
		{28.868121, 94.171829},
		{28.127601, 92.591905},
		{28.127601, 92.591905},
		{26.866337, 89.642715},
		{28.081146, 88.431441},
		{26.442732, 87.957464},
		{26.866337, 85.534914},
		{26.866337, 85.534914},
		{28.821991, 80.110511},
		{30.060257, 80.689816},
		{31.148107, 79.215221},
		{32.668046, 78.477923},
		{34.249674, 79.478541},
		{35.930160, 79.162557},
		{35.673883, 77.266649},
		{36.319769, 76.273263},
		{37.031094, 74.317458},
		{35.844826, 72.895527},
		{33.374553, 73.632825},
		{32.268158, 75.265412},
		{30.196904, 73.896145},
		{28.868121, 72.368886},
		{27.988177, 70.525642},
		{25.685808, 70.630970},
		{24.301619, 69.999001},
		{23.627885, 68.419078},
		{22.902163, 70.209657},
		{22.221299, 68.998383},
		{20.849688, 70.736299},
		{22.270043, 72.474214},
		{20.345380, 72.746391},
		{18.668829, 72.883216},
		{17.367715, 73.156866},
		{15.881901, 73.476125},
		{14.914549, 74.023425},
		{13.544105, 74.616333},
		{12.299439, 75.026808},
		{11.183107, 75.710933},
		{10.914529, 75.756541},
		{9.388169, 76.258233},
		{8.532194, 76.805533},

	};

	//converting long and lat to coordinates on a 2D map of our specified size

	for(i=0;i<70;i++){

		coord[i][0] = ((map_width/360.0) * (180 + outline[i][1]));
		coord[i][1] = ((map_lenght/180.0) * (90 - outline[i][0]));            
	}

	//The above method is good but I found many problems with it so below is another method
	//brute force method
	//Taking boundary points manually from a graph and storing it in 2D array

	map[3][43]=flag;map[3][44]=flag;map[3][46]=flag;

	for(j=40;j<=46;j++) map[4][j]=flag;
	for(j=35;j<=47;j++) map[5][j]=flag;
	for(j=34;j<=48;j++) map[6][j]=flag;
	for(j=33;j<=49;j++) map[7][j]=flag;
	for(j=32;j<=51;j++) map[8][j]=flag;                                       
	for(j=32;j<=52;j++) map[9][j]=flag;
	for(j=32;j<=53;j++) map[10][j]=flag;
	for(j=35;j<=54;j++) map[11][j]=flag;map[11][63]=flag;map[11][65]=flag;map[11][66]=flag;
	for(j=36;j<=55;j++) map[12][j]=flag;for(j=60;j<=68;j++) map[12][j]=flag;
	for(j=38;j<=56;j++) map[13][j]=flag;for(j=58;j<=69;j++) map[13][j]=flag;
	for(j=37;j<=70;j++) map[14][j]=flag;
	for(j=38;j<=70;j++) map[15][j]=flag;
	for(j=40;j<=70;j++) map[16][j]=flag;
	for(j=39;j<=69;j++) map[17][j]=flag;
	for(j=38;j<=69;j++) map[18][j]=flag;
	for(j=36;j<=68;j++) map[19][j]=flag;
	for(j=36;j<=67;j++) map[20][j]=flag;
	for(j=36;j<=66;j++) map[21][j]=flag;
	for(j=36;j<=66;j++) map[22][j]=flag;
	for(j=37;j<=63;j++) map[23][j]=flag;
	for(j=37;j<=63;j++) map[24][j]=flag;
	for(j=37;j<=63;j++) map[25][j]=flag;
	for(j=37;j<=63;j++) map[26][j]=flag;
	for(j=37;j<=63;j++) map[27][j]=flag;
	for(j=37;j<=64;j++) map[28][j]=flag;
	for(j=38;j<=65;j++) map[29][j]=flag;
	for(j=42;j<=65;j++) map[30][j]=flag;
	for(j=42;j<=66;j++) map[31][j]=flag;
	for(j=42;j<=65;j++) map[32][j]=flag;
	for(j=45;j<=61;j++) map[33][j]=flag;for(j=63;j<=65;j++) map[33][j]=flag;
	for(j=45;j<=61;j++) map[34][j]=flag;
	for(j=44;j<=61;j++) map[35][j]=flag;
	for(j=42;j<=62;j++) map[36][j]=flag;
	for(j=41;j<=62;j++) map[37][j]=flag;
	for(j=41;j<=62;j++) map[38][j]=flag;
	for(j=41;j<=62;j++) map[39][j]=flag;
	for(j=41;j<=63;j++) map[40][j]=flag;
	for(j=41;j<=64;j++) map[41][j]=flag;
	for(j=40;j<=65;j++) map[42][j]=flag;
	for(j=39;j<=68;j++) map[43][j]=flag;
	for(j=39;j<=69;j++) map[44][j]=flag;
	for(j=38;j<=69;j++) map[45][j]=flag;
	for(j=38;j<=71;j++) map[46][j]=flag;
	for(j=38;j<=74;j++) map[47][j]=flag;
	for(j=35;j<=73;j++) map[48][j]=flag;map[48][151]=flag;
	for(j=35;j<=72;j++) map[49][j]=flag;map[49][143]=flag;for(j=149;j<=152;j++) map[49][j]=flag;
	for(j=35;j<=71;j++) map[50][j]=flag;for(j=142;j<=151;j++) map[50][j]=flag;
	for(j=34;j<=70;j++) map[51][j]=flag;for(j=141;j<=153;j++) map[51][j]=flag;
	for(j=34;j<=69;j++) map[52][j]=flag;for(j=141;j<=153;j++) map[52][j]=flag;
	for(j=33;j<=70;j++) map[53][j]=flag;for(j=140;j<=153;j++) map[53][j]=flag;
	for(j=32;j<=70;j++) map[54][j]=flag;for(j=138;j<=153;j++) map[54][j]=flag;
	for(j=31;j<=69;j++) map[55][j]=flag;for(j=137;j<=158;j++) map[55][j]=flag;
	for(j=29;j<=69;j++) map[56][j]=flag;for(j=136;j<=158;j++) map[56][j]=flag;
	for(j=29;j<=69;j++) map[57][j]=flag;for(j=135;j<=157;j++) map[57][j]=flag;
	for(j=28;j<=72;j++) map[58][j]=flag;for(j=134;j<=156;j++) map[58][j]=flag;
	map[59][19]=flag;for(j=27;j<=74;j++) map[59][j]=flag;for(j=134;j<=156;j++) map[59][j]=flag;
	for(j=18;j<=20;j++) map[60][j]=flag;for(j=27;j<=75;j++) map[60][j]=flag;for(j=112;j<=114;j++) map[60][j]=flag;for(j=130;j<=157;j++) map[60][j]=flag;
	for(j=17;j<=20;j++) map[61][j]=flag;for(j=22;j<=76;j++) map[61][j]=flag;for(j=111;j<=114;j++) map[61][j]=flag;for(j=130;j<=153;j++) map[61][j]=flag;map[61][156]=flag;map[61][157]=flag;
	for(j=17;j<=79;j++) map[62][j]=flag;for(j=111;j<=114;j++) map[62][j]=flag;for(j=131;j<=152;j++) map[62][j]=flag;map[62][157]=flag;
	for(j=16;j<=80;j++) map[63][j]=flag;for(j=111;j<=114;j++) map[63][j]=flag;for(j=131;j<=151;j++) map[63][j]=flag;
	for(j=15;j<=83;j++) map[64][j]=flag;for(j=111;j<=114;j++) map[64][j]=flag;for(j=131;j<=150;j++) map[64][j]=flag;
	for(j=14;j<=91;j++) map[65][j]=flag;for(j=111;j<=114;j++) map[65][j]=flag;for(j=132;j<=148;j++) map[65][j]=flag;
	for(j=14;j<=92;j++) map[66][j]=flag;for(j=111;j<=115;j++) map[66][j]=flag;for(j=131;j<=148;j++) map[66][j]=flag;
	for(j=14;j<=93;j++) map[67][j]=flag;for(j=111;j<=118;j++) map[67][j]=flag;for(j=123;j<=148;j++) map[67][j]=flag;
	for(j=17;j<=95;j++) map[68][j]=flag;for(j=112;j<=148;j++) map[68][j]=flag;
	for(j=17;j<=98;j++) map[69][j]=flag;for(j=111;j<=148;j++) map[69][j]=flag;
	for(j=17;j<=102;j++) map[70][j]=flag;map[70][106]=flag;for(j=110;j<=148;j++) map[70][j]=flag;
	for(j=17;j<=148;j++) map[71][j]=flag;map[71][116]=0;
	for(j=16;j<=111;j++) map[72][j]=flag;for(j=117;j<=147;j++) map[72][j]=flag;map[72][120]=0;
	for(j=17;j<=111;j++) map[73][j]=flag;for(j=119;j<=146;j++) map[73][j]=flag;
	for(j=18;j<=111;j++) map[74][j]=flag;for(j=119;j<=146;j++) map[74][j]=flag;
	for(j=19;j<=112;j++) map[75][j]=flag;for(j=119;j<=145;j++) map[75][j]=flag;
	for(j=19;j<=114;j++) map[76][j]=flag;for(j=119;j<=146;j++) map[76][j]=flag;
	for(j=20;j<=115;j++) map[77][j]=flag;for(j=119;j<=146;j++) map[77][j]=flag;
	for(j=20;j<=115;j++) map[78][j]=flag;for(j=134;j<=146;j++) map[78][j]=flag;
	for(j=21;j<=113;j++) map[79][j]=flag;for(j=134;j<=146;j++) map[79][j]=flag;
	for(j=21;j<=112;j++) map[80][j]=flag;for(j=133;j<=145;j++) map[80][j]=flag;
	for(j=21;j<=111;j++) map[81][j]=flag;for(j=133;j<=144;j++) map[81][j]=flag;
	map[82][9]=flag;map[82][18]=flag;for(j=21;j<=111;j++) map[82][j]=flag;for(j=132;j<=144;j++) map[82][j]=flag;
	for(j=9;j<=113;j++) map[83][j]=flag;map[83][15]=0;map[83][20]=0;for(j=131;j<=144;j++) map[83][j]=flag;
	for(j=9;j<=115;j++) map[84][j]=flag;for(j=129;j<=140;j++) map[84][j]=flag;
	for(j=8;j<=115;j++) map[85][j]=flag;for(j=128;j<=140;j++) map[85][j]=flag;
	for(j=7;j<=114;j++) map[86][j]=flag;for(j=128;j<=140;j++) map[86][j]=flag;
	for(j=7;j<=114;j++) map[87][j]=flag;for(j=128;j<=140;j++) map[87][j]=flag;map[87][135]=0;
	for(j=7;j<=114;j++) map[88][j]=flag;for(j=129;j<=133;j++) map[88][j]=flag;for(j=136;j<=140;j++) map[88][j]=flag;
	for(j=8;j<=115;j++) map[89][j]=flag;for(j=130;j<=132;j++) map[89][j]=flag;for(j=136;j<=140;j++) map[89][j]=flag;
	for(j=8;j<=115;j++) map[90][j]=flag;map[90][131]=flag;for(j=136;j<=139;j++) map[90][j]=flag;
	for(j=9;j<=15;j++) map[91][j]=flag;for(j=19;j<=116;j++) map[91][j]=flag;for(j=136;j<=139;j++) map[91][j]=flag;
	for(j=11;j<=14;j++) map[92][j]=flag;for(j=17;j<=116;j++) map[92][j]=flag;for(j=136;j<=139;j++) map[92][j]=flag;
	for(j=16;j<=116;j++) map[93][j]=flag;for(j=136;j<=139;j++) map[93][j]=flag;
	for(j=14;j<=116;j++) map[94][j]=flag;for(j=137;j<=139;j++) map[94][j]=flag;
	for(j=9;j<=117;j++) map[95][j]=flag;map[95][10]=0;for(j=137;j<=139;j++) map[95][j]=flag;
	for(j=9;j<=117;j++) map[96][j]=flag;for(j=138;j<=139;j++) map[96][j]=flag;
	for(j=10;j<=118;j++) map[97][j]=flag;
	for(j=11;j<=118;j++) map[98][j]=flag;map[98][27]=0;
	for(j=12;j<=25;j++) map[99][j]=flag;for(j=29;j<=118;j++) map[99][j]=flag;
	for(j=12;j<=26;j++) map[100][j]=flag;for(j=28;j<=111;j++) map[100][j]=flag;
	for(j=13;j<=26;j++) map[101][j]=flag;for(j=29;j<=110;j++) map[101][j]=flag;
	for(j=14;j<=26;j++) map[102][j]=flag;for(j=29;j<=109;j++) map[102][j]=flag;
	for(j=14;j<=25;j++) map[103][j]=flag;for(j=28;j<=106;j++) map[103][j]=flag;
	for(j=15;j<=24;j++) map[104][j]=flag;for(j=28;j<=105;j++) map[104][j]=flag;
	for(j=16;j<=22;j++) map[105][j]=flag;for(j=29;j<=106;j++) map[105][j]=flag;
	map[106][18]=flag;for(j=29;j<=107;j++) map[106][j]=flag;
	for(j=29;j<=106;j++) map[107][j]=flag;
	for(j=29;j<=105;j++) map[108][j]=flag;
	for(j=29;j<=105;j++) map[109][j]=flag;
	for(j=28;j<=104;j++) map[110][j]=flag;
	for(j=28;j<=103;j++) map[111][j]=flag;
	for(j=28;j<=102;j++) map[112][j]=flag;
	for(j=28;j<=102;j++) map[113][j]=flag;
	for(j=29;j<=99;j++) map[114][j]=flag;
	for(j=28;j<=97;j++) map[115][j]=flag;
	for(j=28;j<=96;j++) map[116][j]=flag;
	for(j=28;j<=96;j++) map[117][j]=flag;
	for(j=29;j<=95;j++) map[118][j]=flag;
	for(j=29;j<=93;j++) map[119][j]=flag;
	for(j=29;j<=93;j++) map[120][j]=flag;
	for(j=29;j<=92;j++) map[121][j]=flag;
	for(j=29;j<=92;j++) map[122][j]=flag;
	for(j=29;j<=91;j++) map[123][j]=flag;
	for(j=30;j<=89;j++) map[124][j]=flag;
	for(j=30;j<=88;j++) map[125][j]=flag;
	for(j=30;j<=88;j++) map[126][j]=flag;
	for(j=30;j<=87;j++) map[127][j]=flag;
	for(j=30;j<=85;j++) map[128][j]=flag;
	for(j=30;j<=85;j++) map[129][j]=flag;
	for(j=30;j<=82;j++) map[130][j]=flag;
	for(j=31;j<=81;j++) map[131][j]=flag;
	for(j=31;j<=81;j++) map[132][j]=flag;
	for(j=31;j<=81;j++) map[133][j]=flag;
	for(j=31;j<=81;j++) map[134][j]=flag;
	for(j=31;j<=79;j++) map[135][j]=flag;
	for(j=32;j<=75;j++) map[136][j]=flag;
	for(j=32;j<=75;j++) map[137][j]=flag;
	for(j=32;j<=75;j++) map[138][j]=flag;
	for(j=33;j<=74;j++) map[139][j]=flag;
	for(j=33;j<=73;j++) map[140][j]=flag;map[140][71]=0;map[140][72]=0;
	for(j=34;j<=70;j++) map[141][j]=flag;
	for(j=34;j<=69;j++) map[142][j]=flag;
	for(j=34;j<=69;j++) map[143][j]=flag;
	for(j=35;j<=69;j++) map[144][j]=flag;
	for(j=35;j<=69;j++) map[145][j]=flag;
	for(j=36;j<=69;j++) map[146][j]=flag;
	for(j=36;j<=69;j++) map[147][j]=flag;
	for(j=36;j<=69;j++) map[148][j]=flag;
	for(j=37;j<=69;j++) map[149][j]=flag;
	for(j=37;j<=69;j++) map[150][j]=flag;
	for(j=37;j<=70;j++) map[151][j]=flag;
	for(j=38;j<=70;j++) map[152][j]=flag;
	for(j=38;j<=70;j++) map[153][j]=flag;
	for(j=38;j<=70;j++) map[154][j]=flag;
	for(j=38;j<=71;j++) map[155][j]=flag;
	for(j=38;j<=70;j++) map[156][j]=flag;
	for(j=39;j<=70;j++) map[157][j]=flag;
	for(j=39;j<=70;j++) map[158][j]=flag;
	for(j=39;j<=70;j++) map[159][j]=flag;
	for(j=40;j<=70;j++) map[160][j]=flag;
	for(j=40;j<=69;j++) map[161][j]=flag;
	for(j=40;j<=68;j++) map[162][j]=flag;
	for(j=41;j<=68;j++) map[163][j]=flag;
	for(j=42;j<=68;j++) map[164][j]=flag;
	for(j=43;j<=67;j++) map[165][j]=flag;
	for(j=43;j<=67;j++) map[166][j]=flag;
	for(j=43;j<=68;j++) map[167][j]=flag;
	for(j=44;j<=68;j++) map[168][j]=flag;
	for(j=44;j<=68;j++) map[169][j]=flag;
	for(j=44;j<=68;j++) map[170][j]=flag;
	for(j=45;j<=68;j++) map[171][j]=flag;
	for(j=45;j<=68;j++) map[172][j]=flag;
	for(j=45;j<=68;j++) map[173][j]=flag;
	for(j=46;j<=68;j++) map[174][j]=flag;
	for(j=46;j<=68;j++) map[175][j]=flag;
	for(j=47;j<=64;j++) map[176][j]=flag;
	for(j=47;j<=64;j++) map[177][j]=flag;
	for(j=47;j<=63;j++) map[178][j]=flag;
	for(j=47;j<=62;j++) map[179][j]=flag;
	for(j=47;j<=62;j++) map[180][j]=flag;
	for(j=47;j<=62;j++) map[181][j]=flag;
	for(j=47;j<=59;j++) map[182][j]=flag;
	for(j=48;j<=58;j++) map[183][j]=flag;
	for(j=49;j<=58;j++) map[184][j]=flag;
	for(j=49;j<=57;j++) map[185][j]=flag;
	for(j=50;j<=57;j++) map[186][j]=flag;
	for(j=51;j<=57;j++) map[187][j]=flag;
	for(j=51;j<=56;j++) map[188][j]=flag;
	for(j=54;j<=54;j++) map[189][j]=flag;
	
	//construction of india is complete

	temp=0;

	//calculating area of india
	for(i=0;i<=map_lenght;i++){
		for(j=0;j<=map_width;j++)
			if(map[i][j]==flag)
				temp++;
		printf("\n");
	}

	area=temp;
	temp=0;sum=0;

	//actual area of india is 3287263 sq.km
	scale=sqrt(3287263/area);

	//calculating first moment of area of india about original x-axis to find y component of centroid
	for(i=0;i<=map_lenght;i++){

		temp=0;
		for(j=0;j<=map_width;j++)
			if(map[i][j]==flag)
				temp++;
		sum+=temp*i;
	}

	moment.x=sum;
	sum=0;temp=0;
	centroid.y=moment.x/area;

	//calculating first moment of area of india about original y-axis to find x component of centroid
	for(j=0;j<=map_width;j++){

		temp=0;
		for(i=0;i<=map_lenght;i++)
			if(map[i][j]==flag)
				temp++;
		sum+=temp*j;
	}

	moment.y=sum;
	sum=0;temp=0;
	centroid.x=moment.y/area;

	//centroid will appear as '?' if you print india
	map[centroid.y][centroid.x]=1;


	//calculating second moment of area about centroidal x-axis
	for(i=0;i<=centroid.y;i++){

		temp=0;
		for(j=0;j<=map_width;j++)
			if(map[i][j]==flag)
				temp++;
		sum+=temp*(centroid.y-i)*(centroid.y-i);

	}

	for(i=centroid.y+1;i<=map_lenght;i++){

		temp=0;
		for(j=0;j<=map_width;j++)
			if(map[i][j]==flag)
				temp++;
		sum+=temp*(i-centroid.y)*(i-centroid.y);

	}

	k=sqrt(sum/area);

	//print squeezed india because the width of india will probably not be sufficient for terminal width
	//else print space with every element to veiw original shape
	printf("Squeezed Inida\n\n\n");
	for(i=0;i<=map_lenght;i++){
		for(j=0;j<=map_width;j++)
			printf("%c",map[i][j]);
		printf("\n");
	}
	

	printf("centroid is (%.2lf km,%.2lf km)\n",centroid.x*scale,centroid.y*scale);
	printf("Area of india is %.3lf sq.km\n",area*scale*scale);
	printf("Second moment of area is %.3lf (km)^4\n",sum*scale*scale*scale*scale);
	printf("Radius of gyration (k)= %.2lf km\n\n ",k*scale);

	return 0;
}
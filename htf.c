#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

struct nav_ps
{
    double nav;// 净值
    double ps;// 对应的概率
};
/* 净值表*/
double gnav_20170117[] =
{
    1.7270, 1.7000, 1.6750, 1.7800, 1.8950, 1.9160, 1.8500, 1.9300, 1.9450, 1.9570,
    1.8030, 1.8770, 1.8120, 1.6820, 1.5430, 1.4160, 1.3310, 1.3710, 1.4590, 1.3890,
    1.2920, 1.2350, 1.2690, 1.3330, 1.4000, 1.3720, 1.4050, 1.2980, 1.2100, 1.3030,
    1.2970, 1.3310, 1.3310, 1.4120, 1.4260, 1.4410, 1.4580, 1.3830, 1.4570, 1.4360,
    1.4260, 1.5080, 1.5310, 1.6170, 1.6590, 1.6490, 1.7210, 1.7710, 1.7810, 1.8530,
    1.8500, 1.8860, 1.8060, 1.8180, 1.8440, 1.7970, 1.7880, 1.9120, 2.0080, 2.0730,
    2.0790, 2.1260, 2.0950, 2.0370, 2.1130, 2.0730, 2.0190, 2.1100, 2.1570, 2.1030,
    2.1460, 2.2040, 2.1780, 2.0440, 2.0480, 1.9980, 1.9590, 2.0400, 2.0250, 2.0560,
    2.0590, 2.0680, 2.0640, 2.0480, 2.0680, 2.1030, 2.1300, 2.1890, 2.1610, 2.1470,
    2.1680, 2.1170, 2.1050, 2.1160, 2.1160, 2.0790, 2.0690, 2.0970, 2.0390, 1.8770,
    1.8180, 1.8670, 1.7110, 1.7120, 1.5830, 1.5780, 1.5010, 1.5820, 1.5340, 1.5880,
    1.6520, 1.6310, 1.5440, 1.5920, 1.4760, 1.3760, 1.4330, 1.4090, 1.4840, 1.4930,
    1.5260, 1.4880, 1.5050, 1.5870, 1.6290, 1.6120, 1.6230, 1.6620, 1.6620, 1.6310,
    1.5510, 1.4920, 1.4020, 1.4280, 1.4890, 1.4910, 1.4171, 1.4340, 1.4030, 1.3980,
    1.4710, 1.4600, 1.4450, 1.5160, 1.5930, 1.6380, 1.6300, 1.6750, 1.6370, 1.6290,
    1.6150, 1.5850, 1.6590, 1.6550, 1.6430, 1.6970, 1.6950, 1.6710, 1.6550, 1.6820,
    1.6700, 1.6950, 1.7110, 1.7040, 1.6730, 1.6780, 1.5930, 1.5670, 1.5890, 1.5750,
    1.5910, 1.5870, 1.5840, 1.6410, 1.6420, 1.6580, 1.5890, 1.5310, 1.5220, 1.4920,
    1.4970, 1.4850, 1.5090, 1.5260, 1.4830, 1.4930, 1.5130, 1.5330, 1.5200, 1.5150,
    1.5270, 1.5160, 1.5130, 1.5940, 1.0608, 1.6250, 1.6390, 1.6440, 1.6430, 1.6350,
    1.5400, 1.5310, 1.5840, 1.5760, 1.5830, 1.5920, 1.5770, 1.6170, 1.6210, 1.6090,
    1.6520, 1.6630, 1.6600, 1.6660, 1.6520, 1.6780, 1.6800, 1.6840, 1.6780, 1.6720,
    1.6870, 1.7050, 1.7060, 1.6880, 1.6840, 1.6960, 1.6970, 1.6960, 1.6790, 1.6710,
    1.6900, 1.5940, 1.5710, 1.5380, 1.5530, 1.5530, 1.5720, 1.5530, 1.5700, 1.5830,
    1.5760, 1.5450, 1.5570, 1.6060, 1.6060, 1.6140, 1.6080, 1.6110, 1.5850, 1.5880,
    1.6030, 1.5940, 1.5970, 1.5990, 1.5910, 1.5840, 1.5790, 1.5830, 1.6120, 1.6070,
    1.6150, 1.5940, 1.5430, 1.5480, 1.5450, 1.5650, 1.5610, 1.5630, 1.5680, 1.5630,
    1.5320, 1.5450, 1.5410, 1.5450, 1.5560, 1.5980, 1.5980, 1.5950, 1.5950, 1.5920,
    1.5750, 1.5970, 1.5960, 1.6090, 1.6000, 1.6150, 1.6200, 1.6060, 1.6020, 1.5960,
    1.5940, 1.6050, 1.5880, 1.5930, 1.5840, 1.5810, 1.5900, 1.5700, 1.5910, 1.5930,
    1.6020, 1.6160, 1.6150, 1.6020, 1.5970, 1.5950, 1.6180, 1.6180, 1.5930, 1.6050,
    1.5960, 1.5830, 1.5770, 1.5960, 1.5710, 1.5640, 1.5610, 1.5720, 1.5550, 1.5410,
    1.4520, 1.4480, 1.4370, 1.4470, 1.4700, 1.4570, 1.4520, 1.4590, 1.4560, 1.4430,
    1.4430, 1.4400, 1.4310, 1.4300, 1.4300, 1.4360, 1.4530, 1.4610, 1.4370/*2017-01-06*/
};
/* 净值对应的概率表*/
struct nav_ps gnav_20170117_ps[sizeof(gnav_20170117)/sizeof(double)] =
{
    {0.0, 0.0}
};
// 求数学期望
double count_Mathematical_Expectation(int counts, double array[], int *differ_num)
{
    int i = 0;
    double sum = 0.0, nav = 0.0;
    double result = 0;
    int j = 0, k = 0;
    int array_num = 0;
    
    printf("counts num = %d\n\r", counts);
    
    for (i = 0; i < counts; ++i)// 计算概率
    {
        int nav_num = 0;
        int exist = 0;

        nav = array[i];

        for (k = 0; k < array_num; k++)
        {
            if (nav == gnav_20170117_ps[k].nav)
            {/* already count ps */
                exist =1;
                break;
            }
        }

        if (exist) {
            continue;
        }

        for (j = 0; j < counts; j++)
        {
            if (nav == array[j])
            {
                nav_num++;
            }
        }

        gnav_20170117_ps[array_num].nav = nav;
        gnav_20170117_ps[array_num].ps = (nav_num/(double)counts);
        array_num++;
    }

    *differ_num = array_num;
    printf("differ num = %d\n\r", *differ_num);

    // 开始计算期望
    for (i = 0; i < *differ_num; i++)
    {
        result += (gnav_20170117_ps[i].nav * gnav_20170117_ps[i].ps);
    }

    return result;
}

double count_variance(int counts, struct nav_ps array[], double Mathematical_Expectation)// 求方差
{
    int i = 0;
    double result = 0.0;

    for (i = 0; i < counts; i++)
    {
        result += array[i].ps * (pow(array[i].nav, 2));
    }

    result -= pow(Mathematical_Expectation, 2);

    return result;
}

int main(int argc, char* argv[])
{
    int fn = sizeof(gnav_20170117)/sizeof(double);
    int i = 0;
    double sum = 0.0, average_val = 0.0;
    double variance = 0.0, Mathematical_Expectation = 0.0;
    int left_num = 0;
    double	Standard_deviation, Nav_date,Maximum_deviation;
    double Mini_deviation, Maximum_deviation_percentage, Mini_deviation_percentage;

    for (i = 0; i < fn; ++i)
    {
        sum += gnav_20170117[i];
    }

    Nav_date = gnav_20170117[fn-1];
    average_val = sum/(double)fn;
    Mathematical_Expectation = count_Mathematical_Expectation(fn, gnav_20170117, &left_num);
    variance = count_variance(left_num, gnav_20170117_ps, Mathematical_Expectation);
    Standard_deviation = sqrt(variance);
    Maximum_deviation = Mathematical_Expectation + Standard_deviation;
    Mini_deviation = Mathematical_Expectation - Standard_deviation;
    Maximum_deviation_percentage = ((Maximum_deviation-Nav_date)/Nav_date)*(double)100;
    Mini_deviation_percentage = ((Mini_deviation-Nav_date)/Nav_date)*(double)100;
	
    printf("----------------------------------------HuiTianFu Movation Internet Stock Fund-------------------------------------------------------------------------------------------------------\n");
    printf("     Nav   | average_val | Mathematical Expectation | variance | Standard deviation | Maximum deviation | Mini deviation | Maximum deviation percentage | Mini deviation percentage |\n");
    printf("  %8.6f | %11.6f | %24.6f | %8.6f | %18.6f | %17.6f | %14.6f | %27.6f%% | %24.6f%% |\n",
		Nav_date, average_val, Mathematical_Expectation,
		variance, Standard_deviation, Maximum_deviation,
		Mini_deviation, Maximum_deviation_percentage, Mini_deviation_percentage);

    double variance1 = 0.0, Mathematical_Expectation1 = 0.0;
    while (scanf("%lf", &Mathematical_Expectation1) != EOF)
    {
        variance1 = count_variance(left_num, gnav_20170117_ps, Mathematical_Expectation1);
        printf("your nav number is %lf,  the result is %06f (closing to zero is means close nav)\n", Mathematical_Expectation1, variance1);
    }

    return 0;
}


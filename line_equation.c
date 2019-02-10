#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int regression(int[],float[],int);
void error_rate(int[],float[],int);

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

float m=0.0;
float c=0.0; 

// const char* getfield(char* line, int num)
// {
//     const char* tok;
//     for (tok = strtok(line, ",");
//             tok && *tok;
//             tok = strtok(NULL, ",\n"))
//     {
//         if (!--num)
//             return tok;
//     }
//     return NULL;
// }

/*
int fileread(char filename[])
{
    char line[100];
    //const char delim=",";
    char *token;
    char valuelist[500];
    FILE *data=fopen(filename,"r");
    if(data==NULL)
    {
        printf("The file has failed to open\n");
        exit(0);
    }
    else
    {   
        int i=0;
        while(fgetsl())
        {
            token=strtok(line,",");
            valuelist[i]=token;
            i++;
        }
        int j;
        for(j=0;j<=i;j++)
            printf(valuelist[j]);
    fclose(data);
    }
    return 0;
}*/

int main()
{
    float value_list[50]={229.25,
227.6,
228.9,
231.4,
234.85,
236.7,
234.4,
233.7,
237.3,
232.75,
237.3,
238.15,
235.15,
239.85,
238.55,
240,
239.75,
240.9,
237.75,
236.65,
238.7,
242.7,
242,
};

    int days[50]={30,
31,
29,
28,
03,
14,
04,
22,
23,
01,
02,
21,
15,
11,
16,
9,
8,
25,
07,
24,
17,
18,
10,
};

//    printf("Enter the name of the file the data is stored\n");
//    char filename[20];
//    gets(filename);
//    fileread(filename);
    int count=23;
    //int error_values[50];
    printf("%d\n",count);
    regression(days,value_list,count);
    printf("y=%fx+(%f)",m,c);
    error_rate(days,value_list,count);

    return 0;
}

int regression(int x[],float y[],int count){
    int sumx=0;
    float sumy=0.0;
    int sum_xsq=0;
    float sum_xy=0.0;
    float denom=0.0;
    int i;
    for(i=0;i<count;i++)
    {
        sumx+=x[i];
        sumy+=y[i];
        sum_xsq+=pow(x[i],2);
        sum_xy+=(x[i]*y[i]);
    }
    denom = count * sum_xsq - pow(sumx,2);
    c = ((sumy * sum_xsq) - (sumx * sum_xy)) / denom;
    m = ((count * sum_xy) - (sumx * sumy)) / denom;
}


void error_rate(int days[],float value_list[],int count)
{
    int i;
    float error_value;
    printf("\n\nActual value\t\tPredicted value\t\tError\n");
    for(i=0;i<count;i++)
    {
        float temp_value=m*days[i]+c;
        error_value=value_list[i]-temp_value;
        printf("%f\t\t%f\t\t%f\n",value_list[i],temp_value,error_value);
    }
}

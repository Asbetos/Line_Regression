#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int regression(int[],int[],int);

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
        while(fgets(line,10,data)!=NULL)
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
    int value_list[31]={229.25,
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

    int days[31]={30,
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
    int count=NELEMS(days);
    printf("%d\n",count);
    regression(days,value_list,count);
    printf("y=%fx+(%f)",m,c);
    return 0;
}

int regression(int x[],int y[],int count){
    int sumx=0;int sumy=0;int sum_xsq=0;int sum_xy=0;
    float denom=0.0;
    int i;
    for(i=0;i<=count;i++)
    {
        sumx=x[i]+sumx;
        sumy=y[i]+sumy;
        sum_xsq=sum_xsq+x[i]*x[i];
        sum_xy=sum_xsq+(x[i]*y[i]);
    }
    denom = count * sum_xsq-pow(sumx,2);
    c = (sumy * sum_xsq - sumx * sum_xy) / denom;
    m = (count * sum_xy - sumx * sumy) / denom;
}

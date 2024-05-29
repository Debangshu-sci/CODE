#include <stdio.h>

unsigned int DPBinomialCoefficientMethod(int n, int k)
{
    unsigned int nCr[k + 1];
    for (int l = 0; l < k + 1; ++l)
        nCr[l] = 0;
    nCr[0] = 1;
     int C[100][100];
    for(int i=0;i<=n+1;i++){
     for(int j=0;j<=k+1;j++){
        C[i][j]=0;
    }
 }
    for (int p = 1; p <= n; p++)
    {
        for (int q = (p < k) ? p : k; q > 0; q--){
            nCr[q] = nCr[q] + nCr[q - 1];
            C[p][q]=nCr[q];
            }

    }

     for(int i=0;i<=n;i++){
        for(int j=0;j<=k+1;j++){
            printf("%d   ",C[i][j]);
        }
        printf("\n");
     }

    return nCr[k];
}

int main()
{
    unsigned int valueOfN, valueOfK;
    printf("Enter the value of n: ");
    scanf("%u", &valueOfN);
    printf("Enter the value of k: ");
    scanf("%u", &valueOfK);
    printf("Value of C(%u, %u): %u\n", valueOfN, valueOfK, DPBinomialCoefficientMethod(valueOfN, valueOfK));
    return 0;
}

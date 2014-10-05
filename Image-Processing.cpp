// Program to detect lines/filter and others (details in Usage file) in any angle using openCV - Author - Payel Bandyopadhyay
#include "cv.h"
#include "highgui.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "getopt.h"
#include "string.h"


float ar1[1000][1000], L0[100000];
float y1t, z1t, l1t, x1;

int i,w1,j,width, xt, yt, zt, x1t, yt1,xt1, yt2, xt2, yt3, xt3, yt4, xt4, yt5, xt5, xt6, xt7, xt8, xt9, xt10, yt10, xt11, yt11, xt12, yt12, zt12, xt13, yt13, zt13, xt14, xt15, xt16, xt17, xt18, yt18, zt18, xt19, yt19, zt19, opt, v, a, b, c, d;
int totalsize = 0, totalsize1 = 0, totalsize12 = 0, totalsize13 = 0, totalsize2 = 0, totalsize3 = 0, totalsize4 = 0, totalsize5 = 0, totalsize6 = 0, totalsize7 = 0, totalsize8 = 0, totalsize9 = 0, totalsize10 = 0, totalsize11 = 0, totalsize20 = 0, totalsize14 = 0, totalsize15 = 0, totalsize16 = 0, totalsize17 = 0, totalsize18 = 0, totalsize19 = 0;

unsigned int t;
double angle, scale;
double z1, y14,o1,p1,r1,q1;

char str[1000], str1[1000];
char * ret, *ret1, *ret11, *ret12, *ret2, *ret3, *ret4, *ret5, *ret6, *ret7, *ret8, *ret9, *ret10, *ret13, *ret14, *ret15, *ret16, *ret17, *ret18, *ret19, *ret20, *ptr;


int main(int argc, char** argv)
{

char s[3]="-", s5[3]="-", s3[3]="-", s4[3]="-",s7[3]="-",s6[3]="-", s8[3]="-", s9[3]="-", s10[3]="-", s11[3]="-", s2[5]=" ", s25[5]=" ", s12[5]=" ", s13[5]=" ", s14[5]=" ", s15[5]=" ", s16[5]=" ", s17[5]=" ", s18[5]=" ", s19[5]=" ", s20[5]=" ", s21[5]="-", s22[5]=" ", s23[5]="-", s24[5]=" ", s27[5]="-", s26[5]=" ", s28[5]= "-", s29[5]= " ", s30[5]= "-", s31[5]= " ", s32[5]= "-", s33[5]= " ", s34[5]= "-", s35[5]= " ",  s36[5]= "-", s37[5]= " ", c77[10], c771[10], d771[100], c88[10], c99[10], c66[10], c7[10], b7[10]="f", b17[10]="m", b16[10]="M", b18[10]="g", b19[10]="G", b20[10]="l", b21[10]="L", b22[10]="s", b23[10]="S", b24[10]="b", b25[10]="B", b26[10]="k", b27[10]="K", b28[10]="d", b29[10]="D", b30[10]="e", b31[10]="E", b32[10]="p", d7[100], d66[100], d77[100], d8[100], d81[100], d9[100], d91[100], d92[100], d93[100], d94[100], d95[100], d96[100], d97[100], d98[100], d99[100], d100[100], d101[100], d102[100], c1[50], d1[50], c12[50], d121[50], c121[50], c13[50], c122[50], c123[50], c124[50], c125[50], c126[50], c127[50], c128[50], c129[50], c130[50], c131[50], c132[50], c133[50], c134[50], c135[50], c22[50], c23[50], d12[50], d122[50], d123[50], d124[50], d125[50], d126[50], d127[50], d128[50], d129[50], d130[50], d131[50], d132[50], d133[50], d134[50], d135[50], d13[50], c15[50], d5[50], c5[50], d15[50], b1[5]="a[1]", b2[5]="a[2]", b3[5]="a[3]", b4[5]="a[4]", b5[5]="a[5]", b6[5]="a[6]", b71[5]="a[7]", b8[5]="a[8]", f[10]="F";

char *token, *a7, *a77, *a771, *a8, *a18, *a28, *a38, *a48, *a58, *a68, *a78, *a79, *a88, *a9, *a99, *a51, *a52, *a53, *a54, *a55, *a56, *a66, *a75, *a76, *a772, *a781,  *a791, *a800, *a801, *a802, *a803, *a80,  *a81, *a82, *token2, *a1, *a12, *a13, *token1, *token5, *token25, *a15, *a5, *token3, *token6, *token21, *token22, *token7, *token17, *token8, *token18, *token9, *token91, *token27, *token28, *token29, *token30, *token31, *token32, *token33, *token34, *token35, *token36, *token37, *token38, *token39, *token40, *token41, *token42, *token43, *token44, *token45, *token46, *token47, *token48, *token49, *token50, *token51, *token52, *token53;

CvMat*  rgb3;
CvMat*  rgb1;
CvMat*  rgb2;
CvMat*  rot;
CvMat*  rot3;
CvMat* rgbMat;
CvScalar sum1;
CvScalar sum;
CvScalar avg;
CvPoint2D32f center;

IplImage* dst;
IplImage* dst1;
IplImage* dstnew;
IplImage* srcnew;
IplImage* srcp;
IplImage* div1;
IplImage* dest;
IplImage* div;


    


IplImage* src = cvLoadImage(argv[1],0); // Loading the original image that is to be processed or filtered as Gray-scale
	  if (src==NULL)
	   {
           printf("Hey!  Can't read image\n");
           system("PAUSE");
           return 1;
           }

          cvNamedWindow(argv[1], 1);
          cvShowImage(argv[1], src);

while((opt = getopt(argc, argv, "fF:j:m:M:g:G:l:L:s:S:b:B:k:K:d:D:e:E:p:")) != -1) {
    switch (opt){


	case 'p': //case p for darkening the original image

		 for (t = 0; t < argc; t++)
        	 {
         	 totalsize19 += strlen(argv[t]);
        	 }
       		 ret20 = new char[totalsize19 + argc + 1];
		 ret20[0]=0;
      		 for (t = 0; t < argc; t++)
       		 {
        	 strcat(ret20, argv[t]);
        	 strcat(ret20, " ");
       		 }

		 token52 = strtok(ret20, s36);
	
		 while( token52 != NULL ) 
        	{
		for(i=0;i<=6;i++){
		a802 =token52;
        	snprintf(d102, sizeof(d102), "%s", a802 );
	
		if (0 == strncmp(b32, d102,1)){
		if (d102[0] == 'p') 
       		memmove(d102, d102+1, strlen(d102));
		if (d102[0] == ' ') 
       		memmove(d102, d102+1, strlen(d102));
		token53 = strtok(d102,s37);
	
		while( token53 != NULL ) 
    		{
	 	for(i=1;i<=7;i++){
		a803 =token53;
      
		snprintf(c135, sizeof(c135), "a[%d]", i );
		snprintf(d135, sizeof(d135), "%s", a803 );
		if (0 == strncmp(b1, c135,4)){
	 	xt18 = atoi(d135);
		printf("The value of xt8 is %d\n", xt18);
		}

		else if (0 == strncmp(b2, c135,4)){
	 	yt18 = atoi(d135);
		printf("The value of yt1 is %d\n", yt18);
		}

		else if (0 == strncmp(b3, c135,4)){
	 	zt18 = atoi(d135);
		printf("The value of yt1 is %d\n", zt18);
		}

		else if (0 == strncmp(b4, c135,4)){
	 	yt19 = atoi(d135);
		printf("The value of yt1 is %d\n", yt19);
		}

		else if (0 == strncmp(b5, c135,4)){
	 	zt19 = atoi(d135);
		printf("The value of yt1 is %d\n", zt19);
		}

		else if (0 == strncmp(b6, c135,4)){
	 	xt19 = atoi(d135);
		printf("The value of yt1 is %d\n", xt19);
		}

        	token53 = strtok(NULL, s37);
        	}
   		}
   		}
        	token52 = strtok(NULL, s36);
		}
		}

		printf("The value of xt8 is %d, %d, %d, %d, %d, %d\n", xt18, yt18, zt18, xt19, yt19, zt19);

	 	srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
		div1 = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
		dest = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
		div= cvCreateImage(cvSize(src->width, src->height),  src->depth,  src->nChannels);
		cvSet( div, cvScalar(xt18, yt18, zt18), NULL); //2,2,2 expected values
		cvDiv( src, div, dest, 1 );
		cvSet( div1, cvScalar( xt19, yt19, zt19 ), NULL);//64,64,64 expected values
		//cvScaleAdd(src, cvScalar(xt19, yt19, zt19), div1, srcnew);
		cvScaleAdd(dest, cvScalar(1,1,1), div1, srcnew);


	 	cvNamedWindow("srcDarkening1", 1);
         	cvShowImage("srcDarkening1", dest);
	 	cvNamedWindow("srcDarkening", 1);
         	cvShowImage("srcDarkening", srcnew);
         	cvWaitKey(0);
	 	cvDestroyWindow("srcDarkening");
         	break;	



	
	case 'e': //case e for erode before

		 for (t = 0; t < argc; t++)
       		 {
         	 totalsize17 += strlen(argv[t]);
       		 }
		 printf("Hi I got printed 1\n");
       		 ret18 = new char[totalsize17 + argc + 1];

		 ret18[0]=0;
      		 for (t = 0; t < argc; t++)
      		 {
       		 strcat(ret18, argv[t]);
        	 strcat(ret18, " ");
       		 }

		 token47 = strtok(ret18, s32);
		 while( token47 != NULL ) 
        	 {
		 for(i=0;i<=1;i++){
		 a781 =token47;
        	 snprintf(d100, sizeof(d100), "%s", a781 );
		 if (0 == strncmp(b30, d100,1)){
		 if (d100[0] == 'e') 
       	         memmove(d100, d100+1, strlen(d100));
	         if (d100[0] == ' ') 
       	         memmove(d100, d100+1, strlen(d100));
	
	         token48 = strtok(d100,s33);
	         while( token48 != NULL ) 
    	         {
	         for(i=1;i<=2;i++){
	         a801 =token48;
      
	         snprintf(c133, sizeof(c133), "a[%d]", i );
		 snprintf(d133, sizeof(d133), "%s", a801 );
		 if (0 == strncmp(b1, c133,4)){
	 	 xt16 = atoi(d133);
	 	 printf("The value of xt8 is %d\n", xt16);
		 }
		 token48 = strtok(NULL, s33);
       		 }
		 }
		 }
        	 token47 = strtok(NULL, s32);
		 }
		 }

   		 srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
		 cvErode(src, srcnew, NULL,xt16 );
		 cvNamedWindow("dstErodeBefore", 1);
                 cvShowImage("dstErodeBefore", srcnew);
		 cvWaitKey(0);
                 break;	



	case 'E': //case k for erode after

		 for (t = 0; t < argc; t++)
        	 {
         	 totalsize18 += strlen(argv[t]);
       		 }
		 printf("Hi I got printed 1\n");
       		 ret19 = new char[totalsize18 + argc + 1];

		 ret19[0]=0;
      		 for (t = 0; t < argc; t++)
      		 {
       		 strcat(ret19, argv[t]);
        	 strcat(ret19, " ");
      		 }

		 token49 = strtok(ret19, s34);
	
		 while( token49 != NULL ) 
        	 {
		 for(i=0;i<=1;i++){
		 a791 =token49;
        
		 snprintf(d101, sizeof(d101), "%s", a791 );
		 if (0 == strncmp(b31, d101,1)){
		 if (d101[0] == 'E') 
      		 memmove(d101, d101+1, strlen(d101));
		 if (d101[0] == ' ') 
       		 memmove(d101, d101+1, strlen(d101));
		 token50 = strtok(d101,s35);
	
		 while( token50 != NULL ) 
    		 {
	 	 for(i=1;i<=2;i++){
		 a800 =token50;
		 snprintf(c134, sizeof(c134), "a[%d]", i );
		 snprintf(d134, sizeof(d134), "%s", a800 );
	
		 if (0 == strncmp(b1, c134,4)){
	 	 xt17 = atoi(d134);
	
		 printf("The value of xt8 is %d\n", xt17);
		 }

        	 token50 = strtok(NULL, s35);
        	 }
	  	 }
		 }
        	 token49 = strtok(NULL, s34);
		 }
		 }

   		 srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
		 cvErode(src, srcnew, NULL,xt17 );
		 cvNamedWindow("dstErodeAfter", 1);
                 cvShowImage("dstErodeAfter", srcnew);
		 cvWaitKey(0);
                 break;	




	
	
	case 'd': //case k for dilate before

		 for (t = 0; t < argc; t++)
        	 {
         	  totalsize15 += strlen(argv[t]);
        	 }
       		 ret16 = new char[totalsize15 + argc + 1];
		 ret16[0]=0;
      		 for (t = 0; t < argc; t++)
      		 {
        	 strcat(ret16, argv[t]);
        	 strcat(ret16, " ");
       		 }
	
     		 token43 = strtok(ret16, s28);
	
		 while( token43 != NULL ) 
        	 {
		 for(i=0;i<=1;i++){
		 a75 =token43;
		 snprintf(d98, sizeof(d98), "%s", a75 );
		 if (0 == strncmp(b28, d98,1)){
		 if (d98[0] == 'd') 
      		 memmove(d98, d98+1, strlen(d98));
		 if (d98[0] == ' ') 
      		 memmove(d98, d98+1, strlen(d98));
		 token44 = strtok(d98,s29);
	
		 while( token44 != NULL ) 
    		 {
	 	 for(i=1;i<=2;i++){
		 a76 =token44;
		 snprintf(c131, sizeof(c131), "a[%d]", i );
		 snprintf(d131, sizeof(d131), "%s", a76 );
		 if (0 == strncmp(b1, c131,4)){
	 	 xt14 = atoi(d131);
		 printf("The value of xt8 is %d\n", xt14);
		 }
	         token44 = strtok(NULL, s29);
   	         }
   	         }

    	         }
                 token43 = strtok(NULL, s28);
	         }
		 }

 		 srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
		 cvDilate(src, srcnew, NULL,xt14 );
		 cvNamedWindow("dstDilateBefore", 1);
                 cvShowImage("dstDilateBefore", srcnew);
		 cvWaitKey(0);
                 break;	



	case 'D': //case k for dilate after

		 for (t = 0; t < argc; t++)
        	 {
         	 totalsize16 += strlen(argv[t]);
        	 }
       		 ret17 = new char[totalsize16 + argc + 1];
		 ret17[0]=0;
     		 for (t = 0; t < argc; t++)
      		 {
       		 strcat(ret17, argv[t]);
        	 strcat(ret17, " ");
       		 }
		 token45 = strtok(ret17, s30);
	
		 while( token45 != NULL ) 
        	 {
		 for(i=0;i<=1;i++){
		 a772 =token45;
		 snprintf(d99, sizeof(d99), "%s", a772 );
		 if (0 == strncmp(b29, d99,1)){
		 if (d99[0] == 'D') 
      		 memmove(d99, d99+1, strlen(d99));
		 if (d99[0] == ' ') 
      		 memmove(d99, d99+1, strlen(d99));
		 token46 = strtok(d99,s31);
	
		 while( token46 != NULL ) 
    		 {
	 	 for(i=1;i<=2;i++){
		 a781 =token46;
		 snprintf(c132, sizeof(c132), "a[%d]", i );
		 snprintf(d132, sizeof(d132), "%s", a781 );
		 if (0 == strncmp(b1, c132,4)){
	 	 xt15 = atoi(d132);
		 }
		 token46 = strtok(NULL, s31);
        	 }
		 }

    		}
        	token45 = strtok(NULL, s30);
		}
		}

   		srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
		cvDilate(src, srcnew, NULL,xt15 );
		cvNamedWindow("dstdilateAfter", 1);
                cvShowImage("dstdilateAfter", srcnew);
		cvWaitKey(0);
                break;	





	case 'k': //case k for bilateral filtering before

		 for (t = 0; t < argc; t++)
       		 {
         	 totalsize20 += strlen(argv[t]);
       		 }
       		 ret14 = new char[totalsize20 + argc + 1];
		 ret14[0]=0;
      		 for (t = 0; t < argc; t++)
       		 {
        	 strcat(ret14, argv[t]);
       		 strcat(ret14, " ");
       		 }
		 token39 = strtok(ret14, s23);
	
		 while( token39 != NULL ) 
        	 {
		 for(i=0;i<=3;i++){
		 a53 =token39;
		 snprintf(d96, sizeof(d96), "%s", a53 );
		 if (0 == strncmp(b26, d96,1)){
	  	 if (d96[0] == 'k') 
                 memmove(d96, d96+1, strlen(d96));
		 if (d96[0] == ' ') 
       		 memmove(d96, d96+1, strlen(d96));
		 token40 = strtok(d96,s24);
	
		 while( token40 != NULL ) 
    		 {
	 	 for(i=1;i<=3;i++){
		 a54 =token40;
		 snprintf(c129, sizeof(c129), "a[%d]", i );
		 snprintf(d129, sizeof(d129), "%s", a54 );
		 if (0 == strncmp(b1, c129,4)){
	 	 xt12 = atoi(d129);
		 }

		 else if (0 == strncmp(b2, c129,4)){
	 	 yt12 = atoi(d129);
		 printf("The value of yt1 is %d\n", yt12);
		 }

		 else if (0 == strncmp(b3, c129,4)){
		 zt12 = atoi(d129);
		 printf("The value of yt1 is %d\n", zt12);
		 }
        	 token40 = strtok(NULL, s24);
        	 }
   		 }
		 }
       		 token39 = strtok(NULL, s23);
		 }
		 }

   		 srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
		 cvSmooth(src, srcnew, CV_BILATERAL, xt12, 0, yt12, zt12);
		 cvNamedWindow("dstBilateralBefore", 1);
                 cvShowImage("dstBilateralBefore", srcnew);
		 cvWaitKey(0);
                 break;


	
	case 'K': //case k for bilateral filtering after

		 for (t = 0; t < argc; t++)
        	 {
         	 totalsize14 += strlen(argv[t]);
        	 }
      		 ret15 = new char[totalsize14 + argc + 1];
		 ret15[0]=0;
      		 for (t = 0; t < argc; t++)
       		 {
        	 strcat(ret15, argv[t]);
        	 strcat(ret15, " ");
       		 }

		token41 = strtok(ret15, s27);
	
		while( token41 != NULL ) 
        	{
		for(i=0;i<=3;i++){
		a55 =token41;
       		snprintf(d97, sizeof(d97), "%s", a55 );
		if (0 == strncmp(b27, d97,1)){
		if (d97[0] == 'K') 
       		memmove(d97, d97+1, strlen(d97));
		if (d97[0] == ' ') 
      	        memmove(d97, d97+1, strlen(d97));
		token42 = strtok(d97,s26);
	
		while( token42 != NULL ) 
    		{
	 	for(i=1;i<=3;i++){
		a56 =token42;
		snprintf(c130, sizeof(c130), "a[%d]", i );
		snprintf(d130, sizeof(d130), "%s", a56 );
		if (0 == strncmp(b1, c130,4)){
	 	xt13 = atoi(d130);
		printf("The value of xt8 is %d\n", xt13);
		}

		else if (0 == strncmp(b2, c130,4)){
	 	yt13 = atoi(d130);
		printf("The value of yt1 is %d\n", yt13);
		}

		else if (0 == strncmp(b3, c130,4)){
	 	zt13 = atoi(d130);
		printf("The value of yt1 is %d\n", zt13);
		}

        	token42 = strtok(NULL, s26);
        	}
   	
		}

    		}
        	token41 = strtok(NULL, s27);
		}
		}

		printf("The value of xt8 is %d, %d, %d\n", xt13, yt13, zt13);
   		srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
		cvSmooth(src, srcnew, CV_BILATERAL, xt13, 0, yt13, zt13);
		cvNamedWindow("dstBilateralAfter", 1);
                cvShowImage("dstBilateralAfter", srcnew);
		cvWaitKey(0);
                break;





    case 'b': //case b for blur before
		for (t = 0; t < argc; t++)
        	{
         	totalsize10 += strlen(argv[t]);
        	}
       		ret10 = new char[totalsize10 + argc + 1];
		ret10[0]=0;
      		for (t = 0; t < argc; t++)
       		{
        	strcat(ret10, argv[t]);
        	strcat(ret10, " ");
       		}
		token35 = strtok(ret10, s11);
	
		while( token35 != NULL ) 
       	 	{
		for(i=0;i<=1;i++){
		a79 =token35;
		snprintf(d94, sizeof(d94), "%s", a79 );
	
		if (0 == strncmp(b24, d94,1)){
		if (d94[0] == 'b') 
       		memmove(d94, d94+1, strlen(d94));
		if (d94[0] == ' ') 
      	        memmove(d94, d94+1, strlen(d94));
		token36 = strtok(d94,s20);
	
		while( token36 != NULL ) 
    		{
	 	for(i=1;i<=2;i++){
		a99 =token36;
		snprintf(c127, sizeof(c127), "a[%d]", i );
		snprintf(d127, sizeof(d127), "%s", a99 );
		printf("The value of d1 is %s\n", d127);

		if (0 == strncmp(b1, c127,4)){
	 	xt10= atoi(d127);
		printf("The value of xt8 is %d\n", xt10);
		}

		else if (0 == strncmp(b2, c127,4)){
	 	yt10 = atoi(d127);
		printf("The value of yt1 is %d\n", yt10);
		}
        	token36 = strtok(NULL, s20);
        	}
		}
		}
        	token35 = strtok(NULL, s11);
		}
		}
       

   		 srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
		 cvSmooth(src, srcnew, CV_BLUR, xt10, yt10, 0,0);
		 cvNamedWindow("dstBlurBefore", 1);
                 cvShowImage("dstBlurBefore", srcnew);
		 cvWaitKey(0);
                 break;



	case 'B': //case b for blur after

		 for (t = 0; t < argc; t++)
        	 {
         	 totalsize11 += strlen(argv[t]);
        	 }
       		 ret13 = new char[totalsize11 + argc + 1];
		 ret13[0]=0;
      		 for (t = 0; t < argc; t++)
       		 {
        	 strcat(ret13, argv[t]);
        	 strcat(ret13, " ");
       		 }
	
    		 token37 = strtok(ret13, s21);
	
		while( token37 != NULL ) 
        	{
		for(i=0;i<=2;i++){
		a51 =token37;
		snprintf(d95, sizeof(d95), "%s", a51 );
		if (0 == strncmp(b25, d95,1)){
		if (d95[0] == 'B') 
      	        memmove(d95, d95+1, strlen(d95));
		if (d95[0] == ' ') 
      	        memmove(d95, d95+1, strlen(d95));
		token38 = strtok(d95,s22);
	
		while( token38 != NULL ) 
    		{
	 	for(i=1;i<=2;i++){
		a52 =token38;
		snprintf(c128, sizeof(c128), "a[%d]", i );
		snprintf(d128, sizeof(d128), "%s", a52 );
		printf("The value of d1 is %s\n", d128);

		if (0 == strncmp(b1, c128,4)){
	 	xt11= atoi(d128);
		printf("The value of xt8 is %d\n", xt11);
		}

		else if (0 == strncmp(b2, c128,4)){
	 	yt11 = atoi(d128);
		printf("The value of yt1 is %d\n", yt11);
		}

        	token38 = strtok(NULL, s22);
        	}
   		}
    		}
        	token37 = strtok(NULL, s21);
		}
		}

		printf("The value of xt8 is %d, %d\n", xt11, yt11);
       

   		 srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
		 cvSmooth(src, srcnew, CV_BLUR, xt11, yt11, 0,0);
		 cvNamedWindow("dstBlurAfter", 1);
                 cvShowImage("dstBlurAfter", srcnew);
		 cvWaitKey(0);
                 break;



	

	case 's': //case s for sobel before

		 for (t = 0; t < argc; t++)
        	 {
         	 totalsize8 += strlen(argv[t]);
        	 }
      		 ret8 = new char[totalsize8 + argc + 1];
		 ret8[0]=0;
     		 for (t = 0; t < argc; t++)
      		 {
        	 strcat(ret8, argv[t]);
        	 strcat(ret8, " ");
      		 }
		 token31 = strtok(ret8, s9);
	
		while( token31 != NULL ) 
        	{
		for(i=0;i<=1;i++){
		a58 =token31;
		snprintf(d92, sizeof(d92), "%s", a58 );
		if (0 == strncmp(b22, d92,1)){
		if (d92[0] == 's') 
       		memmove(d92, d92+1, strlen(d92));
		if (d92[0] == ' ') 
       		memmove(d92, d92+1, strlen(d92));
		token32 = strtok(d92,s18);
	
		while( token32 != NULL ) 
    		{
	 	for(i=1;i<=1;i++){
		a68=token32;
		snprintf(c125, sizeof(c125), "a[%d]", i );
		snprintf(d125, sizeof(d125), "%s", a68 );
		printf("The value of d1 is %s\n", d125);

		if (0 == strncmp(b1, c125,4)){
	 	xt8= atoi(d125);
	
		printf("The value of xt8 is %d\n", xt8);
		}

        	token32 = strtok(NULL, s18);
        	}  	
		}
    		}
        	token31 = strtok(NULL, s9);
		}
		}

   		 srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
		 cvSobel(src, srcnew, 1, 0, xt8 );
		 cvNamedWindow("dstSobelBefore", 1);
                 cvShowImage("dstSobelBefore", srcnew);
		 cvWaitKey(0);
                 break;


	

	case 'S': //case S for sobel after

		 for (t = 0; t < argc; t++)
        	 {
         	 totalsize9 += strlen(argv[t]);
        	 }
      		 ret9 = new char[totalsize9 + argc + 1];

		ret9[0]=0;
      		for (t = 0; t < argc; t++)
      		{
       		strcat(ret9, argv[t]);
        	strcat(ret9, " ");
      		}
		token33 = strtok(ret9, s10);
	
		while( token33 != NULL ) 
        	{
		for(i=0;i<=1;i++){
		a78 =token33;
		snprintf(d93, sizeof(d93), "%s", a78 );
		if (0 == strncmp(b23, d93,1)){
		if (d93[0] == 'S') 
       		memmove(d93, d93+1, strlen(d93));
		if (d93[0] == ' ') 
       		memmove(d93, d93+1, strlen(d93));
		token34 = strtok(d93,s19);
	
		while( token34 != NULL ) 
    		{
	 	for(i=1;i<=1;i++){
		a88=token34;
		snprintf(c126, sizeof(c126), "a[%d]", i );
		snprintf(d126, sizeof(d126), "%s", a88 );
		printf("The value of d1 is %s\n", d126);

		if (0 == strncmp(b1, c126,4)){
	 	xt9= atoi(d126);
		printf("The value of xt8 is %d\n", xt9);
		}
	        token34 = strtok(NULL, s19);
        	}
		}
    		}
       	        token33 = strtok(NULL, s9);
		}
		}

		 srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
		 cvSobel(src, srcnew, 1, 0, xt9 );
		 cvNamedWindow("dstSobelAfter", 1);
                 cvShowImage("dstSobelAfter", srcnew);
		 cvWaitKey(0);
                 break;




	
	case 'g': // case g for gaussian blur with standard deviation as 0 before

		 for (t = 0; t < argc; t++)
      		 {
         	 totalsize4 += strlen(argv[t]);
     		 }
		 ret4 = new char[totalsize4 + argc + 1];
		 ret4[0]=0;
      		 for (t = 0; t < argc; t++)
      		 {
        	 strcat(ret4, argv[t]);
        	 strcat(ret4, " ");
      		 }
     		 token7 = strtok(ret4, s6);
	
		while( token7 != NULL ) 
        	{
		for(i=0;i<=2;i++){
		a8 =token7;
		snprintf(d8, sizeof(d8), "%s", a8 );
		if (0 == strncmp(b18, d8,1)){
		if (d8[0] == 'g') 
       		memmove(d8, d8+1, strlen(d8));
   		if (d8[0] == ' ') 
      	        memmove(d8, d8+1, strlen(d8));
		token17 = strtok(d8,s14);
	
		while( token17 != NULL ) 
    		{
	 	for(i=1;i<=2;i++){
		a18=token17;
		snprintf(c121, sizeof(c121), "a[%d]", i );
		snprintf(d121, sizeof(d121), "%s", a18 );
		if (0 == strncmp(b1, c121,4)){
	 	xt3= atoi(d121);
		printf("The value of xt1 is %d\n", xt3);
		}

		else if (0 == strncmp(b2, c121,4)){
	 	yt3 = atoi(d121);
		printf("The value of yt1 is %d\n", yt3);
		}

        	token17 = strtok(NULL, s14);
        	}
   	
		}

    		}
        	token7 = strtok(NULL, s6);
		}
		}
                printf("The value of xt1 is %d\n", xt3);
		printf("The value of yt1 is %d\n", yt3);

   		 srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
                 cvSmooth(src, srcnew, CV_GAUSSIAN, xt3,yt3,0,0);
		 cvNamedWindow("dstGaussianBefore", 1);
                 cvShowImage("dstGaussianBefore", srcnew);
		 cvWaitKey(0);
                 break;



	case 'G': //case G for gaussian blur with standard deviation as 0 after
      

		 for (t = 0; t < argc; t++)
      		 {
         	 totalsize5 += strlen(argv[t]);
      		 }
      		 ret5 = new char[totalsize5 + argc + 1];
		 ret5[0]=0;
      		 for (t = 0; t < argc; t++)
      		 {
       		 strcat(ret5, argv[t]);
        	 strcat(ret5, " ");
      		 }
     	       	 token9 = strtok(ret5, s7);
	
		while( token9 != NULL ) 
        	{
		for(i=0;i<=2;i++){
		a771=token9;
		snprintf(c771, sizeof(c771), "a77[%d]", i );
		snprintf(d771, sizeof(d771), "%s", a771 );

		if (0 == strncmp(b19, d771,1)){
		if (d771[0] == 'G') 
       		memmove(d771, d771+1, strlen(d771));
		if (d771[0] == ' ') 
      	        memmove(d771, d771+1, strlen(d771));
		printf("The value of new d is %s\n", d771);
		token91 = strtok(d771,s15);
	
		while( token91 != NULL ) 
    		{
	 	for(i=1;i<=2;i++){
		a12=token91;
		snprintf(c122, sizeof(c122), "a[%d]", i );
		snprintf(d122, sizeof(d122), "%s", a12 );
	
		if (0 == strncmp(b1, c122,4)){
	 	xt5= atoi(d122);
		printf("The value of xt5 is %d\n", xt5);
		}

		else if (0 == strncmp(b2, c122,4)){
	 	yt5= atoi(d122);
		printf("The value of yt5 is %d\n", yt5);
		}
	        token91 = strtok(NULL, s15);
        	}
		}
    		}
        	token9 = strtok(NULL, s7);
		}
		}

   		 srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
                 cvSmooth(src, srcnew, CV_GAUSSIAN, xt5,yt5,0,0);
		 cvNamedWindow("dstGaussianAfter", 1);
                 cvShowImage("dstGaussianAfter", srcnew);
		 cvWaitKey(0);
                 break;


      



	case 'm': //case m for median blur before


      		 for (t = 0; t < argc; t++)
      		 {
         	 totalsize2 += strlen(argv[t]);
      		 }
      		 ret2 = new char[totalsize2 + argc + 1];
		 ret2[0]=0;
      		 for (t = 0; t < argc; t++)
      		 {
        	 strcat(ret2, argv[t]);
        	 strcat(ret2, " ");
      		 }
     	       	 token3 = strtok(ret2, s3);
	
		 while( token3 != NULL ) 
        	 {
		 for(i=0;i<=2;i++){
		 a77=token3;
		 snprintf(c77, sizeof(c77), "a77[%d]", i );
		 snprintf(d77, sizeof(d77), "%s", a77 );
	
		if (0 == strncmp(b17, d77,1)){
		if (d77[0] == 'm') 
       		memmove(d77, d77+1, strlen(d77));
		if (d77[0] == ' ') 
       		memmove(d77, d77+1, strlen(d77));
	
		token21 = strtok(d77,s12);
	
		while( token21 != NULL ) 
    		{
	 	for(i=1;i<=2;i++){
		a12=token21;
      
		snprintf(c12, sizeof(c12), "a[%d]", i );
		snprintf(d12, sizeof(d12), "%s", a12 );
		if (0 == strncmp(b1, c12,4)){
	 	xt1= atoi(d12);
		printf("The value of xt1 is %d\n", xt1);
		}

		else if (0 == strncmp(b2, c12,4)){
	 	yt1= atoi(d12);
		printf("The value of yt1 is %d\n", yt1);
		}

        	token21 = strtok(NULL, s12);
        	}   	
		}
    		}
        	token3 = strtok(NULL, s3);
      
		}
		}


   		 srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
                 cvSmooth(src, srcnew, CV_MEDIAN, xt1,yt1,0,0);
		 cvNamedWindow("dstMedianBefore", 1);
                 cvShowImage("dstMedianBefore", srcnew);
		 cvWaitKey(0);
                 break;



	case 'M': //case M for median blur after


      		 for (t = 0; t < argc; t++)
      		 {
         	 totalsize3 += strlen(argv[t]);
      		 }
      		 ret3 = new char[totalsize3 + argc + 1];
	         ret3[0]=0;
                 for (t = 0; t < argc; t++)
                 {
        	 strcat(ret3, argv[t]);
        	 strcat(ret3, " ");
      		 }

		token6 = strtok(ret3, s4);
	
		while( token6 != NULL ) 
        	{
		for(i=0;i<=2;i++){
		a66=token6;
		snprintf(c66, sizeof(c66), "a66[%d]", i );
		snprintf(d66, sizeof(d66), "%s", a66 );
		
		if (0 == strncmp(b16, d66,1)){
		if (d66[0] == 'M') 
       		memmove(d66, d66+1, strlen(d66));

		if (d66[0] == ' ') 
       		memmove(d77, d77+1, strlen(d66));

		token22 = strtok(d66,s13);
	
		while( token22 != NULL ) 
    		{	
	 	for(i=1;i<=3;i++){
		a13=token22;
		snprintf(c13, sizeof(c13), "a[%d]", i );
		snprintf(d13, sizeof(d13), "%s", a13 );
	
		if (0 == strncmp(b1, c13,4)){
	 	xt2= atoi(d13);
		printf("The value of xt2 is %d\n", xt2);
		}

		else if (0 == strncmp(b2, c13,4)){
	 	yt2= atoi(d13);
		printf("The value of yt2 is %d\n", yt2);
		}

        	token22 = strtok(NULL, s13);
        	}
   		}
		}
        	token6 = strtok(NULL, s4);
		}	
		}

		 srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
                 cvSmooth(src, srcnew, CV_MEDIAN, xt2,yt2,0,0);
		 cvNamedWindow("dstMedianAfter", 1);
                 cvShowImage("dstMedianAfter", srcnew);
		 cvWaitKey(0);
                 break;



	case 'l': //case l for laplacian before

		for (t = 0; t < argc; t++)
      		{
         	totalsize6 += strlen(argv[t]);
      		}
      		ret6 = new char[totalsize6 + argc + 1];

		ret6[0]=0;
      		for (t = 0; t < argc; t++)
      		{
        	strcat(ret6, argv[t]);
        	strcat(ret6, " ");
      		}
     		token27 = strtok(ret6, s8);
	
		while( token27 != NULL ) 
        	{
		for(i=0;i<=1;i++){
		a28 =token27;
		snprintf(c99, sizeof(c99), "a77[%d]", i );
		snprintf(d81, sizeof(d81), "%s", a28 );
	
		if (0 == strncmp(b20, d81,1)){
		if (d81[0] == 'l') 
       		memmove(d81, d81+1, strlen(d81));
	
		if (d81[0] == ' ') 
       		memmove(d81, d81+1, strlen(d81));
	
		token28 = strtok(d81,s16);
	
		while( token28 != NULL ) 
    		{
	 	for(i=1;i<=1;i++){
		a18=token28;
		snprintf(c123, sizeof(c123), "a[%d]", i );
		snprintf(d123, sizeof(d123), "%s", a18 );
		if (0 == strncmp(b1, c123,4)){
	 	xt6= atoi(d123);
		printf("The value of xt1 is %d\n", xt6);
		}

        	token28 = strtok(NULL, s16);
        	}   	
		}
    		}
        	token27 = strtok(NULL, s8);	
		}
		}

	   	 srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
		 cvLaplace(src, srcnew, xt6);
		 cvNamedWindow("dstLaplacianBefore", 1);
                 cvShowImage("dstLaplacianBefore", srcnew);
		 cvWaitKey(0);
                 break;



	case 'L': //case L for laplacian after

		 for (t = 0; t < argc; t++)
      		 {
         	 totalsize7 += strlen(argv[t]);
      		 }
      		 ret7 = new char[totalsize7 + argc + 1];
		 ret7[0]=0;
      		 for (t = 0; t < argc; t++)
      		 {
        	 strcat(ret7, argv[t]);
        	 strcat(ret7, " ");
      		 }
		 token29 = strtok(ret7, s9);
	
		while( token29 != NULL ) 
        	{
		for(i=0;i<=1;i++){
		a38 =token29;
        	snprintf(c99, sizeof(c99), "a77[%d]", i );
		snprintf(d91, sizeof(d91), "%s", a38 );
	
		if (0 == strncmp(b21, d91,1)){
		if (d91[0] == 'L') 
       		memmove(d91, d91+1, strlen(d91));

		if (d91[0] == ' ') 
       		memmove(d91, d91+1, strlen(d91));
		token30 = strtok(d91,s17);
	
		while( token30 != NULL ) 
    		{
	 	for(i=1;i<=1;i++){
		a48=token30;
		snprintf(c124, sizeof(c124), "a[%d]", i );
		snprintf(d124, sizeof(d124), "%s", a48 );
		if (0 == strncmp(b1, c124,4)){
	 	xt7= atoi(d124);
		printf("The value of xt1 is %d\n", xt7);
		}

        	token30 = strtok(NULL, s17);
        	}
		}
    		}
        	token29 = strtok(NULL, s9);
		}
		}

   		 srcnew = cvCreateImage(cvSize(src->width, src->height), src->depth, src->nChannels);
		 cvLaplace(src, srcnew, xt7);
		 cvNamedWindow("dstLaplacianAfter", 1);
                 cvShowImage("dstLaplacianAfter", srcnew);
		 cvWaitKey(0);
                 break;







      case 'f': //filter by creating own filter

	
      		for (t = 0; t < argc; t++)
      		{
         	totalsize += strlen(argv[t]);
      		}
      		ret = new char[totalsize + argc + 1];
		ret[0]=0;
      		for (t = 0; t < argc; t++)
      		{
        	strcat(ret, argv[t]);
        	strcat(ret, " ");
      		}
     
		if((strstr(ret,"-m") != NULL) || (strstr(ret,"-g") != NULL) || (strstr(ret,"-l") != NULL) || (strstr(ret,"-s") != NULL) || (strstr(ret,"-b") != NULL) || (strstr(ret,"-k") != NULL) || (strstr(ret,"-d") != NULL) || (strstr(ret,"-e") != NULL) || (strstr(ret,"-p") != NULL)){
		srcp=srcnew;
		printf("Hi I am new\n");
		}

		else{
         	srcp=src;
	 	printf("Hi I am old\n");
		}


		token = strtok(ret, s);
	
		while( token != NULL ) 
        	{
		for(i=0;i<=7;i++){
		a7=token;
		snprintf(c7, sizeof(c7), "a[%d]", i );
		snprintf(d7, sizeof(d7), "%s", a7 );
	
		if (0 == strncmp(b7, d7,1)){
		if (d7[0] == 'f') 
       		memmove(d7, d7+1, strlen(d7));

		if (d7[0] == ' ') 
       		memmove(d7, d7+1, strlen(d7));
	
		char s2[5]=" ";
		token2 = strtok(d7,s2);
	
		while( token2 != NULL ) 
    		{
	 	for(i=1;i<=7;i++){
		a1=token2;
		snprintf(c1, sizeof(c1), "a[%d]", i );
		snprintf(d1, sizeof(d1), "%s", a1 );
		if (0 == strncmp(b1, c1,4)){
		xt= atoi(d1);
		printf("The value of xt is %d\n", xt);
		}

		else if (0 == strncmp(b2, c1,4)){
	 	yt= atoi(d1);
		printf("The value of yt is %d\n", yt);
		}

		else if (0 == strncmp(b3, c1,4)){
	 	zt= atoi(d1);
		printf("The value of zt is %d\n", zt);
		}

		else if (0 == strncmp(b4, c1,4)){
	 	x1t= atoi(d1);
		printf("The value of x1t is %d\n", x1t);
		}

		else if (0 == strncmp(b5, c1,4)){
	 	y1t= atoi(d1);
		printf("The value of y1t is %f\n", y1t);
		}

		else if (0 == strncmp(b6, c1,4)){
	 	z1t= atoi(d1);
		printf("The value of z1t is %f\n", z1t);
		}

		else if (0 == strncmp(b71, c1,4)){
	 	l1t= atoi(d1);
		printf("The value of l1t is %f\n", l1t);
		}
   
        	token2 = strtok(NULL, s2);
        	}
		}
    		}
	        token = strtok(NULL, s);	
		}
		}

	
		for (t = 0; t < argc; t++)
      		{
         	totalsize13 += strlen(argv[t]);
      		}
       
       		ret12 = new char[totalsize13 + argc + 1];
		ret12[0]=0;
      		for (t = 0; t < argc; t++)
      		{
        	strcat(ret12, argv[t]);
        	strcat(ret12, " ");
      		}
	


                for(width = yt; width<=x1t;){
             	if( (xt>width) && (xt%2 != 0) && (width%2 !=0) )  // creating the original 2D matrix in 0 degree, so that it can be rotated as desired
              	{ 
	        for(i=0;i<xt;i++)
	        {
	        for(j=0;j<xt;j++)
	        {
	         a=(width-1)/2;  
                 b=((xt-1)/2)-a;
                         
                 for(b=((xt-1)/2)-a;b<=((xt-1)/2)+a;b=b+1)
 		 {
                 if(i==b)
	         {
	          ar1[i][j]=2;
	          printf("%f, ",ar1[i][j]);
	          }
                  }
                     
		  if(i==0)
		  {
                   ar1[i][j]=-1;
                   printf("%f, ",ar1[i][j]);
                   }
	           else if(i==(xt-1))
	           {
	           ar1[i][j]=-1;
	           printf("%f, ",ar1[i][j]);
	           }
                        
	           for(c=1;c<((xt-1)/2)-a;c++)
	           {
                    if(i==c)
	            {
	            ar1[i][j]=-1;
	            printf("%f, ",ar1[i][j]);
	            }
                    }
                        
                    for(d=(((xt-1)/2)+a)+1;d<(xt-1);d++)
	            {
                     if(i==d)
	             {
	              ar1[i][j]=-1;
	              printf("%f, ",ar1[i][j]);
	              }
                      }       
                      }
	              printf("\n");
	              }

                     for(i=0;i<xt;i++)
	             {
	             for(j=0;j<xt;j++)
                     {
                     L0[j+(i*(xt))]=ar1[i][j];
                     printf("%f,\n ",L0[j+(i*(xt))]);
                     }
	             }  
	             }   
                     

     
          	     rgbMat = cvCreateMat(xt, xt, CV_32FC1);
 	  	     rgb1 = cvCreateMat(xt, xt, CV_32FC1);
	   	     rgb2 = cvCreateMat(xt, xt, CV_32FC1); 

          	     for (int y = 0; y < xt; y++) {
         	     for (int x = 0; x < xt; x++) {
            	     cvmSet(rgbMat, y, x, L0[y*(xt) + x]);
           	     }
          	     }
                 
	 	     rot = cvCreateMat(2,3,CV_32FC1);
         	     center = cvPoint2D32f(rgbMat->width/2,rgbMat->height/2); 
	 
    	             scale = 1;

	 	     for(angle =y1t; angle<=l1t; ){
    	 	     rot3= cv2DRotationMatrix( center, angle, scale, rot);	

    		     cvWarpAffine( rgbMat, rgb1, rot); // Transforming the matrix

         	     sum = cvSum(rgb1);       // calculating the sum of all elements of matrix after rotation and printing it
		     printf("The sum is %f\n", sum.val[0]); 

	 	     avg = cvAvg(rgb1);        // calculating the avg of all elements of matrix after rotation and printing it
		     printf("The avg is %f\n", avg.val[0]);  
        	     cvSubS(rgb1, avg, rgb2);    // substracting the average value from each of the elements of matrix after rotation
		     sum1 = cvSum(rgb2);
	 	     printf("The sum is %f\n", sum1.val[0]); // printing the value of sum of all elements after substracting the average value, to check whether the sum of all elements are coming equal to zero

          	     dst = cvCreateImage(cvSize(src->width, src->height), src->depth, 1); 
	 	     cvFilter2D(srcp,dst,rgb2, cvPoint(-1,-1));
	
	 	     snprintf(str, sizeof(str), "%dout%lf.ppm", width, angle);

		     if(strstr(ret12,"-M") != NULL){
		     dstnew = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		     printf("Hi I am new\n");
		     cvSmooth(dst, dstnew, CV_MEDIAN, xt2,yt2,0,0);
		     }

		    else if(strstr(ret12,"-G") != NULL){
		    dstnew = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		    printf("Hi I am new\n");
		    cvSmooth(dst, dstnew, CV_GAUSSIAN, xt5,yt5,0,0);
	            }

	           else if(strstr(ret12,"-L") != NULL){
		   dstnew = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		   printf("Hi I am new\n");
		   cvLaplace(dst, dstnew, xt7);
		   }

		   else if(strstr(ret12,"-S") != NULL){
		   dstnew = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		   printf("Hi I am new\n");
		   cvSobel(dst, dstnew, 1, 0, xt8 );
	           }

		  else if(strstr(ret12,"-B") != NULL){
		  dstnew = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		  printf("Hi I am new\n");
		  cvSmooth(dst, dstnew, CV_BLUR, xt11, yt11, 0,0);
	          }

		  else if(strstr(ret12,"-K") != NULL){
		  dstnew = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		  printf("Hi I am new\n");
		  cvSmooth(dst, dstnew, CV_BILATERAL, xt13, 0, yt13, zt13);
	          }

		 else if(strstr(ret12,"-D") != NULL){
		 dstnew = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		 printf("Hi I am new\n");
		 cvDilate(dst, dstnew, NULL,xt15 );
		 }

		 else if(strstr(ret12,"-E") != NULL){
		 dstnew = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		 printf("Hi I am new\n");
		 cvErode(dst, dstnew, NULL,xt17 );
		 }

		else{
        	dstnew =dst;
	 	printf("Hi I am old\n");
		}	

		cvNamedWindow(str, 1);
		cvShowImage(str, dstnew);
		cvSaveImage(str, dstnew);
 
	 	angle = angle+z1t; 
	 	cvWaitKey(0);
	 	}
         	width = width+zt;
	 	}
         	cvReleaseImage(&dstnew);

         	cvDestroyWindow(argv[1]);
         	cvDestroyWindow(str);
	 	break;
	       
	
      


	case 'F': //filter by image (.png) as input
		printf("I am being clicked :%s\n",optarg);
		rgbMat = cvLoadImageM(optarg, 0);

		for (t = 0; t < argc; t++)
     	        {
         	totalsize1 += strlen(argv[t]);
         	}
   
       		ret1 = new char[totalsize1 + argc + 1];
		ret1[0]=0;
      		for (t = 0; t < argc; t++)
      		{
        	strcat(ret1, argv[t]);
        	strcat(ret1, " ");
      		}


		if((strstr(ret1,"-m") != NULL) || (strstr(ret1,"-g") != NULL) || (strstr(ret1,"-l") != NULL) || (strstr(ret1,"-s") != NULL) || (strstr(ret1,"-b") != NULL) || (strstr(ret1,"-k") != NULL) || (strstr(ret1,"-d") != NULL) || (strstr(ret1,"-e") != NULL) || (strstr(ret1,"-p") != NULL)){
		srcp=srcnew;
		printf("Hi I am new\n");
		}

		else{
         	srcp=src;
	 	printf("Hi I am old\n");
		}

		token5 = strtok(ret1, s5);
		while( token5 != NULL ) 
        	{
	
		for(w1=0;w1<=7;w1++){
		a5=token5;
        	snprintf(c5, sizeof(c5), "a5[%d]", w1 );
		snprintf(d5, sizeof(d5), "%s", a5 );
	
		if (0 == strncmp(f, d5,1)){
		if (d5[0] == 'F') 
      	        memmove(d5, d5+1, strlen(d5));
		if (d5[0] == ' ') 
       		memmove(d5, d5+1, strlen(d5));
		token25 = strtok(d5,s25);
	
		while( token25 != NULL ) 
    		{
	 	for(w1=1;w1<=7;w1++){
		a15=token25;
		snprintf(c15, sizeof(c15), "a[%d]", w1 );
		snprintf(d15, sizeof(d15), "%s", a15 );
	
		if (0 == strncmp(b1, c15,4)){
	 	x1= atof(d15);
		printf("The value of x1 is %f\n", x1);
		}

		else if (0 == strncmp(b2, c15,4)){
		y14= atof(d15);
		printf("The value of y14 is %f\n", y14);
		}

		else if (0 == strncmp(b3, c15,4)){
	 	z1= atof(d15);
		printf("The value of z1 is %f\n", z1);
		}

		else if (0 == strncmp(b4, c15,4)){
	 	o1= atof(d15);
		printf("The value of o1 is %f\n", o1);
		}

		else if (0 == strncmp(b5, c15,4)){
		p1= atof(d15);
		printf("The value of p1 is %f\n", p1);
		}

		else if (0 == strncmp(b6, c15,4)){
	 	r1= atof(d15);
		printf("The value of r1 is %f\n", r1);
		}

		else if (0 == strncmp(b71, c15,4)){
	 	q1= atof(d15);
		printf("The value of q1 is %f\n", q1);
		}
   
        	token25 = strtok(NULL, s25);
        	}  	
		}
    		}
        	token5 = strtok(NULL, s5);
		}
		}
	
		for (t = 0; t < argc; t++)
      		{
         	totalsize12 += strlen(argv[t]);
      		}
       
       		ret11 = new char[totalsize12 + argc + 1];
		ret11[0]=0;
      		for (t = 0; t < argc; t++)
      		{
        	strcat(ret11, argv[t]);
        	strcat(ret11, " ");
      		}
		
          	rgb3 = cvCreateMat(rgbMat->height, rgbMat->width, CV_32FC1);
	  	rgb1 = cvCreateMat(rgbMat->height, rgbMat->width, CV_32FC1);	
	  	rgb2 = cvCreateMat(rgbMat->height, rgbMat->width, CV_32FC1);		

		cvConvertScale(rgbMat, rgb3, 1.0/255.0, 0.0);

	 	rot = cvCreateMat(2,3,CV_32FC1);
       		center = cvPoint2D32f(rgbMat->width/2,rgbMat->height/2); 
		
		for(scale=y14; scale<=o1;){            //beginning of for loops
        	for(angle =p1; angle<=q1; ){
    		rot3= cv2DRotationMatrix( center, angle, scale, rot);		
    		cvWarpAffine( rgb3, rgb1, rot); // Transforming the matrix	
         	sum = cvSum(rgb1);       // calculating the sum of all elements of matrix after rotation and printing it
		printf("The sum is %f\n", sum.val[0]); 

	 	avg = cvAvg(rgb1);        // calculating the avg of all elements of matrix after rotation and printing it
		printf("The avg is %f\n", avg.val[0]);  
        	cvSubS(rgb1, avg, rgb2);    // substracting the average value from each of the elements of matrix after rotation

	
	 	sum1 = cvSum(rgb2);
	 	printf("The sum is %f\n", sum1.val[0]); // printing the value of sum of all elements after substracting the average value, to check whether the sum of all elements are coming equal to zero

         	dst1 = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		printf("I am getting created\n");
       
        	cvFilter2D(srcp, dst1, rgb2, cvPoint(-1,-1));
        	snprintf(str1, sizeof(str), "%.2fout%lf.ppm", scale, angle);
	
	
		if(strstr(ret11,"-M") != NULL){
		dstnew = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		printf("Hi I am new\n");
		cvSmooth(dst1, dstnew, CV_MEDIAN, xt2,yt2,0,0);
		}

		else if(strstr(ret11,"-G") != NULL){
		dstnew = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		printf("Hi I am new\n");
		cvSmooth(dst1, dstnew, CV_GAUSSIAN, xt5,yt5,0,0);
		}

		else if(strstr(ret11,"-L") != NULL){
		dstnew = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		printf("Hi I am new\n");
		cvLaplace(dst1, dstnew, xt7);
		}

		else if(strstr(ret11,"-S") != NULL){
		dstnew = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		printf("Hi I am new\n");
		cvSobel(dst1, dstnew, 1, 0, xt8 );
		}

		else if(strstr(ret11,"-B") != NULL){
		dstnew = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		printf("Hi I am new\n");
		cvSmooth(dst1, dstnew, CV_BLUR, xt11, yt11, 0,0);
		}

		else if(strstr(ret11,"-K") != NULL){
		dstnew = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		printf("Hi I am new\n");
		cvSmooth(dst1, dstnew, CV_BILATERAL, xt13, 0, yt13, zt13);
		}

		else if(strstr(ret11,"-D") != NULL){
		dstnew = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		printf("Hi I am new\n");
		cvDilate(dst1, dstnew, NULL,xt15 );
		}

		else if(strstr(ret11,"-E") != NULL){
		dstnew = cvCreateImage(cvSize(src->width, src->height), src->depth, 1);
		printf("Hi I am new\n");
		cvErode(dst1, dstnew, NULL,xt17 );
		}

		else{
          	dstnew =dst1;
	 	printf("Hi I am old\n");
		}
      
		cvNamedWindow(str1, 1);
		cvShowImage(str1, dstnew);
		cvSaveImage(str1, dstnew);

		angle = angle+r1;        
       	 	cvWaitKey(0);
		}         
		scale = scale+z1;	
		}

	 	cvReleaseImage(&dstnew);		
		cvDestroyWindow(argv[1]);
        	cvDestroyWindow(str1);
		break;

	case 'j':
		 printf("My option is: %s\n",optarg);
		 break;

	default: 
        	 fprintf(stderr, "Usage: %s filename [-f or -F or -m or -M or -g or -G or -l or -L or -s or -S or -b or -B or -k or -K or -d or -D or -e or -E or -p] arguments\n", argv[0]);
        	 exit(EXIT_FAILURE);

        
    }
  }
  return 0;
}
 


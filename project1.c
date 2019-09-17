#include <stdio.h>
#include <stdlib.h>
//#include "time_functions.h"
#include "setpath_defs.h"

void read_chars(FILE *fp,FILE *outfp);
void read_lines(FILE *fp,FILE *outfp);

int main(int argc, char *argv[]){

	FILE *fp;
	FILE *outfp;
	char buff[80];

	if (argc != 3){
		printf("Usage: %s filename mode\n", argv[0]);
	}
	
	setpath(); // must invoke before doing any IO (what are file names for getting fp?)

	// open input and output files
	if ((fp = fopen(argv[1],"r")) == NULL){
		printf("Can't open %s\n", argv[1]);
		return 1;
	}
	setvbuf(fp,buff,_IONBF,80);
	outfp = fopen("outfile.txt","w"); // CHANGE 
	setvbuf(outfp,buff,_IONBF,80);
	
	//request mode for program to use
	int mode = atoi(argv[2]);


	if(mode==0){
		//start_timing();
		read_chars(fp,outfp);
		//stop_timing();
	} 
	else if(mode==1){
		//start_timing();
		read_lines(fp,outfp);
		//stop_timing();
	}
	else {
		printf("Incorrect mode input, mode must be either '1' for line-by-line modeor '0' for character-by-character mode");
		return 1;
	}

	//close files
	fclose(fp);
	fclose(outfp);

	//compute and display times
	//double x = get_wall_clock_dif(); //wall clock difference
	//int y = get_nanodiff(); //CPU clock difference
	double x = 0.00;
	int y = 0;
	printf("Wall clock time: %f\nCPU time: %d\n",x,y);
	//pause311();

	return 0;
}

//Function 1 - character-by-character mode
void read_chars(FILE *fp, FILE *outfp){
	int ch;
	while ((ch = getc(fp)) != EOF) {
		putc(ch, outfp);
	}
	printf("finished reading characters\n");
}

//Function 2 - line-by-line mode
void read_lines(FILE *fp, FILE *outfp){
	char line[80];
	while (fgets(line,sizeof(line),fp) != NULL) {
		fputs(line,outfp);
	}
	printf("finished reading lines\n");
}

#include "setpath_fn.h" 
